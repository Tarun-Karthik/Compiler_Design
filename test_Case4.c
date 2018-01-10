#include<stdio.h>

int x1;

void recurse()
{
	recurse();
}

void main()
{
	recurse();
	// recurse();
	recurse();
}