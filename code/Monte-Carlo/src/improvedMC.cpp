#include "../include/mclib.h"

double improvedMC(double infty,int MCsamples){
    double mc, var, fval; vec r1, r2;

    double r_interval = infty; // Interval of r.
    double theta_interval = 2*M_PI; // Interval of theta.
    double phi_interval = M_PI; // Interval of phi
    double V = pow(M_PI,3)*pow(r_interval,6)/6; // Integration volume.

    // Initialize RNG (Mersenne Twister) in our interval
    mt19937::result_type seed = time(0);
    auto r_rand = bind(uniform_real_distribution<double>(0,1),mt19937(seed));
    auto costheta_rand = bind(uniform_real_distribution<double>(-1,1),mt19937(seed));
    auto phi_rand = bind(uniform_real_distribution<double>(0,2*M_PI),mt19937(seed));

    for (int i=0 ; i<MCsamples ; i++){
        // Fill vectors with random values in interval.
        r1(0) = -lambda * log(1-r_rand()); r2(0) = -lambda * log(1-r_rand())

        // Add function value to sum.
        mc += f2(r1,r2);
        var += f2(r1,r2) * f(r1,r2);
    }
    // Find variance
    var = V*sqrt((var-mc/MCsamples)/MCsamples);
    // Find mean and multiply by integration volume.
    mc *= V/MCsamples;

    // Printing the variance.
    cout << "Variance is: " << var << endl;

    return mc;
}