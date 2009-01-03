/*
 * Object.cpp - 
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
 *  $Id$
 */

#include "Object.h"
#include "Object-inl.h"
#include "Pair.h"
#include "Pair-inl.h"
#include "Record.h"
#include "Equivalent.h"
#include "Vector.h"
#include "SString.h"
#include "Symbol.h"
#include "ByteVector.h"
#include "Closure.h"
#include "Stack.h"
#include "EqHashTable.h"
#include "GenericHashTable.h"
#include "EqvHashTable.h"
#include "CProcedure.h"
#include "Box.h"
#include "Regexp.h"
#include "UtilityProcedures.h"
#include "Callable.h"
#include "Record.h"
#include "RecordTypeDescriptor.h"
#include "RecordConstructorDescriptor.h"
#include "CompoundCondition.h"
#include "FileBinaryInputPort.h"
#include "FileBinaryOutputPort.h"
#include "TextualOutputPort.h"
#include "TextualInputPort.h"
#include "Latin1Codec.h"
#include "UTF8Codec.h"
#include "UTF16Codec.h"
#include "Transcoder.h"
#include "StringTextualInputPort.h"
#include "StringTextualOutputPort.h"
#include "ByteArrayBinaryInputPort.h"
#include "CustomBinaryInputPort.h"
#include "TextualByteVectorOutputPort.h"
#include "CodeBuilder.h"
#include "Ratnum.h"
#include "Flonum.h"
#include "Bignum.h"
#include "ProcedureMacro.h"
#include "Compnum.h"
#include "Arithmetic.h"

using namespace scheme;

const Object Object::Nil     = Object::makeConst(0);
const Object Object::Eof     = Object::makeConst(1);
const Object Object::Undef   = Object::makeConst(2);
const Object Object::UnBound = Object::makeConst(3);
const Object Object::True    = Object::makeConst(4);
const Object Object::False   = Object::makeConst(5);
const Object Object::Ignore  = Object::makeConst(6);

bool Object::isRational() const
{
    return isFixnum() || isBignum() || (isFlonum() && toFlonum()->isRational()) || isRatnum();
}


bool Object::isReal() const
{
    return isFixnum() || isBignum() || isFlonum() || isRatnum() || (isCompnum() && toCompnum()->isReal());
}

bool Object::isInteger() const
{
    return isFixnum() || isBignum() || (isNumber() && Arithmetic::isInteger(*this));
}

bool Object::equal(VM* theVM, Object o) const
{
    return ::equal(*this, o, new EqHashTable());
}

Object Object::makeBinaryInputPort(FILE* in)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::BinaryInputPort,
                                                        reinterpret_cast<word>(new FileBinaryInputPort(in)))));
}

Object Object::makeBinaryOutputPort(FILE* out)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::BinaryOutputPort,
                                                        reinterpret_cast<word>(new FileBinaryOutputPort(out)))));
}

Object Object::makeBinaryInputPort(BinaryInputPort* port)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::BinaryInputPort,
                                                        reinterpret_cast<word>(port))));
}

Object Object::makeBinaryOutputPort(BinaryOutputPort* port)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::BinaryOutputPort,
                                                        reinterpret_cast<word>(port))));
}

Object Object::makeTextualOutputPort(BinaryOutputPort* port, Transcoder* transcoder)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::TextualOutputPort,
                                                        reinterpret_cast<word>(new TextualOutputPort(port, transcoder)))));
}



Object Object::makeTextualInputFilePort(const ucs4char* file)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::TextualInputPort,
                                                        reinterpret_cast<word>(new TextualInputPort(new FileBinaryInputPort(file)
                                                                                                    , new Transcoder(new UTF8Codec, Transcoder::LF, Transcoder::IGNORE_ERROR))))));
}

Object Object::makeTextualInputFilePort(const char* file)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::TextualInputPort,
                                                        reinterpret_cast<word>(new TextualInputPort(new FileBinaryInputPort(file)
                                                                                                    , new Transcoder(new UTF8Codec, Transcoder::LF, Transcoder::IGNORE_ERROR))))));
}


