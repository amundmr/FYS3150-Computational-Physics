#pragma once
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <armadillo>
#include <cstdlib>
#include <string>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

//void input(int &N, double &t_end, arma::mat&position, arma::mat&velocity);
void output(double t_end, arma::mat&position, arma::mat&velocity,ofstream & ofile, int&);
<<<<<<< HEAD
//void euler(arma::vec & r, arma::vec & v, double (*a)(double), double init_r, double init_v, double dt, int N);
//void verlet(arma::vec & r, arma::vec & v, double (*a)(double), double init_r, double init_v, double dt, int N);
=======
void euler(arma::vec & r, arma::vec & v, double (*a)(double), double init_r, double init_v, double dt, int N);
void verlet(arma::mat & r, arma::mat & v, double (*a)(double), double init_r, double init_v, double dt, int N);
>>>>>>> dae580c248020a5750f550375d02c07c6f101393