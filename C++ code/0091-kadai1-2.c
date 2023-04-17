#include <stdio.h>

int main()
{
	int x,y;
	for (x = 1; x <= 7; x++) 
	{
		for (y = 1; y <= x; y++)
		{
			printf("mod(%d,%d) = %d\n",x,y,x%y);
		}
		printf("--------------------\n");
	}
	return 0;
}