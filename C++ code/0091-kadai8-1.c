#include <stdio.h>
#include <stdlib.h>
#define STACK_SIZE 10

int array[STACK_SIZE];
int stack_ptr;

void initstack(void)
{
	stack_ptr = 0;
}

int chkempty(void)
{
	return stack_ptr==0;
}

int chkfull(void)
{
	return stack_ptr==STACK_SIZE;
}

void push(int x)
{
	array[stack_ptr] = x;
	stack_ptr++;
}

void pop(void)
{
	// int x = array[stack_ptr-1];
	stack_ptr--;
	// return x;
}

void printstack(void)
{
	printf("スタックの中[");
	for (int i = 0; i < stack_ptr; ++i)
	{
		printf("%d", array[i]);
		if(i != stack_ptr-1) printf(" ");
	}
	printf("]\n");
}

int main(void)
{
	initstack();
	int cmd;
	printf("番号を入力して下さい (1) PUSH, (2) POP, (3) SHOW (4) EXIT > ");
	scanf(" %d",&cmd);

	while(1)
	{
		switch(cmd)
		{
			int x;
			case 1:
				if(chkfull()) printf("スタックはフルのためプッシュできません．\n");
				else{
					printf("プッシュする整数を入力して下さい： ");
					scanf("%d",&x);
					push(x);
				}
				break;
			case 2:
				if(chkempty()) printf("スタックは空のためポップできません．\n");
				else{
					printf("ポップします．\n");
					pop();
				}
				break;
			case 3:
				printstack();
				break;
			case 4:
				printf("終了します．\n");
				return 0;
				break;
			default:
				printf("1 から 4 までの番号を入力して下さい．\n");
				break;
		}
		printf("番号を入力して下さい (1) PUSH, (2) POP, (3) SHOW (4) EXIT > ");
		scanf(" %d",&cmd);
	}
}

