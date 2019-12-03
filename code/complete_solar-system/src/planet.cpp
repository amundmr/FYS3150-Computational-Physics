#include "./include/lib.h"

class Planet
{
public:
    arma::vec r;
    arma::vec v;
    double m;
    // Default constructor
    Planet()
    {
        m = 1; r = arma::zeros(3); v = arma::zeros(3);
    }
    // Constructor with init values.
    Planet(double mass, arma::vec init_r, arma::vec init_v){
        m = mass; r = init_r; v = init_v;
    };

    // Distance between two planets.
    double d(Planet & planet)
    {
        double x = this->r(0) - planet.r(0);
        double y = this->r(1) - planet.r(1);
        double z = this->r(2) - planet.r(2);
        return sqrt(x*x + y*y + z*z);
    };
    
    // Acceleration
    arma::vec a(Planet planet)
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
    };
};