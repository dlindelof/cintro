#include <stdio.h>

main()
{
  unsigned short even_more = 61546;
  signed short negative = -3990;

  printf("%d is represented as 0x%hX\n", even_more, even_more);
  printf("%d is represented as 0x%hX\n", negative, negative);
}
