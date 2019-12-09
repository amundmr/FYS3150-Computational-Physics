#include "../include/lib.h"

// Default constructor
System::System()
{
    no_bodies = 0;
}

// Adding bodies to system
void System::add(Body body){
    no_bodies += 1;
    bodies.push_back(body);
}

// Solve for whole system using Velocity Verlet method.
void System::solve(int N, double tot_years) // Takes in no. integration points and no. years to solve.
{
    std::vector<std::ofstream> writefiles (no_bodies);

    //Opening all the files
    for (int p=0; p<no_bodies; p++){
        Body & current = bodies[p];
        std::string name = current.name;
        writefiles[p].open("./output/" + name + ".txt");
    }

    double dt = tot_years/N;

    arma::mat acc(no_bodies, 3); // Arrays for storing the bodies' accelerations.
    double t = 0;
    while (t < tot_years) // Loop over total years.
    {
        for (int i=0; i<no_bodies; i++) // Loop over all bodies.
        {
            Body & current = bodies[i];
            arma::vec a = arma::zeros<arma::vec>(3); arma::vec a_next = arma::zeros<arma::vec>(3);

            for (int j=i+1; j<no_bodies; j++){ // Loops over body +1 the current. Might need just i!=j.
                Body & other = bodies[j];
                a -= current.a(other);
            };

            current.r = verlet_r(current.r, current.v, a, dt);

            // Update acceleration
            for (int j=i+1; j<no_bodies; j++){ // Loops over body +1 the current. Might need just i!=j.
                Body & other = bodies[j];
                a_next -= current.a(other);
            };

            current.v = verlet_v(current.v, a, a_next, dt);
        };

        // Printing current position of whole solar system to files.
        for (int p=0; p<no_bodies; p++)
        {
            Body & current = bodies[p];
            
            for (int i=0; i<3; i++){
                writefiles[p] << current.r(i) << "\t";
            }
            writefiles[p] << std::endl;
        }

        t += dt;
    }

    for (int p=0; p<no_bodies; p++){
        writefiles[p].close();
    }
}