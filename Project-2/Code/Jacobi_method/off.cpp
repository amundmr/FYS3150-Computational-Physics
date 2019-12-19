#include <cmath>
#include <armadillo>

using namespace std;
using namespace arma;

// This function returns the maximum non-diagonal element and stores its indices k and l.
double off(mat A, int &k, int &l, int n){
	double max = 0;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (i != j && (max < fabs(A(i,j)))){
				max = fabs(A(i,j));
				k = i;
				l = j;
			}
		}
	}
	return max;
}