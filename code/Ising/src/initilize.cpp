#include "../include/lib.h"

using namespace std;

void initilize(int L, double T, mat &spinn, double& E, double& M)
  {
    //spinn and magnetisation
  for (int y = 0; y < L; y++){
    for (int x = 0; x < L; x++){
      if(T < 1.5 ) {spinn(x,y) = 1;} //ground state spinn
      else spinn(x,y) = -1;
      M += (double)spinn(x,y);
    }}
 //energy initilize
  for (int y = 0; y < L; y++){
    for (int x = 0; x < L; x++){
    E -= (double)spinn(x,y)
      *(spinn(periodic_boundary_conditions(x,L,-1),y)
      + (spinn(x,periodic_boundary_conditions(y,L,-1))));
    }
  }
}
//end initilize
