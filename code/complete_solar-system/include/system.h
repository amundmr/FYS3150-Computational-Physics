#include "../include/lib.h"

class System
{
private:
    std::vector<Planet> planets;
    std::vector<std::shared_ptr<std::ofstream>> writefiles; //Vector for storing the ofstream objects for writing to file
    std::vector<std::string> filenames;
    int no_planets;

    // Printing planet position to file
    void print();
public:
    // Default constructor
    System();

    // Adding a planet to the system
    void add(Planet planet);

    // Solve for whole system using Velocity Verlet method.
    void solve(int N, double tot_years);
};
