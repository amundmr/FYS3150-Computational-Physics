#include "mcarlo.h"

// Function to intagrate over
double f(vec r1, vec r2, double alpha){
    return exp(-alpha*(sqrt(pow(r1(0),2)+pow(r1(1),2)+pow(r1(2),2))+sqrt(pow(r2(0),2)+pow(r2(1),2)+pow(r2(2),2))));
}