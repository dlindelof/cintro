#include <stdio.h>
#include <time.h>

main() {
  printf("Char: %ld bytes\n", sizeof(char));
  printf("Short: %ld bytes\n", sizeof(short));
  printf("Int: %ld bytes\n", sizeof(int));
  printf("Long: %ld bytes\n", sizeof(long));
  printf("Float: %ld bytes\n", sizeof(float));
  printf("Double: %ld bytes\n", sizeof(double));
  printf("Long double: %ld bytes\n", sizeof(long double));

  printf("Time_t: %ld bytes\n", sizeof(time_t));
}
