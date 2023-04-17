#include <stdio.h>
#include <stdlib.h> /* malloc 関数，free 関数用*/ 
struct cell{ 
  int value; 
  struct cell *next; 
}; 

void free_memory(struct cell *head ) {
  struct cell *p, *q;
  for ( p = head ; p != NULL ; ) {
  q = p->next;
  free(p);
  p = q;
  }
}

int main(void)
{
  struct cell head; /* ダミーのセル */
  struct cell *p, *q;
  int i;

  q = &head;
  while(1) {
  scanf ("%d",&i);
  if (i == 0) break;
  if ( (p = (struct cell *)malloc(sizeof(struct cell))) == NULL) {
    fprintf(stderr,"メモリ不足です。\n");
    free_memory(head.next);
    exit(1);
  }
  p->value = i;
  q->next = p;
  q = p;
  }
  q->next = NULL;
  for(p = head.next; p != NULL; p = p->next)
  printf("%d ",p->value);
  printf("\n");

  free_memory(head.next);
  return 0;
}