Object Object::makeStringInputPort(const ucs4string& str)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::TextualInputPort,
                                                        reinterpret_cast<word>(new StringTextualInputPort(str)))));
}

Object Object::makeStringOutputPort()
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::TextualOutputPort,
                                                        reinterpret_cast<word>(new StringTextualOutputPort()))));
}

Object Object::makeStringInputPort(const uint8_t* buf, int size)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::TextualInputPort,
                                                        reinterpret_cast<word>(new TextualInputPort(new ByteArrayBinaryInputPort(buf, size)
                                                                                                    , new Transcoder(new UTF8Codec, Transcoder::LF, Transcoder::IGNORE_ERROR))))));
}

Object Object::makeCustomBinaryInputPort(VM* theVM, Object readProc)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::BinaryInputPort,
                                                        reinterpret_cast<word>(new CustomBinaryInputPort(theVM, readProc)))));
}

Object Object::makeLatin1Codec()
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::Codec,
                                                        reinterpret_cast<word>(new Latin1Codec()))));
}

Object Object::makeUTF8Codec()
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::Codec,
                                                        reinterpret_cast<word>(new UTF8Codec()))));
}

Object Object::makeUTF16Codec()
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::Codec,
                                                        reinterpret_cast<word>(new UTF16Codec()))));
}

Object Object::makeTranscoder(Codec* codec)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::Transcoder,
                                                        reinterpret_cast<word>(new Transcoder(codec)))));
}

Object Object::makeTranscoder(Codec* codec, const Object eolStyle)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::Transcoder,
                                                        reinterpret_cast<word>(new Transcoder(codec, eolStyle)))));
}

Object Object::makeTranscoder(Codec* codec, const Object eolStyle, const Object errorHandlingMode)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::Transcoder,
                                                        reinterpret_cast<word>(new Transcoder(codec, eolStyle, errorHandlingMode)))));
}

Object Object::makeTextualInputPort(BinaryInputPort* port, Transcoder* transcoder)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::TextualInputPort,
                                                        reinterpret_cast<word>(new TextualInputPort(port, transcoder)))));
}

Object Object::makeTextualByteVectorOuputPort(Transcoder* transcoder)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::TextualOutputPort,
                                                        reinterpret_cast<word>(new TextualByteVectorOutputPort(transcoder)))));
}

Object Object::makeRegexp(const ucs4string& pattern, bool caseFold /* = false */)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::Regexp,
                                                        reinterpret_cast<word>(new Regexp(pattern, caseFold)))));
}

Object Object::makeRegMatch(OnigRegion* region, const ucs4string& text)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::RegMatch,
                                                        reinterpret_cast<word>(new RegMatch(region, text)))));
}
Object Object::makeSymbol(const ucs4char* str)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::Symbol, reinterpret_cast<word>(new Symbol(str)))));
}

Object Object::makeBox(Object o)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::Box, reinterpret_cast<word>(new Box(o)))));
}

Object Object::makeByteVector(int n)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::ByteVector, reinterpret_cast<word>(new ByteVector(n)))));
}

Object Object::makeByteVector(int n, int8_t v)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::ByteVector, reinterpret_cast<word>(new ByteVector(n, v)))));
}

Object Object::makeStack(Object* src, int size)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::Stack, reinterpret_cast<word>(new Stack(src, size)))));
}


Object Object::makeEqHashTable()
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::EqHashTable, reinterpret_cast<word>(new EqHashTable()))));
}

Object Object::makeEqvHashTable(VM* theVM)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::EqvHashTable, reinterpret_cast<word>(new EqvHashTable(theVM)))));
}


Object Object::makeCProcedure(Object (*proc)(VM* vm, int, const Object*))
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::CProcedure, reinterpret_cast<word>(new CProcedure(proc)))));
}

