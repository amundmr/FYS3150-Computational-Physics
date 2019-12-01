

void output(double t,double x, double y, double vx, double vy, ofstream & ofile)
{
  ofile << setiosflags(ios::showpoint | ios::uppercase);
  ofile << setprecision(8) << t;
  ofile << " " << setprecision(8) << x;
  ofile << " " << setprecision(8) << y;
  ofile << " " << setprecision(8) << vx;
  ofile << " " << setprecision(8) << vy << endl;
}
