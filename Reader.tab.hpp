
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     SCHEME_BOOLEAN = 259,
     STRING = 260,
     CHARACTER = 261,
     CHARACTER_NAME = 262,
     REGEXP = 263,
     NUMBER = 264,
     NUMBER2 = 265,
     NUMBER8 = 266,
     NUMBER10 = 267,
     NUMBER16 = 268,
     LEFT_PAREN = 269,
     RIGHT_PAREN = 270,
     END_OF_FILE = 271,
     VECTOR_START = 272,
     BYTE_VECTOR_START = 273,
     DOT = 274,
     DATUM_COMMENT = 275,
     ABBV_QUASIQUOTE = 276,
     ABBV_QUOTE = 277,
     ABBV_UNQUOTESPLICING = 278,
     ABBV_UNQUOTE = 279,
     ABBV_SYNTAX = 280,
     ABBV_QUASISYNTAX = 281,
     ABBV_UNSYNTAXSPLICING = 282,
     ABBV_UNSYNTAX = 283
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif




