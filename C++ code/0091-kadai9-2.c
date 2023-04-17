#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool enqueued[10000000] = {false}; //すでにキューに格納した数値はtrue

struct cell{
	int element;
	struct cell *next;
};

struct queue{
	struct cell *front;
	struct cell *rear;
};

void enqueue(int x, struct queue *Q){
	if(enqueued[x]){
		printf("既に格納されています.\n");
		return;
	}

	struct cell *p;
	p = (struct cell*)malloc(sizeof(struct cell));
	if (Q->rear != NULL){
		(Q->rear->next = p);
	}  
	Q->rear = p;

	if(Q->front == NULL) Q->front = p;
	Q->rear->element = x;
	Q->rear->next = NULL;
	printf("enqueue(%d):",x);
	enqueued[x] = true;
	return;
}

void dequeue(struct queue *Q){
	struct cell *q;
	if(Q->front == NULL){
		printf("空状態のためでキューできません.\n");
		exit(1);
	}
	else{
		printf("dequeue() %d:", Q->front->element);
		q = Q->front;
		Q->front = Q->front->next;
		free(q);
	}
	if(Q->front == NULL){
		Q->rear = NULL;
	}
	return;
}

void printQueue(struct queue *Q){
	struct cell *q;
	q = Q->front;
	printf("\nキューの中[ ");
	while(q!=NULL){
		printf("%d ", q->element);
		q = q->next;
	}
	printf("]\n");
	fflush(stdout);

	q=Q->front;
	printf("キューの中のアドレス [ ");
	while(q!=NULL){
		printf("%p", q);
		printf(" ");
		q=q->next;
	}
	printf("%p", q);
	printf(" ]\n"); 
}

int main(void){
	struct queue Q;
	struct cell *q;
	int x;

	Q.front = Q.rear = NULL;

	while(1){
		printf("\n整数を入力してください：\n");
		scanf("%d", &x);
		if(x>=0){
			if(x%2==0) enqueue(x, &Q);
			else dequeue(&Q);
			printQueue(&Q);
		}
		else{
			while(Q.front!=NULL){
				dequeue(&Q);
				printQueue(&Q);
			}
			return 0;
		}
	}
}