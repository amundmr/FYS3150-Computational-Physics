#include "catch.hpp"

#include <iostream>
#include <cmath>
#include <armadillo>

using namespace std;
using namespace arma;

double int_function(double x1, double y1, double z1, double x2, double y2, double z2);
void gauss_laguerre(double *, double *, int, double);
void gauleg(double, double, double *, double *, int);
double gammln(double);
double func_polar_laguerre(double r1, double t1, double p1, double r2, double t2, double p2);

TEST_CASE("Test int_function return correct exponential function"){
  //Initializing points
  double x1, y1, z1, x2, y2, z2;
  x1 = 0.2, y1 = 0.2, z1 = 0.2;
  x2 = -0.2, y2 = -0.2, z2 = -0.2;

  //Analytical solution definition
  double analSol = 0.09032900125;

  //Getting calculated solution
  double calcSol = int_function(x1, y1, z1, x2, y2, z2);

  //Require that the calculation is close to the analytical
  REQUIRE(calcSol == Approx(analSol).epsilon(1e-9));

}


TEST_CASE("Test gauleg return correct mesk points and weights"){
  //Analytical solutions:
  int N = 5;
  double *xAnalSol = new double[N];   //Defining space in mem for analytical mesh points (which is the roots of the n'th legendre pol)
  double *wAnalSol = new double[N];   //space in mem for analytical weights
  xAnalSol[2] =	0.0, xAnalSol[1] =	-0.5384693101056831, xAnalSol[3] =	0.5384693101056831, xAnalSol[0] =	-0.9061798459386640, xAnalSol[4] =	0.9061798459386640;
  wAnalSol[2] = 0.5688888888888889 , wAnalSol[3] = 0.4786286704993665 , wAnalSol[1] = 0.4786286704993665 , wAnalSol[0] = 0.2369268850561891 , wAnalSol[4] = 0.2369268850561891;
                                      //Analytical solutions found at https://pomax.github.io/bezierinfo/legendre-gauss.html
                                      //The indexing here is weird because the index needs to match that of the gauleg func.


  //Calculated solutions
  double x1 = -1.0, x2 = 1.0;          //Defining interval

  double *x = new double [N];          //Mesh points for brute force Legendre
  double *w = new double [N];          //Weights Legendre

  gauleg(x1, x2, x, w, N);             //Getting the mesh points and weights from gauleg func

  double eps = 0.00000000001;          //Setting required precision.

  }
  for (int i = 0 ; i < N ; i++){
    REQUIRE( x[i] == Approx( xAnalSol[i] ).epsilon(eps));
  }

  for (int i = 0 ; i < N ; i++ ){
    REQUIRE(w[i] == Approx( wAnalSol[i] ).epsilon(eps));
  }

}
