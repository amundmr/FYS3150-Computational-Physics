<<<<<<< HEAD
#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <random>
#include <chrono>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
//#include "lib.h"
=======
#include "./include/lib.h"

>>>>>>> bf8ab18eee2b3d99ef650c7a9e313b1bd3134b22
using namespace std;
ofstream ofile;
bind()
inline int periodic_boundary_conditions(int &i, int &limit, int &add){
  return (i+limit+add) % (limit);
}

//Main program
int main(int argc, char* argv[] ){

  int **spinn, L, mcs,w[17], avarage[5];
  double T, T_start, T_end, T_step, E, M;
  char *outfilename;
  long idum;

  //Input arguments from command line. Aborts if there are too few
  if (argc <= 1){
    cout<<"Wrong" << argv[0];
    cout <<"Write also output filename on same line" << endl;
    exit(1);
  }
  else {
    outfilename = argv[1];
  }

  ofile.open(outfilename);
  input(L, mcs, T_start, T_end, T_step);
  spinn = (int**) matrix(L,L, sizeof(int));
  idum = -1; //random starting point

  for (T = T_start; T<= T_end; T += T_step){
    E = M = 0.;

    for (int de = -8; de <= 8 ;de++) w[de+8] = 0;
    for (int de = -8; de <= 8 ;de+=4) w[de+8] = exp(-de/T);

    //Array for expectation values
    for(int i = 0; i < 5; i++) avarage[i] = 0;
    initilize(L, double T, spinn, E, M);

    //Monte Carlo:
      for (int cycles = 1; cycles <= mcs; cycles++){
        Metropolis(L,idum,spinn,E,M,w);

        avarage[0] += E; avarage[1] += E*E;
        avarage[2] += M; avarage[3] += M*M; avarage[4] += fabs(M);


      }

      //print results;
      output(L,mcs,T,avarage);
  }

  free_matrix((void**) spinn);
  ofile.close();
  return 0;
}
