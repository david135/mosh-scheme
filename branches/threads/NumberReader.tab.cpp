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

using namespace scheme;
extern int number_yylex();
extern int number_yyerror(const char *);
//#define YYDEBUG 1
// yydebug = 1

// text => "e100", "e+100" or "e-100" style
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
    MOSH_ASSERT(!exponent.isBignum());
    return Arithmetic::expt(Object::makeFixnum(10), exponent);
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
#line 208 "NumberReader.tab.cpp"

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
# if defined YYENABLE_NLS && YYENABLE_NLS
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
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   358

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  23
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  134
/* YYNRULES -- Number of states.  */
#define YYNSTATES  211

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
     259,   263,   266,   269,   271,   274,   276,   278,   281,   283,
     287,   292,   297,   301,   305,   309,   313,   316,   319,   324,
     329,   333,   337,   339,   341,   344,   347,   349,   353,   356,
     359,   362,   366,   371,   375,   377,   379,   382,   384,   386,
     387,   389,   391,   392,   394,   397,   400,   403,   406,   408,
     411,   414,   417,   420,   422
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      24,     0,    -1,    25,    -1,     3,    -1,    26,    -1,    33,
      -1,    47,    -1,    40,    -1,    58,    27,    -1,    28,    -1,
      28,     8,    28,    -1,    30,    11,    -1,    28,     4,    29,
      11,    -1,    28,     5,    29,    11,    -1,    28,     4,    11,
      -1,    28,     5,    11,    -1,     4,    11,    -1,     5,    11,
      -1,    28,     4,    62,    11,    -1,    28,     5,    62,    11,
      -1,     4,    62,    11,    -1,     5,    62,    11,    -1,    29,
      -1,    30,    -1,     4,    62,    -1,     5,    62,    -1,    31,
      -1,    31,     6,    31,    -1,     4,    29,    -1,     5,    29,
      -1,    32,    -1,    31,    32,    -1,    18,    -1,    60,    34,
      -1,    35,    -1,    35,     8,    35,    -1,    35,     4,    36,
      11,    -1,    35,     5,    36,    11,    -1,    35,     4,    11,
      -1,    35,     5,    11,    -1,     4,    36,    11,    -1,     5,
      36,    11,    -1,     4,    11,    -1,     5,    11,    -1,    35,
       4,    62,    11,    -1,    35,     5,    62,    11,    -1,     4,
      62,    11,    -1,     5,    62,    11,    -1,    36,    -1,    37,
      -1,     4,    62,    -1,     5,    62,    -1,    38,    -1,    38,
       6,    38,    -1,     4,    36,    -1,     5,    36,    -1,    39,
      -1,    38,    39,    -1,    32,    -1,    19,    -1,    61,    41,
      -1,    42,    -1,    42,     8,    42,    -1,    42,     4,    43,
      11,    -1,    42,     5,    43,    11,    -1,    42,     4,    11,
      -1,    42,     5,    11,    -1,     4,    43,    11,    -1,     5,
      43,    11,    -1,     4,    11,    -1,     5,    11,    -1,    42,
       4,    62,    11,    -1,    42,     5,    62,    11,    -1,     4,
      62,    11,    -1,     5,    62,    11,    -1,    43,    -1,    44,
      -1,     4,    62,    -1,     5,    62,    -1,    45,    -1,    45,
       6,    45,    -1,     4,    43,    -1,     5,    43,    -1,    46,
      -1,    45,    46,    -1,    55,    -1,    21,    -1,    59,    48,
      -1,    49,    -1,    49,     8,    49,    -1,    49,     4,    50,
      11,    -1,    49,     5,    50,    11,    -1,    49,     4,    11,
      -1,    49,     5,    11,    -1,     4,    50,    11,    -1,     5,
      50,    11,    -1,     4,    11,    -1,     5,    11,    -1,    49,
       4,    62,    11,    -1,    49,     5,    62,    11,    -1,     4,
      62,    11,    -1,     5,    62,    11,    -1,    50,    -1,    51,
      -1,     4,    62,    -1,     5,    62,    -1,    52,    -1,    53,
       6,    53,    -1,     4,    50,    -1,     5,    50,    -1,    54,
      57,    -1,     7,    54,    57,    -1,    54,     7,    54,    57,
      -1,    54,     7,    57,    -1,    54,    -1,    55,    -1,    54,
      55,    -1,    39,    -1,    20,    -1,    -1,    16,    -1,    17,
      -1,    -1,    22,    -1,    12,    56,    -1,    56,    12,    -1,
      14,    56,    -1,    56,    14,    -1,    56,    -1,    13,    56,
      -1,    56,    13,    -1,    15,    56,    -1,    56,    15,    -1,
       9,    -1,    10,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   101,   101,   102,   104,   104,   104,   104,   106,   109,
     110,   111,   112,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   123,   124,   125,   126,   129,   130,   140,   141,
     144,   145,   150,   152,   154,   155,   156,   157,   158,   159,
     160,   161,   162,   163,   164,   165,   166,   167,   170,   171,
     172,   173,   176,   177,   187,   188,   191,   192,   197,   198,
     201,   203,   204,   205,   206,   207,   208,   209,   210,   211,
     212,   213,   214,   215,   216,   219,   220,   221,   222,   225,
     226,   236,   237,   240,   241,   246,   247,   250,   252,   253,
     254,   255,   256,   257,   258,   259,   260,   261,   262,   263,
     264,   265,   268,   269,   270,   271,   274,   275,   285,   286,
     289,   296,   307,   318,   330,   332,   337,   344,   345,   348,
     349,   350,   353,   354,   361,   362,   365,   366,   367,   370,
     371,   374,   375,   378,   379
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
  "uinteger16", "digit16", "num10", "complex10", "real10", "ureal10",
  "sreal10", "decimal10", "uinteger10", "uinteger10String", "digit10",
  "exactness", "suffix", "prefix2", "prefix10", "prefix8", "prefix16",
  "naninf", 0
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
      43,    44,    44,    45,    45,    46,    46,    47,    48,    48,
      48,    48,    48,    48,    48,    48,    48,    48,    48,    48,
      48,    48,    49,    49,    49,    49,    50,    50,    51,    51,
      52,    52,    52,    52,    53,    54,    54,    55,    55,    56,
      56,    56,    57,    57,    58,    58,    59,    59,    59,    60,
      60,    61,    61,    62,    62
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
       3,     2,     2,     1,     2,     1,     1,     2,     1,     3,
       4,     4,     3,     3,     3,     3,     2,     2,     4,     4,
       3,     3,     1,     1,     2,     2,     1,     3,     2,     2,
       2,     3,     4,     3,     1,     1,     2,     1,     1,     0,
       1,     1,     0,     1,     2,     2,     2,     2,     1,     2,
       2,     2,     2,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
     119,     3,   119,   119,   119,   119,   120,   121,     0,     2,
       4,     5,     7,     6,   128,     0,     0,     0,     0,   124,
     129,   126,   131,     1,   125,   130,   127,   132,     0,     0,
      32,     8,     9,    22,    23,    26,    30,     0,     0,     0,
      59,   118,    58,   117,    87,    88,   102,   103,   106,     0,
     122,   115,     0,     0,    33,    34,    48,    49,    52,    56,
       0,     0,    86,    60,    61,    75,    76,    79,    83,    85,
     133,   134,    16,    28,    24,    17,    29,    25,     0,     0,
       0,    11,     0,    31,    96,   108,   104,    97,   109,   105,
     122,     0,     0,     0,     0,   122,   123,   116,   110,    42,
      54,    50,    43,    55,    51,     0,     0,     0,     0,    57,
      69,    81,    77,    70,    82,    78,     0,     0,     0,     0,
      84,    20,    21,    14,     0,     0,    15,     0,     0,     0,
       0,    10,    23,    27,    94,   100,    95,   101,   111,    92,
       0,     0,    93,     0,     0,     0,     0,    89,   107,   114,
     122,   113,    40,    46,    41,    47,    38,     0,     0,    39,
       0,     0,     0,     0,    35,    53,    67,    73,    68,    74,
      65,     0,     0,    66,     0,     0,     0,     0,    62,    80,
      12,    18,    13,    19,    24,    25,    90,    98,    91,    99,
     108,   104,   109,   105,   112,    36,    44,    37,    45,    54,
      50,    55,    51,    63,    71,    64,    72,    81,    77,    82,
      78
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     8,     9,    10,    31,    32,    33,    34,    35,    42,
      11,    54,    55,    56,    57,    58,    43,    12,    63,    64,
      65,    66,    67,    68,    13,    44,    45,    46,    47,    48,
      49,    50,    51,    14,    98,    15,    16,    17,    18,    74
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -88
static const yytype_int16 yypact[] =
{
     181,   -88,     7,     7,     7,     7,   -88,   -88,     4,   -88,
     -88,   -88,   -88,   -88,   334,    87,   149,    11,    17,   -88,
     -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   299,   302,
     -88,   -88,   143,   -88,    -2,    -1,   -88,   192,   197,    21,
     -88,   -88,   -88,   -88,   -88,   330,   -88,   -88,   -88,     8,
     167,   -88,    37,   280,   -88,   332,   -88,   -88,   164,   -88,
     233,   246,   -88,   -88,   337,   -88,   -88,    67,   -88,   -88,
     -88,   -88,   -88,   -88,     9,   -88,   -88,    20,   312,   315,
     112,   -88,    32,   -88,   -88,    47,    51,   -88,    65,    73,
     309,   211,   216,   172,    21,   309,   -88,   -88,   -88,   -88,
      82,    93,   -88,    99,   100,   283,   286,    78,    48,   -88,
     -88,   101,   116,   -88,   122,   123,   250,   263,   121,   333,
     -88,   -88,   -88,   -88,   144,   146,   -88,   151,   154,   134,
     134,   -88,   -88,    32,   -88,   -88,   -88,   -88,   -88,   -88,
     169,   170,   -88,   177,   189,   230,   230,   -88,   -88,    21,
     309,   -88,   -88,   -88,   -88,   -88,   -88,   194,   198,   -88,
     202,   203,   297,   297,   -88,    48,   -88,   -88,   -88,   -88,
     -88,   208,   213,   -88,   217,   221,   267,   267,   -88,   333,
     -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
     -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,   -88,
     -88
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -88,   -88,   -88,   -88,   -88,    43,    16,    80,    96,    42,
     -88,   -88,   126,   -25,   -88,   130,     1,   -88,   -88,   127,
     -48,   -88,   128,   -66,   -88,   -88,   148,   -31,   -88,   -88,
     152,   -20,   -18,   353,   -87,   -88,   -88,   -88,   -88,   -27
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -115
static const yytype_int16 yytable[] =
{
      69,   120,    77,   138,    23,    82,    85,    88,   151,    81,
      86,    89,   111,   114,    94,    52,    53,    30,    59,    90,
     121,    60,    61,     6,     7,   101,   104,   100,   103,    30,
      40,   122,    97,   112,   115,    30,    40,    41,    62,    30,
      40,    41,    69,    69,    73,    76,    70,    71,    99,    69,
      30,   125,   128,    59,    59,    30,    40,    36,   134,   109,
     140,   143,   135,   194,   141,   144,    30,    40,   171,   174,
      36,    36,    97,   119,   149,   150,   136,    83,   158,   161,
     157,   160,   162,   163,   137,    30,    40,    41,    62,   172,
     175,    28,    29,   152,   124,   127,    30,    40,    69,    69,
      69,    69,   184,   185,   153,    30,    59,    59,    59,    59,
     154,   155,   166,   120,   190,   192,   129,   130,   191,   193,
      36,    36,    36,   131,    36,   176,   177,   167,   207,   209,
      30,    97,    97,   168,   169,   200,   202,   199,   201,    30,
      40,    41,    62,    70,    71,    73,    76,    78,    79,   208,
     210,    80,    30,    37,    38,   180,    39,   181,    69,    69,
     132,    69,   182,    59,    59,   183,   109,    30,    40,    41,
     108,    36,    36,  -114,    95,    83,   145,   146,   133,    39,
     186,   187,    30,    40,     1,    30,    40,    41,   188,    96,
      30,    40,    41,     2,     3,     4,     5,     6,     7,    39,
     189,    70,    71,    84,    39,   195,    70,    71,    87,   196,
      30,    40,    41,   197,   198,    30,    40,    41,    39,   203,
      70,    71,   139,    39,   204,    70,    71,   142,   205,    30,
      40,    41,   206,   164,    30,    40,    41,    39,   165,    70,
      71,   147,    70,    71,   110,   178,   148,   179,    30,    40,
      41,    30,    40,    41,    62,    70,    71,   113,     0,    70,
      71,   170,     0,     0,    30,    40,    41,    62,    30,    40,
      41,    62,    70,    71,   173,     0,    70,    71,     0,     0,
       0,    30,    40,    41,    62,    30,    40,    41,    62,    70,
      71,   102,    70,    71,   156,    70,    71,   159,    30,    40,
       0,    30,    40,     0,    30,    40,    70,    71,    70,    71,
      72,    70,    71,    75,     0,    30,    40,    30,     0,     0,
      30,    70,    71,   123,    70,    71,   126,    30,    40,    41,
      30,    96,     0,    30,    91,    92,   105,   106,    93,     0,
     107,   116,   117,     0,     0,   118,    24,    25,    26,    27,
       0,    30,    40,    41,    62,    19,    20,    21,    22
};

static const yytype_int16 yycheck[] =
{
      18,    67,    29,    90,     0,     6,    37,    38,    95,    11,
      37,    38,    60,    61,     6,     4,     5,    18,    17,    39,
      11,     4,     5,    16,    17,    52,    53,    52,    53,    18,
      19,    11,    50,    60,    61,    18,    19,    20,    21,    18,
      19,    20,    60,    61,    28,    29,     9,    10,    11,    67,
      18,    78,    79,    52,    53,    18,    19,    15,    11,    58,
      91,    92,    11,   150,    91,    92,    18,    19,   116,   117,
      28,    29,    90,     6,    94,    95,    11,    35,   105,   106,
     105,   106,     4,     5,    11,    18,    19,    20,    21,   116,
     117,     4,     5,    11,    78,    79,    18,    19,   116,   117,
     118,   119,   129,   130,    11,    18,   105,   106,   107,   108,
      11,    11,    11,   179,   145,   146,     4,     5,   145,   146,
      78,    79,    80,    80,    82,     4,     5,    11,   176,   177,
      18,   149,   150,    11,    11,   162,   163,   162,   163,    18,
      19,    20,    21,     9,    10,   129,   130,     4,     5,   176,
     177,     8,    18,     4,     5,    11,     7,    11,   176,   177,
      80,   179,    11,   162,   163,    11,   165,    18,    19,    20,
       6,   129,   130,     6,     7,   133,     4,     5,    82,     7,
      11,    11,    18,    19,     3,    18,    19,    20,    11,    22,
      18,    19,    20,    12,    13,    14,    15,    16,    17,     7,
      11,     9,    10,    11,     7,    11,     9,    10,    11,    11,
      18,    19,    20,    11,    11,    18,    19,    20,     7,    11,
       9,    10,    11,     7,    11,     9,    10,    11,    11,    18,
      19,    20,    11,   107,    18,    19,    20,     7,   108,     9,
      10,    93,     9,    10,    11,   118,    94,   119,    18,    19,
      20,    18,    19,    20,    21,     9,    10,    11,    -1,     9,
      10,    11,    -1,    -1,    18,    19,    20,    21,    18,    19,
      20,    21,     9,    10,    11,    -1,     9,    10,    -1,    -1,
      -1,    18,    19,    20,    21,    18,    19,    20,    21,     9,
      10,    11,     9,    10,    11,     9,    10,    11,    18,    19,
      -1,    18,    19,    -1,    18,    19,     9,    10,     9,    10,
      11,     9,    10,    11,    -1,    18,    19,    18,    -1,    -1,
      18,     9,    10,    11,     9,    10,    11,    18,    19,    20,
      18,    22,    -1,    18,     4,     5,     4,     5,     8,    -1,
       8,     4,     5,    -1,    -1,     8,    12,    13,    14,    15,
      -1,    18,    19,    20,    21,     2,     3,     4,     5
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    12,    13,    14,    15,    16,    17,    24,    25,
      26,    33,    40,    47,    56,    58,    59,    60,    61,    56,
      56,    56,    56,     0,    12,    13,    14,    15,     4,     5,
      18,    27,    28,    29,    30,    31,    32,     4,     5,     7,
      19,    20,    32,    39,    48,    49,    50,    51,    52,    53,
      54,    55,     4,     5,    34,    35,    36,    37,    38,    39,
       4,     5,    21,    41,    42,    43,    44,    45,    46,    55,
       9,    10,    11,    29,    62,    11,    29,    62,     4,     5,
       8,    11,     6,    32,    11,    50,    62,    11,    50,    62,
      54,     4,     5,     8,     6,     7,    22,    55,    57,    11,
      36,    62,    11,    36,    62,     4,     5,     8,     6,    39,
      11,    43,    62,    11,    43,    62,     4,     5,     8,     6,
      46,    11,    11,    11,    29,    62,    11,    29,    62,     4,
       5,    28,    30,    31,    11,    11,    11,    11,    57,    11,
      50,    62,    11,    50,    62,     4,     5,    49,    53,    54,
      54,    57,    11,    11,    11,    11,    11,    36,    62,    11,
      36,    62,     4,     5,    35,    38,    11,    11,    11,    11,
      11,    43,    62,    11,    43,    62,     4,     5,    42,    45,
      11,    11,    11,    11,    62,    62,    11,    11,    11,    11,
      50,    62,    50,    62,    57,    11,    11,    11,    11,    36,
      62,    36,    62,    11,    11,    11,    11,    43,    62,    43,
      62
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
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
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
#line 101 "NumberReader.y"
    { NumberReader::parsed = (yyval.object); YYACCEPT; ;}
    break;

  case 3:
#line 102 "NumberReader.y"
    { NumberReader::parsed = Object::Eof; YYACCEPT; ;}
    break;

  case 8:
#line 106 "NumberReader.y"
    { (yyval.object) = ScannerHelper::applyExactness((yyvsp[(1) - (2)].exactValue), (yyvsp[(2) - (2)].object)); ;}
    break;

  case 10:
#line 110 "NumberReader.y"
    { (yyval.object) = Arithmetic::makePolar((yyvsp[(1) - (3)].object), (yyvsp[(3) - (3)].object)); ;}
    break;

  case 11:
#line 111 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), (yyvsp[(1) - (2)].object)); ;}
    break;

  case 12:
#line 112 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), (yyvsp[(3) - (4)].object)); ;}
    break;

  case 13:
#line 113 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), Arithmetic::mul(-1, (yyvsp[(3) - (4)].object))); ;}
    break;

  case 14:
#line 114 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (3)].object), Object::makeFixnum(1)); ;}
    break;

  case 15:
#line 115 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (3)].object), Object::makeFixnum(-1)); ;}
    break;

  case 16:
#line 116 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Object::makeFixnum(1)); ;}
    break;

  case 17:
#line 117 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Object::makeFixnum(-1)); ;}
    break;

  case 18:
#line 118 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), (yyvsp[(3) - (4)].object)); ;}
    break;

  case 19:
#line 119 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), Arithmetic::mul(-1, (yyvsp[(3) - (4)].object))); ;}
    break;

  case 20:
#line 120 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), (yyvsp[(2) - (3)].object)); ;}
    break;

  case 21:
#line 121 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Arithmetic::mul(-1, (yyvsp[(2) - (3)].object))); ;}
    break;

  case 24:
#line 125 "NumberReader.y"
    { (yyval.object) = (yyvsp[(2) - (2)].object); ;}
    break;

  case 25:
#line 126 "NumberReader.y"
    { (yyval.object) = Arithmetic::mul(-1, (yyvsp[(2) - (2)].object)); ;}
    break;

  case 27:
#line 130 "NumberReader.y"
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
#line 140 "NumberReader.y"
    { (yyval.object) = (yyvsp[(2) - (2)].object); ;}
    break;

  case 29:
#line 141 "NumberReader.y"
    { (yyval.object) = Arithmetic::mul(-1, (yyvsp[(2) - (2)].object)); ;}
    break;

  case 30:
#line 144 "NumberReader.y"
    { (yyval.object) = Object::makeFixnum((yyvsp[(1) - (1)].intValue)); ;}
    break;

  case 31:
#line 145 "NumberReader.y"
    {
               (yyval.object) = Arithmetic::add(Arithmetic::mul(2, (yyvsp[(1) - (2)].object)), Object::makeFixnum((yyvsp[(2) - (2)].intValue)));
          ;}
    break;

  case 33:
#line 152 "NumberReader.y"
    { (yyval.object) = ScannerHelper::applyExactness((yyvsp[(1) - (2)].exactValue), (yyvsp[(2) - (2)].object)); ;}
    break;

  case 35:
#line 155 "NumberReader.y"
    { (yyval.object) = Arithmetic::makePolar((yyvsp[(1) - (3)].object), (yyvsp[(3) - (3)].object)); ;}
    break;

  case 36:
#line 156 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), (yyvsp[(3) - (4)].object)); ;}
    break;

  case 37:
#line 157 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), Arithmetic::mul(-1, (yyvsp[(3) - (4)].object))); ;}
    break;

  case 38:
#line 158 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (3)].object), Object::makeFixnum(1)); ;}
    break;

  case 39:
#line 159 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (3)].object), Object::makeFixnum(-1)); ;}
    break;

  case 40:
#line 160 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), (yyvsp[(2) - (3)].object)); ;}
    break;

  case 41:
#line 161 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Arithmetic::mul(-1, (yyvsp[(2) - (3)].object))); ;}
    break;

  case 42:
#line 162 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Object::makeFixnum(1)); ;}
    break;

  case 43:
#line 163 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Object::makeFixnum(-1)); ;}
    break;

  case 44:
#line 164 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), (yyvsp[(3) - (4)].object)); ;}
    break;

  case 45:
#line 165 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), Arithmetic::mul(-1, (yyvsp[(3) - (4)].object))); ;}
    break;

  case 46:
#line 166 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), (yyvsp[(2) - (3)].object)); ;}
    break;

  case 47:
#line 167 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Arithmetic::mul(-1, (yyvsp[(2) - (3)].object))); ;}
    break;

  case 50:
#line 172 "NumberReader.y"
    { (yyval.object) = (yyvsp[(2) - (2)].object); ;}
    break;

  case 51:
#line 173 "NumberReader.y"
    { (yyval.object) = Arithmetic::mul(-1, (yyvsp[(2) - (2)].object)); ;}
    break;

  case 53:
#line 177 "NumberReader.y"
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
#line 187 "NumberReader.y"
    { (yyval.object) = (yyvsp[(2) - (2)].object); ;}
    break;

  case 55:
#line 188 "NumberReader.y"
    { (yyval.object) = Arithmetic::mul(-1, (yyvsp[(2) - (2)].object)); ;}
    break;

  case 56:
#line 191 "NumberReader.y"
    { (yyval.object) = Object::makeFixnum((yyvsp[(1) - (1)].intValue)); ;}
    break;

  case 57:
#line 192 "NumberReader.y"
    {
                (yyval.object) = Arithmetic::add(Arithmetic::mul(8, (yyvsp[(1) - (2)].object)), Object::makeFixnum((yyvsp[(2) - (2)].intValue)));
          ;}
    break;

  case 59:
#line 198 "NumberReader.y"
    { (yyval.intValue) = (yyvsp[(1) - (1)].intValue); ;}
    break;

  case 60:
#line 201 "NumberReader.y"
    { (yyval.object) = ScannerHelper::applyExactness((yyvsp[(1) - (2)].exactValue), (yyvsp[(2) - (2)].object)); ;}
    break;

  case 62:
#line 204 "NumberReader.y"
    { (yyval.object) = Arithmetic::makePolar((yyvsp[(1) - (3)].object), (yyvsp[(3) - (3)].object)); ;}
    break;

  case 63:
#line 205 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), (yyvsp[(3) - (4)].object)); ;}
    break;

  case 64:
#line 206 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), Arithmetic::mul(-1, (yyvsp[(3) - (4)].object))); ;}
    break;

  case 65:
#line 207 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (3)].object), Object::makeFixnum(1)); ;}
    break;

  case 66:
#line 208 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (3)].object), Object::makeFixnum(-1)); ;}
    break;

  case 67:
#line 209 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), (yyvsp[(2) - (3)].object)); ;}
    break;

  case 68:
#line 210 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Arithmetic::mul(-1, (yyvsp[(2) - (3)].object))); ;}
    break;

  case 69:
#line 211 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Object::makeFixnum(1)); ;}
    break;

  case 70:
#line 212 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Object::makeFixnum(-1)); ;}
    break;

  case 71:
#line 213 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), (yyvsp[(3) - (4)].object)); ;}
    break;

  case 72:
#line 214 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), Arithmetic::mul(-1, (yyvsp[(3) - (4)].object))); ;}
    break;

  case 73:
#line 215 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), (yyvsp[(2) - (3)].object)); ;}
    break;

  case 74:
#line 216 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Arithmetic::mul(-1, (yyvsp[(2) - (3)].object))); ;}
    break;

  case 77:
#line 221 "NumberReader.y"
    { (yyval.object) = (yyvsp[(2) - (2)].object); ;}
    break;

  case 78:
#line 222 "NumberReader.y"
    { (yyval.object) = Arithmetic::mul(-1, (yyvsp[(2) - (2)].object)); ;}
    break;

  case 80:
#line 226 "NumberReader.y"
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
#line 236 "NumberReader.y"
    { (yyval.object) = (yyvsp[(2) - (2)].object); ;}
    break;

  case 82:
#line 237 "NumberReader.y"
    { (yyval.object) = Arithmetic::mul(-1, (yyvsp[(2) - (2)].object)); ;}
    break;

  case 83:
#line 240 "NumberReader.y"
    { (yyval.object) = Object::makeFixnum((yyvsp[(1) - (1)].intValue)); ;}
    break;

  case 84:
#line 241 "NumberReader.y"
    {
                (yyval.object) = Arithmetic::add(Arithmetic::mul(16, (yyvsp[(1) - (2)].object)), Object::makeFixnum((yyvsp[(2) - (2)].intValue)));
          ;}
    break;

  case 86:
#line 247 "NumberReader.y"
    { (yyval.intValue) = (yyvsp[(1) - (1)].intValue); ;}
    break;

  case 87:
#line 250 "NumberReader.y"
    { (yyval.object) = ScannerHelper::applyExactness((yyvsp[(1) - (2)].exactValue), (yyvsp[(2) - (2)].object)); ;}
    break;

  case 89:
#line 253 "NumberReader.y"
    { (yyval.object) = Arithmetic::makePolar((yyvsp[(1) - (3)].object), (yyvsp[(3) - (3)].object)); ;}
    break;

  case 90:
#line 254 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), (yyvsp[(3) - (4)].object)); ;}
    break;

  case 91:
#line 255 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), Arithmetic::mul(-1, (yyvsp[(3) - (4)].object))); ;}
    break;

  case 92:
#line 256 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (3)].object), Object::makeFixnum(1)); ;}
    break;

  case 93:
#line 257 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (3)].object), Object::makeFixnum(-1)); ;}
    break;

  case 94:
#line 258 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), (yyvsp[(2) - (3)].object)); ;}
    break;

  case 95:
#line 259 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Arithmetic::mul(-1, (yyvsp[(2) - (3)].object))); ;}
    break;

  case 96:
#line 260 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Object::makeFixnum(1)); ;}
    break;

  case 97:
#line 261 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Object::makeFixnum(-1)); ;}
    break;

  case 98:
#line 262 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), (yyvsp[(3) - (4)].object)); ;}
    break;

  case 99:
#line 263 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum((yyvsp[(1) - (4)].object), Arithmetic::mul(-1, (yyvsp[(3) - (4)].object))); ;}
    break;

  case 100:
#line 264 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), (yyvsp[(2) - (3)].object)); ;}
    break;

  case 101:
#line 265 "NumberReader.y"
    { (yyval.object) = Object::makeCompnum(Object::makeFixnum(0), Arithmetic::mul(-1, (yyvsp[(2) - (3)].object))); ;}
    break;

  case 104:
#line 270 "NumberReader.y"
    { (yyval.object) = (yyvsp[(2) - (2)].object); ;}
    break;

  case 105:
#line 271 "NumberReader.y"
    { (yyval.object) = Arithmetic::mul(-1, (yyvsp[(2) - (2)].object)); ;}
    break;

  case 107:
#line 275 "NumberReader.y"
    {
               bool isDiv0Error = false;
               (yyval.object) = Arithmetic::div((yyvsp[(1) - (3)].object), (yyvsp[(3) - (3)].object), isDiv0Error);
               if (isDiv0Error) {
                   yyerror("division by zero");
                   YYERROR;
               }
          ;}
    break;

  case 108:
#line 285 "NumberReader.y"
    { (yyval.object) = (yyvsp[(2) - (2)].object); ;}
    break;

  case 109:
#line 286 "NumberReader.y"
    { (yyval.object) = Arithmetic::mul(-1, (yyvsp[(2) - (2)].object)); ;}
    break;

  case 110:
#line 289 "NumberReader.y"
    {
              if ((yyvsp[(2) - (2)].stringValue).empty()) {
                  (yyval.object) = Bignum::makeInteger((yyvsp[(1) - (2)].stringValue));
              } else {
                (yyval.object) = Arithmetic::mul(Bignum::makeInteger((yyvsp[(1) - (2)].stringValue)), suffixToNumber((yyvsp[(2) - (2)].stringValue)));
              }
          ;}
    break;

  case 111:
#line 296 "NumberReader.y"
    {
              ucs4string ret = UC(".");
              ret += (yyvsp[(2) - (3)].stringValue);
              if (!(yyvsp[(3) - (3)].stringValue).empty()) {

                (yyval.object) = Arithmetic::mul(Flonum::fromString(ret), suffixToNumber((yyvsp[(3) - (3)].stringValue)));
              } else {
                  (yyval.object) = Flonum::fromString(ret);
              }

          ;}
    break;

  case 112:
#line 307 "NumberReader.y"
    {
              ucs4string ret = (yyvsp[(1) - (4)].stringValue);
              ret += UC(".") + (yyvsp[(3) - (4)].stringValue);
              if (!(yyvsp[(4) - (4)].stringValue).empty()) {
//                  VM_LOG2("from~a: ~a\n", Flonum::fromString(ret), suffixToNumber($4));
                (yyval.object) = Arithmetic::mul(Flonum::fromString(ret), suffixToNumber((yyvsp[(4) - (4)].stringValue)));
//                  VM_LOG1("$$~a: n", $$);
              } else {
                  (yyval.object) = Flonum::fromString(ret);
              }
          ;}
    break;

  case 113:
#line 318 "NumberReader.y"
    {
              ucs4string ret = (yyvsp[(1) - (3)].stringValue);
              ret += UC(".0");
              if (!(yyvsp[(3) - (3)].stringValue).empty()) {
                (yyval.object) = Arithmetic::mul(Flonum::fromString(ret), suffixToNumber((yyvsp[(3) - (3)].stringValue)));
              } else {
                  (yyval.object) = Flonum::fromString(ret);
              }
          ;}
    break;

  case 114:
#line 330 "NumberReader.y"
    { (yyval.object) = Bignum::makeInteger((yyvsp[(1) - (1)].stringValue)); ;}
    break;

  case 115:
#line 332 "NumberReader.y"
    {
                const ucs4char ch = '0' + (yyvsp[(1) - (1)].intValue);
                (yyval.stringValue) = UC("");
                (yyval.stringValue) += ch;
           ;}
    break;

  case 116:
#line 337 "NumberReader.y"
    {
               const ucs4char ch = '0' + (yyvsp[(2) - (2)].intValue);
               (yyval.stringValue) = (yyvsp[(1) - (2)].stringValue);
               (yyval.stringValue) += ch;
          ;}
    break;

  case 118:
#line 345 "NumberReader.y"
    { (yyval.intValue) = (yyvsp[(1) - (1)].intValue); ;}
    break;

  case 119:
#line 348 "NumberReader.y"
    { (yyval.exactValue) = 0; ;}
    break;

  case 120:
#line 349 "NumberReader.y"
    { (yyval.exactValue) = 1; ;}
    break;

  case 121:
#line 350 "NumberReader.y"
    { (yyval.exactValue) = -1; ;}
    break;

  case 122:
#line 353 "NumberReader.y"
    { (yyval.stringValue) = UC(""); ;}
    break;

  case 123:
#line 354 "NumberReader.y"
    {
              ucs4string ret = UC("e");
              ret += (yyvsp[(1) - (1)].stringValue).substr(1, (yyvsp[(1) - (1)].stringValue).size() - 1);
              (yyval.stringValue) = ret;
          ;}
    break;

  case 124:
#line 361 "NumberReader.y"
    { (yyval.exactValue) = (yyvsp[(2) - (2)].exactValue); ;}
    break;

  case 125:
#line 362 "NumberReader.y"
    { (yyval.exactValue) = (yyvsp[(1) - (2)].exactValue); ;}
    break;

  case 126:
#line 365 "NumberReader.y"
    { (yyval.exactValue) = (yyvsp[(2) - (2)].exactValue);;}
    break;

  case 127:
#line 366 "NumberReader.y"
    { (yyval.exactValue) = (yyvsp[(1) - (2)].exactValue);;}
    break;

  case 129:
#line 370 "NumberReader.y"
    { (yyval.exactValue) = (yyvsp[(2) - (2)].exactValue);;}
    break;

  case 130:
#line 371 "NumberReader.y"
    { (yyval.exactValue) = (yyvsp[(1) - (2)].exactValue);;}
    break;

  case 131:
#line 374 "NumberReader.y"
    { (yyval.exactValue) = (yyvsp[(2) - (2)].exactValue);;}
    break;

  case 132:
#line 375 "NumberReader.y"
    { (yyval.exactValue) = (yyvsp[(1) - (2)].exactValue);;}
    break;

  case 133:
#line 378 "NumberReader.y"
    { (yyval.object) = Flonum::NOT_A_NUMBER; ;}
    break;

  case 134:
#line 379 "NumberReader.y"
    { (yyval.object) = Flonum::POSITIVE_INF; ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2253 "NumberReader.tab.cpp"
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


#line 380 "NumberReader.y"


extern ucs4char* token;
int number_yyerror(char const *str)
{
    TextualInputPort* const port = Reader::port();
    port->setError(format(NULL, UC("~a near [~a] at ~a:~d. "),
                          Pair::list4(str, Object::makeString(port->scanner()->currentToken()), port->toString(), Object::makeFixnum(port->getLineNo()))));
    return 0;
}

