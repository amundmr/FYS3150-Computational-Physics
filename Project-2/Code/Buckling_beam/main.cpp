#include <iostream>
#include <cmath>
#include <armadillo>

using namespace std;
using namespace arma;

// Our implementation of the Jacobi method. Returns a vector with the eigenvalues.
vec Jacobi_method(mat A, int n);
// A simple premade eigenvalue-solver using armadillo.
vec arma_eig(mat A);

int main(){
	int n = 10;	// Small n, for legibility. Works for any size matrix.

	// Making tridiagonal matrix
	mat A(n,n, fill::zeros);
	A.diag() += 2;
	A.diag(-1) -= 1;
	A.diag(1) -= 1;

	// Variables to store time before and after the functions have run.
	clock_t t0,t1;

	t0 = clock();
	vec arma_eigvals = arma_eig(A);
	t1 = clock();

	double t_arma = (double (t1 - t0))/CLOCKS_PER_SEC;	// Time spent on arma's eigenvalue solver.

	t0 = clock();
	vec eigvals = Jacobi_method(A, n);
	t1 = clock();

	double t_jacobi = (double (t1- t0)) /CLOCKS_PER_SEC;	// Time spent on our eigenvalue solver.

	cout << "------------------------------------" << endl;
	cout << "Eigenvalues from arma solver: " << endl;
	cout << arma_eigvals << endl;
	cout << "Time spent on arma solver: " << t_arma << "s" << endl;
	cout << "------------------------------------" << endl;
	cout << "Eigenvalues from our Jacobi solver: " << endl;
	cout << sort(eigvals) << endl;
	cout << "Time spent on our solver: " << t_jacobi << "s" << endl;

	vec lambda = zeros<vec>(n);
	for (int i=0; i<n; i++){
		lambda(i)=2-2*cos((i+1)*M_PI/(n+1));
	}
	cout << "------------------------------------" << endl;
	cout << "Analytical values: " << endl << lambda << endl;
}