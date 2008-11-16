/* Generated by re2c 0.13.5 on Sun Nov 16 13:20:04 2008 */
#line 1 "NumberScanner.re"
/*
 * NumberScanner.re
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
 *  $Id: Reader.y 183 2008-07-04 06:19:28Z higepon $
 */

#include <stdio.h>
#include "Object.h"
#include "Pair.h"
#include "StringProcedures.h"
#include "TextualInputPort.h"
#include "TextualOutputPort.h"
#include "ucs4string.h"
#include "ScannerHelper.h"
#include "NumberScanner.h"

#include "Reader.h"
#include "NumberReader.h"
#include "NumberReader.tab.hpp"
#include "VM.h"

#define YYCTYPE ucs4char
#define YYCURSOR cursor_
#define YYMARKER marker_
#define YYLIMIT limit_
#define YYTOKEN token_
#define YYDEBUG(state, ch)  yydebug(state, ch)
#define YYFILL(n) fill(n)
extern YYSTYPE number_yylval;
#define yylval number_yylval
using namespace scheme;
extern VM* theVM;

NumberScanner::NumberScanner() : dummy_('Z'),  // for YYDEBUG
                     buffer_(NULL),
                     cursor_(&dummy_),
                     token_(buffer_),
                     limit_(buffer_),
                     marker_(buffer_),
                     bufferSize_(32)
{
}

NumberScanner::~NumberScanner()
{
}

void NumberScanner::fill(int n)
{
    TextualInputPort* const inputPort = NumberReader::port();
    const int restCharCount = limit_ - token_;
    const int tokenOffset = token_ - buffer_;
    if (buffer_ == NULL) {
        buffer_ = new(GC) ucs4char[bufferSize_];
        cursor_ = buffer_;
        limit_ = buffer_;
        token_ = buffer_;
        marker_ = buffer_;
    }

    if ((restCharCount + n) > bufferSize_) {
        ucs4char* newBuffer = new(GC) ucs4char[restCharCount + n + 1];
        bufferSize_ = restCharCount + n + 1;
        memmove(newBuffer, token_, restCharCount * sizeof(ucs4char));
        cursor_ = &newBuffer[cursor_ - buffer_];
        token_ = &newBuffer[token_ - buffer_];
        limit_ = &newBuffer[limit_ - buffer_];
        marker_ = &newBuffer[marker_ - buffer_];
        buffer_ = newBuffer;
    } else if (restCharCount > 0) {
        memmove(buffer_, token_, restCharCount * sizeof(ucs4char));
    }

    int i;
    for (i = 0; i < n; i++) {
        const ucs4char ch = inputPort->getChar();
        if (ch == EOF) {
            buffer_[i + restCharCount] = '\0';
            i++;
            break;
        } else {
            buffer_[i + restCharCount] = ch;
        }

    }
    const int readSize = i;
    cursor_ = cursor_ - tokenOffset;
    token_ = buffer_;
    marker_ = marker_ - tokenOffset;
    limit_ = limit_ - tokenOffset + readSize;

}

int number_yylex()
{
    return NumberReader::port()->numberScanner()->scan();
}

int NumberScanner::scan()
{
#line 141 "NumberScanner.re"


    for(;;)
    {

#line 135 "<stdout>"
{
	YYCTYPE yych;
	unsigned int yyaccept = 0;
	static const unsigned char yybm[] = {
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		128, 128, 128, 128, 128, 128, 128, 128, 
		128, 128,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
		  0,   0,   0,   0,   0,   0,   0,   0, 
	};

	if ((YYLIMIT - YYCURSOR) < 5) YYFILL(5);
	yych = *YYCURSOR;
	if (yych & ~0xFF) {
	} else {
		static void *yytarget[256] = {
			&&yy30, &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy3,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy12, &&yy2,  &&yy14, &&yy20, &&yy16,
			&&yy22, &&yy22, &&yy24, &&yy24, &&yy24, &&yy24, &&yy24, &&yy24,
			&&yy26, &&yy26, &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy18, &&yy28, &&yy28, &&yy28, &&yy4,  &&yy4,  &&yy4,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy6,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy6,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy29, &&yy29, &&yy29, &&yy7,  &&yy7,  &&yy7,  &&yy2,
			&&yy2,  &&yy10, &&yy2,  &&yy2,  &&yy6,  &&yy2,  &&yy9,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy6,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2
		};
		goto *yytarget[yych];
	}
yy2:
	YYCURSOR = YYMARKER;
	if (yyaccept <= 1) {
		if (yyaccept <= 0) {
			goto yy5;
		} else {
			goto yy8;
		}
	} else {
		goto yy11;
	}
yy3:
	yych = *++YYCURSOR;
	if (yych & ~0xFF) {
		goto yy2;
	} else {
		static void *yytarget[256] = {
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy52, &&yy2,  &&yy48, &&yy56, &&yy2,  &&yy2,
			&&yy2,  &&yy54, &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy50,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy46, &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy52, &&yy2,  &&yy48, &&yy56, &&yy2,  &&yy2,
			&&yy2,  &&yy54, &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy50,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy46, &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2
		};
		goto *yytarget[yych];
	}
yy4:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych == '+') goto yy42;
	if (yych == '-') goto yy42;
yy5:
#line 222 "NumberScanner.re"
	{
            const ucs4char ch = YYTOKEN[0];
            yylval.intValue = ch - 'A' + 10;
            YYTOKEN = YYCURSOR;
            return DIGIT_16;
        }
#line 279 "<stdout>"
yy6:
	yych = *++YYCURSOR;
	if (yych == '+') goto yy42;
	if (yych == '-') goto yy42;
	goto yy2;
yy7:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych == '+') goto yy42;
	if (yych == '-') goto yy42;
yy8:
#line 228 "NumberScanner.re"
	{
            const ucs4char ch = YYTOKEN[0];
            yylval.intValue = ch - 'a' + 10;
            YYTOKEN = YYCURSOR;
            return DIGIT_16;
        }
#line 298 "<stdout>"
yy9:
	yych = *++YYCURSOR;
	if (yych == 'a') goto yy37;
	goto yy2;
yy10:
	yyaccept = 2;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych == 'n') goto yy32;
