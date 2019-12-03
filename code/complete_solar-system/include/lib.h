#pragma once

#include <armadillo>
#include <cmath>
#include <vector>
#include <tuple>

class Planet;
class System;

void verlet(arma::vec &, arma::vec &, double (*a)(double), double, double, double, int);

static const double G = 4*M_PI*M_PI; // AU^3/(yr^2*Msun)