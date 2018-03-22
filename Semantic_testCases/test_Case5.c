//Return Statements

#include <stdio.h>

int function()
{
	int a[10];
<<<<<<< HEAD

	int i;
	for (i=0; i<10; i++)
	{
		a[i] = 0;
	}

	return(a);

=======

	return(a);   //Error - array returned not int
	
>>>>>>> c2327320606ad81a7c0047ef27ef94e3bcc9197f
}

void main()
{
	int i = 10;
}
