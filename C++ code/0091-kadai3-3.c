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
		number[x%10+1]++;
	}
	// printf("\n");

	//一番出現度がある数を求める
	int max=number[1], maxpos=1;

	for (int i = 2; i <= 10; ++i)
	{
		if(max<number[i])
		{
			max = number[i];
			maxpos = i;
		}
	}

	int sum=0;
	for (int i = 1; i <= 10; ++i)
	{
		int starnum = (int)(number[i]*20/max);
		// printf("%d\n", starnum);
		if (i<10)printf(" %d: ", i);
		else printf("%d: ", i);
		for (int i = 0; i < 20; ++i) 
		{
			if (i<starnum) printf("*");
			else printf(" ");
		}
		printf("\t%d\n", number[i]);
		sum+=number[i];

	}

	printf("===================================\nTOTAL:\t\t\t\t%d\n", sum);
	return 0;
}