/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0

/* Substitute the variable and function names.  */
#define yyparse number_yyparse
#define yylex   number_yylex
#define yyerror number_yyerror
#define yylval  number_yylval
#define yychar  number_yychar
#define yydebug number_yydebug
#define yynerrs number_yynerrs


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     END_OF_FILE = 258,
     PLUS = 259,
     MINUS = 260,
     SLASH = 261,
     DOT = 262,
     AT = 263,
     MY_NAN = 264,
     MY_INF = 265,
     IMAG = 266,
     RADIX_2 = 267,
     RADIX_8 = 268,
     RADIX_10 = 269,
     RADIX_16 = 270,
     EXACT = 271,
     INEXACT = 272,
     DIGIT_2 = 273,
     DIGIT_8 = 274,
     DIGIT_10 = 275,
     DIGIT_16 = 276,
     EXPONENT_MARKER = 277
   };
#endif
/* Tokens.  */
#define END_OF_FILE 258
#define PLUS 259
#define MINUS 260
#define SLASH 261
#define DOT 262
#define AT 263
#define MY_NAN 264
#define MY_INF 265
#define IMAG 266
#define RADIX_2 267
#define RADIX_8 268
#define RADIX_10 269
#define RADIX_16 270
#define EXACT 271
#define INEXACT 272
#define DIGIT_2 273
#define DIGIT_8 274
#define DIGIT_10 275
#define DIGIT_16 276
#define EXPONENT_MARKER 277




/* Copy the first part of user declarations.  */
#line 32 "NumberReader.y"

#include <stdio.h>
#include <stdlib.h>
#include "scheme.h"
#include "Object.h"
#include "Object-inl.h"
#include "Pair.h"
#include "Pair-inl.h"
#include "SString.h"
#include "StringProcedures.h"
#include "NumberScanner.h"
#include "TextualInputPort.h"
#include "TextualOutputPort.h"
#include "Arithmetic.h"
#include "Reader.h"
#include "NumberReader.h"
#include "ScannerHelper.h"
#include "Scanner.h"
#include "Ratnum.h"
#include "Flonum.h"
#include "ProcedureMacro.h"
#include "MultiVMProcedures.h"

using namespace scheme;
extern int number_yylex();
extern int number_yyerror(const char *);
//#define YYDEBUG 1
// yydebug = 1

static int ucs4stringToInt(const ucs4string& text)
{
    int ret = strtol(text.ascii_c_str(), NULL, 10);
    if (errno == ERANGE) {
        MOSH_FATAL("reader suffix");
    }
    return ret;
}

// e1000 => 1000 e+100 => 100, e-100 =>-100
static int suffix(const ucs4string& text)
{
    MOSH_ASSERT(text.size() > 0);
    const char* p = text.ascii_c_str();
    int ret = strtol(p + 1, NULL, 10);
    if (errno == ERANGE) {
        MOSH_FATAL("reader suffix");
    }
    return ret;
}

// text => "e100", "e+100" or "e-100" style
static Object suffixToNumberOld(const ucs4string& text)
{
    int sign = 1;
    ucs4string decimal10(UC(""));
    if (text[1] == '-') {
        sign = -1;
        decimal10 = text.substr(2, text.size() - 2);
    } else if (text[1] == '+') {
        decimal10 = text.substr(2, text.size() - 2);
    } else {
        decimal10 = text.substr(1, text.size() - 1);
    }
    Object exponent = Bignum::makeInteger(decimal10);
    if (sign == -1) {
        exponent = Arithmetic::negate(exponent);
    }
    MOSH_ASSERT(!exponent.isBignum());
    return Arithmetic::expt(Object::makeFixnum(10), exponent);
}

static Object suffixToNumber(const ucs4string& text)
{
    int sign = 1;
    ucs4string decimal10(UC(""));
    if (text[1] == '-') {
        sign = -1;
        decimal10 = text.substr(2, text.size() - 2);
    } else if (text[1] == '+') {
        decimal10 = text.substr(2, text.size() - 2);
    } else {
        decimal10 = text.substr(1, text.size() - 1);
    }
    Object exponent = Bignum::makeInteger(decimal10);
    if (sign == -1) {
        exponent = Arithmetic::negate(exponent);
    }
    return exponent;
}



