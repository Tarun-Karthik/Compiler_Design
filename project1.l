%{
#include<stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "y.tab.h"
int keywordcount = 0;
int linecount = 1;
int mcomment = 0;
#define SIZE 100

extern void yyerror(const char *);

%}

preprocessor #include
header <[a-zA-Z]+\.h>
keywords auto|break|case|const|continue|default|do|double|enum|extern|goto|long|register|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|printf|scanf|main
line [\n]
space [ ][\t]
startc "/*"
endc "*/"
varchar [a-zA-Z_][a-zA-Z0-9_]*
number [0-9]*"."[0-9]*
string \".+\"
digit [0-9]*
invalidid {digit}+[_a-zA-Z]+[_a-zA-Z0-9]*
pointer "*"{varchar}
array {varchar}"["{number}+"]"
illegel "@"|"$"
define #define
negdigit -{digit}
charlit '.+'

%s comment
%s function

%%

{space} {}
{line} {  linecount++;  }

{charlit} {int i,j,count=0; char* temp; char text[1000]; temp = yytext;  for(i=1;temp[i]!='\'';i++){} count = i-1; for(i=1,j=0;i<=count;i++,j++)text[j] = temp[i]; text[j]='\0'; printf("\nline number : %d : %s , is a string\n",linecount,text);if(mcomment==0)Insert("String",text,Search(text)); return CHARLIT;}

{negdigit} {return NEGDIGIT;}

"void" {if(mcomment==0){keywordcount++; printf("\nline number : %d : C Keyword(%d) : %s\n",linecount,keywordcount,yytext);    Insert("keywords",yytext,Search(yytext)); return VOID;}}

"main" {if(mcomment==0){keywordcount++; printf("\nline number : %d : C Keyword(%d) : %s\n",linecount,keywordcount,yytext);    Insert("keywords",yytext,Search(yytext)); return MAIN;}}

"int" {if(mcomment==0){keywordcount++; printf("\nline number : %d : C Keyword(%d) : %s\n",linecount,keywordcount,yytext);    Insert("keywords",yytext,Search(yytext)); return INT;}}

"float" { if(mcomment==0){keywordcount++; printf("\nline number : %d : C Keyword(%d) : %s\n",linecount,keywordcount,yytext);    Insert("keywords",yytext,Search(yytext)); return FLOAT;}}

"char" { if(mcomment==0){keywordcount++; printf("\nline number : %d : C Keyword(%d) : %s\n",linecount,keywordcount,yytext);    Insert("keywords",yytext,Search(yytext));return CHAR;}}

"if" { if(mcomment==0){keywordcount++; printf("\nline number : %d : C Keyword(%d) : %s\n",linecount,keywordcount,yytext);    Insert("keywords",yytext,Search(yytext));return IF;}}

"while" { if(mcomment==0){keywordcount++; printf("\nline number : %d : C Keyword(%d) : %s\n",linecount,keywordcount,yytext);    Insert("keywords",yytext,Search(yytext));return WHILE;}}

"else" { if(mcomment==0){keywordcount++; printf("\nline number : %d : C Keyword(%d) : %s\n",linecount,keywordcount,yytext);    Insert("keywords",yytext,Search(yytext));return ELSE;}}

"return" { if(mcomment==0){keywordcount++; printf("\nline number : %d : C Keyword(%d) : %s\n",linecount,keywordcount,yytext);    Insert("keywords",yytext,Search(yytext));return RETURN;}}

"printf"  { if(mcomment==0){keywordcount++; printf("\nline number : %d : C Keyword(%d) : %s\n",linecount,keywordcount,yytext);    Insert("keywords",yytext,Search(yytext));return PRINTF;}}

"for"  { if(mcomment==0){keywordcount++; printf("\nline number : %d : C Keyword(%d) : %s\n",linecount,keywordcount,yytext);    Insert("keywords",yytext,Search(yytext));return FOR;}}

{keywords} { if(mcomment==0){keywordcount++; printf("\nline number : %d : C Keyword(%d) : %s\n",linecount,keywordcount,yytext);    Insert("keywords",yytext,Search(yytext)); }}

{varchar} { if(mcomment==0){ printf("\nline number : %d : %s is a variable name\n",linecount,yytext); Insert("identifier",yytext,Search(yytext)); return VARCHAR;}}

{define} {printf("\nline number : %d : %s is a definition\n",linecount,yytext);if(mcomment==0)
Insert("definition",yytext,Search(yytext));
  }

