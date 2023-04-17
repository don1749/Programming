#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int rn(int x)
{
	int A=48109, B=2531011, C=32768;
	return ((A*x + B) %C);
}

int max(int a, int b)
{
	if(a<b) return b;
	else return a;
}

int main()
{
	int a, b; 
	int n, m=0;

	printf("積分区間の下限値aを入力して下さい > "); scanf("%d",&a);
	printf("積分区間の下限値bを入力して下さい > "); scanf("%d",&b);
	printf("乱数を発生する回数を入力して下さい(1000万回以下) >"); scanf("%d",&n);

	int x=1, y=0;
	double rangex=(double)(abs(b-a)), rangey=(double)(max(a,b)*max(a,b));

	for (int i = 0; i < n; ++i)
	{
		x = rn(x), y = rn(y);
		double x0 = (double)(x%1001)*0.001*rangex+(double)(a);
		double y0 = (double)(y%1001)*0.001*rangey;
		//printf("%f %f\n",x0,y0);
		if((x0*x0)>=y0) m++;
	}

	float s, ds;
	s = rangex*rangey*((m*1000/n)*0.001);
	ds = fabs(s-(double)((b*b*b-a*a*a)/3));
	printf("--- 計算結果 ---\n");
	printf("積分値(理論値) = %.7lf\n積分値(シミュレーション値) = %.7lf\n積分値の誤差 = %.7lf\n", (double)((b*b*b-a*a*a)/3), s, ds);
	return 0;
}