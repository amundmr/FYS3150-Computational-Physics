#include "../include/lib.h"

// Function takes in position and velocity vectors. In addition to this, it takes the force affecting the object
// and the time step. From this, it returns the next time-step of the two vectors.
auto verlet(arma::vec r, arma::vec v, arma::vec a, arma::vec a_next, double dt)
{
    // Initializing memory for next values.
    arma::vec r_next(3); arma::vec v_next(3);

    // Verlet method over all three dimensions.
    for (int i=0; i<3; i++){
        r_next(i) = r(i) + v(i)*dt + a(i)*0.5*dt*dt;
        v_next(i) = v(i) + (a(i) + a_next(i))*0.5*dt;
    };

    struct next {arma::vec r_next; arma::vec v_next;};
    return next {r_next, v_next};
}