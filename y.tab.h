/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    MYNUM = 258,
    MYID = 259,
    STRING = 260,
    MYINT = 261,
    MYVOID = 262,
    MYBOOLEAN = 263,
    MYTRUE = 264,
    MYFALSE = 265,
    MYBEG = 266,
    MYEND = 267,
    MYIF = 268,
    MYTHEN = 269,
    MYELSE = 270,
    MYWHILE = 271,
    MYDO = 272,
    MYRETURN = 273,
    MYREAD = 274,
    MYWRITE = 275,
    MYAND = 276,
    MYOR = 277,
    MYNOT = 278,
    EQ = 279,
    LT = 280,
    QT = 281,
    NE = 282
  };
#endif
/* Tokens.  */
#define MYNUM 258
#define MYID 259
#define STRING 260
#define MYINT 261
#define MYVOID 262
#define MYBOOLEAN 263
#define MYTRUE 264
#define MYFALSE 265
#define MYBEG 266
#define MYEND 267
#define MYIF 268
#define MYTHEN 269
#define MYELSE 270
#define MYWHILE 271
#define MYDO 272
#define MYRETURN 273
#define MYREAD 274
#define MYWRITE 275
#define MYAND 276
#define MYOR 277
#define MYNOT 278
#define EQ 279
#define LT 280
#define QT 281
#define NE 282

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 60 "lab9.y" /* yacc.c:1921  */

int value;
char *string;
struct ASTnodetype *node;
enum ASTtype op;
enum OPERATORS operator;

#line 120 "y.tab.h" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
