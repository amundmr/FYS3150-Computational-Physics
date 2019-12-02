#include "../include/lib.h"

// Function takes in empty position and velocity vectors.
// In addition to this, it takes the force affecting the object, as well as some initial conditions and the time-step characteristics.
void verlet(arma::vec & r, arma::vec & v, double (*a)(double), double init_r, double init_v, double dt, int N) // void for now, but will have some return type.
{
    double ai;
    // Pre-calculated values to save some FLOPs
    double half_dt = 0.5*dt;
    double half_dt_sqr = 0.5 * dt * dt;
    
    r = arma::zeros<arma::vec>(N); r(0) = init_r; // Filling the position vector with initial condition and zeros.
    v = arma::zeros<arma::vec>(N); v(0) = init_v; // Filling the velocity vector with initial condition and zeros.

    // Velocity Verlet method
    for(int i=0; i<N-1; i++)
    {
        ai = a(r(i));
        r(i+1) = r(i) + v(i)*dt + ai*half_dt_sqr;
        v(i+1) = v(i) + (ai+a(r(i+1)))*half_dt;
    }
}