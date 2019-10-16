#include "./include/mclib.h"

int main(){
    int MCsamples; double infty;

    // Take in the number of samples to be done.
    cout << "Number of Monte Carlo samples: ";
    cin >> MCsamples;

    // Take in an approximation of infinity, used to find the integration domain.
    cout << "Approximation of infinity: ";
    cin >> infty;

    double a = -infty; // Lower integration bound.
    double b = infty; // Upper integration bound.

    // Naive Monte Carlo. Cartesian coordinates and uniform distribution.
    double naive = naiveMC(a,b,MCsamples); 

    cout << "======================================================" << endl;
    cout << "Naive Monte Carlo integral is:\t\t" << naive << endl;
    cout << "Analytical integral value (5pi^2/16^2):\t" << 5*M_PI*M_PI/(16*16) << endl;
}