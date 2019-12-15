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

    //Open output files
    for (int p=0; p<no_bodies; p++){
        Body & current = bodies[p];
        std::string name = current.name;
        writefiles[p].open("./output/" + name + ".txt");
    }

    double dt = tot_years/N;

    arma::mat acc(no_bodies, 3); // Arrays for storing the bodies' accelerations.
    double t = 0;

    //Begin timer
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();

    while (t < tot_years) // Loop over total years.
    {
        for (int i=1; i<no_bodies; i++) // Loop over all bodies. Starting at i = 1 excludes the sun as a dynamic object
        {
            Body & current = bodies[i];
            arma::vec a = arma::zeros<arma::vec>(3); arma::vec a_next = arma::zeros<arma::vec>(3);

            for (int j=0; j<no_bodies; j++){ // Loops over all other bodies
                Body & other = bodies[j];
                a += current.a_relcor(other);

            };

            current.r = verlet_r(current.r, current.v, a, dt);
            //current.r = euler_r(current.r, current.v, a, dt);


            // Update acceleration, NOT needed for Euler
            for (int j=0; j<no_bodies; j++){ // Loops over body +1 the current. Might need just i!=j.
                Body & other = bodies[j];
                a_next += current.a_relcor(other);
            };



            current.v = verlet_v(current.v, a, a_next, dt);
            //current.v = euler_v(current.v, a, a_next, dt);
        };

        // Printing current position of whole solar system to files.
        if (t > 0.99*tot_years) {
        for (int p=0; p<no_bodies; p++)
        {
            Body & current = bodies[p];

            for (int i=0; i<3; i++){
                writefiles[p] << std::setprecision(15) << current.r(i) << "\t";
            }
            writefiles[p] << std::endl; //for Energy Printing: << current.Ek(bodies[0]) << "\t" << current.Ep(bodies[0])
        }
        }
        t += dt;
    }
    //End timer
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time Spent = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << "[ms]" << std::endl;

    //Close files
    for (int p=0; p<no_bodies; p++){
        writefiles[p].close();
    }
}
