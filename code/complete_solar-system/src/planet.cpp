#include "../include/lib.h"

// Default constructor
Planet::Planet()
{
    m = 1; r = arma::zeros(3); v = arma::zeros(3); name = "Unnamed planet";
}

// Constructor with init values.
Planet::Planet(std::string name, double mass, arma::vec init_r, arma::vec init_v){
    m = mass; r = init_r; v = init_v * 365.2442; name = name;
}

// Distance between two planets.
double Planet::d(Planet & planet)
{
    double x = this->r(0) - planet.r(0);
    double y = this->r(1) - planet.r(1);
    double z = this->r(2) - planet.r(2);
    return sqrt(x*x + y*y + z*z);
}

// Acceleration
arma::vec Planet::a(Planet planet)
{
    // Storing the relative distance and the returned acceleration
    arma::vec rel_d(3); arma::vec acc(3);
    // Setting the relative distance in each dimension between the planets.
    for(int i=0; i<3; i++) rel_d(i) = this->r(i) - planet.r(i);
    // Setting the actual distance between the planets.
    double d = this->d(planet);
    // Smoothing??

    // If distance is not zero, return calculated acceleration, else return 0 vector.
    if (d != 0){
        for(int i=0; i<3; i++){
            acc(i) = G * planet.m * rel_d(i) / (d*d*d);
        };
        return acc;
    }
    else{acc.fill(0); return acc;}
}
