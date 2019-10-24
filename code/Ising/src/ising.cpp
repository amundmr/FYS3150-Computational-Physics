#include <iostream>
#include <cmath>
#include <ctime>
#include <random>
#include <fstream>
#include <cstdlib>
#include <stdio.h>
#include <armadillo>
using namespace std;
using namespace arma;

double ice (double abc)
  {

  int N,x,y,MCstep, B, J, mu, Nx, Ny;
  double beta, T, energy, M, Boltzmann;

  //no. of spins
  N = 100;
  Nx = 10;
  Ny = 10;

  mat spinn(Nx, Ny);
  MCstep = 100; //Metropolian steps
  Boltzmann = 1; //Boltzmann constant
  B = 0; //magnetic field
  T = 1.0; //temperature
  J = 1; //ferromagnetic coupling
  mu = 1;//
  //periodic boundary conditions
  //jm = N


  //initial spinns
  random_device seed;
  mt19937 engine(seed());
  uniform_real_distribution<double> spinnpossibilities(0.0, 1.0 );
  for (x = 0; x< Nx;x++){
    for (y = 0; y<Ny;y++){
      if(spinnpossibilities(engine) < 0.5){
        spinn(x,y) = 1;
      }
      else {spinn(x,y) = -1;}

      cout << "inital spinn" << spinn(x,y);
    }}

}

int main(){
}
