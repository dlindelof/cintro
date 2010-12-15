#include <stdio.h>
#include <stdlib.h>

/*initialisateur de matrice*/

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

/* Calcul de la somme de la diagonale de la matrice carrée */

double chem_trace(double **A, int m, int n)

{
	int w = 0;  // traite m
	int v = 0; //  traite n
	double RM = 0;

	while (w<m) {
		while (v<n) {
			if (w==v) {
				RM = RM+A[v][w];
			}
			v++;
		}
		v=0;
		w++;
	}
	return RM;
}


int main(int argc, char *argv[]) {
	
	double moyennetableau;
	
	double tableauvariance;
	
	double grandeur[] = {1,2,3,4,5,6,7,8,9,10}; /* Définition du tableau*/
	
#define M 4
#define N 4
	
	
	double A [M][N] =				{{ 3, 46, 10, 13},
							{  7, 21, 81, 5},
							{  7, 27, 23, 12},			/*définition matrice A*/
							{  42, 26, 54, 1}};
	
	double **a = chem_new_matrix (M,N);
	
	//double **b = chem_new_matrix(N,O);
	
	int i,j;
	for (i=0;i<M;i++)
		for (j=0;j<N;j++)
			a[i][j] = A[i][j];
	
	/*for (i=0;i<N;i++)
		for (j=0;j<O;j++)
			b[i][j] = B[i][j];*/
	
        /* moyennetableau = chem_mean(grandeur, 10);  */
	
	/* tableauvariance = chem_var(grandeur, 10); */
	
	/* printf("La moyenne de la table de double est %f\n", moyennetableau);  */
	
	/* printf("La variance de la table est %g\n", tableauvariance); */
	
	printf("La somme de la diagonale de la matrice A est %g\n",chem_trace(a, M, N));
	
	return 0;
}
