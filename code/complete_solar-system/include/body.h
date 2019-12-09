#include "./lib.h"

class Body
{
public:
    arma::vec r;
    arma::vec v;
    double m;
    std::string name;
    // Default constructor
    Body();
    // Constructor with init values.
    Body(std::string name, double mass, arma::vec init_r, arma::vec init_v);

    // Distance between two bodys.
    double d(Body & body);
    
    // Acceleration
    arma::vec a(Body body);
};