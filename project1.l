%{
#include<stdio.h>
int keywordcount = 0;
int linecount = 0;
%}

preprocessor #include
header <[a-zA-Z]+\.h>
keywords auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while
line [\n]
space [ ]
startc "/*"
endc "*/"
varchar [a-zA-Z_][a-zA-Z0-9_]*
wrongid [0-9]+[a-zA-Z0-9]*

%s comment

%%

[/]{1}[/]{1}[a-zA-Z0-9 ]* {   printf("\nline number : %d : %s : is a comment\n",linecount,yytext);  }

{keywords} { keywordcount++;     printf("\nline number : %d : C Keyword(%d) : %s\n",linecount,keywordcount,yytext);     }

{startc} 	{BEGIN comment; printf("\nmultiline comment starts at line %d\n",linecount);}
<comment>\n	{BEGIN comment;  linecount++;}
<comment>[a-zA-Z0-9 ]* ;
<comment>{endc}	{BEGIN 0; printf("\nmultiline comment end at line %d\n",linecount); }

{line} {  linecount++;  }

[a-z|A-z]+ {printf("\nline number : %d : %s is not a C Keyword\n",linecount,yytext);}

{preprocessor} {printf("\nline number : %d : %s is a preprocessor\n",linecount,yytext);}

{header} {printf("\nline number : %d : %s is a header\n",linecount,yytext);}

{varchar} {printf("\nline number : %d : %s is a variable name\n",linecount,yytext);}

{wrongid} {printf("\nError at Line number : %d : Error Message : Invalid Identifier\n",linecount);

"+" {printf("\nline number : %d : addition operator %s\n",linecount,yytext);

"-" {printf("\nline number : %d : subtraction operator %s\n",linecount,yytext);

"*" {printf("\nline number : %d : multiplication operator %s\n",linecount,yytext);

"/" {printf("\nline number : %d : division operator %s\n",linecount,yytext);

"%" {printf("\nline number : %d : modulo operator %s\n",linecount,yytext);

"++" {printf("\nline number : %d : increment operator %s\n",linecount,yytext);

"--" {printf("\nline number : %d : decrement operator %s\n",linecount,yytext);

"+=" {printf("\nline number : %d : add & assign operator %s\n",linecount,yytext);

"-=" {printf("\nline number : %d : subtract & assign operator %s\n",linecount,yytext);

"*=" {printf("\nline number : %d : multiply & assign operator %s\n",linecount,yytext);

"/=" {printf("\nline number : %d : divide & assign operator %s\n",linecount,yytext);

"==" {printf("\nline number : %d : equal to operator %s\n",linecount,yytext);

"%=" {printf("\nline number : %d : modulo & assign to operator %s\n",linecount,yytext);

">=" {printf("\nline number : %d : greater than or equal to operator %s\n",linecount,yytext);

"<=" {printf("\nline number : %d : less than or equal to operator %s\n",linecount,yytext);

"!=" {printf("\nline number : %d : not equal to operator %s\n",linecount,yytext);

">" {printf("\nline number : %d : greater than operator %s\n",linecount,yytext);

"<"	{printf("\nline number : %d : less than operator %s\n",linecount,yytext);

"?"	{printf("\nline number : %d : conditional operator %s\n",linecount,yytext);

"&"	{printf("\nline number : %d : bit wise AND operator %s\n",linecount,yytext);

"|"	{printf("\nline number : %d : bit wise OR operator %s\n",linecount,yytext);

"||"	{printf("\nline number : %d : OR operator %s\n",linecount,yytext);

"&&"	{printf("\nline number : %d : AND operator %s\n",linecount,yytext);

"!"	{printf("\nline number : %d : NOT operator %s\n",linecount,yytext);

":"	{printf("\nline number : %d : Colon %s\n",linecount,yytext);

";"	{printf("\nline number : %d : semi colon %s\n",linecount,yytext);

","	{printf("\nline number : %d : comma %s\n",linecount,yytext);

"{"	{printf("\nline number : %d : open curly brace %s\n",linecount,yytext);

"}"	{printf("\nline number : %d : closing curly brace %s\n",linecount,yytext);

"("	{printf("\nline number : %d : open brackets %s\n",linecount,yytext);

")" {printf("\nline number : %d : close brackets %s\n",linecount,yytext);

"["	{printf("\nline number : %d : open square brackets %s\n",linecount,yytext);

"]" {printf("\nline number : %d : close square brackets %s\n",linecount,yytext);

%%

int main()
{
  yyin = fopen("Program.txt","r");
  yylex();
}

int yywrap()
{
  return (1);
}
