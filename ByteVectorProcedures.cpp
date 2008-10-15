/*
 * ByteVectorProcedures.cpp -
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
 *  $Id: ByteVectorProcedures.cpp 183 2008-07-04 06:19:28Z higepon $
 */

#include "Object.h"
#include "Object-inl.h"
#include "Pair.h"
#include "Pair-inl.h"
#include "SString.h"
#include "ByteVector.h"
#include "ByteVectorProcedures.h"
#include "BinaryInputPort.h"
#include "Symbol.h"
#include "ProcedureMacro.h"

using namespace scheme;

Object scheme::bytevectorCopyEx(int argc, const Object* argv)
{
    DeclareProcedureName("bytevector-copy");
    checkArgumentLength(1);
    argumentAsByteVector(0, bytevector);
    return Object::makeByteVector(bytevector->copy());
}

Object scheme::bytevectorCopyDEx(int argc, const Object* argv)
{
    DeclareProcedureName("bytevector-copy!");
    checkArgumentLength(5);
    argumentAsByteVector(0, source);
    argumentAsInt(1, sourceStart);
    argumentAsByteVector(2, target)
    argumentAsInt(3, targetStart);
    argumentAsInt(4, k);

    const int sourceLength = source->length();
    const int targetLength = target->length();

    if ((sourceStart <= sourceStart + k)  &&
        (sourceStart + k <= sourceLength) &&
        (0 <= targetStart)                &&
        (targetStart <= targetStart + k)  &&
        (targetStart + k <= targetLength)) {
        memmove(target->data() + targetStart, source->data() + sourceStart, k);
    } else {
        callAssertionViolationAfter(procedureName, "invalid range");
    }
    return Object::Undef;
}

Object scheme::bytevectorFillDEx(int argc, const Object* argv)
{
    DeclareProcedureName("bytevector-fill!");
    checkArgumentLength(2);
    argumentAsByteVector(0, bytevector);
    argumentAsInt(1, value);
    if (ByteVector::isByte(value) || ByteVector::isOctet(value)) {
        bytevector->fill(static_cast<uint8_t>(value));
    } else {
        callAssertionViolationAfter(procedureName, "invalid bytevector value. should be 0 <= v <= 255", L1(argv[1]));
    }
    return Object::Undef;
}

Object scheme::bytevectorEqPEx(int argc, const Object* argv)
{
    DeclareProcedureName("bytevector=?");
    checkArgumentLength(2);
    argumentAsByteVector(0, bv0);
    argumentAsByteVector(1, bv1);
    return Object::makeBool(bv0->equal(bv1));
}

Object scheme::makeBytevectorEx(int argc, const Object* argv)
{
    DeclareProcedureName("make-bytevector");
    checkArgumentLengthBetween(1, 2);
    argumentAsInt(0, length);
    if (1 == argc) {
        return Object::makeByteVector(length);
    } else {
        argumentAsInt(1, value);
        if (ByteVector::isByte(value) || ByteVector::isOctet(value)) {
            return Object::makeByteVector(length, static_cast<uint8_t>(value));
        } else {
            callAssertionViolationAfter(procedureName, "invalid bytevector value. should be 0 <= v <= 255", L1(argv[1]));
            return Object::Undef;
        }
    }
}

Object scheme::nativeEndiannessEx(int argc, const Object* argv)
{
    DeclareProcedureName("native-endianness");
    checkArgumentLength(0);

    static Object nativeEndianness = Object::False;
    if (nativeEndianness.isFalse()) {
#if WORDS_BIGENDIAN
        nativeEndianness = Symbol::intern(UC("big"));
#else
        nativeEndianness = Symbol::intern(UC("little"));
#endif
    }
    return nativeEndianness;
}

Object scheme::bytevectorU8SetDEx(int argc, const Object* argv)
{
    DeclareProcedureName("bytevector-u8-set!");
    checkArgumentLength(3);

    argumentAsByteVector(0, bytevector);
    argumentAsInt(1, index);
    argumentAsInt(2, value);

    if (bytevector->isValidIndex(index)) {
        if (ByteVector::isOctet(value)) {
            bytevector->u8Set(index, static_cast<uint8_t>(value));
        } else {
            callAssertionViolationAfter(procedureName, "value out of range. should be 0 <= value <= 255", L1(argv[2]));
        }
    } else {
        callAssertionViolationAfter(procedureName, "index out of range.", L1(argv[1]));
    }
    return Object::Undef;
}

Object scheme::bytevectorU8RefEx(int argc, const Object* argv)
{
    DeclareProcedureName("bytevector-u8-ref");
    checkArgumentLength(2);

    argumentAsByteVector(0, bytevector);
    argumentAsInt(1, index);
    if (bytevector->isValidIndex(index)) {
        return Object::makeInt(bytevector->u8Ref(index));
    } else {
        callAssertionViolationAfter(procedureName, "index out of range.", L1(argv[2]));
    }
}

Object scheme::bytevectorS8SetDEx(int argc, const Object* argv)
{
    DeclareProcedureName("bytevector-s8-set!");
    checkArgumentLength(3);

    argumentAsByteVector(0, bytevector);
    argumentAsInt(1, index);
    argumentAsInt(2, value);

    if (bytevector->isValidIndex(index)) {
        if (ByteVector::isByte(value)) {
            bytevector->s8Set(index, static_cast<int8_t>(value));
        } else {
            callAssertionViolationAfter(procedureName, "value out of range. should be -127 <= value <= 128", L1(argv[2]));
        }
    } else {
        callAssertionViolationAfter(procedureName, "index out of range.", L1(argv[1]));
    }

    return Object::Undef;
}

Object scheme::bytevectorS8RefEx(int argc, const Object* argv)
{
    DeclareProcedureName("bytevector-s8-ref");
    checkArgumentLength(2);

    argumentAsByteVector(0, bytevector);
    argumentAsInt(1, index);

    if (bytevector->isValidIndex(index)) {
        return Object::makeInt(bytevector->s8Ref(index));
    } else {
        callAssertionViolationAfter(procedureName, "index out of range.", L1(argv[1]));
    }
}


Object scheme::bytevectorLengthEx(int argc, const Object* argv)
{
    DeclareProcedureName("bytevector-length");
    checkArgumentLength(1);

    argumentAsByteVector(0, bytevector);
    return Object::makeInt(bytevector->length());
}

Object scheme::getBytevectorNEx(int argc, const Object* argv)
{
    DeclareProcedureName("get-byte-vector-n");
    checkArgumentLength(2);

    argumentAsBinaryInputPort(0, binaryInputPort);
    argumentAsInt(1, count);

    ByteVector* ret = binaryInputPort->getByteVector(count);
    if (ret->length() == 0) {
        return Object::Eof;
    } else {
        return Object::makeByteVector(ret);
    }
}
