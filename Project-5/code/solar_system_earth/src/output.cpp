
<<<<<<< HEAD

void output(double t,double x, double y, double vx, double vy, ofstream & ofile)
=======
void output(double t, arma::mat & position, arma::mat & velocity, ofstream & ofile, int &i)
>>>>>>> dae580c248020a5750f550375d02c07c6f101393
{
  cout << position << endl;
  ofile << setiosflags(ios::showpoint | ios::uppercase);
  ofile << setprecision(8) << t;
<<<<<<< HEAD
  ofile << " " << setprecision(8) << x;
  ofile << " " << setprecision(8) << y;
  ofile << " " << setprecision(8) << vx;
  ofile << " " << setprecision(8) << vy << endl;
=======
  ofile << " " << setprecision(8) << position(i,0);

  //ofile << " " << setprecision(8) << position(i,0);
  //ofile << " " << setprecision(8) << velocity(i,0);
  ofile << " " << setprecision(8) << velocity(i,0) << endl;
>>>>>>> dae580c248020a5750f550375d02c07c6f101393
}
