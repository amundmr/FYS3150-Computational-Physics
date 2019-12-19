#include "../include/lib.h"

class System
{
private:
    std::vector<Body> bodies;
    int no_bodies;

    // Printing body position to file
    void print();
public:
    // Default constructor
    System();

    // Adding a body to the system
    void add(Body body);

    // Solve for whole system using Velocity Verlet method.
    void solve(int N, double tot_years);
};
