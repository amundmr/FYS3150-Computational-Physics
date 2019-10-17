#include "../include/mclib.h"

double naiveMC(double a,double b,int MCsamples){
    double mc, var, fval; vec r1 = zeros<vec>(3); vec r2 = zeros<vec>(3); // Variable storage.

    // Integration volume.
    double V = pow((b-a),6);

    // Initialize RNG (Mersenne Twister) in our interval
    mt19937::result_type seed = time(0);
    auto interval_rand = bind(uniform_real_distribution<double>(a,b),mt19937(seed));

    for (int i=0 ; i<MCsamples ; i++){
        // Fill vectors with random values.
        r1(0) = interval_rand(); r1(1) = interval_rand(); r1(2) = interval_rand();
        r2(0) = interval_rand(); r2(1) = interval_rand(); r2(2) = interval_rand();

        // Add function value to sum and function value square to another sum.
        mc += f(r1,r2);
        var += f(r1,r2) * f(r1,r2);
    }
    // Find variance
    var = V*sqrt((var-mc/MCsamples)/MCsamples);
    // Find mean and multiply by integration volume.
    mc *= V/MCsamples;

    // Printing the variance.
    cout << "Variance is: " << var << endl;

    return mc;
}