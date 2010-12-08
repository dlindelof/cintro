#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#define EPS 1e-5

double **chem_new_matrix(int m, int n)
{
  double **M;
  int i;
  M = (double **)malloc(m*sizeof(double *));
  if (M == NULL) return NULL;
  M[0] = (double *)malloc(m*n*sizeof(double));
  if (M[0] == NULL) {
    free(M);
    return NULL;
  }
  for (i=1;i<m;i++)
    M[i] = M[0] + i*n;
  return M;
}

void chem_kill_matrix(double **M)
{
  free(M[0]);
  free(M);
}

void chem_matrix_multiply(double **C, double **A, double **B, int n, int m, int o)
{
  int i, j, k;

  for (i=0;i<n;i++) {
    for (j=0;j<o;j++) {
      C[i][j] = 0;
      for (k=0;k<m;k++) {
        C[i][j] += A[i][k] * B[k][j];
      }
    }
  }
}

double chem_mean(double *v, int n)
{
  double sum = 0;
  int i;
  if (n==0)
    return 0.0;
  else
    for (i=0, sum=0.0; i<n; i++)
      sum+=v[i];
  return sum/n;
}

double chem_var(double *v, int n)
{
  double mean = chem_mean(v, n);
  double sum = 0;
  int i;
  for (i=0; i<n; i++)
    sum += (v[i]-mean)*(v[i]-mean);
  return sum/(n-1);
}

double chem_trace(double **M, int n)
{
  double trace=0;
  int i;
  for (i=0; i<n; i++)
    trace += M[i][i];
  return trace;
}

double chem_integrate(double (*f)(double x), double a, double b, int n)
{
  double h = (b-a)/n;
  double x = a+h;
  double result = 0;
  int i; /* don't do any while(x<b-h) crap */
  for (i=1;i<n;i++) {
    result += f(x);
    x+=h;
  }
  result += 0.5 * (f(a)+f(b));
  return result * h;
}

double chem_root(double (*f)(double x), double (*ff)(double x), double x)
{
  int n=0;
  double try=x;
  while (fabs(f(try)) > EPS) {
    try -= f(try)/ff(try);
    if (n++ > 1e4) {
      printf("chem_root: error: no root found after 1e4 loops");
      exit(EXIT_FAILURE);
    }
  }
  return try;
}
      

int chem_random(int n)
{
  int try;
  int rand_max_mod_n = RAND_MAX % n;
  do
    try = rand();
  while (try>=RAND_MAX-rand_max_mod_n);
  return try % n;
}

void chem_pivot(double **A, double **B, int m, int n)
{}
