/*
 * SocketProcedures.cpp - <socket> procedures.
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
 *  $Id: SocketProcedures.cpp 1611 2009-04-16 14:22:32Z higepon $
 */

#include "Object.h"
#include "Object-inl.h"
#include "Pair.h"
#include "Pair-inl.h"
#include "SString.h"
#include "ByteVector.h"
#include "Bignum.h"
#include "ProcedureMacro.h"
#include "OSCompatSocket.h"
#include "SocketProcedures.h"

using namespace scheme;

// (socket-send socket bytevector flags)
Object scheme::socketSendEx(VM* theVM, int argc, const Object* argv)
{
    DeclareProcedureName("socket-send");
    checkArgumentLength(3);
    argumentAsSocket(0, socket);
    argumentAsByteVector(1, bv);
    argumentAsFixnum(2, flags);
    const int result = socket->send(bv->data(), bv->length(), flags);
    if (-1 == result) {
        return callIOErrorAfter(theVM, procedureName, socket->getLastErrorMessage(), L3(argv[0], argv[1], argv[2]));
    } else {
        return Bignum::makeInteger(result);
    }
}

// (socket-recv! socket bytevector len flags)
Object scheme::socketRecvDEx(VM* theVM, int argc, const Object* argv)
{
    DeclareProcedureName("socket-recv!");
    checkArgumentLength(4);
    argumentAsSocket(0, socket);
    argumentAsByteVector(1, bv);
    argumentAsFixnum(2, len);
    argumentAsFixnum(3, flags);
    if (bv->length() <= len) {
        return callAssertionViolationAfter(theVM, procedureName, "bytevector size is not enough", L1(argv[0]));
    }
    const int result = socket->receive(bv->data(), len, flags);
    if (-1 == result) {
        return callIOErrorAfter(theVM, procedureName, socket->getLastErrorMessage(), L3(argv[0], argv[1], argv[2]));
    } else {
        return Bignum::makeInteger(result);
    }
}

// (socket-recv socket len flags)
Object scheme::socketRecvEx(VM* theVM, int argc, const Object* argv)
{
    DeclareProcedureName("socket-recv");
    checkArgumentLength(3);
    argumentAsSocket(0, socket);
    argumentAsFixnum(1, len);
    argumentAsFixnum(2, flags);
    uint8_t* data = allocatePointerFreeU8Array(len);
    MOSH_ASSERT(data != NULL);
    const int result = socket->receive(data, len, flags);
    if (-1 == result) {
        return callIOErrorAfter(theVM, procedureName, socket->getLastErrorMessage(), L3(argv[0], argv[1], argv[2]));
    } else {
        ByteVector* bv = new ByteVector(result, data);
        return Object::makeByteVector(bv);
    }
}

// (make-client-socket node service ai-family ai-socktype ai-flags ai-protocol)
Object scheme::makeClientSocketEx(VM* theVM, int argc, const Object* argv)
{
    DeclareProcedureName("make-client-socket");
    checkArgumentLength(6);
    argumentCheckStringOrFalse(0, nodeOrFalse);
    argumentCheckStringOrFalse(1, serviceOrFalse);
    argumentAsFixnum(2, ai_family);
    argumentAsFixnum(3, ai_socktype);
    argumentAsFixnum(4, ai_flags);
    argumentAsFixnum(5, ai_protocol);
    const char* node = NULL;
    const char* service = NULL;
    if (nodeOrFalse.isString()) {
        node = nodeOrFalse.toString()->data().ascii_c_str();
    }
    if (serviceOrFalse.isString()) {
        service = serviceOrFalse.toString()->data().ascii_c_str();
    }
    bool isErrorOccured = false;
    ucs4string errorMessage;
    Socket* socket = Socket::createClientSocket(node,
                                                service,
                                                ai_family,
                                                ai_socktype,
                                                ai_flags,
                                                ai_protocol,
                                                isErrorOccured,
                                                errorMessage);
    if (isErrorOccured) {
        return callIOErrorAfter(theVM, procedureName, errorMessage, L2(argv[0], argv[1]));
    }

    if (socket->isOpen()) {
        return Object::makeSocket(socket);
    } else {
        return callIOErrorAfter(theVM, procedureName, socket->getLastErrorMessage(), L2(argv[0], argv[1]));
    }
}

Object scheme::makeSocketEx(VM* theVM, int argc, const Object* argv)
{
    DeclareProcedureName("make-socket");
    checkArgumentLength(3);
    argumentAsFixnum(0, domain);
    argumentAsFixnum(1, type);
    argumentAsFixnum(2, protocol);
    Socket* socket = new Socket(domain, type, protocol);
    if (socket->isOpen()) {
        return Object::makeSocket(socket);
    } else {
        return callIOErrorAfter(theVM, procedureName, socket->getLastErrorMessage(), L3(argv[0], argv[1], argv[2]));
    }
}
