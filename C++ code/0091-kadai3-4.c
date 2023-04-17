#include <stdio.h>

int rn(int x)
{
	int A=48109, B=2531011, C=32768;
	return ((A*x + B) %C);
}

int main()
{
	int x=1, y=0; 
	int count=0;
	int n;//乱数の発生回数
	// 宣言が正しかったかどうかをチェック
	// for (int i = 0; i < 11; ++i)
	// {
	// 	printf("%d\t", number[i]);
	// }
	// printf("\n");

	printf("乱数を発生する回数を入力して下さい(1000万回以下) > ");
	scanf("%d",&n);
	for (int i = 0; i < n; ++i)
	{
		x = rn(x)%1001;
		y = rn(y)%1001;
		// printf("%d %d\n",x,y);
		if((x*x + y*y) <= 10000) count++;
	}
	float pi;
	pi = ((double)count*40000000/n)*0.0000001;
	printf("%d\n%d\n%.7lf\n", n, count, pi);
	return 0;
}