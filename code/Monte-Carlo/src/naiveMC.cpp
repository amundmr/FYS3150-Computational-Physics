#include "../include/mclib.h"

double naiveMC(double a,double b,int MCsamples){
    double mc;
    double alpha = 2;
    vec r1;
    vec r2;

    double interval = b-a;
    double V = pow(interval,6);

    for (int i=0 ; i<MCsamples ; i++){
        r1.randu(3); r1=a+interval*r1;
        r2.randu(3); r2=a+interval*r2;
        mc += f(r1,r2,alpha);
    }
    mc=mc*V/MCsamples;

    return mc;
}