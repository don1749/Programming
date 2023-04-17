#include <stdio.h>
#include <stdlib.h>

int n;
int swapCount=0, compareCount=0;//交換回数と比較回数のカウントする変数を宣言

void bubble_sort(int *A); 

int main(int argc, char *argv[])
{
   int i;
   n = argc - 1;
   printf("n = %d\n", n);

   int A[n];

   for (i=1; i < argc; i++) A[i-1] = atoi(argv[i]);

   printf("A = ");
   // for (i=0; i < n; i++) printf(" %d", A[i]);
   // printf("\n");

   bubble_sort(A); // 配列A[0]からA[n-1]のバブルソート

   // printf("A[] =");
   // for (i=0; i < n; i++) printf(" %d", A[i]);
   // printf("\n");
   printf("比較は%d回でした。\n交換は%d回でした。\n", compareCount, swapCount);
   return 0;
}

void bubble_sort(int *A)
{
   int i, j;
   for (i = 0; i < n-1; i = i+1)
   {
      printf("パス%d：\n", i+1);
      for (j = n-1; j > i; j = j-1)
      {
         printf("%d", A[0]);
         for (int k=1; k < n; k++) 
         {
            if(k==j&&A[j-1]<A[j]) printf(" < ");
            else if(k==j&&A[j-1]>A[j]) printf(" > "); 
            else printf("   ");
            printf("%d", A[k]);
         }
         printf("\n");

         if (A[j-1] > A[j]) 
       	{
           	 int t;
      	    t = A[j];
      	    A[j] = A[j-1];
      	    A[j-1] = t;
             swapCount++;
      	}
         compareCount++; 
      }
      for(int k=0; k<n; k++){
         if(k>0 && k<n) printf("   ");
         printf("%d", A[k]);
      }
      printf("\n");
   }
}

