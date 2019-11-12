#include "../include/lib.h"

void Metropolis(int L, long & idum, mat & spin, double & E, double & M, vec Ediff)
{
/*
  // Initialize RNG (Mersenne Twister) in our interval
  mt19937::result_type seed = time(0);//+omp_get_thread_num();  //Include last command to get different seed for each thread
  auto interval_rand = bind(uniform_real_distribution<double>(0.0,1.0),mt19937_64(seed));
*/
  random_device rd; //Creates a random seed with a RNG
  mt19937_64 gen(rd()); //Initialize PRNG with rd as seed
  uniform_real_distribution<double> interval_rand(0.0, 1.0);

  for (int y = 0;  y < L; y++)
  {
    for (int x = 0; x < L; x++)
    {
      // Random position in lattice.

      int ix = (int) (interval_rand(gen) * (double)L);
      int iy = (int) (interval_rand(gen) * (double)L);
      int deltaE = 2 * spin(iy,ix)
                     * (spin(iy,periodic_boundary_conditions(ix,L,-1))
                     + spin(periodic_boundary_conditions(iy,L,-1),ix)
                     + spin(iy,periodic_boundary_conditions(ix,L,1))
                     + spin(periodic_boundary_conditions(iy,L,1),ix));

      // Metropolis test:
      if (interval_rand(gen) <= Ediff((int) deltaE +8)){
        spin(iy,ix) *= -1;    //flipp spin
        M += (double) 2*spin(iy,ix);
        E += (double) deltaE;
      }
    }
  }
}
