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

/*struct SymbTab
{
 char label[100],symbol[100];
 int addr;
struct SymbTab *next;};
struct SymbTab *first,*last;*/

struct sym
{
	int sno;
	char token[100];
	int type[100];
	int tn;
	int addr;
	float fvalue;
	int scope;
}st[100];

/*extern FILE* yyout;

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


int yywrap(void)        /* called at end of input
{
    return 1;           /* terminate now
}

*/


int n=0,arr[10];

int returntype_func(int ct)
{
	return arr[ct-1];
}

void storereturn( int ct, int returntype )
{
	arr[ct] = returntype;
	return;
}

void insertscope(char *a,int s)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(!strcmp(a,st[i].token))
		{
			st[i].scope=s;
			break;
		}
	}
}
int returnscope(char *a,int cs)
{
	int i;
	int max = 0;
	for(i=0;i<=n;i++)
	{
		if(!strcmp(a,st[i].token) && cs>=st[i].scope)
		{
			if(st[i].scope>=max)
				max = st[i].scope;
		}
	}
	return max;
}



int lookup(char *a)
{
	int i;
	for(i=0;i<n;i++)
	{
		if( !strcmp( a, st[i].token) )
			return 0;   // if found return 0
	}
	return 1; // if not found return 1
}


int returntype(char *a,int sct)
{
	int i;
	for(i=0;i<=n;i++)
	{
		if(!strcmp(a,st[i].token) && st[i].scope==sct)
			return st[i].type[0];
	}
}

void check_scope_update(char *a,char *b,int sc)
{
	int i,j,k;
	int max=0;
	for(i=0;i<=n;i++)
	{
		if(!strcmp(a,st[i].token)   && sc>=st[i].scope)
		{
			if(st[i].scope>=max)
				max=st[i].scope;
		}
	}
	for(i=0;i<=n;i++)
	{
		if(!strcmp(a,st[i].token)   && max==st[i].scope)
		{
			float temp=atof(b);
			for(k=0;k<st[i].tn;k++)
			{
				if(st[i].type[k]==258)
					st[i].fvalue=(int)temp;
				else
					st[i].fvalue=temp;
			}
		}
	}
}
void storevalue(char *a,char *b,int s_c)
{
	int i;
	for(i=0;i<=n;i++)
	{
		if(!strcmp(a,st[i].token) && s_c==st[i].scope)
		{
			st[i].fvalue=atof(b);
		}
	}
}


void insert(char *name, int type, int addr)
{
	int i;
	if(lookup(name))
	{ // if not found
		strcpy(st[n].token,name);
		st[n].tn=1;
		st[n].type[st[n].tn-1]=type;
		st[n].addr=addr;
		st[n].sno=n+1;
		n++;
	}
	else
	{ // if found
		for(i=0;i<n;i++)
		{
			if(!strcmp(name,st[i].token))
			{
				st[i].tn++;
				st[i].type[st[i].tn-1]=type; //type can be many
				break;
			}
		}
	}
	return;
}



void insert_dup(char *name, int type, int addr,int s_c)
{
	strcpy(st[n].token,name);
	st[n].tn=1;
	st[n].type[st[n].tn-1]=type;
	st[n].addr=addr;
	st[n].sno=n+1;
	st[n].scope=s_c;
	n++;
	return;
}

void print()
{
	int i,j;
printf("\nSymbol Table\n\n");
	printf("\nSNo.\tToken\tAddress\tValue\tScope\tType\n");
	for(i=0;i<n;i++)
	{
		if(st[i].type[0]==258)
			printf("%d\t%s\t%d\t%d\t%d",st[i].sno,st[i].token,st[i].addr,(int)st[i].fvalue,st[i].scope);
		else
			printf("%d\t%s\t%d\t%.1f\t%d",st[i].sno,st[i].token,st[i].addr,st[i].fvalue,st[i].scope);
		for(j=0;j<st[i].tn;j++)
		{
			if(st[i].type[j]==258)
				printf("\tINT");
			else if(st[i].type[j]==259)
				printf("\tFLOAT");
			else if(st[i].type[j]==271)
				printf("\tFUNCTION");
			else if(st[i].type[j]==269)
				printf("\tARRAY");
			else if(st[i].type[j]==260)
				printf("\tVOID");
		}
		printf("\n");
	}
	return;
}
