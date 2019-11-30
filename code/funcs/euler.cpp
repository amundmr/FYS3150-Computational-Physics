#include <armadillo>

void euler(double (*a)(double), double init_r, double init_v, double dt, int N) // void for now, but will have some return type
{
    double ai;
    arma::vec r = arma::zeros<arma::vec>(N); r(0) = init_r;
    arma::vec v = arma::zeros<arma::vec>(N); v(0) = init_v;

    for(int i=0; i<N-1; i++) 
    {
        ai = a(r(i));
        v(i+1) = v(i) + ai*dt;
        r(i+1) = r(i) + v(i)*dt;
    }

    // return tuple or something
}