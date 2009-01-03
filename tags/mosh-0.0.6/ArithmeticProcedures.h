/*
 * ArithmeticProcedures.h - arithmetic procedures.
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
 *  $Id: ArithmeticProcedures.h 261 2008-07-25 06:16:44Z higepon $
 */

#ifndef __SCHEME_ARITHMETIC_PROCEDURES__
#define __SCHEME_ARITHMETIC_PROCEDURES__

#include "scheme.h"
#include "ErrorProcedures.h"

namespace scheme {

    Object maxEx(int argc, const Object* argv);
    Object minEx(int argc, const Object* argv);
    Object eqEx(int argc, const Object* argv);
    Object gtEx(int argc, const Object* argv);
    Object geEx(int argc, const Object* argv);
    Object ltEx(int argc, const Object* argv);
    Object leEx(int argc, const Object* argv);
    Object addEx(int argc, const Object* argv);
    Object subEx(int argc, const Object* argv);
    Object mulEx(int argc, const Object* argv);
    Object divideEx(int argc, const Object* argv);

    inline bool numberEqual(Object number1, Object number2)
    {
        if (number1.isInt() && number2.isInt()) {
            return number1.toInt() == number2.toInt();
        }
        callWrongTypeOfArgumentViolationAfter("=", "number", Pair::list2(number1, number2), Pair::list2(number1, number2));
        return false;
    }

    inline bool numberGreater(Object number1, Object number2)
    {
        if (number1.isInt() && number2.isInt()) {
            return number1.toInt() > number2.toInt();
        }
        callWrongTypeOfArgumentViolationAfter(">", "number", Pair::list2(number1, number2), Pair::list2(number1, number2));
        return false;
    }

    inline bool numberGreaterEqual(Object number1, Object number2)
    {
        if (number1.isInt() && number2.isInt()) {
            return number1.toInt() >= number2.toInt();
        }
        callWrongTypeOfArgumentViolationAfter(">=", "number", Pair::list2(number1, number2), Pair::list2(number1, number2));
        return false;
    }

    inline bool numberLess(Object number1, Object number2)
    {
        if (number1.isInt() && number2.isInt()) {
            return number1.toInt() < number2.toInt();
        }
        callWrongTypeOfArgumentViolationAfter("<", "number", Pair::list2(number1, number2), Pair::list2(number1, number2));
        return false;
    }

    inline bool numberLessEqual(Object number1, Object number2)
    {
        if (number1.isInt() && number2.isInt()) {
            return number1.toInt() <= number2.toInt();
        }
        callWrongTypeOfArgumentViolationAfter("<=", "number", Pair::list2(number1, number2), Pair::list2(number1, number2));
        return false;
    }

    inline Object numberAdd(Object number1, Object number2)
    {
        if (number1.isInt() && number2.isInt()) {
            return Object::makeInt(number1.toInt() + number2.toInt());
        }
        callWrongTypeOfArgumentViolationAfter("+", "number", Pair::list2(number1, number2), Pair::list2(number1, number2));
        return Object::False;
    }

    inline Object numberSub(Object number1, Object number2)
    {
        if (number1.isInt() && number2.isInt()) {
            return Object::makeInt(number1.toInt() - number2.toInt());
        }
        callWrongTypeOfArgumentViolationAfter("-", "number", Pair::list2(number1, number2), Pair::list2(number1, number2));
        return Object::False;
    }

    inline Object numberMul(Object number1, Object number2)
    {
        if (number1.isInt() && number2.isInt()) {
            return Object::makeInt(number1.toInt() * number2.toInt());
        }
        callWrongTypeOfArgumentViolationAfter("*", "number", Pair::list2(number1, number2), Pair::list2(number1, number2));
        return Object::False;
    }

    inline Object numberDiv(Object number1, Object number2)
    {
        if (number1.isInt() && number2.isInt()) {
            if (number2.toInt() == 0) {
                callAssertionViolationAfter("/", "Dividing by zero", Pair::list2(number1, number2));
                return Object::Undef;
            } else {
                return Object::makeInt(number1.toInt() / number2.toInt());
            }
        }
        callWrongTypeOfArgumentViolationAfter("/", "number", Pair::list2(number1, number2), Pair::list2(number1, number2));
        return Object::False;
    }


}; // namespace scheme

#endif // __SCHEME_ARITHMETIC_PROCEDURES__