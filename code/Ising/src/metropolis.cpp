#include "../include/lib.h"

using namespace std;


void Metropolis(int L, long& idum, int **spinn, double &E, double &M, double *w)
{
for (int x = 0;  x < L; x++){
  for (int y = 0; y < L; y++){
    //random position in lattice
    double ix = (int) (ran1 (idum) * (double) L);
    double iy = (int) (ran1 (idum) * (double) L);
    int deltaE = 2*spinn[ix][iy](*spinn[ periodic_boundary_conditions(iy,L,-1)] +
                  spinn[periodic_boundary_conditions(ix,L,-1)][iy]+
                  spinn[iy][periodic_boundary_conditions(iy,L,1)]+
                  spinn[periodic_boundary_conditions(ix,L,-1)][iy]);id

  //Metropolis test:
  if (ran1(idum)<= w[deltaE+8]){
    spinn[ix][iy] *= -1;    //flipp spinn
    M += (double) 2*spinn[iy][ix];
    E += (double) deltaE;
  }
  }
 }
}
