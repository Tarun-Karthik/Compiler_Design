//Call expressions

#include <stdio.h>

void function(int b){
	
	//Nothing to do with b
}

void main()
{
	int i;
	float c;
	
	for(i=0 ; i<5; i++)
	{
		int b=10;
		b = b - i;
	}

	b = b +5;  // Error - b undeclared in current scope

	function(c);  //Error - parameter type doesn't match with argument type

	function(b, c);  //Error - Number of parameters and arguments donot match
}

