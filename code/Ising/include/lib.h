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

void input(int &, int & , double &, double &, double &);
void initilize(int, double, int **, double&, double&);
void Metropolis(int , long&, int **, double &, double &, double *);
void output(int, int, double, vector<int>&);

inline int periodic_boundary_conditions(int i, int limit, int add){
  return (i+limit+add) % (limit);
}
