#include "../include/lib.h"
// Function takes in empty position and velocity vectors.
// In addition to this, it takes the force affecting the object, as well as some initial conditions and the time-step characteristics.
void verlet(arma::mat & r, arma::mat & v, double (*a)(double), double init_r, double init_v, double dt, int N) // void for now, but will have some return type.
{
    double ai,aix,aiy, next_ai, next_aix, next_aiy;
    // Pre-calculated values to save some FLOPs
    double half_dt = 0.5*dt;
    double half_dt_sqr = 0.5 * dt * dt;

    //r = arma::zeros<arma::mat>(N,2);
    r(0,0) = init_r; // Filling the position vector with initial condition and zeros.
    r(0,1) = 0.0;
    //v = arma::zeros<arma::mat>(N,2);
    v(0,0) = 0.0; // Filling the velocity vector with initial condition and zeros.
    v(0,1) = 2.0*3.14;

    // Velocity Verlet method
    for(int i=0; i<N-1; i++)
    {
        double radius = sqrt(r(i,0)*r(i,0) + r(i,1)*r(i,1));

        ai = a(radius);             //Defining absolute acceleration
        aix = r(i,0)/radius * ai;  //Defining acceleration in x and y directions
        aiy = r(i,1)/radius * ai;

        //The verlet algo for pos, x y and vel, x y.
        r(i+1,0) = r(i,0) + v(i,0)*dt + aix*half_dt_sqr;
        r(i+1,1) = r(i,1) + v(i,1)*dt + aiy*half_dt_sqr;


        double next_radius = sqrt(r(i+1,0)*r(i+1,0) + r(i+1,1)*r(i+1,1));
        next_ai = a(next_radius);             //Defining absolute acceleration
        next_aix = r(i+1,0)/radius * next_ai;  //Defining acceleration in x and y directions
        next_aiy = r(i+1,1)/radius * next_ai;

        v(i+1,0) = v(i,0) + (aix+next_aix)*half_dt;
        v(i+1,1) = v(i,1) + (aiy+next_aiy)*half_dt;

    }
}
