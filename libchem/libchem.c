#include <stdlib.h>

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

double chem_matrix_mean(double **M, int m, int n)
{
  int i, j;
  double sum=0;
  for (i=0;i<m;i++)
    for (j=0;j<n;j++)
      sum += M[i][j];
  return sum / (m*n);
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
  double sum;
  int i;
  if (n==0)
    return 0.0;
  else
    for (i=0, sum=0.0; i<n; i++)
      sum+=v[i];
  return sum/n;
}
