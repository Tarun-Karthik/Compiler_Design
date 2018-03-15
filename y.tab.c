/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 2 "project1.y" /* yacc.c:339  */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include "main.c"
extern FILE* yyin;
extern FILE* yyout;

extern char *temp;
extern  int i,j;
extern  int count ;
int yylineno;
int yyerror(char *);
int yylex(void);

int g_addr = 100;
int i=1;
int j=8;
int stack[100];
int index1=0;
int end[100];
int arr[10];
int gl1,gl2,ct=0,c=0,b;

#line 92 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 32 "project1.y" /* yacc.c:355  */

		int ival;
		char *str;

#line 257 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 274 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   234

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  42
/* YYNRULES -- Number of rules.  */
#define YYNRULES  108
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  192

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   315

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    55,    55,    56,    57,    60,    63,    83,    86,    88,
      89,    93,    97,   101,   102,   103,   104,   108,   111,   113,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   129,
     132,   134,   136,   140,   141,   167,   178,   184,   188,   189,
     190,   191,   192,   193,   196,   211,   216,   217,   222,   227,
     228,   231,   232,   233,   237,   241,   245,   246,   250,   252,
     254,   255,   259,   261,   263,   264,   267,   269,   270,   273,
     275,   278,   280,   281,   286,   287,   290,   291,   294,   295,
     299,   304,   305,   306,   307,   308,   309,   310,   315,   316,
     317,   318,   321,   322,   325,   326,   330,   336,   339,   340,
     341,   342,   343,   344,   348,   352,   353,   354,   355
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "VOID", "CHAR",
  "VARCHAR", "DIGIT", "FDIGIT", "STRING", "PREPROCESSOR", "HEADER",
  "KEYWORDS", "LINE", "FUNCTION", "SPACE", "COMMA", "LESS", "S_ADD", "FOR",
  "QUOT", "OPENBC", "CLOSEBC", "POINTER", "ARRAY", "DEFINE", "CCBRACE",
  "OCBRACE", "MAIN", "S_SUB", "PRINTF", "ASSIGNMENT", "PLUS", "MINUS",
  "MULTIPLY", "DIVIDE", "MODULO", "INCREMENT", "DECREMENT", "S_MUL",
  "NEGDIGIT", "ADD_ASSIGN", "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN",
  "MOD_ASSIGN", "WHILE", "RETURN", "S_DIV", "SEMICOLON", "IF", "ELSE",
  "LESS_EQUAL", "MORE_EQUAL", "MORE", "EQUAL", "NOT_EQUAL", "CHARLIT",
  "OSBRACE", "CSBRACE", "$accept", "program", "pre_pro", "funcdef", "args",
  "var_def_list", "var_def_list_extension", "var_def", "types",
  "block_statement", "statements", "statement", "print_statement",
  "in_print", "in_print_ext", "declaration_statement", "assignment",
  "assignment1", "id_list", "id_list_1", "function_call",
  "conditional_statement", "elsest", "while_st", "while_st_ext", "for_st",
  "for_st_ext", "condition1", "condition2", "condition3", "_inc_decre",
  "_inc", "_dec", "conditions", "int_cond", "assignment_statement",
  "int_ass", "char_ass", "ret_statement", "int_expression",
  "char_expression", "expression_list", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315
};
# endif

#define YYPACT_NINF -85

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-85)))

