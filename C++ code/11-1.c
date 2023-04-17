#include <stdio.h>
#include <stdlib.h>
#include "bstree.h"

int main(int argc, char *argv[]){
   BSTREE_NODE *bstree = NULL;
   BSTREE_NODE *result;
   BSTREE_TYPE x;

   int n1;

   bstree = inputBSTree(bstree, &argv[1], argc -1, &n1);
   if (n1 < 1 || argc -1 - n1 != 2)
      error("引数の指定方法：整数1 整数2 … -- X");
   printf("入力データ　"); printBSTree(bstree, 0, 1);

   x = atoi(argv[n1 + 2]);
   printf("findNode(%d)\n", x);

   result = findNode(bstree, x);
   if (result != NULL){
      printf(" ==> 値 %d のノードは含まれます", x);
      printBSTree(result, 0, 1);
   }
   else printf("==> 値 %d のノードは含まれません", x);
   destroyBSTree(bstree);

   return 0;
}
