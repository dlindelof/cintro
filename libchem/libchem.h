/*
 * Allocates new nxm matrix.
 */
double **chem_new_matrix(int n, int m);

/*
 * De-allocated matrix.
 */
void chem_kill_matrix(double **M);

/*
 * Multiplies matrix A(nxm) by B(mxo) and saves result in C(mxo).
 * It's up to the user to allocate C.
 */
void chem_matrix_multiply(double** C, double** A, double** B, int m , int n, int o);

/*
 * Returns mean of an array of doubles.
 */
double chem_mean(double *v, int n);

/*
 * Returns variance of an array of doubles.
 */
double chem_var(double *v, int n);

/*
 * Returns trace of mxn matrix.
 */
double chem_trace(double **M, int n);

/*
 * Integrates function f over [a,b] through the trapezoidal method, dividing the 
 * interval into 2**n subintervals.
 */
double chem_integrate(double (*f)(double x), double a, double b, int n);

/*
 * Finds root of function f with derivative ff between a and b through
 * Newton-Raphson method.
 */
double chem_root(double (*f)(double x), double (*ff)(double x), double a, double b);
