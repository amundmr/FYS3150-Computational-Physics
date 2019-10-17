#pragma once

#include <iostream>
#include <cmath>
#include <armadillo>
#include <random>

using namespace std;
using namespace arma;

double f(vec, vec);
double naiveMC(double,double,int);
double f2(vec, vec);