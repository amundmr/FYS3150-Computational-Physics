#include "../include/lib.h"
#include <armadillo>

void output(double t, arma::mat&position, arma::mat&velocity, ofstream & ofile, int &i)
{
  ofile << setiosflags(ios::showpoint | ios::uppercase);
  ofile << setprecision(8) << t;
  ofile << " " << setprecision(8) << position(0,i);
  ofile << " " << setprecision(8) << position(1,i);
  ofile << " " << setprecision(8) << velocity(0,i);
  ofile << " " << setprecision(8) << velocity(1,i) << endl;
}
