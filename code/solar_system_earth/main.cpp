#include "./include/lib.h"
#include <armadillo>
//global file variable

double a(double r) //Making func for acceleration of earth for use in verlet!
{
  double pi = acos(-1.0);         //define pi
  double GM_sun = 4 * pi * pi; //In units of AU^3/yr^2
  //double F_g = GM_sun * M_earth/(r*r);
  double a = GM_sun / (r*r);
  return a;
}



int main(int argc, char * argv[]){

  char * filename;

  if (argc <= 1){
    cout <<"Bad usage: " << argv[0] <<"Name of file on same line"<< endl;
    exit(1);
  }
  else {
    filename = argv[1];
  }

  ofstream ofile;
  ofile.open(filename);
  ofile << "Time x y v_x v_y" << endl;

  //input(N,t_end,position,velocity);
  //initial positions and constants
  double pi = acos(-1.0);         //define pi
  double t=0.0, t_end = 2.0,x = 1.0, y = 0.0, vx = 1.0, vy = 2.0*pi;
  double r = sqrt(x*x+y*y);
  double N = 1000;
  double dN = t_end/((double) N);   //stepsize
  arma::mat position, velocity;

  position = arma::zeros<arma::mat>(N,2);
  velocity = arma::zeros<arma::mat>(N,2);


  //Running verlet!
  verlet(position, velocity, *a, x, vx, dN, N);
  ofile << setiosflags(ios::showpoint | ios::uppercase);
  for (int i = 0; i<N-1; i++){

    ofile << setprecision(8) << i;
    ofile << " " << setprecision(8) << position(i,0);
    ofile << " " << setprecision(8) << position(i,1);
    ofile << " " << setprecision(8) << velocity(i,0);
    ofile << " " << setprecision(8) << velocity(i,1) << endl;
  }



// while(t<=t_end){
// for (int i = 0;i<= N;i++){
//   position(0,i+1) = position(0,i) + dN*velocity(0,i);
//   position(1,i+1) = position(1,i) + dN*velocity(1,i);
//   velocity(0,i+1) = velocity(0,i) - dN*4*pi*pi*x/(r*r*r);
//   velocity(0,i+1) = velocity(0,i) - dN*4*pi*pi*y/(r*r*r);
//   t+= dN;
//   output(t, position, velocity,ofile,i); //write to file
// }
// }
  ofile.close();
  return 0;
}
