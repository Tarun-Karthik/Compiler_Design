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

%s comment

%%

[/]{1}[/]{1}[a-zA-Z0-9 ]* {
  printf("\nline number : %d : %s : is a comment\n",linecount,yytext);
 }

{keywords} {
    keywordcount++;
    printf("\nline number : %d : C Keyword(%d) : %s\n",linecount,keywordcount,yytext);
    }

{startc} 	{BEGIN comment; printf("\nmultiline comment starts at line %d\n",linecount);}
<comment>\n	{BEGIN comment;  linecount++;}
<comment>[a-zA-Z0-9 ]* ;
<comment>{endc}	{BEGIN 0; printf("\nmultiline comment end at line %d\n",linecount); }

{line} {
  linecount++;
  }

[a-z|A-z]+ {
  printf("\nline number : %d : %s is not a C Keyword\n",linecount,yytext);
  }

{preprocessor} {printf("\nline number : %d : %s is a preprocessor\n",linecount,yytext);}

{header} {printf("\nline number : %d : %s is a header\n",linecount,yytext);}

{varchar} {printf("\nline number : %d : %s is a variable name\n",linecount,yytext);}

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
