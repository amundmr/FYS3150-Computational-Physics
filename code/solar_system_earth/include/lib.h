

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

void input(int &N, int &t_end, arma::mat&position, arma::mat&velocity);
void output(double t_end, arma::mat&position, arma::mat&velocity,ofstream & ofile, int&);
void euler(arma::vec & r, arma::vec & v, double (*a)(double), double init_r, double init_v, double dt, int N);
void verlet(arma::mat & r, arma::mat & v, double (*a)(double), double init_r, double init_v, double dt, int N);
