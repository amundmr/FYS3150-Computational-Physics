#include <armadillo>
#include <iostream>
#include <cmath>

using namespace std;
using namespace arma;

mat init(double Rho_N, int N) {
  /*
  This function takes Rho_max (which approximates infinity) and number of integration points as input.
  Returns a tridiagonal matrix A.
  */
  double Rho_0, h, d, a, V, Rho;   //Declaring all doubles

  int i;
  Rho_0 = 0.0;                //Defining start and stop. Rho_N = Rho_max which approximates infinity

  h =  (Rho_N-Rho_0)/ (N+1);              //Stepsize
  a = -1 / (h * h);                       //Value of nondiagonal element


  //Setting up tridiagonal matrix A.
  mat A = mat(N,N, fill::zeros);
  for ( i = 0; i < N; i++ ) {             //Calculating the diagonal since it changes with Rho

    Rho = Rho_0 + ((i+1) * h);
    V = Rho*Rho;
    d = 2 / (h * h) + V;                  //Value of diagonal element
    A(i,i) = d;
  }

  //Changing the nondiagnonal elements is easier this way
  A.diag(1)  += a;
  A.diag(-1) += a;

  return A;
}
