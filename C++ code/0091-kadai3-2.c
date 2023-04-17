#include <stdio.h>

int rn(int x)
{
	int A=48109, B=2531011, C=32768;
	return ((A*x + B) %C);
}

int main()
{
	int x=1; double y;
	int t;//乱数の発生回数
	int number[11]={};//各乱数に対応した配列.最初に全ての要素が0にする
	// 宣言が正しかったかどうかをチェック
	// for (int i = 0; i < 11; ++i)
	// {
	// 	printf("%d\t", number[i]);
	// }
	// printf("\n");

	printf("乱数を発生する回数を入力して下さい(1000万回以下) > ");
	scanf("%d",&t);

	for (int i = 0; i < t; ++i)
	{
		x = rn(x);
		// printf("x: %d\t",x%11);
		number[x%11]++;
	}
	// printf("\n");

	for (int i = 1; i <= 10; ++i)
	{
		double frequency;
		frequency = ((double)(number[i]*10000/t))*0.01;
		//printf("%d:\t%d\n",i, number[i]);
		printf("%d が出た割合:\t%.2f ％です\n", i, frequency);
	}
	return 0;
}