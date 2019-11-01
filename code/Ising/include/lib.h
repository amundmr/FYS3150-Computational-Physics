#pragma once

#include <iostream>
#include <cmath>
//#include <fstream>
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

void input(int&, int& , double&, double&, double&);
void initilize(int, double, mat, double&, double&);
void Metropolis(int , long&, mat, double&, double&, vec);
void output(int, int, double, vec);

 int periodic_boundary_conditions(int i, int limit, int add){
  return (i + limit + add) % limit;
}
