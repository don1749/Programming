#include <stdio.h>
void pinc (int *x, int d){
  printf("Kari-Hikisu x %p %p\n", &x, x);
  *x = (*x)+d;
}
int main(void){
  int d, x, b;
  printf("INPUT INTEGERS x AND d\n");
  scanf("%d %d", &x, &d);
  printf(" ADDRESS VALUE\n");
  printf("Jitsu-Hikisu x %p %d\n", &x, x);
  b = x;
  pinc(&x,d);
  printf("%d + %d = %d\n", b, d, x);
  return 0;
}