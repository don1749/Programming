#include <stdio.h>
#include <math.h>
#define PI 3.141592654
typedef struct point
{
  double x;
  double y;
}POINT;

void rotatePoint(POINT *p1, int dt)
{
  double theta = dt*PI/180;
  double px = p1->x;
  p1->x = (p1->x)*cos(theta) + (p1->y)*sin(theta); 
  p1->y = (p1->y)*cos(theta) - px*sin(theta);
}

int main()
{
  POINT p;
  int dt;
  printf("> (x1, y1) ");
  scanf("%lf %lf", &p.x, &p.y);
  printf("> (dt) ");
  while(scanf("%d", &dt) != EOF)
  {
    rotatePoint(&p, dt);
    printf("(%.0lf, %.0lf)\n", p.x, p.y);
    printf("> (dt) ");
  }
  return 0;
}
