#include <stdio.h>
int main()
{
	int a=5;
	while(a>7)
	{
		int b=6;
		while(b>=5)
		{
			printf("While inside while");
		}
	}
	return 0;
}
