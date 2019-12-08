#include "../include/lib.h"

// Default constructor
System::System()
{
    no_planets = 0;
}

// Adding planets to system
void System::add(Planet planet){
    no_planets += 1;
    planets.push_back(planet);
}

// Solve for whole system using Velocity Verlet method.
void System::solve(int N, double tot_years) // Takes in no. integration points and no. years to solve.
{
    std::vector<std::ofstream> writefiles;
    //Opening all the files
    for (int p=0; p<no_planets; p++){
        std::string name = std::to_string(p);
        std::ofstream file;
        file.open(name + ".txt");
        writefiles.push_back(file);
    }

    double dt = tot_years/N;

    arma::mat acc(no_planets, 3); // Arrays for storing the planets' accelerations.
    double t = 0;
    while (t < tot_years) // Loop over total years.
    {
        for (int i=0; i<no_planets; i++) // Loop over all planets.
        {
            Planet & current = planets[i];
            arma::vec a = arma::zeros<arma::vec>(3); arma::vec a_next = arma::zeros<arma::vec>(3);

            for (int j=i+1; j<no_planets; j++){ // Loops over planet +1 the current. Might need just i!=j.
                Planet & other = planets[j];
                a -= current.a(other);
            };

            current.r = verlet_r(current.r, current.v, a, dt);

            // Update acceleration
            for (int j=i+1; j<no_planets; j++){ // Loops over planet +1 the current. Might need just i!=j.
                Planet & other = planets[j];
                a_next -= current.a(other);
            };

            current.v = verlet_v(current.v, a, a_next, dt);
        };

        // Printing current position of whole solar system to files.
        for (int p=0; p<no_planets; p++)
        {
            Planet & current = planets[p];
            
            for (int i=0; i<3; i++){
                writefiles[p] << current.r(i) << "\t";
            }
            writefiles[p] << std::endl;
        }

        t += dt;
    }

    for (int p=0; p<no_planets; p++){
        writefiles[p].close();
    }
}