yy11:
#line 179 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return IMAG;
        }
#line 313 "<stdout>"
yy12:
	++YYCURSOR;
#line 167 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return PLUS;
        }
#line 321 "<stdout>"
yy14:
	++YYCURSOR;
#line 171 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return MINUS;
        }
#line 329 "<stdout>"
yy16:
	++YYCURSOR;
#line 175 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return SLASH;
        }
#line 337 "<stdout>"
yy18:
	++YYCURSOR;
#line 183 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return AT;
        }
#line 345 "<stdout>"
yy20:
	++YYCURSOR;
#line 187 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return DOT;
        }
#line 353 "<stdout>"
yy22:
	++YYCURSOR;
#line 207 "NumberScanner.re"
	{
            yylval.intValue = YYTOKEN[0] - '0';
            YYTOKEN = YYCURSOR;
            return DIGIT_2;
        }
#line 362 "<stdout>"
yy24:
	++YYCURSOR;
#line 212 "NumberScanner.re"
	{
            yylval.intValue = YYTOKEN[0] - '0';
            YYTOKEN = YYCURSOR;
            return DIGIT_8;
        }
#line 371 "<stdout>"
yy26:
	++YYCURSOR;
#line 217 "NumberScanner.re"
	{
            yylval.intValue = YYTOKEN[0] - '0';
            YYTOKEN = YYCURSOR;
            return DIGIT_10;
        }
#line 380 "<stdout>"
yy28:
	yych = *++YYCURSOR;
	goto yy5;
yy29:
	yych = *++YYCURSOR;
	goto yy8;
yy30:
	++YYCURSOR;
#line 234 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return END_OF_FILE;
        }
#line 394 "<stdout>"
yy32:
	yych = *++YYCURSOR;
	if (yych != 'f') goto yy2;
	yych = *++YYCURSOR;
	if (yych != '.') goto yy2;
	yych = *++YYCURSOR;
	if (yych != '0') goto yy2;
	++YYCURSOR;
#line 163 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return MY_INF;
        }
#line 408 "<stdout>"
yy37:
	yych = *++YYCURSOR;
	if (yych != 'n') goto yy2;
	yych = *++YYCURSOR;
	if (yych != '.') goto yy2;
	yych = *++YYCURSOR;
	if (yych != '0') goto yy2;
	++YYCURSOR;
#line 159 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return MY_NAN;
        }
#line 422 "<stdout>"
yy42:
	yych = *++YYCURSOR;
	if (yych & ~0xFF) {
	} else if (yybm[0+yych] & 128) {
		goto yy43;
	}
	goto yy2;
yy43:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych & ~0xFF) {
	} else if (yybm[0+yych] & 128) {
		goto yy43;
	}
#line 150 "NumberScanner.re"
	{
            yylval.stringValue = ucs4string(YYTOKEN, (YYCURSOR - YYTOKEN));
            YYTOKEN = YYCURSOR;
            return EXPONENT_MARKER;
        }
#line 444 "<stdout>"
yy46:
	++YYCURSOR;
#line 203 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return RADIX_16;
        }
#line 452 "<stdout>"
yy48:
	++YYCURSOR;
#line 199 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return RADIX_10;
        }
#line 460 "<stdout>"
yy50:
	++YYCURSOR;
#line 195 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return RADIX_8;
        }
#line 468 "<stdout>"
yy52:
	++YYCURSOR;
#line 191 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return RADIX_2;
        }
#line 476 "<stdout>"
yy54:
	++YYCURSOR;
#line 155 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return INEXACT;
        }
#line 484 "<stdout>"
yy56:
	++YYCURSOR;
#line 146 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return EXACT;
        }
#line 492 "<stdout>"
}
#line 238 "NumberScanner.re"


    }
}

ucs4char* NumberScanner::currentToken() const
{
    return token_;
}
