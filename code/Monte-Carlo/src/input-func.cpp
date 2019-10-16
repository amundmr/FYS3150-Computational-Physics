#include "../include/mclib.h"

// Function to intagrate over
double f(vec r1, vec r2, double alpha){
    double f = sqrt(pow(r1(0),2)+pow(r1(1),2)+pow(r1(2),2))+sqrt(pow(r2(0),2)+pow(r2(1),2)+pow(r2(2),2)); // Length of r1 + length of r2
    f = exp(-alpha*f);
    vec r_tot = r1-r2; // Storing r1-r2
    f = f/(sqrt(pow(r_tot(0),2)+pow(r_tot(1),2)+pow(r_tot(2),2))); // Dividing by abs of r1-r2
    return f;
}