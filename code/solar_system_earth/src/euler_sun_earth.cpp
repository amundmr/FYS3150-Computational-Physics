#include "../include/lib.h"
using namespace std;

// output file as global variable
ofstream ofile;
// function declarations
void output( double, double, double, double, double);
int main(int argc, char* argv[])
{
// declarations of variables
char *outfilename;
// Read in output file, abort if there are too few command-line arguments
if( argc <= 1 ){
  cout << "Bad Usage: " << argv[0] << " read also output file on same line" << endl;
  exit(1);
}
else{
  outfilename=argv[1];
}
ofile.open(outfilename);

int NumberofSteps = 1000;
double FinalTime = 1.0;
double Step = FinalTime/((double) NumberofSteps);
double time = 0.0;

// Initial values x = 1.0 AU and vy = 2*pi
double pi = acos(-1.0);
double FourPi2 = 4*pi*pi;
double x = 1.0; double y = 0.0; double vx = 0.0; double vy = 2.0*pi;
double r = sqrt(x*x+y*y);

//differential equations using Euler’s method
while (time <= FinalTime){
x += Step*vx;
y += Step*vy;
vx -= Step*FourPi2*x/(r*r*r);
vy -= Step*FourPi2*y/(r*r*r);
r = sqrt(x*x+y*y);
time += Step;
output(time, x, y, vx, vy,ofile); // write to file
}
ofile.close(); // close output file
return 0;
} // End of main function
