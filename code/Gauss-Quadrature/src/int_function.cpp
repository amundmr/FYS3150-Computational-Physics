#include "../include/gqlib.h"

#define EPS 3.0e-14
#define MAXIT 10
#define ZERO 1.0E-10

//  this function defines the function to integrate
double int_function(double x1, double y1, double z1, double x2, double y2, double z2)
{
  double alpha = 2.0;
  double exp1 = -2*alpha*sqrt(x1*x1 + y1*y1 + z1*z1);
  double exp2 = -2*alpha*sqrt(x2*x2 + y2*y2 + z2*z2);
  double deno = sqrt(pow((x1-x2),2)+pow((y1-y2),2)+pow((z1-z2),2));
  if (abs(deno) < 1E-8){
    return 0;
  }
  else
  {
    return exp(exp1 + exp2) / deno;
  }
} // end of function to evaluate
