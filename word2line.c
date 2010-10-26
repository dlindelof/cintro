#include <stdio.h>
#include <ctype.h>

#define IN  1
#define OUT 0

int main()
{
  int c, state = OUT;

  while ((c = getchar()) != EOF) {
    if (isspace(c)) {
      if (state == IN) {
        state=OUT;
        putchar('\n');
      }
    } else if (state==OUT) {
      state = IN;
      putchar(c);
    } else
      putchar(c);
  }
  
  return 0;
}
