#include "../include/lib.h"

using namespace std;
ofstream ofile;

void output(int L, int mcs, double T, vector<int>& ExpecationValues){

  double norm = 1.0/((double) (mcs));
  double E_ExpectVal    = ExpecationValues[0]*norm;
  double E2_ExpectVal   = ExpecationValues[1]*norm;
  double M_ExpectVal    = ExpecationValues[2]*norm;
  double M2_ExpectVal   = ExpecationValues[3]*norm;
  double Mabs_ExpectVal = ExpecationValues[4]*norm;

  double Evariance =(E2_ExpectVal-E_ExpectVal*E_ExpectVal)/L/L;
  double Mvariance =(M2_ExpectVal-Mabs_ExpectVal*Mabs_ExpectVal)/L/L;

  ofile << setiosflags(ios::showpoint | ios::uppercase);
  ofile << setw(15) << setprecision(8) << T;
  ofile << setw(15) << setprecision(8) << E_ExpectVal/L/L;
  ofile << setw(15) << setprecision(8) << Evariance/T/T;
  ofile << setw(15) << setprecision(8) << M_ExpectVal/L/L;
  ofile << setw(15) << setprecision(8) << Mvariance/T;
  ofile << setw(15) << setprecision(8) << Mabs_ExpectVal/L/L<<endl;

}
