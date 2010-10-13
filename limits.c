#include <stdio.h>
#include <limits.h>

main()
{
  unsigned int ui = 0;
  signed int si = 0;

  ui = ui - 1; /* underflow, wrap around to UINT_MAX */

  printf("maximum unsigned int: %u\n", ui);
  printf("maximum unsigned int from limits.h: %u\n", UINT_MAX);
  
  while (si >= 0)
    si = si + 1;

  printf("minimum signed int: %d\n", si);
  printf("minimum signed int from limits.h: %d\n", INT_MIN);
  printf("minimum signed int from bit manipulation: %d\n", -(int)((unsigned int) ~0 >> 1) - 1);
  si = si - 1;
  printf("maximum signed int: %d\n", si);
  printf("maximum signed int from limits.h: %d\n", INT_MAX);
  

}
