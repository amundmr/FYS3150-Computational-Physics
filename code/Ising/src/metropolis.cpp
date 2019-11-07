#include "../include/lib.h"

void Metropolis(int L, long& idum, mat &spinn, double& E, double& M, vec Ediff)
{


random_device rd;
mt19937_64 gen(rd());
uniform_real_distribution<double> interval_rand(0.0, 1.0);

for (int y = 0;  y < L; y++){
  for (int x = 0; x < L; x++){
    //random position in lattice
    int ix = (int) (interval_rand(gen) * (double)L);
    int iy = (int) (interval_rand(gen) * (double)L);
    int deltaE = 2*spinn(iy,ix)*(spinn(iy,periodic_boundary_conditions(ix,L,-1))+
                  spinn(periodic_boundary_conditions(iy,L,-1),ix)+
                  spinn(iy,periodic_boundary_conditions(ix,L,1))+
                  spinn(periodic_boundary_conditions(iy,L,1),ix));

  //Metropolis test:
  if (interval_rand(gen) <= Ediff((int) deltaE +8)){
    spinn(iy,ix) *= -1;    //flipp spinn
    M += (double) 2*spinn(iy,ix);
    E += (double) deltaE;
  }
  
  }

 }

}
