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
  PrintList();
  return 0;
}