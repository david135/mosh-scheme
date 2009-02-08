/*
 * VM-inl.h - 
 *
 *   Copyright (c) 2008  Higepon(Taro Minowa)  <higepon@users.sourceforge.jp>
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
 *  $Id: VM-inl.h 261 2008-07-25 06:16:44Z higepon $
 */

#ifndef __SCHEME_VM_INL__
#define __SCHEME_VM_INL__

namespace scheme {

inline void VM::copyJmpBuf(jmp_buf dst, jmp_buf src)
{
    memcpy(dst, src, sizeof(jmp_buf));
}

inline Object VM::fetchOperand()
{
    return *pc_++;
}

inline void VM::skip(int n)
{
    pc_ = pc_ + n ;
}

inline void VM::push(Object obj)
{
    *sp_++ = obj;
}

inline void VM::pushWithCheck(Object obj)
{
    if (sp_ > maxStack_) {
        maxStack_ = sp_;
    }
    *sp_++ = obj;
}

inline Object VM::stackToPairArgs(Object* sp, int nArgs)
{
    Object args = Object::Nil;
    for (int i = 0; i < nArgs; i++) {
        args = Object::cons(index(sp, i), args);
    }
    return args;
}

inline void VM::pairArgsToStack(Object* sp, int offset, Object args)
{
    if (args.isNil()) {
        indexSet(sp, offset, Object::Nil);
    } else {
        const int length = Pair::length(args);
        for (int i =  length - 1; !(args.isNil()); i--, args = args.cdr()) {
            indexSet(sp, i + offset, args.car());
        }
    }
}

inline void VM::indexSet(Object* sp, int i, Object v)
{
    *(sp - i - 1) = v;
}

inline Object* VM::shiftArgsToBottom(Object* sp, int depth, int diff)
{
    for (int i = depth - 1; i >= 0; i--) {
//          stack_[sp - i - diff - 1] = stack_[sp - i - 1];
        indexSet(sp, i + diff, index(sp, i)); // this is fastest
    }
//        memmove(&stack_[sp - diff - depth], &stack_[sp - depth], depth * sizeof(Object));
    return sp - diff;
}

// depth is not used
//    Object* unShiftArgs(Object* sp, int depth, int diff)
inline Object* VM::unShiftArgs(Object* sp, int diff)
{
    for (int i = 0; i < diff; i++) {
        indexSet(sp + diff - i, 0, index(sp, i));
    }
    return sp + diff;
}


inline Object VM::index(Object* sp, int n)
{
    return *(sp - n - 1);
}

    // あとで
inline Object VM::referLocal(int n)
{
    return index(fp_ + n + 1, 0);
}

inline Object VM::referFree(Object n)
{
    MOSH_ASSERT(n.isFixnum());
    return dc_.toClosure()->referFree(n.toFixnum());
}

inline Object VM::referFree(int n)
{
    return dc_.toClosure()->referFree(n);
}

inline Object VM::makeContinuation(Object n)
{
    const int codeSize = 7;
    Object* code = Object::makeObjectArray(codeSize);
    code[0] = Object::makeRaw(Instruction::REFER_LOCAL);
    code[1] = Object::makeFixnum(0);
    code[2] = Object::makeRaw(Instruction::CONTINUATION_VALUES);
    code[3] = Object::makeRaw(Instruction::RESTORE_CONTINUATION);
    code[4] = Object::makeStack(stack_, sp_ - stack_);
    code[5] = Object::makeRaw(Instruction::RETURN);
    code[6] = n;
    return Object::makeClosure(getDirectThreadedCode(code, codeSize), 1, true, sp_, 0, 1, Object::False);
}


Object* VM::getDirectThreadedCode(Object* code, int length)
{
#ifdef USE_DIRECT_THREADED_CODE
    Object* direct = Object::makeObjectArray(length);
    void** table = (void**)run(NULL, NULL, true).val;
    for (int i = 0; i < length; i++) {
        // Direct threaded code
        // Be careful on using direct threaded code for following case.
        //   1. pre-compiled compiler has two types of instructions.
        //      (a) Instruction Object
        //          index for dispatch_table[].
        //          this object will be converted into the address of LABEL_XXX for direct jump.
        //      (b) CompilerInstruction Object
        //          Only pre-compiled compiler has this object.
        //          This object represents the instruction code which the compiler outputs.
        //      For example
        //          If compiler has a scheme code 'PUSH, it is pre-compiled into '(<Instruction::CONSTANT> <CompilerInstruction::PUSH>).
        if (code[i].isCompilerInstruction()) {
            direct[i] = Object::makeInstruction(code[i].toCompilerInstruction());
        } else if (code[i].isPair()) {
            // special case on compiler.scm
            // compiler.scm includes '(0 UNDEF) and UNDEF should be compiled as CompilerInstruction Object.
            for (Object p = code[i]; !p.isNil(); p = p.cdr()) {
                if (p.car().isCompilerInstruction()) {
                    p.toPair()->car = (Object::makeInstruction(p.car().toCompilerInstruction()));
                }
                // p can be dotted list.
                if (!p.cdr().isPair()) {
                    break;
                }
            }
            direct[i] = code[i];
        } else if (code[i].isInstruction()) {
            direct[i].val = (word)(table[code[i].val]);
        } else {
            direct[i] = code[i];
        }
    }
    return direct;
#else
    return code;
#endif
}


#ifdef ENABLE_PROFILER

inline void VM::countCall(Object proc)
{
    if (isProfiler_ && profilerRunning_) {
        static int i = 0;
        if (i >= SAMPLE_NUM) {
            stopTimer();
            storeCallSample();
            startTimer();
            i = 0;
        }
        callSamples_[i++] = proc;
    }
}

#endif // ENABLE_PROFILER

}; // namespace scheme

#endif // __SCHEME_VM_INL__