Object Object::makeCodeBuilder()
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::CodeBuilder,
                                                        reinterpret_cast<word>(new CodeBuilder()))));
}

Object Object::makeGenericHashTable(VM* theVM, Object hashFunction, Object equivalenceFunction)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::GenericHashTable,
                                                        reinterpret_cast<word>(new GenericHashTable(theVM, hashFunction, equivalenceFunction)))));
}

Object Object::makeCallable(Callable* callable)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::Callable,
                                                        reinterpret_cast<word>(callable))));
}

Object Object::makeRecordTypeDescriptor(Object name,
                                        Object parent,
                                        Object uid,
                                        Object isSealed,
                                        Object isOpaque,
                                        Object fields)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::RecordTypeDescriptor,
                                                        reinterpret_cast<word>(new RecordTypeDescriptor(name,
                                                                                                        parent,
                                                                                                        uid,
                                                                                                        isSealed,
                                                                                                        isOpaque,
                                                                                                        fields)))));
}

Object Object::makeRecord(Object rtd, const Object* fields, int fieldsLength)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::Record,
                                                        reinterpret_cast<word>(new Record(rtd,
                                                                                          fields,
                                                                                          fieldsLength)))));
}

Object Object::makeRecordConstructorDescriptor(VM* theVM,
                                               Object rtd,
                                               Object parentRcd,
                                               Object protocol)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::RecordConstructorDescriptor,
                                                        reinterpret_cast<word>(new RecordConstructorDescriptor(theVM,
                                                                                                               rtd,
                                                                                                               parentRcd,
                                                                                                               protocol)))));
}

Object Object::makeCompoundCondition(int conditionCounts, const Object* conditions)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::CompoundCondition,
                                                        reinterpret_cast<word>(new CompoundCondition(conditionCounts,
                                                                                                     conditions)))));
}

Object Object::makeCompoundCondition(Object conditions)
{
    const int conditionCounts = Pair::length(conditions);
    Object* conditionsArray = Object::makeObjectArray(conditionCounts);
    Object p = conditions;
    for (int i = 0; i < conditionCounts; i++) {
        conditionsArray[i] = p.car();
        p = p.cdr();
    }
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::CompoundCondition,
                                                        reinterpret_cast<word>(new CompoundCondition(conditionCounts,
                                                                                                     conditionsArray)))));
}

Object Object::makeRatnum(int numerator, int denominator)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::Ratnum,
                                                        reinterpret_cast<word>(new Ratnum(numerator, denominator)))));
}

Object Object::makeRatnum(mpq_t r)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::Ratnum,
                                                        reinterpret_cast<word>(new Ratnum(r)))));
}

Object Object::makeFlonum(double value)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::Flonum,
                                                        reinterpret_cast<word>(new Flonum(value)))));
}

Object Object::makeBignum(long n)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::Bignum,
                                                        reinterpret_cast<word>(new Bignum(n)))));
}

Object Object::makeBignum(const mpz_t b)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::Bignum,
                                                        reinterpret_cast<word>(new Bignum(b)))));
}

Object Object::makeBignum(Bignum* b)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::Bignum,
                                                        reinterpret_cast<word>(b))));
}

Object Object::makeRatnum(Ratnum* r)
{
    return Object(reinterpret_cast<word>(new HeapObject(HeapObject::Ratnum,
                                                        reinterpret_cast<word>(r))));
}

Object Object::makeCompnum(Object real, Object imag)
{
    if (Arithmetic::isExactZero(imag)) {
        return real;
    } else {
        return Object(reinterpret_cast<word>(new HeapObject(HeapObject::Compnum,
                                                            reinterpret_cast<word>(new Compnum(real, imag)))));
    }
}

bool Object::isIntegerValued() const
{
    return Arithmetic::isIntegerValued(*this);
}

bool Object::isList() const
{
    return Pair::isList(*this);
}


Object* Object::makeObjectArray(int size)
{
#ifdef USE_BOEHM_GC
    return new(GC) Object[size];
#else
    return new Object[size];
#endif
}