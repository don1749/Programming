#include <stdio.h>

int main(void){
	int x = 77;
	int *p = &x;
	double y = 3.14;
	double *py = &y;
	printf("HENSU \t ADDRESS \t SIZE \t VALUE\n");
	printf("x \t %p \t %lu \t %d\n", &x, sizeof(x), x);
	printf("p \t %p \t %lu \t %p\n", &p, sizeof(p), p);
	printf("y \t %p \t %lu \t %lf\n", &y, sizeof(y), y);
	printf("py \t %p \t %lu \t %p\n", &py, sizeof(py), py);
	return 0;
}