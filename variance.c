#include <stdio.h>

float measurements[] = {34124.75f, 34124.48f, 34124.90f, 34125.31f, 34125.05f, 34124.98f};

float one_pass(float data[], int n)
{
  int i;
  float variance;
  float sum_squares, mean;

  for (i=0, sum_squares=mean=0; i<n; i++) {
    sum_squares += data[i] * data[i];
    mean += data[i];
  }

  mean /= n;
  
  variance = (sum_squares - n*mean*mean)/(n-1);
  return variance;
}

float two_pass(float data[], int n)
{
  int i;
  float mean, variance;

  for (i=0, mean=0; i<n; i++) {
    mean += data[i];
  }
  mean /= n;

  for (i=0, variance=0; i<n; i++) {
    variance += (data[i] - mean) * (data[i] - mean);
  }
  variance /= (n-1);
  return variance;
}

int main()
{
  printf("One pass: variance = %f\n", one_pass(measurements, 6));
  printf("Two pass: variance = %f\n", two_pass(measurements, 6));
}
