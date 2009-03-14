/*
 * FileBinaryInputOutputPort.h - <file binary input/output port>
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
 *  $Id: FileBinaryInputOutputPort.h 1227 2009-02-21 03:01:29Z higepon $
 */

#ifndef __SCHEME__FILE_BINARY_INPUT_OUTPUT_PORT__
#define __SCHEME__FILE_BINARY_INPUT_OUTPUT_PORT__

#include "BinaryInputOutputPort.h"

namespace scheme {

class FileBinaryInputOutputPort : public BinaryInputOutputPort
{
public:
    FileBinaryInputOutputPort(const ucs4string& file, int openFlags);
    virtual ~FileBinaryInputOutputPort();

    // port interfaces
    bool hasPosition() const;
    bool hasSetPosition() const;
    Object position() const;
    int close();
    bool setPosition(int position) ;
    ucs4string toString();

    // binary port interfaces
    int open();
    bool isClosed() const;
    int fileNo() const;

    // input interfaces
    int getU8();
    int lookaheadU8();
    int readBytes(uint8_t* buf, int reqSize, bool& isErrorOccured);
    int readSome(uint8_t** buf, bool& isErrorOccured);
    int readAll(uint8_t** buf, bool& isErrorOccured);

    // output interfaces
    int putU8(uint8_t v);
    int putU8(uint8_t* v, int size);
    int putByteVector(ByteVector* bv, int start = 0);
    int putByteVector(ByteVector* bv, int start, int count);
    void flush();

private:

    ucs4string fileName_;
    int fd_;
    bool isClosed_;
};

}; // namespace scheme

#endif // __SCHEME__FILE_BINARY_INPUT_OUTPUT_PORT__