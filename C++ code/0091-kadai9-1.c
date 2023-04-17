#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define QUEUE_SIZE 5
typedef int QUEUE_TYPE;

QUEUE_TYPE gQueue[QUEUE_SIZE+1];
int gQFront = 0;
int gQRear = 0;
bool enqueued[10000000] = {false}; //すでにキューに格納した数値はtrue

void error(char *s){
	fflush(stdout);
	fprintf(stderr, "%s\n", s);
	exit(1);
}

void initQueue(void){
	gQFront=0;
	gQRear=0;
}

int queueNext(int n){
	return (n+1) % (QUEUE_SIZE+1);
}

int chkEmpty(void){
	return gQFront == gQRear;
}

int chkFull(void){
	return queueNext(gQRear) == gQFront;
}

void enqueue(QUEUE_TYPE x){
	if(chkFull()) error("enqueue: フル状態のためエンキューできません.");

	if(!enqueued[x]){
		gQueue[gQRear] = x;
		gQRear = queueNext(gQRear);
		enqueued[x] = true;
		printf("enqueue(%d):\t",x);
	}
	else printf("既に格納されています.\n");
}

int dequeue(void){
	QUEUE_TYPE x;

	if(chkEmpty()) error("dequeue : 空状態のためデキューできません.");

	x=gQueue[gQFront];
	gQFront = queueNext(gQFront);
	enqueued[x] = false;
	return x;
}

void printQueue(void){
	printf("キューの中[ ");
	for(int i = gQFront; i!=gQRear; i=queueNext(i)){
		printf("%d", gQueue[i]);
		if(i!=gQRear) printf(" ");
	}
	printf("]\n");

	printf("先頭=%d,\t 末尾=%d\n",gQFront, gQRear);
	fflush(stdout);
}

int main(void){
	QUEUE_TYPE x;

	initQueue();

	while(1){
		printf("整数を入力してください：\n");
		scanf("%d",&x);
		
		if(x>=0)
		{
			if(x%2==0) enqueue(x);			
			else printf("dequeue() %d:\t", dequeue());
			printQueue();
		}
		else{
			while(!chkEmpty()){
				printf("dequeue() %d:\t", dequeue());
				printQueue();
			}
			return 0;
		}
		
	}
}