{preprocessor} {printf("\nline number : %d : %s is a preprocessor\n",linecount,yytext);if(mcomment==0)
Insert("preprocessor",yytext,Search(yytext)); return PREPROCESSOR;}

[int|float|char|void]+[ ]+[a-zA-Z_][a-zA-Z0-9_]*[(]{1}[int|float|char]*[ ]*[a-zA-Z_]*[a-zA-Z0-9_]*[)]{1} {BEGIN 0; printf("\nline number : %d : %s : is a function \n",linecount,yytext); }

{header} {printf("\nline number : %d : %s is a header\n",linecount,yytext);if(mcomment==0)Insert("header",yytext,Search(yytext)); return HEADER;}

{invalidid} {if(mcomment==0)printf("\nERROR 1 : Line number %d : Invalid Identifier  :%s",linecount,yytext);}

[/]{1}[/]{1}.* {   printf("\nline number : %d : %s : is a comment\n",linecount,yytext);  }

{startc} 	{BEGIN comment; if(mcomment==0){printf("\nmultiline comment starts at line %d\n",linecount); mcomment = 1;}else{printf("\nERROR 2 : Line number %d : Comment Error  ",linecount);}}
<comment>\n	{BEGIN comment;  linecount++;}
<comment>[a-zA-Z0-9 ]* ;
<comment>{endc}	{BEGIN 0; if(mcomment == 1)printf("\nmultiline comment end at line %d\n",linecount); mcomment = 0;}


{illegel} {if(mcomment==0){printf("\nERROR : Line number %d : Illegel Token  :%s",linecount,yytext);}}


{pointer} {printf("\nline number : %d : %s is a (pointer) variable name\n",linecount,yytext);if(mcomment==0)Insert("identifier",yytext,Search(yytext));}

{array} {printf("\nline number : %d : %s is a (array) variable name\n",linecount,yytext);if(mcomment==0)Insert("identifier",yytext,Search(yytext));}

{number} {if(mcomment==0){ printf("\nline number : %d : %s is a floating point \n",linecount,yytext); Insert("identifier",yytext,Search(yytext)); yylval.floatval = strtol(yytext, 0, 10);
         return FDIGIT;}}

{digit} { if(mcomment==0){ printf("\nline number : %d : %s is a integer \n",linecount,yytext); Insert("identifier",yytext,Search(yytext)); yylval.intval = strtol(yytext, 0, 10);
         return DIGIT;}}

{string} {int i,j,count=0; char* temp; char text[1000]; temp = yytext;  for(i=1;temp[i]!='\"';i++){} count = i-1; for(i=1,j=0;i<=count;i++,j++)text[j] = temp[i]; text[j]='\0'; printf("\nline number : %d : %s , is a string\n",linecount,text);if(mcomment==0)Insert("String",text,Search(text)); return STRING;}

"=" {printf("\nline number : %d : equal to operator %s\n",linecount,yytext);if(mcomment==0)Insert("Assignment",yytext,Search(yytext)); return ASSIGNMENT;}

"+" { printf("\nline number : %d : addition operator %s\n",linecount,yytext);if(mcomment==0)Insert("Add",yytext,Search(yytext));return PLUS;}

"-" {printf("\nline number : %d : subtraction operator %s\n",linecount,yytext);if(mcomment==0)Insert("Subtract",yytext,Search(yytext)); return MINUS;}

"*" {printf("\nline number : %d : multiplication operator %s\n",linecount,yytext);if(mcomment==0)Insert("Multiply",yytext,Search(yytext)); return MULTIPLY;}

"/" {printf("\nline number : %d : division operator %s\n",linecount,yytext);if(mcomment==0)Insert("Divide",yytext,Search(yytext)); return DIVIDE;}

"%" {printf("\nline number : %d : modulo operator %s\n",linecount,yytext);if(mcomment==0)Insert("Modulo",yytext,Search(yytext));}

"++" {printf("\nline number : %d : increment operator %s\n",linecount,yytext);if(mcomment==0)Insert("Increment",yytext,Search(yytext)); return INCREMENT;}

"--" {printf("\nline number : %d : decrement operator %s\n",linecount,yytext);if(mcomment==0)Insert("Decrement",yytext,Search(yytext)); return DECREMENT;}

"+=" {printf("\nline number : %d : add & assign operator %s\n",linecount,yytext);if(mcomment==0)Insert("Add_Assign",yytext,Search(yytext)); return S_ADD;}

