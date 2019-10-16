#include "./include/mclib.h"

int main(){
    int MCsamples; double infty;
    cout << "Enter number of Monte Carlo samples: ";
    cin >> MCsamples;
    cout << "Approximation of infinity: ";
    cin >> infty;
    double a = -infty;
    double b = infty;
    double I1 = naiveMC(a,b,MCsamples);
    cout << "======================================================" << endl;
    cout << "Monte Carlo integral is:\t\t" << I1 << endl;
    cout << "Analytical integral value (5pi^2/16^2):\t" << 5*M_PI*M_PI/(16*16) << endl;
}