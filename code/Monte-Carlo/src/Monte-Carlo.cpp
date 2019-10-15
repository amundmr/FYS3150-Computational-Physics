#include "mclib.h"

double MonteCarlo(double a,double b,int MCsamples){
    double mc;
    double alpha;
    vec r1;
    vec r2;
    for (int i=0 ; i<MCsamples ; i++){
        r1.randu();
        r2.randu();
        mc += f(r1,r2,alpha);
    }
    mc=mc*pow((b-a),3)/MCsamples;

    return mc;
}