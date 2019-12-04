#include "./lib.h"

class Planet
{
public:
    arma::vec r;
    arma::vec v;
    double m;
    std::string name;
    // Default constructor
    Planet();
    // Constructor with init values.
    Planet(std::string name, double mass, arma::vec init_r, arma::vec init_v);

    // Distance between two planets.
    double d(Planet & planet);
    
    // Acceleration
    arma::vec a(Planet planet);
};