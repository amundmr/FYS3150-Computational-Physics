#pragma once

#include <iostream>
#include <cmath>
#include <fstream>
#include <random>
#include <iomanip>
#include <cstdlib>
#include <armadillo>
#include <string>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <chrono>
#include <omp.h>


using namespace std;
using namespace arma;

void initialize(int, double, mat &, double&, double&);
void Metropolis(int, long&, mat &, double&, double&, vec);
void input(int&, int& , double&, double&, double&);
void output(int, int, double, string, double, double, double, double, double);
int periodic_boundary_conditions(int, int, int);
