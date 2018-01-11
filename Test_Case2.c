#include<stdio.h>

int func();

int main(){	
	int +p, a, q;
	char c, *c;
	float b;
	
	/*
	Here is the 
	multiline comment	
	*/

	q= func();     //Function	

	printf("Give a(int) and b(float) values:\n");	

	scanf("%d", &a);
	scanf("%f", &b);
	
	printf("q value= %d\n", q);

	if(a = q){     //ERROR- comparision error, operator should be ==
		printf("a is equal to q\n" );
	}
	else
	{
		printf("a is not equal to q\n");
	}
	
	while{ // ERROR- braces are missing here
		
		while(b){
			
			printf("Inner while loop\n");
			
			b=b-1.0;
		}
		
		printf("Outer while loop\n");
		a/=2;
		
	}
	
	return 0;
}
}

int func(){
	printf("Function implementation");
	return(1);
}
