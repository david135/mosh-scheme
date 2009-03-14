/*
 * CustomBinaryInputOutputPort.h - 
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
 *  $Id: CustomBinaryInputOutputPort.h 261 2008-07-25 06:16:44Z higepon $
 */

#ifndef __SCHEME_CUSTOM_BINARY_INPUT_OUTPUT_PORT__
#define __SCHEME_CUSTOM_BINARY_INPUT_OUTPUT_PORT__

#include "BinaryInputOutputPort.h"

namespace scheme {

class CustomBinaryInputOutputPort : public BinaryInputOutputPort
{
public:
    CustomBinaryInputOutputPort(VM* theVM,
                                const ucs4string& id,
                                Object readProc,
                                Object writeProc,
                                Object getPositionProc,
                                Object setPositionProc,
                                Object closeProc);
    virtual ~CustomBinaryInputOutputPort();

    int getU8();
    int lookaheadU8();
    int readBytes(uint8_t* buf, int reqSize, bool& isErrorOccured);
    int readSome(uint8_t** buf, bool& isErrorOccured);
    int readAll(uint8_t** buf, bool& isErrorOccured);
    ucs4string toString();
    int open();
    int close();
    bool isClosed() const;
    int fileNo() const;

    // out
    int putU8(uint8_t v);
    int putU8(uint8_t* v, int size);
    int putByteVector(ByteVector* bv, int start = 0);
    int putByteVector(ByteVector* bv, int start, int count);
    void flush();

    bool hasPosition() const;
    bool hasSetPosition() const;
    Object position() const;
    bool setPosition(int position);

private:
    bool hasAheadU8() const;

    VM* theVM_;
    const ucs4string id_;
    const Object readProc_;
    const Object writeProc_;
    const Object getPositionProc_;
    const Object setPositionProc_;
    const Object closeProc_;

    bool isClosed_;
    int aheadU8_;
};

}; // namespace scheme

#endif // __SCHEME_CUSTOM_BINARY_INPUT_OUTPUT_PORT__