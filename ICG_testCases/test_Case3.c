#include <stdio.h>
int main()
{
	int a=5;
	int b=6;
	for(a=1;a<=6;a=a+1)
	{
		int i;
		for(i=0;i<2;i+1)
			printf("For loop inside for loop");
	}
	b=b-9;
	return 0;
}
