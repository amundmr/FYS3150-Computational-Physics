#include "./include/lib.h"
using namespace std;
using namespace arma;

//It is assumed that the sun is stationary in origo due to its great mass.
ofstream ofile;

double a(double, double, double);


int main()
{
  ofile.open("earthorbit.dat");
  ofile << "Time, X-pos, Y-pos" << endl;

  int tEnd = 1000;
  double t, step = 2;
  int N = (int) tEnd/step + 1;

  //Initial condish
  vec x(N), y(N), vx(N), vy(N);
  x(0) = 3.625431903009844E-01; y(0) = 9.232148548591661E-01;
  vx(0) = -1.627037566373766E-02; vy(0) = 6.316837256180217E-03;

  double half_dt = 0.5*step;
  double half_dt_sqr = 0.5*step*step;

  //Verlet integration
  int i;
  for (i = 0; i < tEnd-1 ; i++){
    cout << x(i) << endl;
    x(i+1) = x(i) + vx(i)*step + a(x(i),y(i),0)*half_dt_sqr;
    y(i+1) = y(i) + vy(i)*step + a(x(i),y(i),1)*half_dt_sqr;

    vx(i+1) = vx(i) + (a(x(i),y(i),0) + a(x(i+1),y(i+1),0))*half_dt;
    vy(i+1) = vy(i) + (a(x(i),y(i),1) + a(x(i+1),y(i+1),1))*half_dt;

    t += step;
    ofile << t << " " << x(i) << " " << y(i) << endl;

  }
  ofile.close();


  return 0;
}

double a(double x, double y, double direction){
  double r = sqrt(x*x + y*y);
  double pi = acos(-1.0);         //define pi
  double GM_sun = 4 * pi * pi;    //In units of AU^3/yr^2
  double acc;
  //double F_g = GM_sun * M_earth/(r*r);
  if (direction == 1){
    double dir = y/r;
    acc = dir * GM_sun / (r*r);
  }
  if (direction == 0){
    double dir = x/r;
    acc = dir * GM_sun / (r*r);
  }
  return acc;
}
