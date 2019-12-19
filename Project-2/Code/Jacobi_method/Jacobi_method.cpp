#include <armadillo>
#include <iostream>
#include <cmath>

using namespace std;
using namespace arma;

mat Jacobi_rotate(mat A, int k, int l, int n);
double off(mat A, int &k, int &l, int n);

vec Jacobi_method(mat A, int n){
	int k = 0;
	int l = 0;

	// Our approximation of 0. Preferably, this tolerance should end the loop.
	double tol = 10e-8;
	double max_iterations = pow(n, 3);	// Controls that the loop doesn't continue eternally.

	// Find the maximum non-diagonal element of the matrix in question, and begin the loop with its indices.
	double max = off(A, k, l, n);

	// The loop rotates the matrix and finds new maximum non-diagonal elements until the non-diagonals are close to 0 (or it runs for too long).
	double i = 0;
	while (i < max_iterations && max > tol){
		A = Jacobi_rotate(A, k, l, n);
		max = off(A, k, l, n);
		i++;
	}

	cout << "Max non-diagonal element after diagonalization: " << max << endl;
	cout << "Number of rotations: " << i << endl;
	return A.diag();
}