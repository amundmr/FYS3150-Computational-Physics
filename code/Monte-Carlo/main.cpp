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



    auto tStart = std::chrono::high_resolution_clock::now();
    cout << "Waiting for naïve Monte Carlo..." << endl;
    double naive = naiveMC(a,b,MCsamples); // Naive Monte Carlo. Cartesian coordinates and uniform distribution.
    auto t_Naive = std::chrono::high_resolution_clock::now();

    cout << "Waiting for improved Monte Carlo..." << endl;
    double improved = improvedMC(infty,MCsamples); // Improved Monte Carlo. Spherical coordinates and exponential PDF.
    auto t_Improved = std::chrono::high_resolution_clock::now();

    auto tImproved = std::chrono::duration_cast<std::chrono::microseconds>( t_Improved - t_Naive ).count();
    auto tNaive = std::chrono::duration_cast<std::chrono::microseconds>( t_Naive - tStart ).count();


    cout << setprecision(8) << "\rNaïve Monte Carlo integral is:\t\t" << naive << ", Time spent: " << tNaive << endl;
    cout << setprecision(8) << "Improved Monte Carlo integral is:\t" << improved << ", Time spent: " << tImproved << endl;
    cout << "Analytical integral value (5pi^2/16^2):\t" << 5*M_PI*M_PI/(16*16) << endl;
}
