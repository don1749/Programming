#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct point{
  int x;
  int y;
} POINT;

POINT table[5][MAX];

void push(POINT p, int i)
{
  int j=0;
  while(table[i][j].x != 0 && table[i][j].y != 0) j++;
  table[i][j].x = p.x; table[i][j].y = p.y;
}

int main()
{
  FILE *input = freopen("point-data.txt", "r", stdin); // read only 
  FILE *output = freopen("0091-kadai5-1-output.txt", "w", stdout);
  int i=0, X, Y;
  int cnt[5]={0};
  POINT pt;
  while(scanf("%d %d", &X, &Y) != EOF)
  {
    pt.x = X; pt.y = Y;
    // printf("%d %d\n", X, Y);
    if (X>0 && Y>0)
    {
      push(pt,1);
      cnt[1]++;
    }
    else if(X<0 && Y>0)
    {
      push(pt,2);
      cnt[2]++;
    }
    else if (X<0 && Y<0)
    {
      push(pt,3);
      cnt[3]++;
    }
    else if (X>0 && Y<0)
    {
      push(pt,4);
      cnt[4]++;
    }
    else
    {
      push(pt,0);
    }
    i++;
  } 
  for (int j = 1; j <= 4; j++)
  {
    switch (j)
    {
    case 2:
      printf("The number of II quadrant (LUQ)  ");
      break;
    case 3:
      printf("The number of III quadrant (LLQ)  ");
      break;
    case 4:
      printf("The number of IV quadrant (RLQ)  ");
      break;
    default:
      printf("The number of I quadrant (RUQ)  ");
    }
    printf("%d\n", cnt[j]);
    for (int k = 0; k < cnt[j]; k++)
    {
      printf("(%d, %d)\n", table[j][k].x, table[j][k].y);
    }
  }
  fclose(output);
  return 0;
}