"-=" {printf("\nline number : %d : subtract & assign operator %s\n",linecount,yytext);if(mcomment==0)Insert("Sub_Assign",yytext,Search(yytext)); return S_SUB;}

"*=" {printf("\nline number : %d : multiply & assign operator %s\n",linecount,yytext);if(mcomment==0)Insert("Mult_Assign",yytext,Search(yytext)); return S_MUL;}

"/=" {printf("\nline number : %d : divide & assign operator %s\n",linecount,yytext);if(mcomment==0)Insert("Div_Assign",yytext,Search(yytext)); return S_DIV;}

"==" {printf("\nline number : %d : equal to operator %s\n",linecount,yytext);if(mcomment==0)Insert("Equal",yytext,Search(yytext)); return EQUAL;}

"%=" {printf("\nline number : %d : modulo & assign to operator %s\n",linecount,yytext);if(mcomment==0)Insert("Mod_Assign",yytext,Search(yytext));}

">=" {printf("\nline number : %d : greater than or equal to operator %s\n",linecount,yytext);if(mcomment==0)Insert("Greater_Eq",yytext,Search(yytext)); return MORE_EQUAL;}

"<=" {printf("\nline number : %d : less than or equal to operator %s\n",linecount,yytext);if(mcomment==0)Insert("Less_Eq",yytext,Search(yytext)); return LESS_EQUAL;}

"!=" {printf("\nline number : %d : not equal to operator %s\n",linecount,yytext);if(mcomment==0)Insert("Not_Eq",yytext,Search(yytext)); return NOT_EQUAL;}

">"  {printf("\nline number : %d : greater than operator %s\n",linecount,yytext);if(mcomment==0)Insert("Great",yytext,Search(yytext)); return MORE;}

"<"  {printf("\nline number : %d : less than operator %s\n",linecount,yytext);if(mcomment==0)Insert("Less",yytext,Search(yytext)); return LESS;}

"?"  {printf("\nline number : %d : conditional operator %s\n",linecount,yytext);if(mcomment==0)Insert("Condition",yytext,Search(yytext));}

"&"  {printf("\nline number : %d : bit wise AND operator %s\n",linecount,yytext);if(mcomment==0)Insert("Reference/Bit_And",yytext,Search(yytext));}

"|"  {printf("\nline number : %d : bit wise OR operator %s\n",linecount,yytext);if(mcomment==0)Insert("Bit_Or",yytext,Search(yytext));}

"&&" {printf("\nline number : %d : AND operator %s\n",linecount,yytext);if(mcomment==0)Insert("Logic_And",yytext,Search(yytext));}

"||" {printf("\nline number : %d : OR operator %s\n",linecount,yytext);if(mcomment==0)Insert("Logic_Or",yytext,Search(yytext));}

"!"  {printf("\nline number : %d : NOT operator %s\n",linecount,yytext);if(mcomment==0)Insert("Negate",yytext,Search(yytext));}

":"  {printf("\nline number : %d : Colon %s\n",linecount,yytext);if(mcomment==0)Insert("Colon",yytext,Search(yytext));}

";"  {printf("\nline number : %d : semi colon %s\n",linecount,yytext);if(mcomment==0)Insert("SemiColon",yytext,Search(yytext)); return SEMICOLON;}

","  {printf("\nline number : %d : comma %s\n",linecount,yytext);if(mcomment==0)Insert("Coma",yytext,Search(yytext)); return COMMA;}

"("  {printf("\nline number : %d : open curly brace %s\n",linecount,yytext);if(mcomment==0)Insert("Open_Brace",yytext,Search(yytext)); return OCBRACE;}

")"  {printf("\nline number : %d : closing curly brace %s\n",linecount,yytext);if(mcomment==0)Insert("Close_Brase",yytext,Search(yytext)); return CCBRACE;}

"'"  {printf("\nline number : %d : single Quot %s\n",linecount,yytext);if(mcomment==0)Insert("Single_quot",yytext,Search(yytext)); return QUOT;}

"{" {printf("\nline number : %d : open round brace %s\n",linecount,yytext);if(mcomment==0)Insert("Open_Paran",yytext,Search(yytext)); return OPENBC;}

"}" {printf("\nline number : %d : close round brace %s\n",linecount,yytext);if(mcomment==0)Insert("Close_Paran",yytext,Search(yytext)); return CLOSEBC;}

%%
