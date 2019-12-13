#pragma once

#include <armadillo>
#include <cmath>
#include <chrono>
#include <vector>
#include <tuple>
#include <iostream>
#include <string>
#include <fstream>
#include <memory> //Used for building vector of shared pointers and use make_shared to allocate ofstream objects.

#include "./body.h"
#include "./system.h"

arma::vec verlet_r(arma::vec, arma::vec, arma::vec, double);
arma::vec verlet_v(arma::vec, arma::vec, arma::vec, double);

arma::vec euler_r(arma::vec, arma::vec, arma::vec, double);
arma::vec euler_v(arma::vec, arma::vec, arma::vec, double);

System initialize();

static const double G = 4*M_PI*M_PI; // Grav const in units of AU^3/(yr^2*Msun)
static const double c = 63240.0755211; // Speed of light in units of AU/yr
