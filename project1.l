%{
int keywordcount = 0;
int linecount = 1;
int mcomment = 0;
#define SIZE 100


%}

preprocessor ^#include
header <[a-zA-Z]+\.h>
keywords auto|break|case|const|continue|default|do|double|enum|extern|goto|long|register|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|printf|scanf
line [\n]
space [ \t]
startc "/*"
endc "*/"
alpha [A-Za-z]
varchar [a-zA-Z_][a-zA-Z0-9_]*
number [0-9]*"."[0-9]*
string \".+\"
literal \'[A-Za-z]\'
digit [0-9]
invalidid {digit}+[_a-zA-Z]+[_a-zA-Z0-9]*
pointer "*"{varchar}
array {varchar}"["{digit}+"]"
illegel "@"|"$"
define #define
negdigit -[0-9]*
charlit '.+'

%s comment
%s function

%%

[ \t] ;

\n {  yylineno++;  }

{preprocessor} { return PREPROCESSOR;}

{header} { return HEADER;}

"{" { open1(); return OPENBC;}

"}" { close1(); return CLOSEBC;}

"[" { return OSBRACE;}

"]" { return CSBRACE;}

void {yylval.ival = VOID;keywordcount++; return VOID;}

int {yylval.ival = INT;keywordcount++;  return INT;}

"float" { if(mcomment==0){yylval.ival = FLOAT;keywordcount++;  return FLOAT;}}

"char" { if(mcomment==0){yylval.ival = CHAR;keywordcount++; return CHAR;}}

"if" { if(mcomment==0){keywordcount++; return IF;}}

"while" { if(mcomment==0){keywordcount++; return WHILE;}}

"else" { if(mcomment==0){keywordcount++; return ELSE;}}

"return" { if(mcomment==0){keywordcount++; return RETURN;}}

"printf"  { if(mcomment==0){keywordcount++; return PRINTF;}}

"for"  { if(mcomment==0){keywordcount++; return FOR;}}

{keywords} { if(mcomment==0){keywordcount++; }}

{alpha}({alpha}|{digit})* {yylval.str=strdup(yytext);return VARCHAR;}

{digit}+ { yylval.str=strdup(yytext);return DIGIT;}

{digit}+\.{digit}+ {yylval.str=strdup(yytext);return FDIGIT;}

{negdigit} { yylval.str=strdup(yytext);return NDIGIT;}

{define} ;

{invalidid} {if(mcomment==0)printf("\nERROR 1 : Line number %d : Invalid Identifier  :%s",linecount,yytext);}





{illegel} {if(mcomment==0){printf("\nERROR : Line number %d : Illegel Token  :%s",linecount,yytext);}}


{pointer} {yylval.str=strdup(yytext);}


"=" { return ASSIGNMENT;}

"+" {return PLUS;}


"*" {return MULTIPLY;}

"/" { return DIVIDE;}

"%" ;

"++" { return INCREMENT;}

"--" { return DECREMENT;}

"+=" { return S_ADD;}

"-=" { return S_SUB;}

"*=" { return S_MUL;}

"/=" { return S_DIV;}

"==" {return EQUAL;}

"%=" ;

">=" {return MORE_EQUAL;}

"<=" { return LESS_EQUAL;}

"!=" { return NOT_EQUAL;}

">"  { return MORE;}

"<"  { return LESS;}

"?"  ;

"&"  ;

"|"  ;

"&&" ;

"||" ;

"!"  ;

":"  ;

";"  { return SEMICOLON;}

","  { return COMMA;}

"'"  { return QUOT;}



\/\/.* ;

\/\*(.*\n)*.*\*\/ ;
\'[a-zA-Z]\' return LITERAL;
\".*\"	return STRING;


.	return yytext[0];


%%
