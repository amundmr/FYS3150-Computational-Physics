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

using namespace std;
using namespace arma;

void initilize(int L, double T, mat &spinn, double& E, double& M);
void Metropolis(int L, long& idum, mat &spinn, double& E, double& M, vec w);
void input(int&, int& , double&, double&, double&);
void output(int, int, double, vec, string);
int periodic_boundary_conditions(int, int, int);
