
%{
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include "main.c"



int g_addr = 100;
int i=1;
int j=8;
int stack[100];
int index1=0;
int end[100];
int arr[10];
int gl1,gl2,ct=0,c=0,b;
%}

%token<ival> INT FLOAT VOID CHAR ARRAY FUNCTION
%token<str> VARCHAR DIGIT FDIGIT
%token PREPROCESSOR HEADER KEYWORDS  SPACE COMMA LESS S_ADD FOR QUOT
%token OPENBC CLOSEBC POINTER  DEFINE   S_SUB  PRINTF
%token MODULO INCREMENT DECREMENT S_MUL NEGDIGIT STRING
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN WHILE RETURN S_DIV
%token SEMICOLON IF ELSE LESS_EQUAL MORE_EQUAL MORE EQUAL NOT_EQUAL CHARLIT OSBRACE CSBRACE
%left PLUS MINUS
%left MULTIPLY DIVIDE
%right ASSIGNMENT

%type<str> assignment assignment1 consttype
%type<ival> types



%union {
		int ival;
		char *str;
}

/* Decleration*/







%%
    /* Rules*/

    program
						:
            | pre_pro program
            | funcdef	 program
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

		                  insert($2,$1,g_addr);
											insert($2,271,g_addr);
		                  g_addr+=4;
	               }
	    			}
            ;


    args
            :'(' var_def_list ')'
            ;

    var_def_list
            :
						| var_def var_def_list1
            ;

		var_def_list1
						:
						| var_def_list_extension var_def_list1
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
            | Declaration
            | function_call SEMICOLON
            | ret_statement SEMICOLON
            ;

    print_statement
            : PRINTF '(' in_print ')' SEMICOLON
            ;
    in_print
            : STRING in_print_ext
            ;
    in_print_ext
            :
            | COMMA VARCHAR in_print_ext
            ;

Declaration : types VARCHAR ASSIGNMENT consttype SEMICOLON
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
						|types VARCHAR OSBRACE assignment CSBRACE SEMICOLON  {

						if(!lookup($2))
						{
							int currscope=stack[index1-1];
							int previous_scope=returnscope($2,currscope);
							if(currscope==previous_scope)
								printf("\nError : Redeclaration of %s : Line %d\n",$2,printline());
							else
							{
								insert_dup($2,$1,g_addr,currscope);
								check_scope_update($2,"null",stack[index1-1]);
								g_addr+=4;
							}
						}
						else
						{
							int scope=stack[index1-1];
						  insert($2,$1,g_addr);
							insert($2,269,g_addr);
							insertscope($2,scope);
							g_addr+=4;
						}
										}
						| types VARCHAR SEMICOLON
						{
						if(!lookup($2))
						{
							int currscope=stack[index1-1];
							int previous_scope=returnscope($2,currscope);
							if(currscope==previous_scope)
								printf("\nError : Redeclaration of %s : Line %d\n",$2,printline());
							else
							{
								insert_dup($2,$1,g_addr,currscope);
								g_addr+=4;
							}
						}
						else
						{
							int scope=stack[index1-1];
							insert($2,$1,g_addr);
							insertscope($2,scope);
							g_addr+=4;
						}
						}
						| assignment1 SEMICOLON {
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


						| VARCHAR OSBRACE assignment1 CSBRACE SEMICOLON
						;

	assignment : VARCHAR ASSIGNMENT consttype
							| VARCHAR PLUS assignment
							| VARCHAR COMMA assignment
							| consttype COMMA assignment
							| VARCHAR
							| consttype
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

							| VARCHAR COMMA assignment1    {
											if(lookup($1))
												printf("\nUndeclared Variable %s : Line %d\n",$1,printline());
										}
							| consttype COMMA assignment1
							| VARCHAR  {
								if(lookup($1))
									printf("\nUndeclared Variable %s : Line %d\n",$1,printline());
								}
							| consttype
							;

	consttype : DIGIT
	| FDIGIT
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
            : VARCHAR '(' expression_list ')'
            ;

    conditional_statement
            : IF '(' conditions ')' block_statement elsest
            ;

    elsest
            : ELSE block_statement
            |
            ;

   while_st
            : WHILE '(' conditions ')' while_st_ext
            ;
   while_st_ext
            :
            | block_statement
            | SEMICOLON
            ;

   for_st
            : FOR '(' condition1 SEMICOLON condition2 SEMICOLON condition3 ')' for_st_ext
            ;
  for_st_ext
            :
            | SEMICOLON
            | block_statement
            ;

  condition1
            :
            | Declaration
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
            : int_cond LESS consttype
            | int_cond LESS_EQUAL consttype
            | int_cond MORE_EQUAL consttype
            | int_cond MORE consttype
            | int_cond NOT_EQUAL consttype
            | int_cond EQUAL consttype
            | consttype
            ;


  assignment_statement
              : int_ass
              | char_ass
              | types VARCHAR ASSIGNMENT {  }
              | error
              ;
    int_ass
              :types VARCHAR ASSIGNMENT consttype
              | VARCHAR ASSIGNMENT consttype
              ;
    char_ass
              :types VARCHAR ASSIGNMENT char_expression
              | VARCHAR ASSIGNMENT char_expression
              ;

  ret_statement
              : RETURN consttype  {
                if(!(strspn($2,"0123456789")==strlen($2)))
						          storereturn(ct,FLOAT);
					      else
						          storereturn(ct,INT); ct++;
              }
              | RETURN  {storereturn(ct,VOID); ct++;}
              ;

  char_expression
                : QUOT STRING QUOT { }
                ;

  expression_list
                : expression_list COMMA consttype
                | expression_list COMMA STRING
                | consttype
                | STRING
                ;



%%
#include "lex.yy.c"
int main()
{
  yyin = fopen("Program.txt","r");
	if(!yyparse())
	{
		printf("\n Parsing Done");
		print();
	}
	else
	{
	printf("\n Error ");
	}
	fclose(yyin);
	return 0;
}

int yyerror(char *s) {
    printf("\n Line %d : %s %s\n",yylineno,s,yytext);
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
