#include <stdio.h>
#include <stdlib.h>
// #define STACK_SIZE 10

typedef struct cell{
	int element;
	struct cell *next;
}CELL;

CELL *push(int x, CELL *init){
	CELL *q, *r;
	r = (CELL *)malloc(sizeof(CELL));
	q = init;
	init = r;
	r->element = x;
	r->next = q;
	return(init);
}

CELL *pop(CELL *init){
	CELL *q;
	if(init!=NULL){
		q = init;
		init = init->next;
		free(q);
		return(init);
	}
	else{
		printf("スタックは空です．\n");
		exit(1);
	}
}

void printstackdata(CELL *init){
	CELL *p;
	p = init;
	printf("スタックの中[ ");

	while(p!=NULL){
		printf("%d ", p->element);
		p = p->next;
	}
	printf("]\n");
	fflush(stdout);
}

void printstackaddress(CELL *init)
{
	CELL *p;
	p = init;
	printf("スタックの中[ ");

	while(p!=NULL){
		printf("%p ", p);
		p = p->next;
	}
	printf("]\n");
	fflush(stdout);
}

int main(void)
{
	CELL *init;
	int cmd;
	printf("番号を入力して下さい (1) PUSH, (2) POP, (3) SHOW(data) (4) SHOW(add) (5) EXIT > ");
	scanf(" %d",&cmd);

	while(1)
	{
		switch(cmd)
		{
			int x;
			case 1:
				printf("プッシュする整数を入力して下さい： ");
				scanf("%d",&x);
				init = push(x, init);
				break;
			case 2:
				if(init == NULL) printf("スタックは空のためポップできません．\n");
				else{
					printf("ポップします．\n");
					init = pop(init);
				}
				break;
			case 3:
				printstackdata(init);
				break;
			case 4:
				printstackaddress(init);
				break;
			case 5:
				printf("終了します．\n");
				return 0;
				break;
			default:
				printf("1 から 5 までの番号を入力して下さい．\n");
				break;
		}
		printf("番号を入力して下さい (1) PUSH, (2) POP, (3) SHOW(data) (4) SHOW(add) (5) EXIT > ");
		scanf(" %d",&cmd);
	}
}