#include <stdio.h>
#include <stdlib.h>

int cmp(const void * a, const void * b)
{
  int A = *(int *)a;
  int B = *(int *)b;
  return A - B;
}


int main()
{
  int numbers[10000];
  int number;
  int counter=0;
  int i;

  /* Read file in memory */
  while (scanf("%d", &number) != EOF) {
    numbers[counter] = number;
    counter++;
  }

  /* Sort it */
  qsort(numbers, counter, sizeof(int), cmp);

  /* Print it */
  for (i=0;i<counter;i++)
    printf("%d\n", numbers[i]);

  return 0;
}
