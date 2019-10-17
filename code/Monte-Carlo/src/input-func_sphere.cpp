#include "../include/mclib.h"

// Integrand in spherical coordinates.
double f2(vec r1, vec r2){
    double num = r1(0)*r1(0)*r2(0)*r2(0);
    double B = r1(1)*r2(1) + sqrt(1-r1(1)*r1(1)) * sqrt(1-r2(1)*r2(1)) * cos(r1(2)-r2(2));
    double deno = r1(0)*r1(0)+r2(0)*r2(0)-2*r1(0)*r2(0)*B;

    if(deno < 1e-12){
        return 0;
    }
    else{
        return num/sqrt(deno);
    }
}