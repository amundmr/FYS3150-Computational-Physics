#include "../include/lib.h"

void Metropolis(int L, long & idum, mat & spin, double & E, double & M, vec Ediff, ofstream & file2, int &cycles, int&sum, int mcs)
{
  random_device rd;
  mt19937_64 gen(rd());
  uniform_real_distribution<double> interval_rand(0.0, 1.0);
 double accspins = 0;
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
        accspins += 1;              //number of accepted spins
        }
     }
  }
  file2 << cycles << " " << accspins/L/L << endl;
}
