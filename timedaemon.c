#include <stdio.h>
#include <time.h>
#include <limits.h>

main() {
  time_t largest = 0x7FFFFFFF;

  printf("Largest: %s", ctime(&largest));
}
