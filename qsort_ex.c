#include <stdlib.h>
#include <stdio.h>

int cmpint(const void *a, const void *b)
{
  return *(int *)a - *(int *)b;
}

int main()
{
  int number[10000];
  int count=0, i;

  /* Fill up the array */
  while(scanf("%d", &number[count++])!=EOF);
  count--;

  /* Sort it */
  qsort(number, count, sizeof(int), cmpint);

  /* Print results */
  for (i=0;i<count;i++)
    printf("%d\n", number[i]);
 
  return 0;
}
