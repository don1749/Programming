#include <stdio.h>
#include <stdlib.h>
#include "bitree.h"

BITREE_TYPE sumValue(BITREE_NODE *p){
	if(p==NULL) return 0;
	return (p->value + sumValue(p->left) + sumValue(p->right));
}

int main(int argc, char* argv[]){
	char* cmdstring[argc];
	for(int i=0; i<argc-1; i++) cmdstring[i] = argv[i+1]; 
	// for(int i=0;i<argc-1;i++) printf("%d 番目の文字列 %s\n",i,cmdstring[i]);

	BITREE_NODE *root;
	int end = 0;
	root = inputBITree(cmdstring, argc-1, &end);

	printf("入力したデータ");
	printBITree(root, 1, 0);
	printf("=>　合計は　%d　です\n", sumValue(root));
	printf("=>　左部分木の合計は　%d　です\n", sumValue(root->left));
	printf("=>　右部分木の合計は　%d　です\n", sumValue(root->right));
}