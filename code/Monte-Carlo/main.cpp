#include "./include/mclib.h"

int main(){
    int MCsamples; double infty; int power;

    // Take in the number of samples to be done.
    cout << "Number of Monte Carlo samples: 10^";
    cin >> power;
    MCsamples = pow(10,power);

    // Take in an approximation of infinity, used to find the integration domain.
    cout << "Approximation of infinity: ";
    cin >> infty;
    cout << "======================================================" << endl;

    double a = -infty; // Lower integration bound.
    double b = infty; // Upper integration bound.

<<<<<<< HEAD

    auto t1 = std::chrono::high_resolution_clock::now();
    // Naive Monte Carlo. Cartesian coordinates and uniform distribution.
    double naive = naiveMC(a,b,MCsamples);

    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

    cout << "Time spent: " << duration << " microseconds" << endl;
    cout << "Naive Monte Carlo integral is:\t\t" << naive << endl;
=======
    cout << "Waiting for naïve Monte Carlo..." << endl;
    double naive = naiveMC(a,b,MCsamples); // Naive Monte Carlo. Cartesian coordinates and uniform distribution.
    cout << "Waiting for improved Monte Carlo..." << endl;
    double improved = improvedMC(infty,MCsamples); // Improved Monte Carlo. Spherical coordinates and exponential PDF.

    cout << "\rNaïve Monte Carlo integral is:\t\t" << naive << endl;
    cout << "Improved Monte Carlo integral is:\t" << improved << endl;
>>>>>>> 66d80145fe3f6462efaf786d041df2c65fb9e5b0
    cout << "Analytical integral value (5pi^2/16^2):\t" << 5*M_PI*M_PI/(16*16) << endl;
}
