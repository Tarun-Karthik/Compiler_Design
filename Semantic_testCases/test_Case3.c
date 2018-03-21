//Call expressions

#include <stdio.h>
void main()
{
	int i;
	
	for(i=0 ; i<5; i++)
	{
		int b=10;
		b = b - i;
	}

	b = b +5;  // Error - b undeclared in current scope
}

