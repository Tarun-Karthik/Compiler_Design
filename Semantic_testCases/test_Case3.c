//Call expressions

#include <stdio.h>

void function(int b){
	
	//Nothing to do with b
}

void main()
{
	int i;
<<<<<<< HEAD

=======
	float c;
	
>>>>>>> c2327320606ad81a7c0047ef27ef94e3bcc9197f
	for(i=0 ; i<5; i++)
	{
		int b=10;
		b = b - i;
	}

<<<<<<< HEAD
	b = b + 5;  // Error - b undeclared in current scope
=======
	b = b +5;  // Error - b undeclared in current scope

	function(c);  //Error - parameter type doesn't match with argument type

	function(b, c);  //Error - Number of parameters and arguments donot match
>>>>>>> c2327320606ad81a7c0047ef27ef94e3bcc9197f
}

void hello()
{

 b = 1;
}
