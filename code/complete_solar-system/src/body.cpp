#include "../include/lib.h"

// Default constructor
Body::Body()
{
    m = 1; r = arma::zeros(3); v = arma::zeros(3); name = "Unnamed body";
}

// Constructor with init values.
Body::Body(std::string name_in, double mass, arma::vec init_r, arma::vec init_v){
    m = mass; r = init_r; v = init_v * 365.2442; name = name_in;
}

// Distance between two bodies.
double Body::d(Body & body)
{
    double x = this->r(0) - body.r(0);
    double y = this->r(1) - body.r(1);
    double z = this->r(2) - body.r(2);
    return sqrt(x*x + y*y + z*z);
}

// Acceleration
arma::vec Body::a(Body body)
{
    // Storing the relative distance and the returned acceleration
    arma::vec rel_d(3); arma::vec acc(3);
    // Setting the relative distance in each dimension between the bodies.
    for(int i=0; i<3; i++) rel_d(i) = this->r(i) - body.r(i);
    // Setting the actual distance between the bodies.
    double d = this->d(body);
    // Smoothing??

    // If distance is not zero, return calculated acceleration, else return 0 vector.
    if (d != 0){
        for(int i=0; i<3; i++){
            acc(i) = G * body.m * rel_d(i) / (d*d*d);
        };
        return acc;
    }
    else{acc.fill(0); return acc;}
}
