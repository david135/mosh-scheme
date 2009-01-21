/*
 * FFIProcedures.cpp -
 *
 *   Copyright (c) 2009  Higepon(Taro Minowa)  <higepon@users.sourceforge.jp>
 *
 *   Redistribution and use in source and binary forms, with or without
 *   modification, are permitted provided that the following conditions
 *   are met:
 *
 *   1. Redistributions of source code must retain the above copyright
 *      notice, this list of conditions and the following disclaimer.
 *
 *   2. Redistributions in binary form must reproduce the above copyright
 *      notice, this list of conditions and the following disclaimer in the
 *      documentation and/or other materials provided with the distribution.
 *
 *   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 *   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 *   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 *   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 *   TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 *   PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 *   LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 *   NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 *   SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *  $Id: FFIProcedures.cpp 183 2008-07-04 06:19:28Z higepon $
 */

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include <errno.h>
#include "Object.h"
#include "Object-inl.h"
#include "Pair.h"
#include "Pair-inl.h"
#include "SString.h"
#include "VM.h"
#include "ProcedureMacro.h"
#include "FFIProcedures.h"
#include "FFI.h"
#include "Bignum.h"
#include "Symbol.h"

using namespace scheme;

#ifdef ARCH_IA32
#define FFI_SUPPORTED 1
#elif defined ARCH_X86_64
#define FFI_SUPPORTED 1
#endif


static intptr_t callStub(uintptr_t func, intptr_t* frame, int argc)
{
#ifdef ARCH_IA32
    const int bytes = (argc * sizeof(intptr_t) + 15) & ~15;
    intptr_t ret;
    asm volatile(
        "movl    %%esp, %%edx ;"
        "subl    %1   , %%esp ;"
        "movl    %%esp, %%edi ;" // copy arguments to stack
        "rep                  ;"
        "movsb                ;"
        "movl    %%edx, %%edi ;"
        "call    *%%eax       ;"
        "movl    %%edi, %%esp ;"
        : "=a" (ret)
        : "c" (bytes), "S" (frame), "0" (func) // c:ecx, S:esi 0:match to the 0th output
        : "edi", "edx", "memory"); // we have memory destructions.
    return ret;
#elif defined ARCH_X86_64
    intptr_t ret = 0;
    const int MAX_REG = 6;
    if (argc <= MAX_REG) {
        asm volatile("movq %%rsi, %%r10;"
                     "movq 0(%%r10), %%rdi ;"   // register argument 1
                     "movq 8(%%r10), %%rsi ;"   // register argument 2
                     "movq 16(%%r10), %%rdx ;"  // register argument 3
                     "movq 24(%%r10), %%rcx ;"  // register argument 4
                     "movq 32(%%r10), %%r8 ;"   // register argument 5
                     "movq 40(%%r10), %%r9 ;"   // register argument 6
                     "call *%%rax ;"
                     : "=a" (ret)
                     : "0" (func), "S" (frame)
                       // , "r10" (frame)
                     : "memory"
            );
    } else {
        const int bytes = (argc - 6) * 8;
        asm volatile(
            "movq %%rsi, %%r10;" // r10 for pointing frame top
            "movq %%r10, %%r11;" // r11 for pointer to stack argument in frame
            "addq $48 , %%r11;"
            "movq %%r11, %%r12;"
            "addq %%rcx, %%r12;"  // r12 end of stack argument in frame
            "movq 0(%%r10), %%rdi ;"   // register argument 1
            "movq 8(%%r10), %%rsi ;"   // register argument 2
            "movq 16(%%r10), %%rdx ;"  // register argument 3
            "movq 24(%%r10), %%rcx ;"  // register argument 4
            "movq 32(%%r10), %%r8 ;"   // register argument 5
            "movq 40(%%r10), %%r9 ;"   // register argument 6
            "movq %%rsp, %%r13;"
            "1:   ;"
            "cmpq %%r11, %%r12;"
            "je 2f;"
            "movq 0(%%r11), %%r14;"
            "movq %%r14, 0(%%r13);"
            "addq $8, %%r11;"
            "addq $8, %%r13;"
            "jmp 1b;"
            "2:   ;"
            "call *%%rax ;"
            : "=a" (ret)
            : "c" (bytes), "0" (func), "S" (frame)
            : "memory"
            );
    }

    return ret;

#else
    return 0;
#endif
}

