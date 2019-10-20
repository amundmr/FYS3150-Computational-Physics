#include "../include/mclib.h"

double naiveMC(double a,double b,int MCsamples){
    double mc, var, fval, sigma, int_mc;  // Variable storage.

    double V = pow((b-a),6); // Integration volume.

    //Start parallellization
    #pragma omp parallel
    {
    vec r1 = zeros<vec>(3); vec r2 = zeros<vec>(3);
    // Initialize RNG (Mersenne Twister) in our interval
    mt19937::result_type seed = time(0);//+omp_get_thread_num();  //Include last command to get different seed for each thread
    auto interval_rand = bind(uniform_real_distribution<double>(a,b),mt19937(seed));

    //State paralellization of for loop, keeping mc and var private for each thread to sum invidivually, and then globally at end of loop
    #pragma omp for reduction(+:mc) reduction(+:var)
    for ( int i=0 ; i<MCsamples ; i++){

        // Fill vectors with random values.
        r1(0) = interval_rand(); r2(0) = interval_rand();
        r1(1) = interval_rand(); r2(1) = interval_rand();
        r1(2) = interval_rand(); r2(2) = interval_rand();

        // Add function value to sum and function value square to another sum.
        mc += f(r1,r2);
        var += f(r1,r2) * f(r1,r2);
    }

    // End paralellization here
    }

    // Find mean.
    mc /= MCsamples;
    // Find variance
    var = var/MCsamples-pow(mc,2);
    var /= MCsamples;
    // Find standard deviation
    sigma = V*sqrt(var);
    // Find final integral by multiplying with integration volume.
    int_mc = V*mc;
    // Printing the variance.
    cout << "\r\e[0KStandard deviation of naïve Monte Carlo is:\t" << var << endl;

    return int_mc;
}
