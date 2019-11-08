#include "../include/lib.h"

ofstream ofile;
void output(int L, int mcs, double T, vec ExpecationValues, string filename){
  ofile.open(filename);
  double norm = 1.0/((double) (mcs));
  double s_norm = 1.0/(L*L);
  double E_ExpectVal    = ExpecationValues[0]*norm;
  double E2_ExpectVal   = ExpecationValues[1]*norm;
  double M_ExpectVal    = ExpecationValues[2]*norm;
  double M2_ExpectVal   = ExpecationValues[3]*norm;
  double Mabs_ExpectVal = ExpecationValues[4]*norm;

  double Evariance =(E2_ExpectVal-E_ExpectVal*E_ExpectVal)/L/L;
  double Mvariance =(M2_ExpectVal-Mabs_ExpectVal*Mabs_ExpectVal)/L/L;
  double Cv = (E2_ExpectVal-E_ExpectVal*E_ExpectVal)/T/T*s_norm;
  double susep = (M2_ExpectVal-M_ExpectVal*M_ExpectVal)/T*s_norm;

  //ofile << setiosflags(ios::showpoint | ios::uppercase);
  ofile <<"           Temperature: "  << setw(15) << setprecision(8) << T <<endl;
  ofile <<"       Energy variance: "  << setw(15) << setprecision(8) << Evariance/T/T<<endl;
  ofile <<"Expected magnetisation: "  << setw(15) << setprecision(8) << M_ExpectVal/L/L<<endl;
  ofile <<"     Magnetic variance: "  << setw(15) << setprecision(8) << Mvariance/T<<endl;
  ofile <<"       Expected energy: "  << setw(15) << setprecision(8) << E_ExpectVal/L/L<<endl;
  ofile <<"Absolute magnetisation: "  << setw(15) << setprecision(8) << Mabs_ExpectVal/L/L<<endl;
  ofile <<"     Heat capacity, Cv: "  << setw(15) << setprecision(8) << Cv<< endl;
  ofile <<"   Susceptibility, chi: "  << setw(15) << setprecision(8) << susep<< endl;

  ofile.close();
}
