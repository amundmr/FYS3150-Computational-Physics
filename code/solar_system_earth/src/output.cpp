#include "../include/lib.h"

void output(double time, double x, double y, double vx, double vy,ofstream & ofile)
{
ofile << setiosflags(ios::showpoint | ios::uppercase);
ofile << setw(15) << setprecision(8) << time;
ofile << setw(15) << setprecision(8) << x;
ofile << setw(15) << setprecision(8) << y;
ofile << setw(15) << setprecision(8) << vx;
ofile << setw(15) << setprecision(8) << vy << endl;
}
