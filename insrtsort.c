#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

void insrtsort(int array[], int n)
{
  int i,j;
  int a;
  
  for (j=1;j<n;j++) {
    a = array[j];
    i = j-1;
    while (i>=0 && array[i]>a) {
      array[i+1] = array[i];
      i--;
    }
    array[i+1]=a;
  }
}


int main()
{
  int array[SIZE];
  int i;

  for (i=0; i<SIZE; i++)
    array[i] = rand();

  puts("Before sort:\n");
  for (i=0; i<SIZE; i++)
    printf("%d\n", array[i]);
  printf("\n");

  insrtsort(array, SIZE);

  puts("After sort:\n");
  for (i=0; i<SIZE; i++)
    printf("%d\n", array[i]);

  return 0;
}
