#include "../include/lib.h"

// Function takes in position and velocity vectors. In addition to this, it takes the force affecting the object
// and the time step. From this, it returns the next time-step of the two vectors.
arma::vec euler_r(arma::vec r, arma::vec v, arma::vec a, double dt)
{
    // Initializing memory for next value.
    arma::vec r_next(3);

    // Euler FWD method over all three dimensions.
    r_next = r + v*dt;

    return r_next;
}

arma::vec euler_v(arma::vec v, arma::vec a, arma::vec a_next, double dt)
{
    // Initializing memory for next value.
    arma::vec v_next(3);

    // Euler FWD method over all three dimensions.
    v_next = v + a*dt;

    return v_next;
}
