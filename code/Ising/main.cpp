#include <iostream>
#include <cmath>
#include <ctime>
#include <random>
#include <cstdlib>
#include <stdio.h>
#include <fstream>
#include <iomanip>
using namespace std;
ofstream ofile;

inline int periodic_boundary_conditions(int &i, int &limit, int &add){
  return (i+limit+add) % (limit);
}

void initilize(int, double, int **, double&, double&);
void input(int &, int & , double &, double &, double &);

int main(int argc, char* argv[] ){

  int **spinn, L, mcs;
  double T, T_start, T_end, T_step, E, M;
  char *outfilename;
  long idum;

  if (argc <= 1){
    cout<<"Wrong" << argv[0];
    cout <<"Write also output filename on same line" << endl;
  }
  else {
    outfilename = argv[1];
  }

  ofile.open(outfilename)
  input(L, mcs, T_start, T_end, T_step);
  spinn = (int**) matrix(L,L, sizeof(int));
  idum = -1; //random starting point

  for (T = T_start; T<= T_end; T += T_step){
    E = M = 0.;


  }



}
