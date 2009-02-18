/*
 * UTF32Codec.h - 
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
 *  $Id: UTF32Codec.h 261 2008-07-25 06:16:44Z higepon $
 */

#ifndef __SCHEME_UTF32_CODEC__
#define __SCHEME_UTF32_CODEC__

#include "Codec.h"

namespace scheme {

class ByteVector;

class UTF32Codec : public Codec
{
public:
    enum {
        UTF_32BE,
        UTF_32LE,
        NO_BOM
    };
    int out(BinaryOutputPort* port, ucs4char u);
    int out(uint8_t* buf, ucs4char u);
    ucs4char in(BinaryInputPort* port);
    ucs4string readWholeString(BinaryInputPort* port);
    ucs4string getCodecName() const
    {
        return codecName_;
    }

    static int checkBOM(ByteVector* bytevector);
    static Codec* getCodec();
    static Codec* getCodec(int endianness);
private:
    bool isLittleEndian_;
    ucs4string codecName_;

    UTF32Codec();
    UTF32Codec(int endianness);
    UTF32Codec(const UTF32Codec& codec);
    UTF32Codec& operator=(const UTF32Codec& codec);
};

}; // namespace scheme

#endif // __SCHEME_UTF32_CODEC__