#include "../include/lib.h"

void initialize(int L, double T, mat & spin, double & E, double & M)
{
  // Spin and magnetisation.
  for (int y = 0; y < L; y++)
  {
    for (int x = 0; x < L; x++){
      if( T < 1.5 ) {spin(x,y) = 1;} // Ground state spin.
      else spin(x,y) = -1;
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