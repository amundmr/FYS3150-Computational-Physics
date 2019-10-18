#pragma once

#include <iostream>
#include <cmath>
#include <armadillo>
#include <random>
#include <chrono>
#include <iomanip>
#include <omp.h>

using namespace std;
using namespace arma;

double f(vec, vec);
double naiveMC(double,double,int);
double f2(vec, vec);
double improvedMC(double,int);
