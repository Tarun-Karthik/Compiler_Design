
%{
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>
#include "main.c"



int g_addr = 100;
int i=1;
int stack[100];
int index1=0;
int end[100];
int arr[10];
int gl1,gl2,ct,c,b;

int fl,top=0,label[20],lnum=0,ltop=0;
char st1[100][10];
char i_[2]="0";
char temp[2]="t";
char null[2]=" ";

void yyerror(char *s);
int printline();

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

void if1()
{
	lnum++;
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = not %s\n",temp,st1[top]);
 	printf("if %s goto L%d\n",temp,lnum);
	i_[0]++;
	label[++ltop]=lnum;	
	
}
void if2()
{
	lnum++;
	printf("goto L%d\n",lnum);
	printf("L%d: \n",label[ltop--]);
	label[++ltop]=lnum;
}
void if3()
{
	printf("L%d:\n",label[ltop--]);
}
void w1()
{
	lnum++;
	label[++ltop]=lnum;
	printf("L%d:\n",lnum);
}
void w2()
{
	lnum++;
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = not %s\n",temp,st1[top--]);
 	printf("if %s goto L%d\n",temp,lnum);
	i_[0]++;
	label[++ltop]=lnum;
}
void w3()
{
	int y=label[ltop--];
	printf("goto L%d\n",label[ltop--]);
	printf("L%d:\n",y);
}
/*void dw1()
{
	lnum++;
	label[++ltop]=lnum;
	printf("L%d:\n",lnum);
}
void dw2()
{
 	printf("if %s goto L%d\n",st1[top--],label[ltop--]);
}*/
void f1()
{
	lnum++;
	label[++ltop]=lnum;
	printf("L%d:\n",lnum);
}
void f2()
{
	lnum++;
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = not %s\n",temp,st1[top--]);
 	printf("if %s goto L%d\n",temp,lnum);
	i_[0]++;
	label[++ltop]=lnum;
	lnum++;
	printf("goto L%d\n",lnum);
	label[++ltop]=lnum;
	lnum++;
	printf("L%d:\n",lnum);	
	label[++ltop]=lnum;
}
void f3()
{
	printf("goto L%d\n",label[ltop-3]);
	printf("L%d:\n",label[ltop-1]);
}
void f4()
{
	printf("goto L%d\n",label[ltop]);
	printf("L%d:\n",label[ltop-2]);
	ltop-=4;
}
void push(char *a)
{
	strcpy(st1[++top],a);
}
void array1()
{
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = %s * 4\n",temp,st1[top]);
	strcpy(st1[top],temp);
	i_[0]++;
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = %s [ %s ] \n",temp,st1[top-1],st1[top]);
	top--;
	strcpy(st1[top],temp);
	i_[0]++;	
}
void codegen()
{
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = %s %s %s\n",temp,st1[top-2],st1[top-1],st1[top]);
	top-=2;
	strcpy(st1[top],temp);
	i_[0]++;
}
void codegen_umin()
{
	strcpy(temp,"t");
	strcat(temp,i_);
	printf("%s = -%s\n",temp,st1[top]);
	top--;
	strcpy(st1[top],temp);
	i_[0]++;
}
void codegen_assign()
{
	printf("%s = %s\n",st1[top-2],st1[top]);
	top-=2;
}

%}


%token<ival> INT FLOAT VOID CHAR ARRAY FUNCTION
%token<str> VARCHAR DIGIT FDIGIT LESS_EQUAL MORE_EQUAL MORE EQUAL NOT_EQUAL LESS
%token PREPROCESSOR HEADER KEYWORDS  SPACE COMMA S_ADD FOR QUOT
%token OPENBC CLOSEBC POINTER  DEFINE   S_SUB  PRINTF
%token MODULO INCREMENT DECREMENT S_MUL NEGDIGIT STRING
%token ADD_ASSIGN SUB_ASSIGN MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN WHILE RETURN S_DIV
%token SEMICOLON IF ELSE CHARLIT OSBRACE CSBRACE
%left PLUS MINUS
%left MULTIPLY DIVIDE
%right ASSIGNMENT

