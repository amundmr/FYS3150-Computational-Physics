#include "../include/lib.h"
// Function takes in empty position and velocity vectors.
// In addition to this, it takes a pointer to the force affecting the object,
// as well as some initial conditions and the time-step characteristics.
void euler(arma::mat & r, arma::mat & v, double (*a)(double), arma::vec init_r, arma::vec init_v, double dt, int N)
{
    r = arma::zeros<arma::mat>(N,3); r(0,0) = init_r(0); r(0,1) = init_r(1); r(0,2) = init_r(2); // Filling the position vector with initial condition and zeros.
    v = arma::zeros<arma::mat>(N,3); v(0,0) = init_v(0); v(0,1) = init_v(1); v(0,2) = init_v(2); // Filling the velocity vector with initial condition and zeros.

    // Euler method
    for(int i=0; i<N-1; i++)
    {
        v(i+1) = v(i) + a(r(i))*dt;
        r(i+1) = r(i) + v(i)*dt;
    }
}