Object scheme::internalFfiSupportedPEx(VM* theVM, int argc, const Object* argv)
{
    DeclareProcedureName("%ffi-supported?");
    checkArgumentLengthAtLeast(0);
#ifdef FFI_SUPPORTED
    return Object::True;
#else
    return Object::False;
#endif
}

Object scheme::internalFfiCallTovoidMulEx(VM* theVM, int argc, const Object* argv)
{
    DeclareProcedureName("%ffi-call->void*");
#ifndef FFI_SUPPORTED
    callAssertionViolationAfter(theVM, procedureName, "ffi not supported on this architecture");
    return Object::Undef;
#endif

    checkArgumentLengthAtLeast(1);
    argumentAsUintptr_t(0, func, "Invalid FFI function");

    CStack cstack;
    for (int i = 1; i < argc; i++) {
        if (!cstack.push(argv[i])) {
            callAssertionViolationAfter(theVM, procedureName, "argument error", L2(cstack.getLastError(),
                                                                                   argv[i]));
            return Object::Undef;
        }
    }

    const uintptr_t ret = callStub(func, cstack.frame(), cstack.count());
    return Bignum::makeIntegerFromUintprt_t(ret);
}

Object scheme::internalFfiCallTovoidEx(VM* theVM, int argc, const Object* argv)
{
    DeclareProcedureName("%ffi-call->void");
#ifndef FFI_SUPPORTED
    callAssertionViolationAfter(theVM, procedureName, "ffi not supported on this architecture");
    return Object::Undef;
#endif

    checkArgumentLengthAtLeast(1);
    argumentAsUintptr_t(0, func, "Invalid FFI function");
    CStack cstack;
    for (int i = 1; i < argc; i++) {
        if (!cstack.push(argv[i])) {
            callAssertionViolationAfter(theVM, procedureName, "argument error", L2(cstack.getLastError(),
                                                                                   argv[i]));
            return Object::Undef;
        }
    }

    callStub(func, cstack.frame(), cstack.count());
    return Object::Undef;
}

Object scheme::internalFfiCallTointEx(VM* theVM, int argc, const Object* argv)
{
    DeclareProcedureName("%ffi-call->int");
#ifndef FFI_SUPPORTED
    callAssertionViolationAfter(theVM, procedureName, "ffi not supported on this architecture");
    return Object::Undef;
#endif

    checkArgumentLengthAtLeast(1);
    argumentAsUintptr_t(0, func, "Invalid FFI function");

    CStack cstack;
    for (int i = 1; i < argc; i++) {
        if (!cstack.push(argv[i])) {
            callAssertionViolationAfter(theVM, procedureName, "argument error", L2(cstack.getLastError(),
                                                                                   argv[i]));
            return Object::Undef;
        }
    }

    const intptr_t ret = callStub(func, cstack.frame(), cstack.count());
    return Bignum::makeIntegerFromIntprt_t(ret);
}
Object scheme::internalFfiLookupEx(VM* theVM, int argc, const Object* argv)
{
    DeclareProcedureName("%ffi-lookup");

#ifndef FFI_SUPPORTED
    callAssertionViolationAfter(theVM, procedureName, "ffi not supported on this architecture");
    return Object::Undef;
#endif

    checkArgumentLength(2);
    argumentAsUintptr_t(0, handle, "invalid shared library handle");
    argumentAsSymbol(1, name);

    ucs4string n = name->c_str();
    void* symbol = FFI::lookup((void*)handle, n.ascii_c_str());

    if (NULL == symbol) {
        return Object::False;
    } else {
        return Bignum::makeIntegerFromUintprt_t(reinterpret_cast<uintptr_t>(symbol));
    }
}

