#pragma once

#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

double int_function(double x1, double y1, double z1, double x2, double y2, double z2);
void gauss_laguerre(double *, double *, int, double);
void gauleg(double, double, double *, double *, int);
double gammln(double);
double func_polar_laguerre(double r1, double t1, double p1, double r2, double t2, double p2);
double func_polar_lag(double r1, double t1, double p1, double r2, double t2, double p2);