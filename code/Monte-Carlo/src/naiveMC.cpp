#include "../include/mclib.h"

double naiveMC(double a,double b,int MCsamples){
    double mc, var; vec r1, r2;

    double interval = b-a; // Interval per dimension.
    double V = pow(interval,6); // Integration volume.

    for (int i=0 ; i<MCsamples ; i++){
        // Fill vectors with random values in interval.
        r1.randu(3); r1 = a+interval*r1;
        r2.randu(3); r2 = a+interval*r2;

        // Add function value to sum.
        mc += f(r1,r2);
        var += mc*mc;
    }
    // Find mean and multiply by integration volume.
    mc *= V/MCsamples;

    // Printing the variance
    var = var/MCsamples-mc*mc/(V*V);
    cout << "Variance is: " << var << endl;

    return mc;
}