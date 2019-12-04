#include "../include/lib.h"

// Function takes in position and velocity vectors. In addition to this, it takes the force affecting the object
// and the time step. From this, it returns the next time-step of the two vectors.
arma::vec verlet_r(arma::vec r, arma::vec v, arma::vec a, double dt)
{
    // Initializing memory for next value.
    arma::vec r_next(3);

    // Verlet method over all three dimensions.
    for (int i=0; i<3; i++){
        r_next(i) = r(i) + v(i)*dt + a(i)*0.5*dt*dt;
    };

    return r_next;
}

arma::vec verlet_v(arma::vec v, arma::vec a, arma::vec a_next, double dt)
{
    // Initializing memory for next value.
    arma::vec v_next(3);

    // Verlet method over all three dimensions.
    for (int i=0; i<3; i++){
        v_next(i) = v(i) + (a(i) + a_next(i))*0.5*dt;
    };

    return v_next;
}