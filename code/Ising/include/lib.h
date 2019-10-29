#pragma once

#include <iostream>
#include <fstream>
#include <random>
#include <iomanip>
#include <vector>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

inline int periodic_boundary_conditions(int &, int &, int&);
void input(int &, int & , double &, double &, double &);
void initilize(int, double, int **, double&, double&);
void Metropolis(int , long&, int **, double &, double &, double *);
void output(int, int, double, std::vector);