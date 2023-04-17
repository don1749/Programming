#include <stdio.h>
#include <stdlib.h>

int* makeArray(int argc, char* argv[]){
  int* table;
  if (argc < 2)
  {
    fprintf(stderr, "Arguments are not specified.\n");
    exit(1);
  }
  int num;
  num = argc -1;
  table = malloc(sizeof(int) * num);
  if (table == NULL){
    fprintf(stderr, "Memory Shortage.\n");
    exit(1);
  }
  for (int i = 0; i < num; i++)
  {
    *(table + i) = atof(argv[i + 1]);
  }
  return table;
}

int main(int argc, char* argv[])
{
  int *table;
  table = makeArray(argc, argv);
  int num = argc-1;
  double sum = 0.0;
  for (int i = 0; i < num; i++)
  {
    sum += *(table+i);
  }
  printf("Average of %d doubles is %.2f.\n", num, sum / num);
  free(table);
  return 0;
}
