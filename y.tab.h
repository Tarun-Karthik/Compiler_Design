/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
    INT = 258,
    FLOAT = 259,
    VOID = 260,
    CHAR = 261,
    VARCHAR = 262,
    DIGIT = 263,
    FDIGIT = 264,
    STRING = 265,
    PREPROCESSOR = 266,
    HEADER = 267,
    KEYWORDS = 268,
    LINE = 269,
    FUNCTION = 270,
    SPACE = 271,
    COMMA = 272,
    LESS = 273,
    S_ADD = 274,
    FOR = 275,
    QUOT = 276,
    OPENBC = 277,
    CLOSEBC = 278,
    POINTER = 279,
    ARRAY = 280,
    DEFINE = 281,
    CCBRACE = 282,
    OCBRACE = 283,
    MAIN = 284,
    S_SUB = 285,
    PRINTF = 286,
    ASSIGNMENT = 287,
    PLUS = 288,
    MINUS = 289,
    MULTIPLY = 290,
    DIVIDE = 291,
    MODULO = 292,
    INCREMENT = 293,
    DECREMENT = 294,
    S_MUL = 295,
    NEGDIGIT = 296,
    ADD_ASSIGN = 297,
    SUB_ASSIGN = 298,
    MUL_ASSIGN = 299,
    DIV_ASSIGN = 300,
    MOD_ASSIGN = 301,
    WHILE = 302,
    RETURN = 303,
    S_DIV = 304,
    SEMICOLON = 305,
    IF = 306,
    ELSE = 307,
    LESS_EQUAL = 308,
    MORE_EQUAL = 309,
    MORE = 310,
    EQUAL = 311,
    NOT_EQUAL = 312,
    CHARLIT = 313,
    OSBRACE = 314,
    CSBRACE = 315
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define VOID 260
#define CHAR 261
#define VARCHAR 262
#define DIGIT 263
#define FDIGIT 264
#define STRING 265
#define PREPROCESSOR 266
#define HEADER 267
#define KEYWORDS 268
#define LINE 269
#define FUNCTION 270
#define SPACE 271
#define COMMA 272
#define LESS 273
#define S_ADD 274
#define FOR 275
#define QUOT 276
#define OPENBC 277
#define CLOSEBC 278
#define POINTER 279
#define ARRAY 280
#define DEFINE 281
#define CCBRACE 282
#define OCBRACE 283
#define MAIN 284
#define S_SUB 285
#define PRINTF 286
#define ASSIGNMENT 287
#define PLUS 288
#define MINUS 289
#define MULTIPLY 290
#define DIVIDE 291
#define MODULO 292
#define INCREMENT 293
#define DECREMENT 294
#define S_MUL 295
#define NEGDIGIT 296
#define ADD_ASSIGN 297
#define SUB_ASSIGN 298
#define MUL_ASSIGN 299
#define DIV_ASSIGN 300
#define MOD_ASSIGN 301
#define WHILE 302
#define RETURN 303
#define S_DIV 304
#define SEMICOLON 305
#define IF 306
#define ELSE 307
#define LESS_EQUAL 308
#define MORE_EQUAL 309
#define MORE 310
#define EQUAL 311
#define NOT_EQUAL 312
#define CHARLIT 313
#define OSBRACE 314
#define CSBRACE 315

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 32 "project1.y" /* yacc.c:1909  */

		int ival;
		char *str;

#line 179 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
