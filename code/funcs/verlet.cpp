#include <armadillo>

void verlet(double (*a)(double), double init_r, double init_v, double dt, int N) // void for now, but will have some return type.
{
    double ai;
    double half_dt = 0.5*dt;
    double half_dt_sqr = 0.5 * dt * dt;
    arma::vec r = arma::zeros<arma::vec>(N); r(0) = init_r;
    arma::vec v = arma::zeros<arma::vec>(N); v(0) = init_v;

    for(int i=0; i<N-1; i++)
    {
        ai = a(r(i));
        r(i+1) = r(i) + v(i)*dt + ai*half_dt_sqr;
        v(i+1) = v(i) + (ai+a(r(i+1)))*half_dt;
    }

    // return tuple or something
}