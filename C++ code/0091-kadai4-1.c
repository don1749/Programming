#include <stdio.h>

int main(void){
	int x = 77;
	double y = 3.14;
	printf("HENSU  ADDRESS \t SIZE \t VALUE\n");
	printf("x \t %p \t %lu \t %d\n", &x, sizeof(x), x);
	printf("y \t %p \t %lu \t %f\n", &y, sizeof(y), y);
	return 0;
}