#include <iostream>
#include <cmath>
#include <armadillo>


using namespace std;
using namespace arma;

mat Jacobi_rotate(mat A, int k, int l, int n){
	double s, c;	// Representing sin(theta) and cos(theta)

	// If the maximum non-diagonal element is 0, don't rotate.
	if (A(k,l) == 0){
		s = 0.0;
		c = 1.0;
	}
	// Calculate the variable tau, giving tan(theta), which in turn gives us the cos and sin values we seek.
	else {
		double t, tau;	// t represents tan(theta)
		tau = (A(l,l) - A(k,k))/(2*A(k,l));

		if (tau >= 0){
			t = 1.0/(tau + sqrt(1.0 + tau*tau));
		} else {
			t = -1.0 /(-tau + sqrt(1.0 + tau*tau));
		}

		c = 1.0/sqrt(1.0 + t*t);
		s = t * c;
	}

	// Introduce a new matrix B which is going to be the transformed version of A.
	mat B = A;

	// Orthogonal transformation follows
	B(0,0) = A(0,0);
	B(k, k) = A(k,k)*pow(c,2) - 2.0*A(k,l)*c*s + A(l,l)*pow(s,2);
	B(l, l) = A(l,l)*pow(c,2) + 2.0*A(k,l)*c*s + A(k,k)*pow(s,2);
	B(k, l) = 0.0;
	B(l, k) = 0.0;

	for (int i = 0; i < n; i++){
		if (i != k && i != l){
			B(i,i) = A(i,i);
			B(i, k) = A(i,k)*c - A(i,l)*s;
			B(i, l) = A(i,l)*c + A(i,k)*s;
			B(k, i) = B(i,k);
			B(l, i) = B(i,l);
		}
	}
	return B;
}