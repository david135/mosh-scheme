/* Generated by re2c 0.13.5 on Fri Nov 13 00:21:22 2009 */
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
#include "VM.h"
#include "MultiVMProcedures.h"

#define YYCTYPE ucs4char
#define YYCURSOR cursor_
#define YYMARKER marker_
#define YYLIMIT limit_
#define YYTOKEN token_
#define YYGETCONDITION()  condition_
#define YYSETCONDITION(s) condition_ = s
#define YYCONDTYPE int
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
                     bufferSize_(32),
                    condition_(INITIAL)
{
}

NumberScanner::~NumberScanner()
{
}

void NumberScanner::fill(int n)
{
    TextualInputPort* const inputPort = currentVM()->numberReaderContext()->port();
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

int number_yylex(YYSTYPE* yylval)
{
    return currentVM()->numberReaderContext()->port()->numberScanner()->scan(yylval);
}

int NumberScanner::scan(YYSTYPE* yylval)
{
#line 144 "NumberScanner.re"


    for(;;)
    {

#line 138 "<stdout>"
{
	YYCTYPE yych;
	unsigned int yyaccept = 0;
	if (YYGETCONDITION() < 1) {
		goto yyc_INITIAL;
	} else {
		goto yyc_IN_HEX;
	}
/* *********************************** */
yyc_INITIAL:

	if ((YYLIMIT - YYCURSOR) < 5) YYFILL(5);
	yych = *YYCURSOR;
	if (yych <= 'F') {
		if (yych <= '.') {
			if (yych <= '*') {
				if (yych <= 0x00000000) goto yy3;
				if (yych == '#') goto yy5;
			} else {
				if (yych <= '+') goto yy14;
				if (yych <= ',') goto yy2;
				if (yych <= '-') goto yy16;
				goto yy22;
			}
		} else {
			if (yych <= '9') {
				if (yych <= '/') goto yy18;
				if (yych <= '1') goto yy24;
				if (yych <= '7') goto yy26;
				goto yy28;
			} else {
				if (yych <= '?') goto yy2;
				if (yych <= '@') goto yy20;
				if (yych <= 'C') goto yy30;
				goto yy6;
			}
		}
	} else {
		if (yych <= 'h') {
			if (yych <= 'S') {
				if (yych == 'L') goto yy8;
				if (yych >= 'S') goto yy8;
			} else {
				if (yych <= '`') goto yy2;
				if (yych <= 'c') goto yy31;
				if (yych <= 'f') goto yy9;
			}
		} else {
			if (yych <= 'm') {
				if (yych <= 'i') goto yy12;
				if (yych == 'l') goto yy8;
			} else {
				if (yych <= 'n') goto yy11;
				if (yych == 's') goto yy8;
			}
		}
	}
yy2:
	YYCURSOR = YYMARKER;
	if (yyaccept <= 1) {
		if (yyaccept <= 0) {
			goto yy7;
		} else {
			goto yy10;
		}
	} else {
		goto yy13;
	}
yy3:
	++YYCURSOR;
#line 238 "NumberScanner.re"
	{
            YYSETCONDITION(INITIAL);
            YYTOKEN = YYCURSOR;
            return END_OF_FILE;
        }
#line 215 "<stdout>"
yy5:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'B':
	case 'b':	goto yy52;
	case 'D':
	case 'd':	goto yy48;
	case 'E':
	case 'e':	goto yy56;
	case 'I':
	case 'i':	goto yy54;
	case 'O':
	case 'o':	goto yy50;
	case 'X':
	case 'x':	goto yy46;
	default:	goto yy2;
	}
yy6:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych <= ',') {
		if (yych == '+') goto yy42;
	} else {
		if (yych <= '-') goto yy42;
		if (yych <= '/') goto yy7;
		if (yych <= '9') goto yy43;
	}
yy7:
#line 226 "NumberScanner.re"
	{
            const ucs4char ch = YYTOKEN[0];
            yylval->intValue = ch - 'A' + 10;
            YYTOKEN = YYCURSOR;
            return DIGIT_16;
        }
#line 251 "<stdout>"
yy8:
	yych = *++YYCURSOR;
	if (yych <= ',') {
		if (yych == '+') goto yy42;
		goto yy2;
	} else {
		if (yych <= '-') goto yy42;
		if (yych <= '/') goto yy2;
		if (yych <= '9') goto yy43;
		goto yy2;
	}
yy9:
	yyaccept = 1;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych <= ',') {
		if (yych == '+') goto yy42;
	} else {
		if (yych <= '-') goto yy42;
		if (yych <= '/') goto yy10;
		if (yych <= '9') goto yy43;
	}
yy10:
#line 232 "NumberScanner.re"
	{
            const ucs4char ch = YYTOKEN[0];
            yylval->intValue = ch - 'a' + 10;
            YYTOKEN = YYCURSOR;
            return DIGIT_16;
        }
#line 281 "<stdout>"
yy11:
	yych = *++YYCURSOR;
	if (yych == 'a') goto yy37;
	goto yy2;
yy12:
	yyaccept = 2;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych == 'n') goto yy32;