/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 250 "NumberReader.tab.cpp"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  40
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   383

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  23
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  140
/* YYNRULES -- Number of states.  */
#define YYNSTATES  226

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   277

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,     9,    11,    13,    15,    18,
      20,    24,    27,    32,    37,    41,    45,    48,    51,    56,
      61,    65,    69,    71,    73,    76,    79,    81,    85,    88,
      91,    93,    96,    98,   101,   103,   107,   112,   117,   121,
     125,   129,   133,   136,   139,   144,   149,   153,   157,   159,
     161,   164,   167,   169,   173,   176,   179,   181,   184,   186,
     188,   191,   193,   197,   202,   207,   211,   215,   219,   223,
     226,   229,   234,   239,   243,   247,   249,   251,   254,   257,
     259,   263,   266,   269,   271,   274,   276,   278,   280,   283,
     286,   292,   298,   303,   308,   310,   314,   319,   324,   328,
     332,   336,   340,   343,   346,   351,   356,   360,   364,   366,
     368,   371,   374,   376,   380,   383,   386,   389,   393,   398,
     402,   404,   406,   409,   411,   413,   414,   416,   418,   419,
     421,   424,   427,   430,   433,   435,   438,   441,   444,   447,
     449
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      24,     0,    -1,    25,    -1,     3,    -1,    26,    -1,    33,
      -1,    47,    -1,    40,    -1,    59,    27,    -1,    28,    -1,
      28,     8,    28,    -1,    30,    11,    -1,    28,     4,    29,
      11,    -1,    28,     5,    29,    11,    -1,    28,     4,    11,
      -1,    28,     5,    11,    -1,     4,    11,    -1,     5,    11,
      -1,    28,     4,    63,    11,    -1,    28,     5,    63,    11,
      -1,     4,    63,    11,    -1,     5,    63,    11,    -1,    29,
      -1,    30,    -1,     4,    63,    -1,     5,    63,    -1,    31,
      -1,    31,     6,    31,    -1,     4,    29,    -1,     5,    29,
      -1,    32,    -1,    31,    32,    -1,    18,    -1,    61,    34,
      -1,    35,    -1,    35,     8,    35,    -1,    35,     4,    36,
      11,    -1,    35,     5,    36,    11,    -1,    35,     4,    11,
      -1,    35,     5,    11,    -1,     4,    36,    11,    -1,     5,
      36,    11,    -1,     4,    11,    -1,     5,    11,    -1,    35,
       4,    63,    11,    -1,    35,     5,    63,    11,    -1,     4,
      63,    11,    -1,     5,    63,    11,    -1,    36,    -1,    37,
      -1,     4,    63,    -1,     5,    63,    -1,    38,    -1,    38,
       6,    38,    -1,     4,    36,    -1,     5,    36,    -1,    39,
      -1,    38,    39,    -1,    32,    -1,    19,    -1,    62,    41,
      -1,    42,    -1,    42,     8,    42,    -1,    42,     4,    43,
      11,    -1,    42,     5,    43,    11,    -1,    42,     4,    11,
      -1,    42,     5,    11,    -1,     4,    43,    11,    -1,     5,
      43,    11,    -1,     4,    11,    -1,     5,    11,    -1,    42,
       4,    63,    11,    -1,    42,     5,    63,    11,    -1,     4,
      63,    11,    -1,     5,    63,    11,    -1,    43,    -1,    44,
      -1,     4,    63,    -1,     5,    63,    -1,    45,    -1,    45,
       6,    45,    -1,     4,    43,    -1,     5,    43,    -1,    46,
      -1,    45,    46,    -1,    56,    -1,    21,    -1,    48,    -1,
      60,    49,    -1,    17,    50,    -1,    17,    50,     4,    51,
      11,    -1,    17,    50,     5,    51,    11,    -1,    17,     4,
      51,    11,    -1,    17,     5,    51,    11,    -1,    50,    -1,
      50,     8,    50,    -1,    50,     4,    51,    11,    -1,    50,
       5,    51,    11,    -1,    50,     4,    11,    -1,    50,     5,
      11,    -1,     4,    51,    11,    -1,     5,    51,    11,    -1,
       4,    11,    -1,     5,    11,    -1,    50,     4,    63,    11,
      -1,    50,     5,    63,    11,    -1,     4,    63,    11,    -1,
       5,    63,    11,    -1,    51,    -1,    52,    -1,     4,    63,
      -1,     5,    63,    -1,    53,    -1,    54,     6,    54,    -1,
       4,    51,    -1,     5,    51,    -1,    55,    58,    -1,     7,
      55,    58,    -1,    55,     7,    55,    58,    -1,    55,     7,
      58,    -1,    55,    -1,    56,    -1,    55,    56,    -1,    39,
      -1,    20,    -1,    -1,    16,    -1,    17,    -1,    -1,    22,
      -1,    12,    57,    -1,    57,    12,    -1,    14,    57,    -1,
      57,    14,    -1,    57,    -1,    13,    57,    -1,    57,    13,
      -1,    15,    57,    -1,    57,    15,    -1,     9,    -1,    10,
      -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   143,   143,   144,   146,   146,   146,   146,   148,   151,
     152,   153,   154,   155,   156,   157,   158,   159,   160,   161,
     162,   163,   165,   166,   167,   168,   171,   172,   182,   183,
     186,   187,   192,   194,   196,   197,   198,   199,   200,   201,
     202,   203,   204,   205,   206,   207,   208,   209,   212,   213,
     214,   215,   218,   219,   229,   230,   233,   234,   239,   240,
     243,   245,   246,   247,   248,   249,   250,   251,   252,   253,
     254,   255,   256,   257,   258,   261,   262,   263,   264,   267,
     268,   278,   279,   282,   283,   288,   289,   292,   293,   298,
     301,   308,   315,   322,   331,   332,   333,   334,   335,   336,
     337,   338,   339,   340,   341,   342,   343,   344,   347,   348,
     349,   350,   353,   354,   364,   365,   368,   381,   392,   416,
     430,   432,   437,   444,   445,   448,   449,   450,   453,   454,
     461,   462,   465,   466,   467,   470,   471,   474,   475,   478,
     479
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "END_OF_FILE", "PLUS", "MINUS", "SLASH",
  "DOT", "AT", "MY_NAN", "MY_INF", "IMAG", "RADIX_2", "RADIX_8",
  "RADIX_10", "RADIX_16", "EXACT", "INEXACT", "DIGIT_2", "DIGIT_8",
  "DIGIT_10", "DIGIT_16", "EXPONENT_MARKER", "$accept", "top_level",
  "datum", "num2", "complex2", "real2", "ureal2", "sreal2", "uinteger2",
  "digit2", "num8", "complex8", "real8", "ureal8", "sreal8", "uinteger8",
  "digit8", "num16", "complex16", "real16", "ureal16", "sreal16",
  "uinteger16", "digit16", "num10", "inexact_complex10", "complex10",
  "real10", "ureal10", "sreal10", "decimal10", "uinteger10",
  "uinteger10String", "digit10", "exactness", "suffix", "prefix2",
  "prefix10", "prefix8", "prefix16", "naninf", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    23,    24,    24,    25,    25,    25,    25,    26,    27,
      27,    27,    27,    27,    27,    27,    27,    27,    27,    27,
      27,    27,    28,    28,    28,    28,    29,    29,    30,    30,
      31,    31,    32,    33,    34,    34,    34,    34,    34,    34,
      34,    34,    34,    34,    34,    34,    34,    34,    35,    35,
      35,    35,    36,    36,    37,    37,    38,    38,    39,    39,
      40,    41,    41,    41,    41,    41,    41,    41,    41,    41,
      41,    41,    41,    41,    41,    42,    42,    42,    42,    43,
      43,    44,    44,    45,    45,    46,    46,    47,    47,    48,
      48,    48,    48,    48,    49,    49,    49,    49,    49,    49,
      49,    49,    49,    49,    49,    49,    49,    49,    50,    50,
      50,    50,    51,    51,    52,    52,    53,    53,    53,    53,
      54,    55,    55,    56,    56,    57,    57,    57,    58,    58,
      59,    59,    60,    60,    60,    61,    61,    62,    62,    63,
      63
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     2,     4,     4,     3,     3,     2,     2,     4,     4,
       3,     3,     1,     1,     2,     2,     1,     3,     2,     2,
       1,     2,     1,     2,     1,     3,     4,     4,     3,     3,
       3,     3,     2,     2,     4,     4,     3,     3,     1,     1,
       2,     2,     1,     3,     2,     2,     1,     2,     1,     1,
       2,     1,     3,     4,     4,     3,     3,     3,     3,     2,
       2,     4,     4,     3,     3,     1,     1,     2,     2,     1,
       3,     2,     2,     1,     2,     1,     1,     1,     2,     2,
       5,     5,     4,     4,     1,     3,     4,     4,     3,     3,
       3,     3,     2,     2,     4,     4,     3,     3,     1,     1,
       2,     2,     1,     3,     2,     2,     2,     3,     4,     3,
       1,     1,     2,     1,     1,     0,     1,     1,     0,     1,
       2,     2,     2,     2,     1,     2,     2,     2,     2,     1,
       1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     125,     3,   125,   125,   125,   125,   126,   127,     0,     2,
       4,     5,     7,     6,    87,   134,     0,     0,     0,     0,
     127,   130,   135,   132,   137,     0,     0,     0,    32,    59,
     124,    58,   123,    89,   108,   109,   112,     0,   128,   121,
       1,   131,   136,   133,   138,     0,     0,     8,     9,    22,
      23,    26,    30,     0,     0,    88,    94,     0,     0,    33,
      34,    48,    49,    52,    56,     0,     0,    86,    60,    61,
      75,    76,    79,    83,    85,   139,   140,   114,   110,   115,
     111,   128,     0,     0,     0,   128,   129,   122,   116,    16,
      28,    24,    17,    29,    25,     0,     0,     0,    11,     0,
      31,   102,   114,   110,   103,   115,   111,     0,     0,     0,
      42,    54,    50,    43,    55,    51,     0,     0,     0,     0,
      57,    69,    81,    77,    70,    82,    78,     0,     0,     0,
       0,    84,    92,    93,   117,     0,     0,   113,   120,   128,
     119,    20,    21,    14,     0,     0,    15,     0,     0,     0,
       0,    10,    23,    27,   100,   106,   101,   107,    98,     0,
       0,    99,     0,     0,     0,     0,    95,    40,    46,    41,
      47,    38,     0,     0,    39,     0,     0,     0,     0,    35,
      53,    67,    73,    68,    74,    65,     0,     0,    66,     0,
       0,     0,     0,    62,    80,    90,    91,   118,    12,    18,
      13,    19,    24,    25,    96,   104,    97,   105,   114,   115,
      36,    44,    37,    45,    54,    50,    55,    51,    63,    71,
      64,    72,    81,    77,    82,    78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     8,     9,    10,    47,    48,    49,    50,    51,    31,
      11,    59,    60,    61,    62,    63,    32,    12,    68,    69,
      70,    71,    72,    73,    13,    14,    55,    33,    34,    35,
      36,    37,    38,    39,    15,    88,    16,    17,    18,    19,
      78
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -67
static const yytype_int16 yypact[] =
{
     194,   -67,    90,    90,    90,    90,   -67,   164,     8,   -67,
     -67,   -67,   -67,   -67,   -67,   359,   100,   181,    59,   139,
     -67,   -67,   -67,   -67,   -67,   243,   243,   103,   -67,   -67,
     -67,   -67,   -67,   134,   -67,   -67,   -67,     6,    17,   -67,
     -67,   -67,   -67,   -67,   -67,    78,   327,   -67,   141,   -67,
       4,     7,   -67,   205,   210,   -67,   355,   297,   308,   -67,
     357,   -67,   -67,   248,   -67,   259,   263,   -67,   -67,   362,
     -67,   -67,    36,   -67,   -67,   -67,   -67,    27,   -67,    34,
     -67,   334,   238,   238,   103,   334,   -67,   -67,   -67,   -67,
     -67,    37,   -67,   -67,    41,   330,   340,   111,   -67,     9,
     -67,   -67,    47,    50,   -67,    54,    61,   224,   229,   185,
     -67,    70,    75,   -67,    79,    87,   311,   314,   108,   146,
     -67,   -67,   106,   145,   -67,   150,   159,   276,   280,   158,
     358,   -67,   -67,   -67,   -67,   163,   169,   -67,   103,   334,
     -67,   -67,   -67,   -67,   170,   176,   -67,   180,   184,     0,
       0,   -67,   -67,     9,   -67,   -67,   -67,   -67,   -67,   187,
     191,   -67,   202,   207,   243,   243,   -67,   -67,   -67,   -67,
     -67,   -67,   211,   215,   -67,   216,   221,   325,   325,   -67,
     146,   -67,   -67,   -67,   -67,   -67,   226,   230,   -67,   235,
     240,   293,   293,   -67,   358,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,   -67,
     -67,   -67,   -67,   -67,   -67,   -67
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -67,   -67,   -67,   -67,   -67,    53,     5,   162,    15,    -2,
     -67,   -67,   137,   -41,   -67,   152,    16,   -67,   -67,   131,
     -61,   -67,   135,   -66,   -67,   -67,   -67,   -10,   -23,   -67,
     -67,   192,   -16,   -19,   378,   -59,   -67,   -67,   -67,   -67,
     -25
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -121
static const yytype_int16 yytable[] =
{
      74,    80,    77,    79,   122,   125,   131,    56,    40,    75,
      76,    81,    84,    99,    52,    98,   111,   114,    28,    87,
      91,    94,   134,  -120,    85,    28,   140,    28,   103,   106,
     102,   105,   112,   115,    64,    28,    29,    30,   132,    86,
     123,   126,   130,    52,    52,   133,    74,    74,   141,   100,
      90,    93,   142,    74,    28,    29,    30,    67,   154,   135,
     136,   155,    87,    57,    58,   156,   186,   189,   138,   139,
     145,   148,   157,    64,    64,   172,   175,    28,    29,   120,
     197,   167,   160,   163,   159,   162,   168,    75,    76,    89,
     169,   173,   176,    52,    52,    52,    28,    52,   170,   166,
     144,   147,   187,   190,    45,    46,     6,    20,    74,    74,
      74,    74,   177,   178,   153,   149,   150,   181,    28,    87,
      87,    28,    29,    30,   202,   203,    28,    29,   131,    28,
     222,   224,    64,    64,    64,    64,   214,   216,    82,    83,
      80,   208,   209,    65,    66,    95,    96,    52,    52,    97,
     151,   100,   215,   217,    90,    93,   182,    28,    29,    30,
      67,   183,   191,   192,    28,    29,   223,   225,    25,    26,
     184,    27,    74,    74,   195,    74,    28,    29,    30,    67,
     196,   198,    28,    29,    30,    53,    54,   199,    27,   164,
     165,   200,    27,    64,    64,   201,   120,     1,   204,    28,
      29,    30,   205,    28,    29,    30,     2,     3,     4,     5,
       6,     7,    27,   206,    75,    76,   101,    27,   207,    75,
      76,   104,   210,    28,    29,    30,   211,   212,    28,    29,
      30,    27,   213,    75,    76,   158,    27,   218,    75,    76,
     161,   219,    28,    29,    30,    27,   220,    28,    29,    30,
      27,   221,    75,    76,   119,   179,    28,    29,    30,   152,
     193,    28,    29,    30,     0,   194,    28,    29,    75,    76,
     121,   180,    75,    76,   124,     0,   137,    28,    29,    30,
      67,    28,    29,    30,    67,    75,    76,   185,     0,    75,
      76,   188,     0,     0,    28,    29,    30,    67,    28,    29,
      30,    67,    75,    76,     0,     0,    75,    76,   110,     0,
       0,    28,    29,    30,    67,    28,    29,    75,    76,   113,
      75,    76,   171,    75,    76,   174,    28,    29,     0,    28,
      29,     0,    28,    29,    75,    76,    75,    76,    92,    75,
      76,   143,     0,    28,    29,    28,     0,     0,    28,    75,
      76,   146,    28,    29,    30,     0,    86,     0,    28,   107,
     108,   116,   117,   109,     0,   118,   127,   128,     0,     0,
     129,    41,    42,    43,    44,     0,    28,    29,    30,    67,
      21,    22,    23,    24
};

static const yytype_int16 yycheck[] =
{
      19,    26,    25,    26,    65,    66,    72,    17,     0,     9,
      10,    27,     6,     6,    16,    11,    57,    58,    18,    38,
      45,    46,    81,     6,     7,    18,    85,    18,    53,    54,
      53,    54,    57,    58,    18,    18,    19,    20,    11,    22,
      65,    66,     6,    45,    46,    11,    65,    66,    11,    51,
      45,    46,    11,    72,    18,    19,    20,    21,    11,    82,
      83,    11,    81,     4,     5,    11,   127,   128,    84,    85,
      95,    96,    11,    57,    58,   116,   117,    18,    19,    63,
     139,    11,   107,   108,   107,   108,    11,     9,    10,    11,
      11,   116,   117,    95,    96,    97,    18,    99,    11,   109,
      95,    96,   127,   128,     4,     5,    16,    17,   127,   128,
     129,   130,     4,     5,    99,     4,     5,    11,    18,   138,
     139,    18,    19,    20,   149,   150,    18,    19,   194,    18,
     191,   192,   116,   117,   118,   119,   177,   178,     4,     5,
     165,   164,   165,     4,     5,     4,     5,   149,   150,     8,
      97,   153,   177,   178,   149,   150,    11,    18,    19,    20,
      21,    11,     4,     5,    18,    19,   191,   192,     4,     5,
      11,     7,   191,   192,    11,   194,    18,    19,    20,    21,
      11,    11,    18,    19,    20,     4,     5,    11,     7,     4,
       5,    11,     7,   177,   178,    11,   180,     3,    11,    18,
      19,    20,    11,    18,    19,    20,    12,    13,    14,    15,
      16,    17,     7,    11,     9,    10,    11,     7,    11,     9,
      10,    11,    11,    18,    19,    20,    11,    11,    18,    19,
      20,     7,    11,     9,    10,    11,     7,    11,     9,    10,
      11,    11,    18,    19,    20,     7,    11,    18,    19,    20,
       7,    11,     9,    10,     6,   118,    18,    19,    20,    97,
     129,    18,    19,    20,    -1,   130,    18,    19,     9,    10,
      11,   119,     9,    10,    11,    -1,    84,    18,    19,    20,
      21,    18,    19,    20,    21,     9,    10,    11,    -1,     9,
      10,    11,    -1,    -1,    18,    19,    20,    21,    18,    19,
      20,    21,     9,    10,    -1,    -1,     9,    10,    11,    -1,
      -1,    18,    19,    20,    21,    18,    19,     9,    10,    11,
       9,    10,    11,     9,    10,    11,    18,    19,    -1,    18,
      19,    -1,    18,    19,     9,    10,     9,    10,    11,     9,
      10,    11,    -1,    18,    19,    18,    -1,    -1,    18,     9,
      10,    11,    18,    19,    20,    -1,    22,    -1,    18,     4,
       5,     4,     5,     8,    -1,     8,     4,     5,    -1,    -1,
       8,    12,    13,    14,    15,    -1,    18,    19,    20,    21,
       2,     3,     4,     5
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    12,    13,    14,    15,    16,    17,    24,    25,
      26,    33,    40,    47,    48,    57,    59,    60,    61,    62,
      17,    57,    57,    57,    57,     4,     5,     7,    18,    19,
      20,    32,    39,    50,    51,    52,    53,    54,    55,    56,
       0,    12,    13,    14,    15,     4,     5,    27,    28,    29,
      30,    31,    32,     4,     5,    49,    50,     4,     5,    34,
      35,    36,    37,    38,    39,     4,     5,    21,    41,    42,
      43,    44,    45,    46,    56,     9,    10,    51,    63,    51,
      63,    55,     4,     5,     6,     7,    22,    56,    58,    11,
      29,    63,    11,    29,    63,     4,     5,     8,    11,     6,
      32,    11,    51,    63,    11,    51,    63,     4,     5,     8,
      11,    36,    63,    11,    36,    63,     4,     5,     8,     6,
      39,    11,    43,    63,    11,    43,    63,     4,     5,     8,
       6,    46,    11,    11,    58,    51,    51,    54,    55,    55,
      58,    11,    11,    11,    29,    63,    11,    29,    63,     4,
       5,    28,    30,    31,    11,    11,    11,    11,    11,    51,
      63,    11,    51,    63,     4,     5,    50,    11,    11,    11,
      11,    11,    36,    63,    11,    36,    63,     4,     5,    35,
      38,    11,    11,    11,    11,    11,    43,    63,    11,    43,
      63,     4,     5,    42,    45,    11,    11,    58,    11,    11,
      11,    11,    63,    63,    11,    11,    11,    11,    51,    51,
      11,    11,    11,    11,    36,    63,    36,    63,    11,    11,
      11,    11,    43,    63,    43,    63
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 143 "NumberReader.y"
    { currentVM()->numberReaderContext()->setParsed((yyval.object)); YYACCEPT; ;}
    break;

  case 3:
#line 144 "NumberReader.y"
    { currentVM()->numberReaderContext()->setParsed(Object::Eof); YYACCEPT; ;}
    break;

  case 8:
#line 148 "NumberReader.y"
    { (yyval.object) = ScannerHelper::applyExactness((yyvsp[(1) - (2)].exactValue), (yyvsp[(2) - (2)].object)); ;}
    break;

  case 10:
#line 152 "NumberReader.y"
    { (yyval.object) = Arithmetic::makePolar((yyvsp[(1) - (3)].object), (yyvsp[(3) - (3)].object)); ;}
    break;

  case 11:
#line 153 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), (yyvsp[(1) - (2)].object)); ;}
    break;

  case 12:
#line 154 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), (yyvsp[(3) - (4)].object)); ;}
    break;

  case 13:
#line 155 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), Arithmetic::mul(-1, (yyvsp[(3) - (4)].object))); ;}
    break;

  case 14:
#line 156 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (3)].object), Object::makeFixnum(1)); ;}
    break;

  case 15:
#line 157 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (3)].object), Object::makeFixnum(-1)); ;}
    break;

  case 16:
#line 158 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Object::makeFixnum(1)); ;}
    break;

  case 17:
#line 159 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Object::makeFixnum(-1)); ;}
    break;

  case 18:
#line 160 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), (yyvsp[(3) - (4)].object)); ;}
    break;

  case 19:
#line 161 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), Arithmetic::mul(-1, (yyvsp[(3) - (4)].object))); ;}
    break;

  case 20:
#line 162 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), (yyvsp[(2) - (3)].object)); ;}
    break;

  case 21:
#line 163 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Arithmetic::mul(-1, (yyvsp[(2) - (3)].object))); ;}
    break;

  case 24:
#line 167 "NumberReader.y"
    { (yyval.object) = (yyvsp[(2) - (2)].object); ;}
    break;

  case 25:
#line 168 "NumberReader.y"
    { (yyval.object) = Arithmetic::mul(-1, (yyvsp[(2) - (2)].object)); ;}
    break;

  case 27:
#line 172 "NumberReader.y"
    {
               bool isDiv0Error = false;
               (yyval.object) = Arithmetic::div((yyvsp[(1) - (3)].object), (yyvsp[(3) - (3)].object), isDiv0Error);
               if (isDiv0Error) {
                   yyerror("division by zero");
                   YYERROR;
               }
          ;}
    break;

  case 28:
#line 182 "NumberReader.y"
    { (yyval.object) = (yyvsp[(2) - (2)].object); ;}
    break;

  case 29:
#line 183 "NumberReader.y"
    { (yyval.object) = Arithmetic::mul(-1, (yyvsp[(2) - (2)].object)); ;}
    break;

  case 30:
#line 186 "NumberReader.y"
    { (yyval.object) = Object::makeFixnum((yyvsp[(1) - (1)].intValue)); ;}
    break;

  case 31:
#line 187 "NumberReader.y"
    {
               (yyval.object) = Arithmetic::add(Arithmetic::mul(2, (yyvsp[(1) - (2)].object)), Object::makeFixnum((yyvsp[(2) - (2)].intValue)));
          ;}
    break;

  case 33:
#line 194 "NumberReader.y"
    { (yyval.object) = ScannerHelper::applyExactness((yyvsp[(1) - (2)].exactValue), (yyvsp[(2) - (2)].object)); ;}
    break;

  case 35:
#line 197 "NumberReader.y"
    { (yyval.object) = Arithmetic::makePolar((yyvsp[(1) - (3)].object), (yyvsp[(3) - (3)].object)); ;}
    break;

  case 36:
#line 198 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), (yyvsp[(3) - (4)].object)); ;}
    break;

  case 37:
#line 199 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), Arithmetic::mul(-1, (yyvsp[(3) - (4)].object))); ;}
    break;

  case 38:
#line 200 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (3)].object), Object::makeFixnum(1)); ;}
    break;

  case 39:
#line 201 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (3)].object), Object::makeFixnum(-1)); ;}
    break;

  case 40:
#line 202 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), (yyvsp[(2) - (3)].object)); ;}
    break;

  case 41:
#line 203 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Arithmetic::mul(-1, (yyvsp[(2) - (3)].object))); ;}
    break;

  case 42:
#line 204 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Object::makeFixnum(1)); ;}
    break;

  case 43:
#line 205 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Object::makeFixnum(-1)); ;}
    break;

  case 44:
#line 206 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), (yyvsp[(3) - (4)].object)); ;}
    break;

  case 45:
#line 207 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), Arithmetic::mul(-1, (yyvsp[(3) - (4)].object))); ;}
    break;

  case 46:
#line 208 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), (yyvsp[(2) - (3)].object)); ;}
    break;

  case 47:
#line 209 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Arithmetic::mul(-1, (yyvsp[(2) - (3)].object))); ;}
    break;

  case 50:
#line 214 "NumberReader.y"
    { (yyval.object) = (yyvsp[(2) - (2)].object); ;}
    break;

  case 51:
#line 215 "NumberReader.y"
    { (yyval.object) = Arithmetic::mul(-1, (yyvsp[(2) - (2)].object)); ;}
    break;

  case 53:
#line 219 "NumberReader.y"
    {
               bool isDiv0Error = false;
               (yyval.object) = Arithmetic::div((yyvsp[(1) - (3)].object), (yyvsp[(3) - (3)].object), isDiv0Error);
               if (isDiv0Error) {
                   yyerror("division by zero");
                   YYERROR;
               }
          ;}
    break;

  case 54:
#line 229 "NumberReader.y"
    { (yyval.object) = (yyvsp[(2) - (2)].object); ;}
    break;

  case 55:
#line 230 "NumberReader.y"
    { (yyval.object) = Arithmetic::mul(-1, (yyvsp[(2) - (2)].object)); ;}
    break;

  case 56:
#line 233 "NumberReader.y"
    { (yyval.object) = Object::makeFixnum((yyvsp[(1) - (1)].intValue)); ;}
    break;

  case 57:
#line 234 "NumberReader.y"
    {
                (yyval.object) = Arithmetic::add(Arithmetic::mul(8, (yyvsp[(1) - (2)].object)), Object::makeFixnum((yyvsp[(2) - (2)].intValue)));
          ;}
    break;

  case 59:
#line 240 "NumberReader.y"
    { (yyval.intValue) = (yyvsp[(1) - (1)].intValue); ;}
    break;

  case 60:
#line 243 "NumberReader.y"
    { (yyval.object) = ScannerHelper::applyExactness((yyvsp[(1) - (2)].exactValue), (yyvsp[(2) - (2)].object)); ;}
    break;

  case 62:
#line 246 "NumberReader.y"
    { (yyval.object) = Arithmetic::makePolar((yyvsp[(1) - (3)].object), (yyvsp[(3) - (3)].object)); ;}
    break;

  case 63:
#line 247 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), (yyvsp[(3) - (4)].object)); ;}
    break;

  case 64:
#line 248 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), Arithmetic::mul(-1, (yyvsp[(3) - (4)].object))); ;}
    break;

  case 65:
#line 249 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (3)].object), Object::makeFixnum(1)); ;}
    break;

  case 66:
#line 250 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (3)].object), Object::makeFixnum(-1)); ;}
    break;

  case 67:
#line 251 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), (yyvsp[(2) - (3)].object)); ;}
    break;

  case 68:
#line 252 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Arithmetic::mul(-1, (yyvsp[(2) - (3)].object))); ;}
    break;

  case 69:
#line 253 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Object::makeFixnum(1)); ;}
    break;

  case 70:
#line 254 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Object::makeFixnum(-1)); ;}
    break;

  case 71:
#line 255 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), (yyvsp[(3) - (4)].object)); ;}
    break;

  case 72:
#line 256 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), Arithmetic::mul(-1, (yyvsp[(3) - (4)].object))); ;}
    break;

  case 73:
#line 257 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), (yyvsp[(2) - (3)].object)); ;}
    break;

  case 74:
#line 258 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Arithmetic::mul(-1, (yyvsp[(2) - (3)].object))); ;}
    break;

  case 77:
#line 263 "NumberReader.y"
    { (yyval.object) = (yyvsp[(2) - (2)].object); ;}
    break;

  case 78:
#line 264 "NumberReader.y"
    { (yyval.object) = Arithmetic::mul(-1, (yyvsp[(2) - (2)].object)); ;}
    break;

  case 80:
#line 268 "NumberReader.y"
    {
               bool isDiv0Error = false;
               (yyval.object) = Arithmetic::div((yyvsp[(1) - (3)].object), (yyvsp[(3) - (3)].object), isDiv0Error);
               if (isDiv0Error) {
                   yyerror("division by zero");
                   YYERROR;
               }
          ;}
    break;

  case 81:
#line 278 "NumberReader.y"
    { (yyval.object) = (yyvsp[(2) - (2)].object); ;}
    break;

  case 82:
#line 279 "NumberReader.y"
    { (yyval.object) = Arithmetic::mul(-1, (yyvsp[(2) - (2)].object)); ;}
    break;

  case 83:
#line 282 "NumberReader.y"
    { (yyval.object) = Object::makeFixnum((yyvsp[(1) - (1)].intValue)); ;}
    break;

  case 84:
#line 283 "NumberReader.y"
    {
                (yyval.object) = Arithmetic::add(Arithmetic::mul(16, (yyvsp[(1) - (2)].object)), Object::makeFixnum((yyvsp[(2) - (2)].intValue)));
          ;}
    break;

  case 86:
#line 289 "NumberReader.y"
    { (yyval.intValue) = (yyvsp[(1) - (1)].intValue); ;}
    break;

  case 88:
#line 293 "NumberReader.y"
    { (yyval.object) = ScannerHelper::applyExactness((yyvsp[(1) - (2)].exactValue), (yyvsp[(2) - (2)].object)); ;}
    break;

  case 89:
#line 298 "NumberReader.y"
    {
            (yyval.object) = ScannerHelper::applyExactness(-1, (yyvsp[(2) - (2)].object));
          ;}
    break;

  case 90:
#line 301 "NumberReader.y"
    {
            if (Arithmetic::isExactZero((yyvsp[(4) - (5)].object))) {
              (yyval.object) = Object::makeCompnum(ScannerHelper::applyExactness(-1, (yyvsp[(2) - (5)].object)), Object::makeFlonum(0.0));
            } else {
              (yyval.object) = ScannerHelper::applyExactness(-1, Object::makeCompnum((yyvsp[(2) - (5)].object), (yyvsp[(4) - (5)].object)));
            }
          ;}
    break;

  case 91:
#line 308 "NumberReader.y"
    {
            if (Arithmetic::isExactZero((yyvsp[(4) - (5)].object))) {
              (yyval.object) = Object::makeCompnum(ScannerHelper::applyExactness(-1, (yyvsp[(2) - (5)].object)), Object::makeFlonum(0.0));
            } else {
              (yyval.object) = ScannerHelper::applyExactness(-1, Arithmetic::mul(-1, Object::makeCompnum((yyvsp[(2) - (5)].object), (yyvsp[(4) - (5)].object))));
            }
          ;}
    break;

  case 92:
#line 315 "NumberReader.y"
    {
            if (Arithmetic::isExactZero((yyvsp[(3) - (4)].object))) {
              (yyval.object) = Object::makeCompnum(Object::makeFlonum(0.0), Object::makeFlonum(0.0));
            } else {
              (yyval.object) = Object::makeCompnum(Object::makeFlonum(0.0), ScannerHelper::applyExactness(-1, (yyvsp[(3) - (4)].object)));
            }
          ;}
    break;

  case 93:
#line 322 "NumberReader.y"
    {
            if (Arithmetic::isExactZero((yyvsp[(3) - (4)].object))) {
              (yyval.object) = Object::makeCompnum(Object::makeFlonum(0.0), Object::makeFlonum(0.0));
            } else {
              (yyval.object) = Object::makeCompnum(Object::makeFlonum(0.0), ScannerHelper::applyExactness(-1, Arithmetic::mul(-1, (yyvsp[(3) - (4)].object))));
            }
          ;}
    break;

  case 95:
#line 332 "NumberReader.y"
    { (yyval.object) = Arithmetic::makePolar((yyvsp[(1) - (3)].object), (yyvsp[(3) - (3)].object)); ;}
    break;

  case 96:
#line 333 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), (yyvsp[(3) - (4)].object)); ;}
    break;

  case 97:
#line 334 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), Arithmetic::mul(-1, (yyvsp[(3) - (4)].object))); ;}
    break;

  case 98:
#line 335 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (3)].object), Object::makeFixnum(1)); ;}
    break;

  case 99:
#line 336 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (3)].object), Object::makeFixnum(-1)); ;}
    break;

  case 100:
#line 337 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), (yyvsp[(2) - (3)].object)); ;}
    break;

  case 101:
#line 338 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Arithmetic::mul(-1, (yyvsp[(2) - (3)].object))); ;}
    break;

  case 102:
#line 339 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Object::makeFixnum(1)); ;}
    break;

  case 103:
#line 340 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Object::makeFixnum(-1)); ;}
    break;

  case 104:
#line 341 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), (yyvsp[(3) - (4)].object)); ;}
    break;

  case 105:
#line 342 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), Arithmetic::mul(-1, (yyvsp[(3) - (4)].object))); ;}
    break;

  case 106:
#line 343 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), (yyvsp[(2) - (3)].object)); ;}
    break;

  case 107:
#line 344 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Arithmetic::mul(-1, (yyvsp[(2) - (3)].object))); ;}
    break;

  case 110:
#line 349 "NumberReader.y"
    { (yyval.object) = (yyvsp[(2) - (2)].object); ;}
    break;

  case 111:
#line 350 "NumberReader.y"
    { (yyval.object) = Arithmetic::mul(-1, (yyvsp[(2) - (2)].object)); ;}
    break;

  case 113:
#line 354 "NumberReader.y"
    {
               bool isDiv0Error = false;
               (yyval.object) = Arithmetic::div((yyvsp[(1) - (3)].object), (yyvsp[(3) - (3)].object), isDiv0Error);
               if (isDiv0Error) {
                   yyerror("division by zero");
                   YYERROR;
               }
          ;}
    break;

  case 114:
#line 364 "NumberReader.y"
    { (yyval.object) = (yyvsp[(2) - (2)].object); ;}
    break;

  case 115:
#line 365 "NumberReader.y"
    { (yyval.object) = Arithmetic::mul(-1, (yyvsp[(2) - (2)].object)); ;}
    break;

  case 116:
#line 368 "NumberReader.y"
    {
              if ((yyvsp[(2) - (2)].stringValue).empty()) {
                  (yyval.object) = Bignum::makeInteger((yyvsp[(1) - (2)].stringValue));
              } else {
                  (yyval.object) = Arithmetic::mul(Bignum::makeInteger((yyvsp[(1) - (2)].stringValue)), suffixToNumberOld((yyvsp[(2) - (2)].stringValue)));
// todo ("#e-1e-1000" (- (expt 10 -1000)))
//                   int suffixNum = suffix($2);
//                   Object z0 = Arithmetic::mul(Bignum::makeInteger($1),
//                                               Arithmetic::expt(Object::makeFixnum(10), Object::makeFixnum(suffixNum)));
//                   z0 = Arithmetic::inexact(z0);
//                   $$ = Object::makeFlonum(FlonumUtil::algorithmR(Bignum::makeInteger($1), suffixNum, z0.toFlonum()->value()));
              }
          ;}
    break;

  case 117:
#line 381 "NumberReader.y"
    {
              ucs4string ret = UC(".");
              ret += (yyvsp[(2) - (3)].stringValue);
              if (!(yyvsp[(3) - (3)].stringValue).empty()) {
                  (yyval.object) = Arithmetic::mul(Flonum::fromString(ret), suffixToNumberOld((yyvsp[(3) - (3)].stringValue)));
              } else {

                  (yyval.object) = Flonum::fromString(ret);
              }

          ;}
    break;

  case 118:
#line 392 "NumberReader.y"
    {
              ucs4string uinteger10 = (yyvsp[(1) - (4)].stringValue);
              uinteger10 += (yyvsp[(3) - (4)].stringValue);
              Object f = Bignum::makeInteger(uinteger10);
              if (!(yyvsp[(4) - (4)].stringValue).empty()) {
                Object e = suffixToNumber((yyvsp[(4) - (4)].stringValue));
                ucs4string fstring = (yyvsp[(1) - (4)].stringValue);
                fstring += UC(".");
                fstring += (yyvsp[(3) - (4)].stringValue);
                double z0 = Arithmetic::mul(Flonum::fromString(fstring), suffixToNumberOld((yyvsp[(4) - (4)].stringValue))).toFlonum()->value();
                if (!e.isFixnum()) {
                  yyerror("invalid flonum expression: suffix");
                }
                if (!f.isFixnum()) {
                  yyerror("invalid flonum expression: too large significand");
                }
                const int digit = (yyvsp[(3) - (4)].stringValue).size();
                (yyval.object) = Object::makeFlonum(FlonumUtil::algorithmR(f, e.toFixnum() - digit, z0));
              } else {
                ucs4string ret = (yyvsp[(1) - (4)].stringValue);
                ret += UC(".") + (yyvsp[(3) - (4)].stringValue);
                (yyval.object) = Flonum::fromString(ret);
              }
          ;}
    break;

  case 119:
#line 416 "NumberReader.y"
    {
              ucs4string ret = (yyvsp[(1) - (3)].stringValue);
              ret += UC(".0");
              if (!(yyvsp[(3) - (3)].stringValue).empty()) {
//                  printf("%s %s:%d\n", __func__, __FILE__, __LINE__);fflush(stdout);// debug
                (yyval.object) = Arithmetic::mul(Flonum::fromString(ret), suffixToNumberOld((yyvsp[(3) - (3)].stringValue)));
              } else {
//                  printf("%s %s:%d\n", __func__, __FILE__, __LINE__);fflush(stdout);// debug
                  (yyval.object) = Flonum::fromString(ret);
              }
          ;}
    break;

  case 120:
#line 430 "NumberReader.y"
    { (yyval.object) = Bignum::makeInteger((yyvsp[(1) - (1)].stringValue)); ;}
    break;

  case 121:
#line 432 "NumberReader.y"
    {
                const ucs4char ch = '0' + (yyvsp[(1) - (1)].intValue);
                (yyval.stringValue) = UC("");
                (yyval.stringValue) += ch;
           ;}
    break;

  case 122:
#line 437 "NumberReader.y"
    {
               const ucs4char ch = '0' + (yyvsp[(2) - (2)].intValue);
               (yyval.stringValue) = (yyvsp[(1) - (2)].stringValue);
               (yyval.stringValue) += ch;
          ;}
    break;

  case 124:
#line 445 "NumberReader.y"
    { (yyval.intValue) = (yyvsp[(1) - (1)].intValue); ;}
    break;

  case 125:
#line 448 "NumberReader.y"
    { (yyval.exactValue) = 0; ;}
    break;

  case 126:
#line 449 "NumberReader.y"
    { (yyval.exactValue) = 1; ;}
    break;

  case 127:
#line 450 "NumberReader.y"
    { (yyval.exactValue) = -1; ;}
    break;

  case 128:
#line 453 "NumberReader.y"
    { (yyval.stringValue) = UC(""); ;}
    break;

  case 129:
#line 454 "NumberReader.y"
    {
              ucs4string ret = UC("e");
              ret += (yyvsp[(1) - (1)].stringValue).substr(1, (yyvsp[(1) - (1)].stringValue).size() - 1);
              (yyval.stringValue) = ret;
          ;}
    break;

  case 130:
#line 461 "NumberReader.y"
    { (yyval.exactValue) = (yyvsp[(2) - (2)].exactValue); ;}
    break;

  case 131:
#line 462 "NumberReader.y"
    { (yyval.exactValue) = (yyvsp[(1) - (2)].exactValue); ;}
    break;

  case 132:
#line 465 "NumberReader.y"
    { (yyval.exactValue) = (yyvsp[(2) - (2)].exactValue);;}
    break;

  case 133:
#line 466 "NumberReader.y"
    { (yyval.exactValue) = (yyvsp[(1) - (2)].exactValue);;}
    break;

  case 135:
#line 470 "NumberReader.y"
    { (yyval.exactValue) = (yyvsp[(2) - (2)].exactValue);;}
    break;

  case 136:
#line 471 "NumberReader.y"
    { (yyval.exactValue) = (yyvsp[(1) - (2)].exactValue);;}
    break;

  case 137:
#line 474 "NumberReader.y"
    { (yyval.exactValue) = (yyvsp[(2) - (2)].exactValue);;}
    break;

  case 138:
#line 475 "NumberReader.y"
    { (yyval.exactValue) = (yyvsp[(1) - (2)].exactValue);;}
    break;

  case 139:
#line 478 "NumberReader.y"
    { (yyval.object) = Flonum::NOT_A_NUMBER; ;}
    break;

  case 140:
#line 479 "NumberReader.y"
    { (yyval.object) = Flonum::POSITIVE_INF; ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2385 "NumberReader.tab.cpp"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 480 "NumberReader.y"


extern ucs4char* token;
int number_yyerror(char const *str)
{
  TextualInputPort* const port = currentVM()->readerContext()->port();
    port->setError(format(NULL, UC("~a near [~a] at ~a:~d. "),
                          Pair::list4(str, Object::makeString(port->scanner()->currentToken()), port->toString(), Object::makeFixnum(port->getLineNo()))));
    return 0;
}

