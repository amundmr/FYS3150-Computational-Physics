#include "./include/mclib.h"

int main(){
    int MCsamples = 100;
    double a = -10;
    double b = 10;
    double I_1 = MonteCarlo(a,b,MCsamples);
    cout << "Monte Carlo integral is:\t\t" << I_1 << endl;
    cout << "Analytical integral value (5pi^2/16^2):\t" << 5*M_PI*M_PI/(16*16) << endl;
}