%union{

      char *intval;
      char *floatval;
      char *stringval;
      struct Symbol_Table *symp;
}
%{
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
%}

/* Decleration*/
%token PREPROCESSOR HEADER KEYWORDS LINE SPACE COMMA LESS VOID S_ADD INT CHAR FLOAT FOR QUOT
%token OPENBC CLOSEBC POINTER ARRAY DEFINE CCBRACE OCBRACE MAIN S_SUB VARCHAR
%token ASSIGNMENT PLUS MINUS MULTIPLY DIVIDE MODULO INCREMENT DECREMENT S_MUL
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN WHILE RETURN S_DIV
%token SEMICOLON IF ELSE LESS_EQUAL MORE_EQUAL MORE EQUAL NOT_EQUAL
%left PLUS MINUS
%left MULTIPLY DIVIDE



%token <intval> DIGIT
%token <floatval> FDIGIT
%token <stringval> STRING


%%
    /* Rules*/

    program
            : program funcdef
            | funcdef
            ;

    funcdef
            : VOID MAIN args block_statement      { printf("here\n");}
            | types VARCHAR args block_statement
            ;


    args
            :OCBRACE var_def_list CCBRACE
            ;

    var_def_list
            :
            | var_def
            | var_def var_def_list_extension
            ;

    var_def_list_extension
            : COMMA var_def
            ;

    var_def
            : types VARCHAR
            ;

    types
            : INT
            | CHAR
            | FLOAT
            ;

    block_statement
            : OPENBC statements CLOSEBC 
            ;

    statements
            :
            | statement statements
            ;

    statement
            : block_statement
            | conditional_statement
            | while_st
            | for_st
            | assignment_statement SEMICOLON
            | declaration_statement SEMICOLON
            | function_call SEMICOLON
            | ret_statement SEMICOLON
            ;

    declaration_statement
            : types id_list
            ;

   id_list
            : VARCHAR id_list_1
            ;
  id_list_1
            : COMMA VARCHAR id_list_1
            |
            ;

    function_call
            : VARCHAR OCBRACE expression_list CCBRACE
            ;

    conditional_statement
            : IF OCBRACE conditions CCBRACE block_statement elsest
            ;

    elsest
            : ELSE block_statement
            |
            ;

   while_st
            : WHILE OCBRACE conditions CCBRACE block_statement
            ;

   for_st
            :for_woin
            |for_wocon
            |for_wodec
            | FOR OCBRACE INT VARCHAR SEMICOLON conditions SEMICOLON _inc_decre CCBRACE block_statement
            ;

  for_wodec
            : FOR OCBRACE SEMICOLON conditions SEMICOLON _inc_decre CCBRACE block_statement
            ;

  for_wocon
            : FOR OCBRACE SEMICOLON SEMICOLON _inc_decre CCBRACE block_statement
            ;

  for_woin
            : FOR OCBRACE INT VARCHAR SEMICOLON conditions SEMICOLON  CCBRACE block_statement
            ;

  _inc_decre
            :_inc
            |_dec
            ;
  _inc
            : VARCHAR INCREMENT
            | INCREMENT VARCHAR
            ;
  _dec
            : VARCHAR DECREMENT
            | DECREMENT VARCHAR
            ;

   conditions
            : int_cond
            ;


  int_cond
            : int_cond LESS int_expression
            | int_cond LESS_EQUAL int_expression
            | int_cond MORE_EQUAL int_expression
            | int_cond MORE int_expression
            | int_cond NOT_EQUAL int_expression
            | int_cond EQUAL int_expression
            | int_expression
            ;


  assignment_statement
              : int_ass
              | char_ass
              | types VARCHAR ASSIGNMENT {  }
              | error
              ;
    int_ass
              :types VARCHAR ASSIGNMENT int_expression
              | VARCHAR ASSIGNMENT int_expression
              ;
    char_ass
              :types VARCHAR ASSIGNMENT char_expression
              | VARCHAR ASSIGNMENT char_expression
              ;

  ret_statement
              : RETURN int_expression {  }
              ;
  int_expression
                : DIGIT
                | VARCHAR
                | int_expression PLUS int_expression
                | int_expression MINUS int_expression
                | int_expression MULTIPLY int_expression
                | int_expression DIVIDE int_expression
                | OCBRACE int_expression CCBRACE
                ;

  char_expression
                : QUOT STRING QUOT { }
                ;

  expression_list
                : expression_list COMMA int_expression
                | expression_list COMMA STRING
                | int_expression
                | STRING
                ;



%%

int yyerror(char *s) {
    fprintf(stderr , "%s on line %i.\n", s, yylineno);
    exit(0);
}

int main()
{
  yyin = fopen("program2.txt","r");
  FILE *file= fopen("Symbol_Table.txt", "w");
  yyout= file;

  yyparse();
  printf("\nProgram parsed successfully.\n");
  fclose(yyout);
  fclose(yyin);
}