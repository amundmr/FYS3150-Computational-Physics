#include "../include/lib.h"
#include <armadillo>

void output(double t, arma::mat & position, arma::mat & velocity, ofstream & ofile, int &i)
{
  cout << position << endl;
  ofile << setiosflags(ios::showpoint | ios::uppercase);
  ofile << setprecision(8) << t;
  ofile << " " << setprecision(8) << position(i,0);

  //ofile << " " << setprecision(8) << position(i,0);
  //ofile << " " << setprecision(8) << velocity(i,0);
  ofile << " " << setprecision(8) << velocity(i,0) << endl;
}
