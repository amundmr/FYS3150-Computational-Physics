#include "../include/lib.h"

// Default constructor
Body::Body()
{
    m = 1; r = arma::zeros(3); v = arma::zeros(3); name = "Unnamed body";
}

// Constructor with init values.
Body::Body(std::string name_in, double mass, arma::vec init_r, arma::vec init_v){
    m = mass; r = init_r; v = init_v * 365.2442 ; name = name_in; //
}

// Distance between two bodies.
double Body::d(Body & body)
{
    arma::vec dv = body.r - this->r;
    return sqrt(dv(0)*dv(0) + dv(1)*dv(1) + dv(2)*dv(2));
}

// Acceleration
arma::vec Body::a(Body body)
{
    // Storing the relative distance and the returned acceleration
    arma::vec rel_d(3); arma::vec acc(3);

    // Setting the actual distance between the bodies.
    double d = this->d(body);

    // Setting the relative distance in each dimension between the bodies.
    rel_d = (body.r - this->r)/d;

    // Smoothing??

    // If distance is not zero, return calculated acceleration, else return 0 vector.
    if (d != 0){
        acc = G * body.m * rel_d / (d*d);
        return acc;
    }
    else{acc.fill(0); return acc;}
}

//Potential Energy
double Body::Ep(Body body)
{
    double r = this->d(body);
    return this->m * G * r;

}

//Kinetic Energy
double Body::Ek(Body body)
{
    arma::vec vv = this->v;
    double v = sqrt(vv(0)*vv(0) + vv(1)*vv(1) + vv(2)*vv(2));
    return 0.5 * this->m * v * v;
}
