#include "../include/lib.h"

using namespace std;
void Metropolis(int L, long& idum, int **spinn, double& E, double& M, double *w)
{
// Initialize RNG (Mersenne Twister) in our interval
mt19937::result_type seed = time(0);//+omp_get_thread_num();  //Include last command to get different seed for each thread
auto interval_rand = bind(uniform_real_distribution<double>(0,1),mt19937(seed));

for (int y = 0;  y < L; y++){
  for (int x = 0; x < L; x++){
    //random position in lattice
    int ix = (int) (interval_rand(&idum) * (double)L);
    int iy = (int) (interval_rand(&idum) * (double)L);
    cout <<ix <<endl;
    cout <<iy <<endl;
    int deltaE = 2*spinn[iy][ix]*(spinn[iy][periodic_boundary_conditions(ix,L,-1)]+
                  spinn[periodic_boundary_conditions(iy,L,-1)][ix]+
                  spinn[iy][periodic_boundary_conditions(ix,L,1)]+
                  spinn[periodic_boundary_conditions(iy,L,1)][ix]);

  //Metropolis test:
  if (interval_rand() <= w[deltaE+8]){
    spinn[iy][ix] *= -1;    //flipp spinn
    M += (double) 2*spinn[iy][ix];
    E += (double) deltaE;
  }
  }
 }
}
