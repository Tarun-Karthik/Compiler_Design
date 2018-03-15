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

{charlit} {yylval.str=strdup(yytext);int i,j,count=0; return CHARLIT;}

{negdigit} {yylval.str=strdup(yytext);return NEGDIGIT;}

"void" {if(mcomment==0){yylval.ival = VOID;keywordcount++; return VOID;}}

"main" {if(mcomment==0){keywordcount++; return MAIN;}}

"int" {if(mcomment==0){yylval.ival = INT;keywordcount++;  return INT;}}

"float" { if(mcomment==0){yylval.ival = FLOAT;keywordcount++;  return FLOAT;}}

"char" { if(mcomment==0){yylval.ival = CHAR;keywordcount++; return CHAR;}}

"if" { if(mcomment==0){keywordcount++; return IF;}}

"while" { if(mcomment==0){keywordcount++; return WHILE;}}

"else" { if(mcomment==0){keywordcount++; return ELSE;}}

"return" { if(mcomment==0){keywordcount++; return RETURN;}}

"printf"  { if(mcomment==0){keywordcount++; return PRINTF;}}

"for"  { if(mcomment==0){keywordcount++; return FOR;}}

{keywords} { if(mcomment==0){keywordcount++; }}

{varchar} {yylval.str=strdup(yytext);return VARCHAR;}

{define} { }

{preprocessor} { return PREPROCESSOR;}

[int|float|char|void]+[ ]+[a-zA-Z_][a-zA-Z0-9_]*[(]{1}[int|float|char]*[ ]*[a-zA-Z_]*[a-zA-Z0-9_]*[)]{1} {BEGIN 0;  }

{header} { return HEADER;}

{invalidid} {if(mcomment==0)printf("\nERROR 1 : Line number %d : Invalid Identifier  :%s",linecount,yytext);}

[/]{1}[/]{1}.* {   }

{startc} 	{BEGIN comment; if(mcomment==0){ mcomment = 1;}else{printf("\nERROR 2 : Line number %d : Comment Error  ",linecount);}}
<comment>\n	{BEGIN comment;  linecount++;}
<comment>[a-zA-Z0-9 ]* ;
<comment>{endc}	{BEGIN 0;  mcomment = 0;}


{illegel} {if(mcomment==0){printf("\nERROR : Line number %d : Illegel Token  :%s",linecount,yytext);}}


{pointer} {yylval.str=strdup(yytext);}

{array} {yylval.str=strdup(yytext);}

{number} {if(mcomment==0){yylval.str=strdup(yytext);
         return FDIGIT;}}

{digit} { if(mcomment==0){yylval.str=strdup(yytext);
         return DIGIT;}}

{string} {yylval.str=strdup(yytext); return STRING;}

"=" { return ASSIGNMENT;}

"+" {return PLUS;}

"-" { return MINUS;}

"*" {return MULTIPLY;}

"/" { return DIVIDE;}

"%" {}

"++" { return INCREMENT;}

"--" { return DECREMENT;}

"+=" { return S_ADD;}

"-=" { return S_SUB;}

"*=" { return S_MUL;}

"/=" { return S_DIV;}

"==" {return EQUAL;}

"%=" {}

">=" {return MORE_EQUAL;}

"<=" { return LESS_EQUAL;}

"!=" { return NOT_EQUAL;}

">"  { return MORE;}

"<"  { return LESS;}

"?"  {}

"&"  {}

"|"  {}

"&&" {}

"||" {}

"!"  {}

":"  {}

";"  { return SEMICOLON;}

","  { return COMMA;}

"("  { return OCBRACE;}

")"  { return CCBRACE;}

"'"  { return QUOT;}

"{" { open1(); return OPENBC;}

"}" {close1(); return CLOSEBC;}

"[" { return OSBRACE;}

"]" { return CSBRACE;}

%%