#define YYTABLE_NINF -96

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     169,   -85,   -85,   -85,   -85,    -5,   193,   169,   -85,    19,
     -85,   -85,   -85,   197,    27,   197,    43,    41,    60,   104,
     109,   -85,   -85,   197,   -85,   -85,   -85,    91,   -85,    51,
      59,    90,     4,    93,   178,   -85,   116,   109,   -85,    92,
      98,   105,   -85,   -85,   -85,   115,   -85,   -85,   120,    39,
     -85,    99,   136,     9,    99,    33,   168,   117,   -85,   -85,
     171,   117,    -7,   180,   -85,   191,   -85,   -85,   -85,   -85,
     -85,   -85,   -85,    99,   117,   117,   117,   117,    16,   -85,
     -85,   171,    44,   199,   -85,    39,   -85,   150,    88,   -85,
     161,   -85,   195,   186,   187,    80,   171,   188,   185,    74,
     151,   -85,   184,   -85,   -85,   141,   141,   -85,   -85,    99,
     159,   -85,   196,   170,   117,   211,   -85,   172,    -8,   117,
     117,   117,   117,   117,   117,    43,   -12,   191,   118,   202,
      26,   163,   128,    74,   -85,   171,   -85,   -85,   174,   -85,
     195,   -85,   -85,   -85,   -85,   171,   171,   171,   171,   171,
     171,   173,    74,   -85,   -85,   -85,   151,   117,   151,   176,
     151,   171,   -85,    12,   -85,    43,   -85,   171,   -85,   171,
     -85,   -85,   -85,   156,    12,   214,   220,   201,    12,   -85,
     -85,   -85,   -85,   -85,   -85,   -85,   -85,    38,   -85,   -85,
     -85,   -85
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    13,    15,    16,    14,     0,     0,     0,     3,     0,
       5,     1,     2,     4,     0,     8,     0,     0,     9,     0,
       0,     6,     7,     0,    10,    12,    91,    99,    98,     0,
       0,     0,     0,     0,     0,    20,     0,     0,    21,     0,
       0,     0,    22,    23,    24,     0,    88,    89,     0,    48,
      11,     0,     0,     0,     0,     0,     0,     0,    99,    97,
      96,     0,    52,     0,    33,    52,    17,    19,    26,    35,
      27,    25,    28,     0,     0,     0,     0,     0,    99,    45,
     108,   107,     0,     0,    44,    48,    95,     0,    99,    67,
       0,    68,    31,     0,     0,    80,    87,     0,     0,    90,
       0,    49,     0,    50,    46,   100,   101,   102,   103,     0,
       0,    54,     0,     0,    69,     0,    30,     0,    59,     0,
       0,     0,     0,     0,     0,     0,    52,    52,    93,    94,
      99,     0,    43,    90,   106,   105,   104,    37,     0,    70,
      31,    29,    61,    60,    58,    81,    82,    83,    84,    86,
      85,    57,     0,    51,    53,    34,     0,     0,     0,     0,
       0,    92,    94,    71,    32,     0,    55,    93,    40,    38,
      39,    36,    41,     0,    71,     0,     0,     0,    71,    74,
      75,    56,    76,    78,    73,    77,    79,    63,    72,    64,
      65,    62
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -85,   222,   -85,    72,   -85,   -85,   -85,   207,    -2,   -16,
     194,   -85,   -85,   -85,    94,   177,   -59,   -45,   -85,   -64,
     -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   -85,   -74,
     -85,   -85,   -85,   -57,   -85,   -31,   -85,   -85,   -85,   -30,
     -84,   -85
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,    16,    17,    24,    18,     9,    35,
      36,    37,    38,    93,   116,    39,   131,    40,    64,   101,
      41,    42,   166,    43,   144,    44,   191,    90,   138,   177,
     178,   179,   180,    94,    95,    45,    46,    47,    48,    49,
      86,    82
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      21,   103,    60,    65,    97,    98,    79,    10,    84,    87,
      98,    58,    28,    19,    20,   129,    78,    28,    34,   173,
     152,    19,    81,    85,    91,    99,    14,    96,   104,   174,
      83,    96,    63,    51,    26,    34,     1,     2,     3,     4,
      88,    28,   142,   156,   105,   106,   107,   108,   109,   162,
     175,   176,   100,    34,    59,    15,    73,   139,   157,   158,
      20,   110,   153,   154,    84,    20,   -47,   127,    22,   128,
     132,   111,    74,    75,    76,    77,   -47,    23,    12,    55,
     135,    58,    28,   -66,    96,    12,   -42,    56,   189,   145,
     146,   147,   148,   149,   150,    83,    63,   168,   119,   170,
     184,   172,   143,   161,   188,    51,    78,    28,    51,   151,
      26,    25,     1,     2,     3,     4,    27,    28,    57,    52,
      53,    61,   167,    53,    58,    28,   132,   169,   132,    29,
     132,    20,   -18,   120,   121,   122,   123,   124,   -47,    66,
      30,   -47,    68,    58,    28,   160,    80,    54,    69,   181,
      54,    74,    75,    76,    77,    70,    31,    32,   130,    28,
      33,    74,    75,    76,    77,    71,    58,    28,   155,   134,
      72,   190,     1,     2,     3,     4,    76,    77,    92,    26,
       5,     1,     2,     3,     4,    62,    26,   102,     1,     2,
       3,     4,   126,    11,   182,   183,     1,     2,     3,     4,
       1,     2,     3,     4,    74,    75,    76,    77,    98,   112,
     113,   114,   115,   117,   118,   125,   133,   136,   140,   -95,
     137,   185,   141,   159,   163,   165,   171,   186,   187,    13,
      50,    67,    89,     0,   164
};

