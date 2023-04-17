#include <stdio.h>

void swap(int x, int y)
{
	int z;
	z = x;
	x = y;
	y = z;
}

int gcd(int x, int y)
{
	if (y > x) swap(x,y);
	if (y==0) return x;
	else return (gcd(y,x%y));
}

int main()
{
	while(1)
	{
		int x, y;
		scanf("%d%d",&x,&y);
		if ((x<0) || (y<0)) 
		{
			printf("終了\n");		
			return 0;
		}
		printf("gcd(%d,%d) = %d\n",x,y,gcd(x,y));
	}
}