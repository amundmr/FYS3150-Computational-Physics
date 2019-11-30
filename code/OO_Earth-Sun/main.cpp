#include "./include/lib.h"
using namespace std;
using namespace arma;

//It is assumed that the sun is stationary in origo due to its great mass.
ofstream ofile;

double earthAccY(double, double);
double earthAccX(double, double);


int main()
{
  ofile.open("earthorbit.dat");
  ofile << "Time, X-pos, Y-pos" << endl;

  int tEnd = 100;
  double t, step = 1;
  int N = (int) tEnd/step + 1;

  //Initial condish
  vec x(N), y(N), vx(N), vy(N);
  x(0) = 1.0; y(0) = 0.0; vx(0) = 0.0; vy(0) = 0.1;

  x(1) = x(0) + vx(0)*step + 0.5*earthAccX(x(0),y(0))*step*step;
  y(1) = y(0) + vy(0)*step + 0.5*earthAccY(x(0),y(0))*step*step;


  //Verlet integration
  int i;
  for (i = 1; i < tEnd ; i++){
    x(i+1) = 2*x(i) - x(i-1) + earthAccX(x(i),y(i))*step*step;
    y(i+1) = 2*y(i) - y(i-1) + earthAccY(x(i),y(i))*step*step;
    t += step;
    ofile << t << " " << x(i) << " " << y(i) << endl;

  }
  ofile.close();


  return 0;
}

//Calculates earths Y-acceleration based on its position x and y
double earthAccY(double x, double y){

  double gamma = 1.0;// 0.004302; // pc/M_sun (km/s)^2 where the units is pasecs per mass times
  double M_e = 1.0;
  double r = sqrt(x*x + y*y);  //Defining the distance to earth
  double ay = -gamma * M_e/(r*r) * (y/r);

  return ay;
}


//Calculates earths X-acceleration based on its position x and y
double earthAccX(double x, double y){

  double gamma = 0.004302; // pc/M_sun (km/s)^2 where the units is pasecs per mass times
  double M_e = 1.0;
  double r = sqrt(x*x + y*y);  //Defining the distance to earth
  double ax = -gamma * M_e/(r*r) * (x/r);

  return ax;
}
