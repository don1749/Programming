#include <stdio.h>

//階乗の関数
int factorial(int x)
{
	if (x==1) return 1;
	else return (x*factorial(x-1)); //f(x) = xf(x-1)
}

int main()
{
	//事前に1！から10！までの値を格納しておく
	int fact[11]; 
	for (int i=1; i<=10; i++) fact[i] = factorial(i);

	// query処理
	while(1)
	{
		int x;
		scanf("%d",&x);
		if ((x<1) || (x>10))
		{
			printf("終了！\n");
			return 0;
		}
		printf("%d! = %d\n",x,fact[x]);
	}
}
