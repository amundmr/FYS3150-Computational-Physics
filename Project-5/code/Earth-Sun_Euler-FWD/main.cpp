#include "./include/lib.h"

using namespace std;
using namespace arma;

/*NOTES:
It is assumed that the sun is stationary in origo due to its great mass.
Initial Conditions are set in InitialConditions.dat.

*/
ofstream ofile;
ifstream initFile;

double a(double, double);
void vec_push(vec &, double);
vec input(ifstream &);

int main()
{

  initFile.open("InitialConditions.dat");
  vec Conditions = input(initFile);
  initFile.close();
  cout << Conditions << endl;


  ofile.open("earthorbit.dat");
  ofile << "Time, X-pos, Y-pos" << endl;

  int tEnd =  (int) Conditions[0];
  double step = Conditions[1];
  double t = 0.0;
  int N = (int) tEnd/step + 1;
  cout << "Int points N: "<< N << endl;
  //Initial condish
  vec x(N), y(N), vx(N), vy(N);

  x(0) = Conditions[2]; y(0) = Conditions[3]; //AU
  vx(0) = Conditions[4]; vy(0) = Conditions[5]; //AU/day
/*
  x(0) = 1; y(0) = 0; //AU
  vx(0) = 0; vy(0) = 2*M_PI; //AU/day
*/
  double half_dt = 0.5*step;
  double half_dt_sqr = 0.5*step*step;

  //Euler integration
  for (int i = 0; i < N-1 ; i++){
    //cout << x(i) << endl;

    double xdir = x(i)/sqrt(x(i)*x(i) + y(i)*y(i));
    double ydir = y(i)/sqrt(x(i)*x(i) + y(i)*y(i));

    vx(i+1) = vx(i) + step*a(x(i),y(i))*xdir;
    vy(i+1) = vy(i) + step*a(x(i),y(i))*ydir;

    x(i+1) = x(i) + step*vx(i); //Change i to i+1 for the velocity to use Euler-Cromer, which is very accurate.
    y(i+1) = y(i) + step*vy(i);


    t += step;
    ofile << t << " " << x(i) << " " << y(i) << endl;

  }
  ofile.close();
  system("python3 ./Plotter/plotter.py");

  return 0;
}

// FUNCTIONS
double a(double x, double y){
  double r = sqrt(x*x + y*y);
  double GM_sun = 4 * M_PI * M_PI;    //In units of AU^3/yr^2
  double acc;
  acc = -GM_sun / (r*r);
  //double F_g = GM_sun * M_earth/(r*r);
  return acc;
}

void vec_push(vec & v, double value) { // Slow push_back for armadillo vectors
    vec av(1);
    av.at(0) = value;
    v.insert_rows(v.n_rows, av.row(0));
}

vec input(ifstream & initFile) { // Reading from InitialConditions.dat
  if (!initFile) { // Checking if file is open
    cerr << "Unable to open file InitialConditions.dat";
    exit(1); //Call system stop
  }
  vec Conditions;
  string line;
  while ( getline(initFile, line) ){ // Reading every line of the file
    string stringvalue = "";
    for (auto x : line){  //Looping over every element in each line
      if (x == ' ') {
        stringvalue = ""; //If we find the space, save everything after to the value
      }
      else{
        stringvalue += x;
      }
    }
    vec_push(Conditions, stod(stringvalue)); //And then append the value to the vector

  }
  return Conditions;
}