%type<str> assignment assignment1 consttype ASSIGNMENT PLUS MINUS MULTIPLY DIVIDE E T F
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
	     | types VARCHAR args SEMICOLON
	     {
		if(lookup($1))
		{
			insert($2,$1,g_addr);
			insert($2,271,g_addr);
			g_addr+=4;
		}
		else
		{
			printf("\n Error : function redeclared");
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
	    | assignment1 SEMICOLON
            | ret_statement SEMICOLON
	    | assignment SEMICOLON
	    | VARCHAR args SEMICOLON
		{
			if(lookup($1))
			printf("function not declared");
		}
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

Declaration : types VARCHAR {push($2);} '=' {strcpy(st1[++top],"=");} E {codegen_assign();} SEMICOLON
		{
			if( (!(strspn($6,"0123456789")==strlen($6))) && $1==258 && (fl==0))
			{
				printf("\nError : Type Mismatch : Line %d\n",printline());
				fl=1;
			} 
			if(!lookup($2))
			{
				int currscope=stack[index1-1];
				int previous_scope=returnscope($2,currscope);
				if(currscope==previous_scope)
				printf("\nError : Redeclaration of %s : Line %d\n",$2,printline());
				else
				{
					insert_dup($2,$1,g_addr,currscope);
					check_scope_update($2,$6,stack[index1-1]);
					int sg=returnscope($2,stack[index1-1]);
					g_addr+=4;
				}
			}
			else
			{
				int scope=stack[index1-1];
				insert($2,$1,g_addr);
				insertscope($2,scope);
				check_scope_update($2,$6,stack[index1-1]);
				g_addr+=4;
			}
		}
	     |types VARCHAR OSBRACE DIGIT CSBRACE SEMICOLON  
		{
			if(!lookup($2))
			{
				int currscope=stack[index1-1];
				int previous_scope=returnscope($2,currscope);
				if(currscope==previous_scope)
					printf("\nError : Redeclaration of %s : Line %d\n",$2,printline());
				else
				{
					if($4<=0)
						printf("\nError : Invalid Size of %s : Line %d\n",$2,printline());
					insert_dup($2,$1,g_addr,currscope);
					check_scope_update($2,$4,stack[index1-1]);
					g_addr+=4;
				}
			}
			else
			{
				int scope=stack[index1-1];
				if($4<=0)
					printf("\nError : Invalid Size of %s : Line %d\n",$2,printline());
				insert($2,$1,g_addr);
				insert($2,269,g_addr);
				insertscope($2,scope);
				g_addr+=4;
			}
		}
	     |types VARCHAR SEMICOLON
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
	     |assignment1  
		{
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
	     |VARCHAR OSBRACE assignment1 CSBRACE SEMICOLON
	     |assignment
	     ;

	assignment : VARCHAR ASSIGNMENT assignment
			{
				if(direscope($1,stack[index1-1])==0)
					printf("\n Error : variable not declared ");
			}
		   | VARCHAR PLUS assignment
			{
				if(direscope($1,stack[index1-1])==0)
					printf("\n Error : variable not declared ");
			}
		   | VARCHAR MINUS assignment
			{
				if(direscope($1,stack[index1-1])==0)
					printf("\n Error : variable not declared ");
			}
		   | VARCHAR COMMA assignment
			{
				if(direscope($1,stack[index1-1])==0)
					printf("\n Error : variable not declared ");
			}
		   | consttype COMMA assignment
		   | VARCHAR
		   | consttype
		   ;

	assignment1 : VARCHAR {push($1);} '=' {strcpy(st1[++top],"=");} E {codegen_assign();}
			{
				int sct=returnscope($1,stack[index1-1]);
				int type=returntype($1,sct);
				if((!(strspn($5,"0123456789")==strlen($5))) && type==258 && fl==0)
					printf("\nError : Type Mismatch : Line %d\n",printline());
				if(!lookup($1))
					{
						int currscope=stack[index1-1];
						int scope=returnscope($1,currscope);
						if((scope<=currscope && end[scope]==0) && !(scope==0))
						check_scope_update($1,$5,currscope);

					}
			}

		    | VARCHAR COMMA assignment1    
			{
				if(lookup($1))
					printf("\nUndeclared Variable %s : Line %d\n",$1,printline());
			}
		    | consttype COMMA assignment1
		    | VARCHAR PLUS VARCHAR
			{
				if(direscope($1,stack[index1])==0)
					printf("\n variable not declared");
				if(lookup($1))
					printf("\nUndeclared Variable %s : Line %d\n",$1,printline());
				if(lookup($3))
					printf("\nUndeclared Variable %s : Line %d\n",$1,printline());

			}

		    | VARCHAR  
			{
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
            : IF '(' E ')' {if1();} block_statement {if2();} elsest
            ;

    elsest
            : ELSE block_statement {if3();}
            |
            ;

   while_st
            : WHILE {w1();}'(' E ')' {w2();} while_st_ext {w3();}
            ;
   while_st_ext
            :
            | block_statement
            | SEMICOLON
            ;

   for_st
            : FOR '(' E {f1();} SEMICOLON E {f2();} SEMICOLON E {f3();} ')' for_st_ext {f4();}
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
		{
			if(lookup($1))
				printf("\nUndeclared Variable %s : Line %d\n",$1,printline());
		}
            | INCREMENT VARCHAR
		{
			if(lookup($2))
				printf("\nUndeclared Variable %s : Line %d\n",$2,printline());
		}
            ;
  _dec
            : VARCHAR DECREMENT
		{
			if(lookup($1))
				printf("\nUndeclared Variable %s : Line %d\n",$1,printline());
		}
            | DECREMENT VARCHAR
		{
			if(lookup($2))
				printf("\nUndeclared Variable %s : Line %d\n",$2,printline());
		}
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
	    | int_cond ASSIGNMENT consttype
		{
			printf("\n Error : boolean expression required");
		}
            | consttype
	    | VARCHAR
		{
			if(lookup($1))
			printf("\nUndeclared Variable %s : Line %d\n",$1,printline());
		}


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
              : RETURN consttype 
		{
                	if(!(strspn($2,"0123456789")==strlen($2)))
				storereturn(ct,FLOAT);
			else
				storereturn(ct,INT); ct++;
              	}
              | RETURN  {storereturn(ct,VOID); ct++;}
	      | RETURN E
	      | RETURN VARCHAR
		{
			if(lookup($2))
			printf("\n Undeclared Variable %s : Line %d\n",$2,printline());
			int x = returntype_func(ct);
			int y = returntype($2,stack[index1-1]);
			if(y!=x)
				printf("\nError : type Mismatch");

		}
	      | RETURN '(' VARCHAR ')'
		{
			if(lookup($3))
			printf("\nUndeclared Variable %s : Line %d\n",$3,printline());
		}
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

 array : VARCHAR {push($1);}'[' E ']'
       ;

 E : E PLUS {strcpy(st1[++top],"+");} T{codegen();}
   | E MINUS {strcpy(st1[++top],"-");} T{codegen();}
   | T
   | VARCHAR {push($1);} LESS_EQUAL {strcpy(st1[++top],"<=");} E {codegen();}
   | VARCHAR {push($1);} MORE_EQUAL {strcpy(st1[++top],">=");} E {codegen();}
   | VARCHAR {push($1);} EQUAL {strcpy(st1[++top],"==");} E {codegen();}
   | VARCHAR {push($1);} NOT_EQUAL {strcpy(st1[++top],"!=");} E {codegen();}
   | VARCHAR {push($1);} MORE {strcpy(st1[++top],"<");} E {codegen();}
   | VARCHAR {push($1);} LESS {strcpy(st1[++top],">");} E {codegen();}
   | VARCHAR {push($1);} ASSIGNMENT {strcpy(st1[++top],"||");} E {codegen_assign();}
   | array {array1();}
   ;
 T : T MULTIPLY {strcpy(st1[++top],"*");} F{codegen();}
   | T DIVIDE {strcpy(st1[++top],"/");} F{codegen();}
   | F
   ;
 F : '(' E ')' {$$=$2;}
   | VARCHAR {push($1);fl=1;}
   | DIGIT {push($1);}
   ;

%%
#include "lex.yy.c"
int main()
{
  yyin = fopen("Program.txt","r");
  yyparse();
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

void yyerror(char *s) {
    printf("\n Line %d : %s %s\n",yylineno,s,yytext);
}

int printline()
{
  return yylineno;
}
