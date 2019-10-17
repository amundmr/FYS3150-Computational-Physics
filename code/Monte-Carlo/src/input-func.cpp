#include "../include/mclib.h"

// Integrand in cartesian coordinates.
double f(vec r1, vec r2){
    double alpha = 2.0;
    double exp1 = -2*alpha*sqrt(r1(0)*r1(0) + r1(1)*r1(1) + r1(2)*r1(2));
    double exp2 = -2*alpha*sqrt(r2(0)*r2(0) + r2(1)*r2(1) + r2(2)*r2(2));
    double deno = sqrt(pow((r1(0)-r2(0)),2)+pow((r1(1)-r2(1)),2)+pow((r1(2)-r1(2)),2));
    if (abs(deno) < 1E-12){
        return 0;
    }
    else{
        return exp(exp1 + exp2) / deno;
    }
}