yy13:
#line 182 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return IMAG;
        }
#line 296 "<stdout>"
yy14:
	++YYCURSOR;
#line 170 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return PLUS;
        }
#line 304 "<stdout>"
yy16:
	++YYCURSOR;
#line 174 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return MINUS;
        }
#line 312 "<stdout>"
yy18:
	++YYCURSOR;
#line 178 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return SLASH;
        }
#line 320 "<stdout>"
yy20:
	++YYCURSOR;
#line 186 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return AT;
        }
#line 328 "<stdout>"
yy22:
	++YYCURSOR;
#line 190 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return DOT;
        }
#line 336 "<stdout>"
yy24:
	++YYCURSOR;
#line 211 "NumberScanner.re"
	{
            yylval->intValue = YYTOKEN[0] - '0';
            YYTOKEN = YYCURSOR;
            return DIGIT_2;
        }
#line 345 "<stdout>"
yy26:
	++YYCURSOR;
#line 216 "NumberScanner.re"
	{
            yylval->intValue = YYTOKEN[0] - '0';
            YYTOKEN = YYCURSOR;
            return DIGIT_8;
        }
#line 354 "<stdout>"
yy28:
	++YYCURSOR;
#line 221 "NumberScanner.re"
	{
            yylval->intValue = YYTOKEN[0] - '0';
            YYTOKEN = YYCURSOR;
            return DIGIT_10;
        }
#line 363 "<stdout>"
yy30:
	yych = *++YYCURSOR;
	goto yy7;
yy31:
	yych = *++YYCURSOR;
	goto yy10;
yy32:
	yych = *++YYCURSOR;
	if (yych != 'f') goto yy2;
	yych = *++YYCURSOR;
	if (yych != '.') goto yy2;
	yych = *++YYCURSOR;
	if (yych != '0') goto yy2;
	++YYCURSOR;
#line 166 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return MY_INF;
        }
#line 383 "<stdout>"
yy37:
	yych = *++YYCURSOR;
	if (yych != 'n') goto yy2;
	yych = *++YYCURSOR;
	if (yych != '.') goto yy2;
	yych = *++YYCURSOR;
	if (yych != '0') goto yy2;
	++YYCURSOR;
#line 162 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return MY_NAN;
        }
#line 397 "<stdout>"
yy42:
	yych = *++YYCURSOR;
	if (yych <= '/') goto yy2;
	if (yych >= ':') goto yy2;
yy43:
	++YYCURSOR;
	if (YYLIMIT <= YYCURSOR) YYFILL(1);
	yych = *YYCURSOR;
	if (yych <= '/') goto yy45;
	if (yych <= '9') goto yy43;
yy45:
#line 153 "NumberScanner.re"
	{
            yylval->stringValue = ucs4string(YYTOKEN, (YYCURSOR  - YYTOKEN));
            YYTOKEN = YYCURSOR;
            return EXPONENT_MARKER;
        }
#line 415 "<stdout>"
yy46:
	++YYCURSOR;
#line 206 "NumberScanner.re"
	{
            YYSETCONDITION(IN_HEX);
            YYTOKEN = YYCURSOR;
            return RADIX_16;
        }
#line 424 "<stdout>"
yy48:
	++YYCURSOR;
#line 202 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return RADIX_10;
        }
#line 432 "<stdout>"
yy50:
	++YYCURSOR;
#line 198 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return RADIX_8;
        }
#line 440 "<stdout>"
yy52:
	++YYCURSOR;
#line 194 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return RADIX_2;
        }
#line 448 "<stdout>"
yy54:
	++YYCURSOR;
#line 158 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return INEXACT;
        }
#line 456 "<stdout>"
yy56:
	++YYCURSOR;
#line 149 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return EXACT;
        }
#line 464 "<stdout>"
/* *********************************** */
yyc_IN_HEX:
	if ((YYLIMIT - YYCURSOR) < 5) YYFILL(5);
	yych = *YYCURSOR;
	if (yych <= '7') {
		if (yych <= '+') {
			if (yych <= '"') {
				if (yych <= 0x00000000) goto yy61;
			} else {
				if (yych <= '#') goto yy63;
				if (yych >= '+') goto yy67;
			}
		} else {
			if (yych <= '.') {
				if (yych <= ',') goto yy60;
				if (yych <= '-') goto yy69;
				goto yy75;
			} else {
				if (yych <= '/') goto yy71;
				if (yych <= '1') goto yy77;
				goto yy79;
			}
		}
	} else {
		if (yych <= '`') {
			if (yych <= '?') {
				if (yych <= '9') goto yy81;
			} else {
				if (yych <= '@') goto yy73;
				if (yych <= 'F') goto yy83;
			}
		} else {
			if (yych <= 'i') {
				if (yych <= 'f') goto yy85;
				if (yych >= 'i') goto yy65;
			} else {
				if (yych == 'n') goto yy64;
			}
		}
	}
