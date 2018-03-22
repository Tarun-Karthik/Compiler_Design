//Function Declaration

#include <stdio.h>

int function()
{
	printf("This function is for nothing");
	
	//Error - int function has void return
}

void add(int a) 
{
	int c = a;

	return(c);   //Error - void function has int return 
}

int function(int b);  //Error - Function redeclaration
void random(void a);  //Error - Parameter of type Void

void main()
{
	float d;
	int b=10; 
}
