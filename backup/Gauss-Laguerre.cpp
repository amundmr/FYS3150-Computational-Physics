//NONE OF THIS SHIT IS EVEN REMOTELY FINISHED
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>
#include <armadillo>

using namespace std;


double f(double r1, double r2){
  double f;

  f = 1.0/(r1-r2);
  return f;
}

vec Laguerre(int n, double x) {
  vec L(n+1);
  L(0) = 1.0;
  L(1) = 1-x
  for (i=1 ; i<n ; i++){
    L(i+1) = ( (2*i + 1 - x) * L(i) - i * L(i-1) ) / ( n+1 );

  }
  return L;
}

void GaussLaguerre(int n,double *x, double *w){
  double integralSolution;
  vec w(n);
  for (i=1 ; i<n ; i++){
    w[i] = xi / (pow(n+1,2) * pow(L(n+1, xi), 2))
    integralSolution += w[i] * f(r1, r2);

  }


}