yy60:
	YYCURSOR = YYMARKER;
	goto yy66;
yy61:
	++YYCURSOR;
#line 238 "NumberScanner.re"
	{
            YYSETCONDITION(INITIAL);
            YYTOKEN = YYCURSOR;
            return END_OF_FILE;
        }
#line 516 "<stdout>"
yy63:
	yych = *++YYCURSOR;
	switch (yych) {
	case 'B':
	case 'b':	goto yy101;
	case 'D':
	case 'd':	goto yy97;
	case 'E':
	case 'e':	goto yy105;
	case 'I':
	case 'i':	goto yy103;
	case 'O':
	case 'o':	goto yy99;
	default:	goto yy60;
	}
yy64:
	yych = *++YYCURSOR;
	if (yych == 'a') goto yy92;
	goto yy60;
yy65:
	yyaccept = 0;
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych == 'n') goto yy87;
yy66:
#line 182 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return IMAG;
        }
#line 546 "<stdout>"
yy67:
	++YYCURSOR;
#line 170 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return PLUS;
        }
#line 554 "<stdout>"
yy69:
	++YYCURSOR;
#line 174 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return MINUS;
        }
#line 562 "<stdout>"
yy71:
	++YYCURSOR;
#line 178 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return SLASH;
        }
#line 570 "<stdout>"
yy73:
	++YYCURSOR;
#line 186 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return AT;
        }
#line 578 "<stdout>"
yy75:
	++YYCURSOR;
#line 190 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return DOT;
        }
#line 586 "<stdout>"
yy77:
	++YYCURSOR;
#line 211 "NumberScanner.re"
	{
            yylval->intValue = YYTOKEN[0] - '0';
            YYTOKEN = YYCURSOR;
            return DIGIT_2;
        }
#line 595 "<stdout>"
yy79:
	++YYCURSOR;
#line 216 "NumberScanner.re"
	{
            yylval->intValue = YYTOKEN[0] - '0';
            YYTOKEN = YYCURSOR;
            return DIGIT_8;
        }
#line 604 "<stdout>"
yy81:
	++YYCURSOR;
#line 221 "NumberScanner.re"
	{
            yylval->intValue = YYTOKEN[0] - '0';
            YYTOKEN = YYCURSOR;
            return DIGIT_10;
        }
#line 613 "<stdout>"
yy83:
	++YYCURSOR;
#line 226 "NumberScanner.re"
	{
            const ucs4char ch = YYTOKEN[0];
            yylval->intValue = ch - 'A' + 10;
            YYTOKEN = YYCURSOR;
            return DIGIT_16;
        }
#line 623 "<stdout>"
yy85:
	++YYCURSOR;
#line 232 "NumberScanner.re"
	{
            const ucs4char ch = YYTOKEN[0];
            yylval->intValue = ch - 'a' + 10;
            YYTOKEN = YYCURSOR;
            return DIGIT_16;
        }
#line 633 "<stdout>"
yy87:
	yych = *++YYCURSOR;
	if (yych != 'f') goto yy60;
	yych = *++YYCURSOR;
	if (yych != '.') goto yy60;
	yych = *++YYCURSOR;
	if (yych != '0') goto yy60;
	++YYCURSOR;
#line 166 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return MY_INF;
        }
#line 647 "<stdout>"
yy92:
	yych = *++YYCURSOR;
	if (yych != 'n') goto yy60;
	yych = *++YYCURSOR;
	if (yych != '.') goto yy60;
	yych = *++YYCURSOR;
	if (yych != '0') goto yy60;
	++YYCURSOR;
#line 162 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return MY_NAN;
        }
#line 661 "<stdout>"
yy97:
	++YYCURSOR;
#line 202 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return RADIX_10;
        }
#line 669 "<stdout>"
yy99:
	++YYCURSOR;
#line 198 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return RADIX_8;
        }
#line 677 "<stdout>"
yy101:
	++YYCURSOR;
#line 194 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return RADIX_2;
        }
#line 685 "<stdout>"
yy103:
	++YYCURSOR;
#line 158 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return INEXACT;
        }
#line 693 "<stdout>"
yy105:
	++YYCURSOR;
#line 149 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return EXACT;
        }
#line 701 "<stdout>"
}
#line 243 "NumberScanner.re"


    }
}

ucs4char* NumberScanner::currentToken() const
{
    return token_;
}
