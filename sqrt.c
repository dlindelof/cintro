#include <stdio.h>

double sqrt(double x)
{
  double guess = x;
  double error;
  do {
    guess /= 10;
  } while (guess * guess > x);

  do {
    guess = 0.5 * (guess + x / guess);
    error = x - guess * guess;
    error = error < 0 ? -error : error;
  } while (error > 1e-10);
       
  return guess;
}

int main()
{
  double test = 543;

  printf("Square root of %f is approx %f\n", test, sqrt(test));
}
