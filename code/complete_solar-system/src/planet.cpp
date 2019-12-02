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
    double a(Planet & planet)
    {
        double d = d(planet);
        if (d != 0){
            return G * planet.m / (d*d);
        }
    };
};