#include "../include/lib.h"

void output(double t_end, arma::mat&position, arma::mat&velocity,ofstream & ofile)
{
ofile << setiosflags(ios::showpoint | ios::uppercase);
ofile << setprecision(8) << time;
ofile << " " << setprecision(8) << position(0);
ofile << " " << setprecision(8) << position(1);
ofile << " " << setprecision(8) << velocity(0);
ofile << " " << setprecision(8) << velocity(1) << endl;
}
