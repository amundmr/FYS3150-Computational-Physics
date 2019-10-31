<<<<<<< HEAD
#include <iostream>
#include <fstream>
#include <random>
#include <chrono>
#include <iomanip>
#include <vector>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
=======
#include "../include/lib.h"

>>>>>>> bf8ab18eee2b3d99ef650c7a9e313b1bd3134b22
using namespace std;
inline int periodic_boundary_conditions(int &, int &, int&);
void Metropolis(int L, long& idum, int **spinn, double &E, double &M, double *w)
{
// Initialize RNG (Mersenne Twister) in our interval
mt19937::result_type seed = time(0);//+omp_get_thread_num();  //Include last command to get different seed for each thread
auto interval_rand = bind(uniform_real_distribution<double>(0,1),mt19937(seed));

for (int x = 0;  x < L; x++){
  for (int y = 0; y < L; y++){
    //random position in lattice
    int ix = (int) (interval_rand() * (double) L);
    int iy = (int) (interval_rand() * (double) L);
    int deltaE = 2*spinn[ix][iy](*spinn[ periodic_boundary_conditions(iy,L,-1)] +
                  spinn[periodic_boundary_conditions(ix,L,-1)][iy]+
                  spinn[iy][periodic_boundary_conditions(iy,L,-1)]+
                  spinn[periodic_boundary_conditions(ix,L,-1)][iy]);

  //Metropolis test:
  if (ran1(idum)<= w[deltaE+8]){
    spinn[ix][iy] *= -1;    //flipp spinn
    M += (double) 2*spinn[iy][ix];
    E += (double) deltaE;
  }
  }
 }
}
