/*
 * CustomBinaryInputPort.cpp -
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
 *  $Id: CustomBinaryInputPort.cpp 183 2008-07-04 06:19:28Z higepon $
 */


#include "Object.h"
#include "Object-inl.h"
#include "Pair.h"
#include "Pair-inl.h"
#include "ByteVector.h"
#include "CustomBinaryInputPort.h"
#include "VM.h"

using namespace scheme;

CustomBinaryInputPort::CustomBinaryInputPort(VM* theVM, Object readProc) : theVM_(theVM), readProc_(readProc), isClosed_(false), u8Buf_(EOF)
{
}

CustomBinaryInputPort::~CustomBinaryInputPort()
{
}

ucs4string CustomBinaryInputPort::toString()
{
    return UC("<custom port>");
}

int CustomBinaryInputPort::open()
{
    return 0;
}

int CustomBinaryInputPort::close()
{
    // todo if close! proc exists
    isClosed_ = true;
    return 0;
}

bool CustomBinaryInputPort::isClosed() const
{
    return isClosed_;
}

int CustomBinaryInputPort::getU8()
{
    if (u8Buf_ != EOF) {
        int c = u8Buf_;
        u8Buf_ = EOF;
        return c;
    }

    const Object bv = Object::makeByteVector(1);
    const Object start = Object::makeFixnum(0);
    const Object count = Object::makeFixnum(1);
    const Object result = theVM_->callClosure3(readProc_, bv, start, count);
    MOSH_ASSERT(result.isFixnum());
    if (0 == result.toFixnum()) {
        return EOF;
    }
    return bv.toByteVector()->u8Ref(0);
}

int CustomBinaryInputPort::lookaheadU8()
{
    if (u8Buf_ != EOF) {
        return u8Buf_;
    }

    const Object bv = Object::makeByteVector(1);
    const Object start = Object::makeFixnum(0);
    const Object count = Object::makeFixnum(1);
    const Object result = theVM_->callClosure3(readProc_, bv, start, count);
    MOSH_ASSERT(result.isFixnum());
    if (0 == result.toFixnum()) {
        return EOF;
    }
    u8Buf_ = bv.toByteVector()->u8Ref(0);
    return u8Buf_;
}

ByteVector* CustomBinaryInputPort::getByteVector(uint32_t size)
{
    fprintf(stderr, "get-byte-vector-n not implemented");
    exit(-1);
}

int CustomBinaryInputPort::fileNo() const
{
    return BinaryInputPort::INVALID_FILENO;
}