Object scheme::internalFfiOpenEx(VM* theVM, int argc, const Object* argv)
{
    DeclareProcedureName("%ffi-open");

#ifndef FFI_SUPPORTED
    callAssertionViolationAfter(theVM, procedureName, "ffi not supported on this architecture");
    return Object::Undef;
#endif

    checkArgumentLength(1);
    argumentAsString(0, name);
    void* handle = FFI::open(name->data().ascii_c_str());
    if (NULL == handle) {
        callAssertionViolationAfter(theVM, procedureName, "shared library not found", L2(FFI::lastError(), argv[0]));
        return Object::Undef;
    } else {
        return Bignum::makeIntegerFromUintprt_t(reinterpret_cast<uintptr_t>(handle));
    }
}

Object scheme::internalFfiCallTostringOrZeroEx(VM* theVM, int argc, const Object* argv)
{
    DeclareProcedureName("%ffi-call->string-or-zero");

#ifndef FFI_SUPPORTED
    callAssertionViolationAfter(theVM, procedureName, "ffi not supported on this architecture");
    return Object::Undef;
#endif

    checkArgumentLengthAtLeast(1);
    argumentAsUintptr_t(0, func, "Invalid FFI function");

    CStack cstack;
    for (int i = 1; i < argc; i++) {
        if (!cstack.push(argv[i])) {
            callAssertionViolationAfter(theVM, procedureName, "argument error", L2(cstack.getLastError(),
                                                                                   argv[i]));
            return Object::Undef;
        }
    }

    const uintptr_t ret = callStub(func, cstack.frame(), cstack.count());
    if (ret == 0) {
        return Object::makeFixnum(0);
    } else {

        return Object::makeString((char*)ret);
    }

}

Object scheme::internalFfiPointerTostringEx(VM* theVM, int argc, const Object* argv)
{
    DeclareProcedureName("%ffi-pointer->string");

#ifndef FFI_SUPPORTED
    callAssertionViolationAfter(theVM, procedureName, "ffi not supported on this architecture");
    return Object::Undef;
#endif

    checkArgumentLength(1);
    argumentAsUintptr_t(0, p, "pointer required");
    return Object::makeString((char*)p);
}

Object scheme::internalFfiPointerRefEx(VM* theVM, int argc, const Object* argv)
{
    DeclareProcedureName("%ffi-pinter-ref");

#ifndef FFI_SUPPORTED
    callAssertionViolationAfter(theVM, procedureName, "ffi not supported on this architecture");
    return Object::Undef;
#endif

    checkArgumentLengthBetween(1, 2);
    argumentAsUintptr_t(0, p, "pointer required");
    if (argc == 1) {
        return Bignum::makeIntegerFromUintprt_t(*(uintptr_t*)p);
    } else { // argc == 2
        argumentAsFixnum(1, index);
        return Bignum::makeIntegerFromUintprt_t(((uintptr_t*)p)[index]);
    }
}

// Object scheme::internalFfiPointerValueEx(VM* theVM, int argc, const Object* argv)
// {
//     DeclareProcedureName("%ffi-pointer-value");
//     checkArgumentLength(1);
//     const Object obj = argv[0];
//     if (obj.isHeapObject()) {
//         // we know it may over flow, but enough
// //        return Object::makeFixnum(reinterpret_cast<uintptr_t>(reinterpret_cast<HeapObject*>(val)->obj));
//         return Bignum::makeIntegerFromUintprt_t(static_cast<uintptr_t>(reinterpret_cast<HeapObject*>(obj.val)->obj));

//     } else {
//         callAssertionViolationAfter(theVM, procedureName, "not a pointer object", L1(obj));
//         return Object::Undef;
//     }
// }
