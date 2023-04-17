#include <stdio.h>

int main()
{
	int x,y;
	for (x = 9; x > 0; x -= 2) 
	{
		for (y = 1; y <= x; y += 2)
		{
			printf("%d + %d = %d\n",x,y,x+y);
		}
	}
	return 0;
}