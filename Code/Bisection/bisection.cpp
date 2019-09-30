#include <iostream>
#include <math.h>   //fabs()
#include <armadillo>

using namespace std;
using namespace arma;

double f(double x, int n)  //defining function
{
  double f, diag = 2.0, nondiag = -1.0;
  vec p = zeros<vec>(n);
  
  p(0) = 1;
  p(1) = diag - x;

  for (int i=2; i<n; i++){
    p(i) = (diag-x)*p(i-1)-pow(nondiag,2)*p(i-2);
    f = p(i);
  }

  return f;
}

void bisection(double a, double b, int n){
  double c, epsilon = 1e-8, root, fa, fb, fc;
  if ((f(a,n) * f(b,n)) > 0){ // Root not in interval, don't do anything
  }
  else{
    while (fabs(b - a) >= epsilon){
      c = (a + b) /2.0;

      // If there's no root between a and c, set a=c
      if (f(a,n)*f(c,n) > 0){
        a = c;
      }
      // If there's a root between a and c, set a=b
      else{
        b = c;
      }
    }
    cout <<"Root found: " << c << endl;
  }
}

int main(){
  int n = 20;
  int N = 10000;
  double start = -10.0, end = 10.0;
  double h = (end-start)/N;

  for (int i=0; i<N; i++){
    double a = i*h;
    double b = h*(i+1);

    bisection(a,b,n);
  }
}
