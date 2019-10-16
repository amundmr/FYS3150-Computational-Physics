#pragma once

#include <iostream>
#include <cmath>
#include <armadillo>

using namespace std;
using namespace arma;

double f(vec, vec, double);
double naiveMC(double a,double b,int MCsamples);
