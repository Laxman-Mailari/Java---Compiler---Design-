/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     T_NUM = 258,
     T_FNUM = 259,
     T_IMPORT = 260,
     T_CLASS = 261,
     T_PUBLIC = 262,
     T_PRIVATE = 263,
     T_PROTECTED = 264,
     T_STATIC = 265,
     T_VOID = 266,
     T_MAIN = 267,
     T_NEW = 268,
     T_RETURN = 269,
     T_BREAK = 270,
     T_BOOL = 271,
     T_SHORT = 272,
     T_BYTE = 273,
     T_CHAR = 274,
     T_INT = 275,
     T_FLOAT = 276,
     T_LONG = 277,
     T_DOUBLE = 278,
     T_ID = 279,
     T_STRVAL = 280,
     T_LOR = 281,
     T_LAND = 282,
     T_NOT = 283,
     T_STR_ARG = 284,
     T_STR = 285,
     T_STDOUT = 286,
     T_IF = 287,
     T_ELSE = 288,
     T_WHILE = 289,
     T_FOR = 290,
     T_DO = 291,
     T_TRUE = 292,
     T_FALSE = 293,
     T_U_INCR = 294,
     T_U_DECR = 295,
     T_OFB = 296,
     T_CFB = 297,
     T_S_PLUSEQ = 298,
     T_S_MINUSEQ = 299,
     T_S_MULTEQ = 300,
     T_S_DIVEQ = 301,
     T_S_DIV = 302,
     T_S_EQ = 303,
     S_DIV = 304,
     T_ = 305,
     T_S_MULT = 306,
     T_S_MINUS = 307,
     T_S_PLUS = 308,
     T_NE = 309,
     T_ASSG = 310,
     T_GE = 311,
     T_LE = 312,
     T_LEQ = 313,
     T_GEQ = 314
   };
#endif
/* Tokens.  */
#define T_NUM 258
#define T_FNUM 259
#define T_IMPORT 260
#define T_CLASS 261
#define T_PUBLIC 262
#define T_PRIVATE 263
#define T_PROTECTED 264
#define T_STATIC 265
#define T_VOID 266
#define T_MAIN 267
#define T_NEW 268
#define T_RETURN 269
#define T_BREAK 270
#define T_BOOL 271
#define T_SHORT 272
#define T_BYTE 273
#define T_CHAR 274
#define T_INT 275
#define T_FLOAT 276
#define T_LONG 277
#define T_DOUBLE 278
#define T_ID 279
#define T_STRVAL 280
#define T_LOR 281
#define T_LAND 282
#define T_NOT 283
#define T_STR_ARG 284
#define T_STR 285
#define T_STDOUT 286
#define T_IF 287
#define T_ELSE 288
#define T_WHILE 289
#define T_FOR 290
#define T_DO 291
#define T_TRUE 292
#define T_FALSE 293
#define T_U_INCR 294
#define T_U_DECR 295
#define T_OFB 296
#define T_CFB 297
#define T_S_PLUSEQ 298
#define T_S_MINUSEQ 299
#define T_S_MULTEQ 300
#define T_S_DIVEQ 301
#define T_S_DIV 302
#define T_S_EQ 303
#define S_DIV 304
#define T_ 305
#define T_S_MULT 306
#define T_S_MINUS 307
#define T_S_PLUS 308
#define T_NE 309
#define T_ASSG 310
#define T_GE 311
#define T_LE 312
#define T_LEQ 313
#define T_GEQ 314




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 69 "java-yacc.y"
{
    	int number;
      float fnumber;
    	char *string;
      struct Node *block;
}
/* Line 1529 of yacc.c.  */
#line 174 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

