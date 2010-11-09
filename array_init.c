#include <stdio.h>

/* Test what a non-initialized array holds */

char array[10]; /*= {'a'};*/

int main()
{
  int i;

  for (i=0;i<10;i++) {
    putchar(array[i]);
  }
  putchar('|');
  putchar('\n');
}
