#include <stdio.h>
#include <ctype.h>

main()
{
  int c;
  c = getchar();

  while (c != EOF) {
    if (isdigit(c))
      putchar(c);
    c = getchar();
  }
}
