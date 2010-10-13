#include <stdio.h>

#define SIZE 2000000UL

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = (low+high)/2;
        if (x < v[mid])
            high = mid - 1;
        else if (x  > v[mid])
            low = mid + 1;
        else    /* found match */
            return mid;
    }
    return -1;   /* no match */
}

int main()
{
  int test_array[SIZE], i, result;
  int x = 12345;

  /* initalize array */

  for (i=0; i<SIZE; i++)
    test_array[i] = i;

  result = binsearch(x, test_array, SIZE);

  if (result != -1)
    printf("Found at %d\n", result);
  else
    printf("Not found.\n");
}
