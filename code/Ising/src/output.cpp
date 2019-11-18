#include "../include/lib.h"

void output(int L, int mcs, double T, vec ExpecationValues, ofstream & file){

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
  double susep2 = (Mabs_ExpectVal-fabs(M_ExpectVal)*fabs(M_ExpectVal))/T*s_norm;

  //file << setiosflags(ios::showpoint | ios::uppercase);
  //file <<"           Temperature: "  << setw(15) << setprecision(8) << T <<endl;
  //file <<"       Energy variance: "  << setw(15) << setprecision(8) << Evariance/T/T<<endl;
  //file <<"Expected magnetisation: "  << setw(15) << setprecision(8) << M_ExpectVal/L/L<<endl;
  //file <<"     Magnetic variance: "  << setw(15) << setprecision(8) << Mvariance/T<<endl;
  //file <<"       Expected energy: "  << setw(15) << setprecision(8) << E_ExpectVal/L/L<<endl;
  //file << "Absolute magnetisation: "  << setw(15) << setprecision(8) << Mabs_ExpectVal/L/L<<endl;
  //file <<"     Heat capacity, Cv: "  << setw(15) << setprecision(8) << Cv<< endl;
  //file <<"   Susceptibility, chi: "  << setw(15) << setprecision(8) << susep;

  //file << T << " " << Mabs_ExpectVal/L/L << " " << E_ExpectVal/L/L << " "<< susep2 << " " << Cv << endl;
  file << mcs << " " << Mabs_ExpectVal/L/L << " " << E_ExpectVal/L/L <<endl;
}
