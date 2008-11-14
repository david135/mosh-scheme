/* Generated by re2c 0.13.5 on Fri Nov 14 12:07:48 2008 */
#line 1 "NumberScanner.re"
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


static void yydebug(int state, ucs4char ch)
{
//    printf("state=%d ch=[%c] ch=%x\n", state, ch, ch);
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
    printf("fill :");
    for (int k = 0; k < i; k++) {
        printf("<%c>", buffer_[k]);
    }
    printf("\n");
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
#line 112 "NumberScanner.re"


    for(;;)
    {

#line 114 "<stdout>"
{
	YYCTYPE yych;

	if ((YYLIMIT - YYCURSOR) < 5) YYFILL(5);
	yych = *YYCURSOR;
	if (yych & ~0xFF) {
	} else {
		static void *yytarget[256] = {
			&&yy17, &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy3,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy7,  &&yy2,  &&yy9,  &&yy2,  &&yy11,
			&&yy15, &&yy15, &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy13, &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy5,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy4,  &&yy2,
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
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2
		};
		goto *yytarget[yych];
	}
yy2:
	YYCURSOR = YYMARKER;
	goto yy6;
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
			&&yy2,  &&yy2,  &&yy29, &&yy2,  &&yy2,  &&yy33, &&yy2,  &&yy2,
			&&yy2,  &&yy31, &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy29, &&yy2,  &&yy2,  &&yy33, &&yy2,  &&yy2,
			&&yy2,  &&yy31, &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
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
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,
			&&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2,  &&yy2
		};
		goto *yytarget[yych];
	}
yy4:
	yych = *++YYCURSOR;
	if (yych == 'a') goto yy24;
	goto yy2;
yy5:
	yych = *(YYMARKER = ++YYCURSOR);
	if (yych == 'n') goto yy19;
yy6:
#line 145 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return IMAG;
        }
#line 215 "<stdout>"
yy7:
	++YYCURSOR;
#line 133 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return PLUS;
        }
#line 223 "<stdout>"
yy9:
	++YYCURSOR;
#line 137 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return MINUS;
        }
#line 231 "<stdout>"
yy11:
	++YYCURSOR;
#line 141 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return SLASH;
        }
#line 239 "<stdout>"
yy13:
	++YYCURSOR;
#line 149 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return AT;
        }
#line 247 "<stdout>"
yy15:
	++YYCURSOR;
#line 158 "NumberScanner.re"
	{
            yylval.intValue = YYTOKEN[0] - '0';
            printf("TOKEN:DIGIT_2=%d\n", yylval.intValue);
            YYTOKEN = YYCURSOR;
            return DIGIT_2;
        }
#line 257 "<stdout>"
yy17:
	++YYCURSOR;
#line 164 "NumberScanner.re"
	{
            printf("TOKEN:END_OF_FILE\n");
            YYTOKEN = YYCURSOR;
            return END_OF_FILE;
        }
#line 266 "<stdout>"
yy19:
	yych = *++YYCURSOR;
	if (yych != 'f') goto yy2;
	yych = *++YYCURSOR;
	if (yych != '.') goto yy2;
	yych = *++YYCURSOR;
	if (yych != '0') goto yy2;
	++YYCURSOR;
#line 129 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return MY_INF;
        }
#line 280 "<stdout>"
yy24:
	yych = *++YYCURSOR;
	if (yych != 'n') goto yy2;
	yych = *++YYCURSOR;
	if (yych != '.') goto yy2;
	yych = *++YYCURSOR;
	if (yych != '0') goto yy2;
	++YYCURSOR;
#line 125 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return MY_NAN;
        }
#line 294 "<stdout>"
yy29:
	++YYCURSOR;
#line 153 "NumberScanner.re"
	{
            printf("TOKEN:RADIX_2\n");
            YYTOKEN = YYCURSOR;
            return RADIX_2;
        }
#line 303 "<stdout>"
yy31:
	++YYCURSOR;
#line 121 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return INEXACT;
        }
#line 311 "<stdout>"
yy33:
	++YYCURSOR;
#line 117 "NumberScanner.re"
	{
            YYTOKEN = YYCURSOR;
            return EXACT;
        }
#line 319 "<stdout>"
}
#line 171 "NumberScanner.re"


    }
}

ucs4char* NumberScanner::currentToken() const
{
    return token_;
}
