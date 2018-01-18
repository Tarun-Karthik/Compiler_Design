#include<stdio.h>

void func(){
	//Single line comment
}

int main(){	
	int +p, 00a, integer;
	char c;
	float b;
	
	/*
	Here is the/*
	multiline comment error	
	*/

	func();     //Function	
	
	scanf("%d",&a );
	scanf("%f",&b );
	
	if(a == 0){
		printf("a is zero\n" );
	}
	else
	{
		printf("a is non zero\n");
	}
	
	while(a){
		
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
