%{
#include<stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
int keywordcount = 0;
int linecount = 1;
int mcomment = 0, max=0;
#define SIZE 100
%}

preprocessor #include
header <[a-zA-Z]+\.h>
keywords while|for|int|float|char|auto|break|case|const|continue|default|do|double|else|enum|extern|goto|if|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|printf|scanf|main
line [\n]
space [ ]
startc "/*"
endc "*/"
varchar [a-zA-Z_][a-zA-Z0-9_]*
number [0-9]*
string \".+\"
openbc [(]
closebc [)]
digit [0-9]
invalidid {digit}+[_a-zA-Z]+[_a-zA-Z0-9]*
pointer "*"{varchar}
array {varchar}"["{number}+"]"

%s comment
%s function

%%

{preprocessor} {printf("\nline number : %d : %s is a preprocessor\n",linecount,yytext);if(mcomment==0)
Insert("preprocessor",yytext,Search(yytext));}

{header} {printf("\nline number : %d : %s is a header\n",linecount,yytext);if(mcomment==0)Insert("header",yytext,Search(yytext));}

{invalidid} {printf("\nERROR 1 : Line number %d : Invalid Identifier  :%s",linecount,yytext);exit(1);}

[/]{1}[/]{1}.* {   printf("\nline number : %d : %s : is a comment\n",linecount,yytext);  }

{keywords} { keywordcount++;     printf("\nline number : %d : C Keyword(%d) : %s\n",linecount,keywordcount,yytext);   if(mcomment==0)Insert("keywords",yytext,Search(yytext)); }

{startc} 	{BEGIN comment; if(mcomment==0){printf("\nmultiline comment starts at line %d\n",linecount); mcomment = 1;}else{printf("\nERROR 2 : Line number %d : Comment Error  ",linecount);exit(1);}}
<comment>\n	{BEGIN comment;  linecount++;}
<comment>[a-zA-Z0-9 ]* ;
<comment>{endc}	{BEGIN 0; if(mcomment == 1)printf("\nmultiline comment end at line %d\n",linecount); mcomment = 0;}

{line} {  linecount++;  }

{pointer} {printf("\nline number : %d : %s is a (pointer) variable name\n",linecount,yytext);if(mcomment==0)Insert("identifier",yytext,Search(yytext));}

{array} {printf("\nline number : %d : %s is a (array) variable name\n",linecount,yytext);if(mcomment==0)Insert("identifier",yytext,Search(yytext));}

{varchar} {printf("\nline number : %d : %s is a variable name\n",linecount,yytext);if(mcomment==0)Insert("identifier",yytext,Search(yytext));}

{number} {printf("\nline number : %d : %s is a number\n",linecount,yytext);if(mcomment==0)Insert("Number",yytext,Search(yytext));}

{string} {printf("\nline number : %d : %s , is a string\n",linecount,yytext);if(mcomment==0)Insert("String",yytext,Search(yytext));}

"=" {printf("\nline number : %d : equal to operator %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

"+" {printf("\nline number : %d : addition operator %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

"-" {printf("\nline number : %d : subtraction operator %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

"*" {printf("\nline number : %d : multiplication operator %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

"/" {printf("\nline number : %d : division operator %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

"%" {printf("\nline number : %d : modulo operator %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

"++" {printf("\nline number : %d : increment operator %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

"--" {printf("\nline number : %d : decrement operator %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}
"+=" {printf("\nline number : %d : add & assign operator %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

"-=" {printf("\nline number : %d : subtract & assign operator %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

"*=" {printf("\nline number : %d : multiply & assign operator %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

"/=" {printf("\nline number : %d : divide & assign operator %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

"==" {printf("\nline number : %d : equal to operator %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

"%=" {printf("\nline number : %d : modulo & assign to operator %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

">=" {printf("\nline number : %d : greater than or equal to operator %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

"<=" {printf("\nline number : %d : less than or equal to operator %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

"!=" {printf("\nline number : %d : not equal to operator %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

">"  {printf("\nline number : %d : greater than operator %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

"<"  {printf("\nline number : %d : less than operator %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

"?"  {printf("\nline number : %d : conditional operator %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

"&"  {printf("\nline number : %d : bit wise AND operator %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

"|"  {printf("\nline number : %d : bit wise OR operator %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

"&&" {printf("\nline number : %d : AND operator %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

"||" {printf("\nline number : %d : OR operator %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

"!"  {printf("\nline number : %d : NOT operator %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

":"  {printf("\nline number : %d : Colon %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

";"  {printf("\nline number : %d : semi colon %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

","  {printf("\nline number : %d : comma %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

"{"  {printf("\nline number : %d : open curly brace %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

"}"  {printf("\nline number : %d : closing curly brace %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

{openbc} {printf("\nline number : %d : open round brace %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}

{closebc} {printf("\nline number : %d : close round brace %s\n",linecount,yytext);if(mcomment==0)Insert("Operator",yytext,Search(yytext));}


%%

int size=0;
void Insert(char[],char[],int);
void Display();
int Search(char[]);

struct SymbTab
{
 char label[100],symbol[100];
 int addr;
struct SymbTab *next;};
struct SymbTab *first,*last;

int main()
{
  yyin = fopen("Program.txt","r");

  FILE *file= fopen("Symbol_Table.txt", "w");
  yyout= file;
  yylex();
  fclose(yyin);
  
  Display();
  fclose(yyout);
  return(0);
  
}

void Insert(char l[100],char a[100],int op)
{
  int n;
  struct SymbTab *p;
  p=malloc(sizeof(struct SymbTab));
  strcpy(p->label,l);
  strcpy(p->symbol,a);
  p->addr=op;
  p->next=NULL;
  if(size==0){
    first=p;
    last=p;
  }
  else{
    last->next=p;
    last=p;
  }
  size++;
}
int Search(char l[100])
{
	int abc=0;
	struct SymbTab *qw;
	if(size==0)
	{
		return 0;
	}
	qw=first;
	int i;
	for(i=0;i<size;i++)
	{
		if(strcmp(qw->symbol,l)==0)
		{
			abc=qw->addr;
			return abc;
		}
		else
		{
			qw=qw->next;
		}

	}
	max++;
	return max;
}
	
void Display()
{
  int i;
  struct SymbTab *p;
  p=first;
  fprintf(yyout,"\n\tSYMBOL\t\t\t\tTOKEN\t\t\t\tAttribute Number\n");
  for(i=0;i<size;i++)
   {
	fprintf(yyout,"\t%s\t\t\t\t%s\t\t\t\t%d\n",p->symbol,p->label,p->addr);
        p=p->next;
   }
}


int yywrap()
{
  return (1);
}

