#include "../include/lib.h"

class System
{
private:
    std::vector<Planet> planets;
public:
    int no_planets;

    // Adding a planet to the system
    void add(Planet planet){
        no_planets += 1;
        planets.push_back(planet);
    };

    void solve(int N, double tot_years)
    {
        double dt = tot_years/N;

        arma::mat acc(no_planets, 3);
        double t = 0;
        while (t < tot_years)
        {
            for (int i=0; i<no_planets; i++)
            {
                Planet & current = planets[i];
                arma::vec a(3);

                for (int j=i+1; j<no_planets; j++){
                    Planet & other = planets[j];
                    a -= current.a(other);
                }
                // ...
            }
        }
    };
};