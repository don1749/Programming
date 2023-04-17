#include <stdio.h>
int main(void)
{
  int x = 77, y = 115;
  int *p;
  printf("HENSU \t ADDRESS \t VALUE \t INDIRECT\n");
  printf("x \t %p \t %d\n", &x, x);
  printf("y \t %p \t %d\n", &y, y);
  p = &x;
  printf(" p = &x is executed.\n");
  printf("p \t %p \t %p \t %d\n", &p, p, *p);
  p = &y;
  printf(" p = &y is executed.\n");
  printf("p \t %p \t %p \t %d\n", &p, p, *p);
  return 0;
}