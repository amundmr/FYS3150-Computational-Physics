#include "./include/mclib.h"

int main(){
    int MCsamples; double infty; int power; double exact;

    // Take in the number of samples to be done.
    cout << "Number of Monte Carlo samples: 10^";
    cin >> power;
    MCsamples = pow(10,power);
    exact = 5*M_PI*M_PI/(16*16);

    // Take in an approximation of infinity, used to find the integration domain.
    cout << "Approximation of infinity: ";
    cin >> infty;
    cout << "=======================================================================================" << endl << endl << endl;
    cout << "=======================================================================================";

    double a = -infty; // Lower integration bound.
    double b = infty; // Upper integration bound.

    auto tStart = std::chrono::high_resolution_clock::now();
    cout << "\e[A\e[A\rWaiting for naïve Monte Carlo...";
    double naive = naiveMC(a,b,MCsamples); // Naive Monte Carlo. Cartesian coordinates and uniform distribution.
    auto t_Naive = std::chrono::high_resolution_clock::now();

    cout << "Waiting for improved Monte Carlo...";
    double improved = improvedMC(infty,MCsamples); // Improved Monte Carlo. Spherical coordinates and exponential PDF.
    auto t_Improved = std::chrono::high_resolution_clock::now();

    double tImproved = std::chrono::duration_cast<std::chrono::microseconds>( t_Improved - t_Naive ).count();
    double tNaive = std::chrono::duration_cast<std::chrono::microseconds>( t_Naive - tStart ).count();

    cout << "\033[4mNaïve Monte Carlo\033[0m" << endl;
    cout << setprecision(8) << "\tIntegral:\t" << naive << endl << "\tRelative error:\t" << fabs(naive-exact) << endl << "\tTime spent:\t" << tNaive/1000000 << "s" << endl << endl;

    cout << "\033[4mImproved Monte Carlo\033[0m" << endl;
    cout << setprecision(8) << "\tIntegral:\t" << improved << endl << "\tRelative error:\t" << fabs(improved-exact) << endl << "\tTime spent:\t" << tImproved/1000000 << "s" << endl << endl;
    
    cout << "\033[4mAnalytical solution\033[0m" << endl << "\tIntegral:\t" << exact << endl << endl;
}
