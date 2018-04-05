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
    ARRAY = 262,
    FUNCTION = 263,
    FDIGIT = 264,
    NDIGIT = 265,
    VARCHAR = 266,
    LITERAL = 267,
    LESS_EQUAL = 268,
    MORE_EQUAL = 269,
    MORE = 270,
    EQUAL = 271,
    NOT_EQUAL = 272,
    LESS = 273,
    DIGIT = 274,
    PREPROCESSOR = 275,
    HEADER = 276,
    KEYWORDS = 277,
    SPACE = 278,
    COMMA = 279,
    S_ADD = 280,
    FOR = 281,
    QUOT = 282,
    OPENBC = 283,
    CLOSEBC = 284,
    POINTER = 285,
    DEFINE = 286,
    S_SUB = 287,
    PRINTF = 288,
    MODULO = 289,
    INCREMENT = 290,
    DECREMENT = 291,
    S_MUL = 292,
    NEGDIGIT = 293,
    STRING = 294,
    ADD_ASSIGN = 295,
    SUB_ASSIGN = 296,
    MUL_ASSIGN = 297,
    DIV_ASSIGN = 298,
    MOD_ASSIGN = 299,
    WHILE = 300,
    RETURN = 301,
    S_DIV = 302,
    SEMICOLON = 303,
    IF = 304,
    ELSE = 305,
    CHARLIT = 306,
    OSBRACE = 307,
    CSBRACE = 308,
    PLUS = 309,
    MINUS = 310,
    MULTIPLY = 311,
    DIVIDE = 312,
    ASSIGNMENT = 313
  };
#endif
/* Tokens.  */
#define INT 258
#define FLOAT 259
#define VOID 260
#define CHAR 261
#define ARRAY 262
#define FUNCTION 263
#define FDIGIT 264
#define NDIGIT 265
#define VARCHAR 266
#define LITERAL 267
#define LESS_EQUAL 268
#define MORE_EQUAL 269
#define MORE 270
#define EQUAL 271
#define NOT_EQUAL 272
#define LESS 273
#define DIGIT 274
#define PREPROCESSOR 275
#define HEADER 276
#define KEYWORDS 277
#define SPACE 278
#define COMMA 279
#define S_ADD 280
#define FOR 281
#define QUOT 282
#define OPENBC 283
#define CLOSEBC 284
#define POINTER 285
#define DEFINE 286
#define S_SUB 287
#define PRINTF 288
#define MODULO 289
#define INCREMENT 290
#define DECREMENT 291
#define S_MUL 292
#define NEGDIGIT 293
#define STRING 294
#define ADD_ASSIGN 295
#define SUB_ASSIGN 296
#define MUL_ASSIGN 297
#define DIV_ASSIGN 298
#define MOD_ASSIGN 299
#define WHILE 300
#define RETURN 301
#define S_DIV 302
#define SEMICOLON 303
#define IF 304
#define ELSE 305
#define CHARLIT 306
#define OSBRACE 307
#define CSBRACE 308
#define PLUS 309
#define MINUS 310
#define MULTIPLY 311
#define DIVIDE 312
#define ASSIGNMENT 313

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 193 "project1.y" /* yacc.c:1909  */

		int ival;
		char *str;

#line 175 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
