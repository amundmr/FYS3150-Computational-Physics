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


    auto t1 = std::chrono::high_resolution_clock::now();
    // Naive Monte Carlo. Cartesian coordinates and uniform distribution.
    double naive = naiveMC(a,b,MCsamples);

    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();

    cout << "Time spent: " << duration << " microseconds" << endl;
    cout << "Naive Monte Carlo integral is:\t\t" << naive << endl;
    cout << "Analytical integral value (5pi^2/16^2):\t" << 5*M_PI*M_PI/(16*16) << endl;
}
