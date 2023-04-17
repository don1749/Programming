#include <stdio.h>

int main()
{
  int x = 77; int *px = &x;
  int y = 115; int *py = &y;
  int tmp;
  int *p = &tmp;
  printf("HENSU \t ADDRESS \t VALUE\n");
  printf("x \t %p \t %d\n", &x, x);
  printf("y \t %p \t %d\n", &y, y);
  // printf("p \t %p \t %p\n", &p, p);

  *p = x; x = y; y = *p; 
  printf(" exchange x and y\n");
  printf("x \t %p \t %d\n", &x, x);
  printf("y \t %p \t %d\n", &y, y);
}