
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

int g_addr = 100;
int i=1;
int j=8;
int stack[100];
int index1=0;
int end[100];
int arr[10];
int gl1,gl2,ct=0,c=0,b;
%}
%type<ival> types
%type<str> assignment assignment1 int_expression
%token<ival> INT FLOAT VOID CHAR
%token<str> VARCHAR DIGIT FDIGIT
%token<str> STRING
%union {
		int ival;
		char *str;
}

/* Decleration*/
%token PREPROCESSOR HEADER KEYWORDS LINE  FUNCTION SPACE COMMA LESS S_ADD FOR QUOT
%token OPENBC CLOSEBC POINTER ARRAY DEFINE CCBRACE OCBRACE MAIN S_SUB  PRINTF
%token ASSIGNMENT PLUS MINUS MULTIPLY DIVIDE MODULO INCREMENT DECREMENT S_MUL NEGDIGIT
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN WHILE RETURN S_DIV
%token SEMICOLON IF ELSE LESS_EQUAL MORE_EQUAL MORE EQUAL NOT_EQUAL CHARLIT OSBRACE CSBRACE
%left PLUS MINUS
%left MULTIPLY DIVIDE






%%
    /* Rules*/

    program
            : program funcdef
            | funcdef
            | pre_pro program
            ;
    pre_pro
            : PREPROCESSOR HEADER
            ;
    funcdef
            : types VARCHAR args block_statement
            {
                if ($1!=returntype_func(ct))
	               {
		                printf("\nError : Type mismatch : Line %d\n",printline());
	               }

	              if (!(strcmp($2,"printf") && strcmp($2,"scanf")))
		                printf("Error : Type mismatch in redeclaration of %s : Line %d\n",$2,printline());
	              else
	               {
		                  insert($2,FUNCTION,g_addr);
		                  insert($2,$1,g_addr);
		                  g_addr+=4;
	               }
	    }
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
            | VOID
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
            | print_statement
            | conditional_statement
            | while_st
            | for_st
            | assignment_statement SEMICOLON
            | declaration_statement SEMICOLON
            | function_call SEMICOLON
            | ret_statement SEMICOLON
            ;

    print_statement
            : PRINTF OCBRACE in_print CCBRACE SEMICOLON
            ;
    in_print
            : STRING in_print_ext
            ;
    in_print_ext
            :
            | COMMA VARCHAR in_print_ext
            ;

    declaration_statement
            : types id_list
            | types VARCHAR ASSIGNMENT int_expression SEMICOLON
            {
		          if( (!(strspn($4,"0123456789")==strlen($4))) && $1==258)
			           printf("\nError : Type Mismatch : Line %d\n",printline());
		          if(!lookup($2))
		            {
			             int currscope=stack[index1-1];
			             int previous_scope=returnscope($2,currscope);
			             if(currscope==previous_scope)
				               printf("\nError : Redeclaration of %s : Line %d\n",$2,printline());
			             else
			                {
				                 insert_dup($2,$1,g_addr,currscope);
				                 check_scope_update($2,$4,stack[index1-1]);
				                 g_addr+=4;
			                }
		             }
		           else
		             {
			             int scope=stack[index1-1];
			             insert($2,$1,g_addr);
			             insertscope($2,scope);
			             check_scope_update($2,$4,stack[index1-1]);
			             g_addr+=4;
		             }
            }
            |  assignment1 SEMICOLON  {
				        if(!lookup($1))
				            {
					               int currscope=stack[index1-1];
					               int scope=returnscope($1,currscope);
				                 if(!(scope<=currscope && end[scope]==0) || scope==0)
						                 printf("\nError : Variable %s out of scope : Line %d\n",$1,printline());
				            }
				            else
			               		printf("\nError : Undeclared Variable %s : Line %d\n",$1,printline());
				            }
             | types VARCHAR OSBRACE assignment CSBRACE SEMICOLON
                    {
        						insert($2,ARRAY,g_addr);
        						insert($2,$1,g_addr);
        						g_addr+=4;
        					}
       	     | VARCHAR OSBRACE assignment1 CSBRACE SEMICOLON
            ;


  assignment : VARCHAR ASSIGNMENT int_expression
	             | VARCHAR PLUS assignment
	             | VARCHAR COMMA assignment
	             | int_expression COMMA assignment
	             | VARCHAR
	             | int_expression
	              ;

assignment1 : VARCHAR ASSIGNMENT assignment1
	            {
		            int sct=returnscope($1,stack[index1-1]);
		            int type=returntype($1,sct);
		            if((!(strspn($3,"0123456789")==strlen($3))) && type==258)
			                 printf("\nError : Type Mismatch : Line %d\n",printline());
		                   if(!lookup($1))
		                       {
			                        int currscope=stack[index1-1];
			                        int scope=returnscope($1,currscope);
			                        if((scope<=currscope && end[scope]==0) && !(scope==0))
				                            check_scope_update($1,$3,currscope);
		                       }
              }

	          | VARCHAR COMMA assignment1
              {
					         if(lookup($1))
						             printf("\nUndeclared Variable %s : Line %d\n",$1,printline());
				      }
	          | int_expression COMMA assignment1
	          | VARCHAR
                  {
 		               if(lookup($1))
			                printf("\nUndeclared Variable %s : Line %d\n",$1,printline());
		              }
	          | int_expression
	          ;


   id_list
            : VARCHAR id_list_1
            | assignment_statement id_list_1
            ;
  id_list_1
            : COMMA VARCHAR id_list_1
            |
            | COMMA assignment_statement id_list_1
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
            : WHILE OCBRACE conditions CCBRACE while_st_ext
            ;
   while_st_ext
            :
            | block_statement
            | SEMICOLON
            ;

   for_st
            : FOR OCBRACE condition1 SEMICOLON condition2 SEMICOLON condition3 CCBRACE for_st_ext
            ;
  for_st_ext
            :
            | SEMICOLON
            | block_statement
            ;

  condition1
            :
            | declaration_statement
            | assignment_statement
            ;

  condition2
            :
            |conditions
            ;

  condition3
            :
            | _inc_decre condition3
            | COMMA condition3
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
              : RETURN int_expression {
                if(!(strspn($2,"0123456789")==strlen($2)))
						          storereturn(ct,FLOAT);
					      else
						          storereturn(ct,INT); ct++;
              }
              | RETURN SEMICOLON {storereturn(ct,VOID); ct++;}
              ;
  int_expression
                : DIGIT
                | VARCHAR
                | int_expression PLUS int_expression
                | int_expression MINUS int_expression
                | int_expression MULTIPLY int_expression
                | int_expression DIVIDE int_expression
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
