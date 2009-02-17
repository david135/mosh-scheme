/*
 * TypedVector.cpp - <typed-vector>.
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
 *  $Id: Regexp.cpp 5271 2008-04-25 05:02:07Z higepon $
 */

#include "TypedVector.h"
#include "VM.h"

using namespace scheme;

extern VM* theVM;

TypedVector::TypedVector(Object desc, Object fieldsList) : desc(desc), fieldNumber(desc.toTypedVectorDesc()->fieldNumber)
{
    const int length = Pair::length(fieldsList);
    if (length != fieldNumber) {
        VM_RAISE2("wrong number of arguments for typed vector consructor (required ~d, got ~d)\n"
                  , Object::makeInt(fieldNumber)
                  , Object::makeInt(length));
    }
#ifdef USE_BOEHM_GC
    fields = new(GC) Object[fieldNumber];
#else
    fields = new Object[fieldNumber];
#endif

    int i = 0;
    for (Object c = fieldsList; !c.isNil(); c = c.cdr(), i++) {
        fields[i] = c.car();
    }
}