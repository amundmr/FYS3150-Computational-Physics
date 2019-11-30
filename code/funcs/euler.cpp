#include <armadillo>

// Function takes in empty position and velocity vectors.
// In addition to this, it takes a pointer to the force affecting the object,
// as well as some initial conditions and the time-step characteristics.
void euler(arma::vec & r, arma::vec & v, double (*a)(double), double init_r, double init_v, double dt, int N)
{
    r = arma::zeros<arma::vec>(N); r(0) = init_r; // Filling the position vector with initial condition and zeros.
    v = arma::zeros<arma::vec>(N); v(0) = init_v; // Filling the velocity vector with initial condition and zeros.

    // Euler method
    for(int i=0; i<N-1; i++) 
    {
        v(i+1) = v(i) + a(r(i))*dt;
        r(i+1) = r(i) + v(i)*dt;
    }
}