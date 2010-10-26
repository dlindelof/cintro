#include <stdio.h>
#include <ctype.h>

int main()
{
  int c;
  long nblanks = 0;

  while ((c = getchar()) != EOF)
    if (isspace(c)) nblanks++;

  printf("Number of blanks: %ld\n", nblanks);
}
