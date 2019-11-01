#include "../include/lib.h"


ofstream ofile;
void output(int L, int mcs, double T, vec ExpecationValues, string filename){
  ofile.open(filename);
  double norm = 1.0/((double) (mcs));
  double E_ExpectVal    = ExpecationValues[0]*norm;
  double E2_ExpectVal   = ExpecationValues[1]*norm;
  double M_ExpectVal    = ExpecationValues[2]*norm;
  double M2_ExpectVal   = ExpecationValues[3]*norm;
  double Mabs_ExpectVal = ExpecationValues[4]*norm;

  double Evariance =(E2_ExpectVal-E_ExpectVal*E_ExpectVal)/L/L;
  double Mvariance =(M2_ExpectVal-Mabs_ExpectVal*Mabs_ExpectVal)/L/L;

  //ofile << setiosflags(ios::showpoint | ios::uppercase);
  ofile << T<<endl;
  ofile <<   E_ExpectVal/L/L<<endl;
  ofile <<  Evariance/T/T<<endl;
  ofile <<   M_ExpectVal/L/L<<endl;
  ofile <<  Mvariance/T<<endl;
  ofile <<  Mabs_ExpectVal/L/L<<endl;
  ofile.close();
}
