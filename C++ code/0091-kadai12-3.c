#include <stdio.h>
#include <stdlib.h>

void sift_down(int *A, int x, int m); 
void build_heap(int *A); 
void heap_sort(int *A); 
void printf_heap(int *A, int m);
void printf_sub(int *A, int i, int m);

int n;

int main(int argc, char *argv[])
{
  n = argc - 1;
  printf("n = %d\n", n);
  int A[n];

  for(int i=1; i < argc; i++) A[i-1] = atoi(argv[i]);
  
  printf("A[] =");
  
  for(int i=0; i < n; i++) printf(" %d", A[i]);
  printf("\n");

  heap_sort(A);

  printf("A[] =");
  for(int i=0; i < n; i++) printf(" %d", A[i]);
  printf("\n");

  return 0;
}

void sift_down(int *A, int x, int m) {
  int snode, svalue;
  while(2*x+1 <= m-1){                
    if (2*x+1 == m-1){                 
      snode = 2*x+1;  svalue = A[2*x+1];
    }
    else{                              
      if(A[2*x+1] > A[2*x+2]){        
        snode = 2*x+1;  svalue = A[2*x+1];
      }
      else{
        snode = 2*x+2;  svalue = A[2*x+2];
      } 
    }
    if(A[x] < svalue){                // 親の方が小さいため節点を交換
      A[snode] = A[x];  A[x] = svalue;  x = snode;
    }
    else return;                        // 子の方が小さい（終了）
  }
}

void build_heap(int *A)
{
  int x;
  for (x = n/2-1; x >= 0; x = x-1) sift_down(A, x, n);
}

void heap_sort(int *A)
{
  int m;
  build_heap(A);
  for(m = n-1; m > 0; m = m-1)
  {
    printf_heap(A, m+1);
    
    int t; 
    t = A[0]; 
    A[0] = A[m]; 
    A[m] = t; 
    
    sift_down(A, 0, m);
    
    for(int i=m; i<n; i++) printf("%d ", A[i]);
    printf("\n");
  }
}

//　ノード数mのヒープを出力
void printf_heap(int *A, int m)
{
  printf_sub(A, 0, m);
  printf("\n");
}

// A[i]に該当するノードの部分木を出力
void printf_sub(int *A, int i, int m)
{
  if(i>=m) {printf("_"); return;}
  if(i<m && i*2+1>=m) printf("%d", A[i]);
  else{
    printf("[");
    printf("%d ", A[i]);
    printf_sub(A, i*2+1, m);
    printf(" ");
    printf_sub(A, i*2+2, m);
    printf("]");
  }
}


