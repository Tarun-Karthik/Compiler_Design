#include<stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
int max = 0;
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
extern FILE* yyout;

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


int yywrap(void)        /* called at end of input */
{
    return 1;           /* terminate now */
}


