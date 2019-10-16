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
  double x1 = -5.0, x2 = 5.0;

  double *x = new double [N];          //Mesh points for brute force Legandre
  double *w = new double [N];          //Weights Legandre

  int n = 2;

  double calcSol = gauleg(x1, x2, x, w, n)

  double eps = 0.00001;

  REQUIRE( eigvec(0) == Approx( 0.26795  ).epsilon(eps));
  REQUIRE( eigvec(1) == Approx( 1.0      ).epsilon(eps));
  REQUIRE( eigvec(2) == Approx( 2.0      ).epsilon(eps));
  REQUIRE( eigvec(3) == Approx( 3.0      ).epsilon(eps));
  REQUIRE( eigvec(4) == Approx( 3.73205  ).epsilon(eps));

}
