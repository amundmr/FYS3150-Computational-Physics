#include "../include/isinglib.h"

double meanE(double T, int L, double J)
{
    double mean;
    
    double N = L*L; 
    double beta = 1e23/(1.380649*T);

    // calc of E's

    double Z = 2*exp(-beta*8*J)+2*exp(beta*8*J); // Partition function. Planning on actually calculating this.
    int M = 16; // Number of microstates.
    
    for (int i=1; i<M; i++){
        mean = E(i)*exp(-beta*E(i));
    }

    return mean/Z;
}