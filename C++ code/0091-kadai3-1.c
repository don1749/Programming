#include <stdio.h>

int rn(int x)
{
	int A=48109, B=2531011, C=32768;
	return ((A*x + B) %C);
}

int main()
{
	int x=1; double y;
	y = (double) x; 
	for(int i=1;i<10;i++){
		printf("%d\t%d\t%2.4f\t\t%2.4f\n",x,x%11, y, y*10.0-5);
		x = rn(x);
		y = ((double)(x%1001))*0.001;
	}
	return 0;
}
