#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
  int data;
  struct cell *next;
} CELL;

CELL head; /* ダミーのセル */
void InsertCell(int x) /* 新しいセルの挿入用関数 */
{
  CELL *p, *new;
  new = (CELL *)malloc(sizeof(CELL));
  new->data = x;
  for(p = &head ; p->next != NULL ; p = p->next) {
    if(new->data < (p->next)->data) {
    new->next = p->next;
    p->next = new;
    return;
    }
    // x がすでにリストにあるときは、何もしないで終了
    else if(new->data == (p->next)->data)
    return;
  }
  new->next = NULL;
  p->next = new;
}

void DeleteCell(int x)
{
  CELL *p;
  p = &head;
  if(p->data == x)
  {
    if(p->next == NULL)
    {
      free(p);
      return;
    }
    p->data=p->next->data;
    p->next=p->next->next;
    return;
  }
  while(p->next != NULL && p->next->data != x) p = p->next;
  if (p->next == NULL){ 
      printf("そのような数字はありません。\n");
      return;
  }
  p->next = p->next->next;
  return;
}

void DeletePositiveCell()
{
  CELL *p;
  p = &head;
  while(p->next != NULL && p->next->data <= 0) p = p->next;
  p->next = NULL;
  return;
}

void DeleteNegativeCell()
{
  CELL *p, *tmp;
  p = &head;
  tmp = &head;
  while(p->next!=NULL && p->next->data < 0) p = p->next;
  tmp->next = p->next;
  return;
}

void DeleteEvenCell()
{
  CELL *p;
  p = &head;
  while(p->next!=NULL)
  {
    if(p->next->data%2==0 && p->next->data!=0)
    {
      CELL *tmp;
      tmp = p->next;
      p->next = tmp->next;
      free(tmp);
      continue;
    }
    p = p->next;
  }
}

void PrintList() /* 画面表示用関数 */
{
  CELL *p;
  for(p = &head ; p->next != NULL ; p = p->next)
    printf("%d ", (p->next)->data);
    printf("\n");
}

int main(void)
{
  int x;
  while(1){
    printf("整数を入力してください: ");
    scanf("%d", &x);
    if( x == 0) break;
    InsertCell(x);
  }
  while(1)
  {
    char cmd;
    printf("コマンドを入力してください(i, d, p, n, e, s, x): ");
    scanf(" %c", &cmd);
    int num;
    switch (cmd)
    {
    case 'i': 
      printf("整数を入力してください: ");
      scanf("%d", &num);
      InsertCell(num);
      break;
    case 'd':
      printf("整数を入力してください: ");
      scanf("%d", &num);
      DeleteCell(num);
      break;
    case 'p':
      DeletePositiveCell();
      break;
    case 'n':
      DeleteNegativeCell();
      break;
    case 'e':
      DeleteEvenCell();
      break;
    case 's':
      PrintList();
      break;
    case 'x':
      printf("終了です。\n");
      return 0;
    default:  
      printf( "正しいコマンドを入力してください！\n");
      break;
    }
  }
}
