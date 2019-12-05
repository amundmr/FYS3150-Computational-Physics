#pragma once

#include <armadillo>
#include <cmath>
#include <vector>
#include <tuple>
#include <iostream>
#include <fstream>
#include <memory> //Used for building vector of shared pointers and use make_shared to allocate ofstream objects.

#include "./planet.h"
#include "./system.h"

arma::vec verlet_r(arma::vec, arma::vec, arma::vec, double);
arma::vec verlet_v(arma::vec, arma::vec, arma::vec, double);
System initialize();

static const double G = 4*M_PI*M_PI; // AU^3/(yr^2*Msun)
