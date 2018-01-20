#include<stdio.h>

int x1;

void recurse()
{
	recurse();
}

void main()
{
	int c, t;
	1char p;       //ERROR - Invalid Identifier
	recurse();
	// recurse();
	recurse();
}
