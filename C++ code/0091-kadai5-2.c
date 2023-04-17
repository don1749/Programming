#include <stdio.h>
#include <math.h>
typedef struct point{
  int x; /* x座標 */
  int y; /* y座標 */
}POINT;

double distance(POINT p1)
{
  return sqrt(p1.x * p1.x + p1.y * p1.y);
}

int main(void){
  FILE *input = freopen("point-data.txt", "r", stdin); // read only 
  FILE *output = freopen("0091-kadai5-2-output.txt", "w", stdout);
  POINT ptr;
  double d;
  //printf("> (x, y) ");
  while (scanf("%d %d", &ptr.x, &ptr.y) != EOF)
  {
    d = distance(ptr);
    printf("Distance between (%d, %d) and (0, 0) is %.2f. \n", ptr.x, ptr.y, d);
  }
  return 0;
}