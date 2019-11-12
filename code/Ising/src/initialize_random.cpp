#include "../include/lib.h"

void initialize_random(int L, double T, mat & spin, double & E, double & M)
{
  random_device rd; //Creates a random seed with a RNG
  mt19937_64 gen(rd()); //Initialize PRNG with rd as seed
  uniform_real_distribution<double> interval_rand(0.0, 1.0);

  // Spin and magnetisation.
  for (int y = 0; y < L; y++)
  {
    for (int x = 0; x < L; x++){
      if( interval_rand(gen) <= 0.5)  {spin(x,y) = -1;} // Ground state spin.
      else spin(x,y) = 1;
      M += (double) spin(x,y);
    }
  }
  // Energy initialize.
  for (int y = 0; y < L; y++)
  {
    for (int x = 0; x < L; x++){
      E = E - (double)spin(x,y)
            * (spin(periodic_boundary_conditions(x,L,-1),y) + (spin(x,periodic_boundary_conditions(y,L,-1))));
    }
  }
}
