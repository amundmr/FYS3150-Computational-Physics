#include <iostream>
#include <cmath>
#include <armadillo>

using namespace std;
using namespace arma;



vec arma_eig(mat A){
	vec eigval;
	mat eigvec;

	eig_sym(eigval, eigvec, A);

	return eigval;
}
