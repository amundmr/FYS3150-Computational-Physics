#include <armadillo>

class Planet
{
private:
    arma::vec r = arma::zeros(3);
    arma::vec v = arma::zeros(3);
    double m;
public:
    // Constructor
    Planet(double mass, double distance){
        m = mass; r(0) = distance;
    }
};