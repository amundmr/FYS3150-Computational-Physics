#include "./include/lib.h"

using namespace std;
using namespace arma;


//It is assumed that the sun is stationary in origo due to its great mass.
ofstream ofile;
ifstream initFile;

double a(double, double);


int main()
{

  initFile.open("InitialConditions.dat")
  if (!initFile) {
    cerr << "Unable to open file InitialConditions.dat";
    exit(1); //Call system stop
  }
  for ( string line; getline(initFile, line); ){
    istringstream in(line)

    float tEnd, step, x0, y0, vx0, vy0;
    in >> tEnd;
    in >> step;
    in >> x0;
    in >> y0;
    in >> vx0;
    in >> vy0;

  }


  ofile.open("earthorbit.dat");
  ofile << "Time, X-pos, Y-pos" << endl;

  int tEnd = 1000;
  double t, step = 0.02;
  int N = (int) tEnd/step + 1;
  cout << "Int points N: "<< N << endl;
  //Initial condish
  vec x(N), y(N), vx(N), vy(N);
  x(0) = 1; y(0) = 0; //AU
  vx(0) = 0; vy(0) = 1.8*M_PI; //AU/day

  double half_dt = 0.5*step;
  double half_dt_sqr = 0.5*step*step;

  //Verlet integration
  for (int i = 0; i < N-1 ; i++){
    cout << x(i) << endl;

    double xdir = x(i)/sqrt(x(i)*x(i) + y(i)*y(i));
    double ydir = y(i)/sqrt(x(i)*x(i) + y(i)*y(i));

    x(i+1) = x(i) + vx(i)*step + xdir*a(x(i),y(i))*half_dt_sqr;
    y(i+1) = y(i) + vy(i)*step + ydir*a(x(i),y(i))*half_dt_sqr;

    vx(i+1) = vx(i) + xdir*(a(x(i),y(i)) + a(x(i+1),y(i+1)))*half_dt;
    vy(i+1) = vy(i) + ydir*(a(x(i),y(i)) + a(x(i+1),y(i+1)))*half_dt;

    t += step;
    ofile << t << " " << x(i) << " " << y(i) << endl;

  }
  ofile.close();
  system("python3 ./Plotter/plotter.py");

  return 0;
}

double a(double x, double y){
  double r = sqrt(x*x + y*y);
  double GM_sun = 4 * M_PI * M_PI;    //In units of AU^3/yr^2
  double acc;
  acc = -GM_sun / (r*r);
  //double F_g = GM_sun * M_earth/(r*r);
  return acc;
}
