#include <stdio.h>

typedef struct point
{
  double x;
  double y;
}POINT;

POINT getMiddlePoint(POINT p1, POINT p2)
{
  POINT p;
  p.x = (p1.x + p2.x)/2;
  p.y = (p1.y  +p2.y)/2;
  return p;
}

int main()
{
  POINT p1, p2;
  printf(">(x1, y1) ");
  scanf("%lf %lf", &p1.x, &p1.y);
  printf(">(x2, y2) ");
  scanf("%lf %lf", &p2.x, &p2.y);
  POINT res;
  res = getMiddlePoint(p1,p2);
  printf("Midpoint between (%.0f,%.0f) and (%.0f, %.0f) is (%.1lf, %.1f).\n", p1.x, p1.y, p2.x, p2.y, res.x, res.y);
}