static const yytype_int16 yycheck[] =
{
      16,    65,    32,    34,    61,    17,    51,    12,    53,    54,
      17,     7,     8,    15,    22,    99,     7,     8,    20,     7,
      32,    23,    52,    53,    55,    32,     7,    57,    73,    17,
      21,    61,    34,    17,     1,    37,     3,     4,     5,     6,
       7,     8,    50,    17,    74,    75,    76,    77,    32,   133,
      38,    39,    59,    55,    50,    28,    17,   114,    32,    33,
      22,    17,   126,   127,   109,    22,    50,    98,    27,    99,
     100,    27,    33,    34,    35,    36,    60,    17,     6,    28,
     110,     7,     8,    50,   114,    13,    60,    28,    50,   119,
     120,   121,   122,   123,   124,    21,    98,   156,    18,   158,
     174,   160,   118,   133,   178,    17,     7,     8,    17,   125,
       1,     7,     3,     4,     5,     6,     7,     8,    28,    28,
      32,    28,   152,    32,     7,     8,   156,   157,   158,    20,
     160,    22,    23,    53,    54,    55,    56,    57,    50,    23,
      31,    50,    50,     7,     8,    17,    10,    59,    50,   165,
      59,    33,    34,    35,    36,    50,    47,    48,     7,     8,
      51,    33,    34,    35,    36,    50,     7,     8,    50,    10,
      50,   187,     3,     4,     5,     6,    35,    36,    10,     1,
      11,     3,     4,     5,     6,     7,     1,     7,     3,     4,
       5,     6,     7,     0,    38,    39,     3,     4,     5,     6,
       3,     4,     5,     6,    33,    34,    35,    36,    17,    10,
      60,    50,    17,    27,    27,    27,    32,    21,     7,    17,
      50,     7,    50,    60,    50,    52,    50,     7,    27,     7,
      23,    37,    55,    -1,   140
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,    11,    62,    63,    64,    69,
      12,     0,    64,    62,     7,    28,    65,    66,    68,    69,
      22,    70,    27,    17,    67,     7,     1,     7,     8,    20,
      31,    47,    48,    51,    69,    70,    71,    72,    73,    76,
      78,    81,    82,    84,    86,    96,    97,    98,    99,   100,
      68,    17,    28,    32,    59,    28,    28,    28,     7,    50,
     100,    28,     7,    69,    79,    96,    23,    71,    50,    50,
      50,    50,    50,    17,    33,    34,    35,    36,     7,    78,
      10,   100,   102,    21,    78,   100,   101,    78,     7,    76,
      88,    96,    10,    74,    94,    95,   100,    94,    17,    32,
      59,    80,     7,    80,    78,   100,   100,   100,   100,    32,
      17,    27,    10,    60,    50,    17,    75,    27,    27,    18,
      53,    54,    55,    56,    57,    27,     7,    96,   100,   101,
       7,    77,   100,    32,    10,   100,    21,    50,    89,    94,
       7,    50,    50,    70,    85,   100,   100,   100,   100,   100,
     100,    70,    32,    80,    80,    50,    17,    32,    33,    60,
      17,   100,   101,    50,    75,    52,    83,   100,    77,   100,
      77,    50,    77,     7,    17,    38,    39,    90,    91,    92,
      93,    70,    38,    39,    90,     7,     7,    27,    90,    50,
      70,    87
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    61,    62,    62,    62,    63,    64,    65,    66,    66,
      66,    67,    68,    69,    69,    69,    69,    70,    71,    71,
      72,    72,    72,    72,    72,    72,    72,    72,    72,    73,
      74,    75,    75,    76,    76,    76,    76,    76,    77,    77,
      77,    77,    77,    77,    78,    78,    78,    78,    78,    79,
      79,    80,    80,    80,    81,    82,    83,    83,    84,    85,
      85,    85,    86,    87,    87,    87,    88,    88,    88,    89,
      89,    90,    90,    90,    91,    91,    92,    92,    93,    93,
      94,    95,    95,    95,    95,    95,    95,    95,    96,    96,
      96,    96,    97,    97,    98,    98,    99,    99,   100,   100,
     100,   100,   100,   100,   101,   102,   102,   102,   102
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     2,     2,     4,     3,     0,     1,
       2,     2,     2,     1,     1,     1,     1,     3,     0,     2,
       1,     1,     1,     1,     1,     2,     2,     2,     2,     5,
       2,     0,     3,     2,     5,     2,     6,     5,     3,     3,
       3,     3,     1,     1,     3,     3,     3,     1,     1,     2,
       2,     3,     0,     3,     4,     6,     2,     0,     5,     0,
       1,     1,     9,     0,     1,     1,     0,     1,     1,     0,
       1,     0,     2,     2,     1,     1,     2,     2,     2,     2,
       1,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       3,     1,     4,     3,     4,     3,     2,     2,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:
#line 64 "project1.y" /* yacc.c:1646  */
    {
                if ((yyvsp[-3].ival)!=returntype_func(ct))
	               {
		                printf("\nError : Type mismatch : Line %d\n",printline());
	               }

	              if (!(strcmp((yyvsp[-2].str),"printf") && strcmp((yyvsp[-2].str),"scanf")))
		                printf("Error : Type mismatch in redeclaration of %s : Line %d\n",(yyvsp[-2].str),printline());
	              else
	               {
		                  insert((yyvsp[-2].str),FUNCTION,g_addr);
		                  insert((yyvsp[-2].str),(yyvsp[-3].ival),g_addr);
		                  g_addr+=4;
	               }
	    }
#line 1523 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 142 "project1.y" /* yacc.c:1646  */
    {
		          if( (!(strspn((yyvsp[-1].str),"0123456789")==strlen((yyvsp[-1].str)))) && (yyvsp[-4].ival)==258)
			           printf("\nError : Type Mismatch : Line %d\n",printline());
		          if(!lookup((yyvsp[-3].str)))
		            {
			             int currscope=stack[index1-1];
			             int previous_scope=returnscope((yyvsp[-3].str),currscope);
			             if(currscope==previous_scope)
				               printf("\nError : Redeclaration of %s : Line %d\n",(yyvsp[-3].str),printline());
			             else
			                {
				                 insert_dup((yyvsp[-3].str),(yyvsp[-4].ival),g_addr,currscope);
				                 check_scope_update((yyvsp[-3].str),(yyvsp[-1].str),stack[index1-1]);
				                 g_addr+=4;
			                }
		             }
		           else
		             {
			             int scope=stack[index1-1];
			             insert((yyvsp[-3].str),(yyvsp[-4].ival),g_addr);
			             insertscope((yyvsp[-3].str),scope);
			             check_scope_update((yyvsp[-3].str),(yyvsp[-1].str),stack[index1-1]);
			             g_addr+=4;
		             }
            }
#line 1553 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 167 "project1.y" /* yacc.c:1646  */
    {
				        if(!lookup((yyvsp[-1].str)))
				            {
					               int currscope=stack[index1-1];
					               int scope=returnscope((yyvsp[-1].str),currscope);
				                 if(!(scope<=currscope && end[scope]==0) || scope==0)
						                 printf("\nError : Variable %s out of scope : Line %d\n",(yyvsp[-1].str),printline());
				            }
				            else
			               		printf("\nError : Undeclared Variable %s : Line %d\n",(yyvsp[-1].str),printline());
				            }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 179 "project1.y" /* yacc.c:1646  */
    {
        						insert((yyvsp[-4].str),ARRAY,g_addr);
        						insert((yyvsp[-4].str),(yyvsp[-5].ival),g_addr);
        						g_addr+=4;
        					}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 197 "project1.y" /* yacc.c:1646  */
    {
		            int sct=returnscope((yyvsp[-2].str),stack[index1-1]);
		            int type=returntype((yyvsp[-2].str),sct);
		            if((!(strspn((yyvsp[0].str),"0123456789")==strlen((yyvsp[0].str)))) && type==258)
			                 printf("\nError : Type Mismatch : Line %d\n",printline());
		                   if(!lookup((yyvsp[-2].str)))
		                       {
			                        int currscope=stack[index1-1];
			                        int scope=returnscope((yyvsp[-2].str),currscope);
			                        if((scope<=currscope && end[scope]==0) && !(scope==0))
				                            check_scope_update((yyvsp[-2].str),(yyvsp[0].str),currscope);
		                       }
              }
#line 1597 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 212 "project1.y" /* yacc.c:1646  */
    {
					         if(lookup((yyvsp[-2].str)))
						             printf("\nUndeclared Variable %s : Line %d\n",(yyvsp[-2].str),printline());
				      }
#line 1606 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 218 "project1.y" /* yacc.c:1646  */
    {
 		               if(lookup((yyvsp[0].str)))
			                printf("\nUndeclared Variable %s : Line %d\n",(yyvsp[0].str),printline());
		              }
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 317 "project1.y" /* yacc.c:1646  */
    {  }
#line 1621 "y.tab.c" /* yacc.c:1646  */
    break;

  case 96:
#line 330 "project1.y" /* yacc.c:1646  */
    {
                if(!(strspn((yyvsp[0].str),"0123456789")==strlen((yyvsp[0].str))))
						          storereturn(ct,FLOAT);
					      else
						          storereturn(ct,INT); ct++;
              }
#line 1632 "y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 336 "project1.y" /* yacc.c:1646  */
    {storereturn(ct,VOID); ct++;}
#line 1638 "y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 348 "project1.y" /* yacc.c:1646  */
    { }
#line 1644 "y.tab.c" /* yacc.c:1646  */
    break;


#line 1648 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 360 "project1.y" /* yacc.c:1906  */


int yyerror(char *s) {
    fprintf(stderr , "%s\n", s);
    exit(0);
}

int printline()
{
  return yylineno;
}

 void open1()
 {
  stack[index1] = i;
  i++;
  index1++;
  return;
 }

 void close1()
 {
  index1--;
  end[stack[index1]]=1;
  stack[index1]=0;
  return;
 }

int main()
{
  yyin = fopen("program25.txt","r");
  FILE *file= fopen("Symbol_Table.txt", "w");
  yyout= file;

  yyparse();
  printf("\nProgram parsed successfully.\n");
  Display();
  fclose(yyout);
  fclose(yyin);
}
