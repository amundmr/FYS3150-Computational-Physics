#include "../include/lib.h"

void output(int L, int mcs, double T, ofstream & file, double E_avg, double M_avg, double EE_avg, double MM_avg, double Mfabs){

  double norm = 1.0/((double) (mcs));
  double s_norm = 1.0/(L*L);
  double E_ExpectVal    = E_avg*norm;
  double E2_ExpectVal   = EE_avg*norm;
  double M_ExpectVal    = M_avg*norm;
  double M2_ExpectVal   = MM_avg*norm;
  double Mabs_ExpectVal = Mfabs*norm;

  double Evariance =(E2_ExpectVal-E_ExpectVal*E_ExpectVal)/L/L;
  double Mvariance =(M2_ExpectVal-Mabs_ExpectVal*Mabs_ExpectVal)/L/L;
  double Cv = (E2_ExpectVal-E_ExpectVal*E_ExpectVal)/T/T*s_norm;
<<<<<<< HEAD
  double susep2 = (Mabs_ExpectVal-fabs(M_ExpectVal)*fabs(M_ExpectVal))/T*s_norm;

  file << setiosflags(ios::showpoint | ios::uppercase);
=======
  double susep = (M2_ExpectVal-M_ExpectVal*M_ExpectVal)/T*s_norm;

  //file << setiosflags(ios::showpoint | ios::uppercase);
>>>>>>> af80a730ea5b3db70f4ecf4fff5b18fb82ec0871
  //file <<"           Temperature: "  << setw(15) << setprecision(8) << T <<endl;
  //file <<"       Energy variance: "  << setw(15) << setprecision(8) << Evariance/T/T<<endl;
  //file <<"Expected magnetisation: "  << setw(15) << setprecision(8) << M_ExpectVal/L/L<<endl;
  //file <<"     Magnetic variance: "  << setw(15) << setprecision(8) << Mvariance/T<<endl;
  //file <<"       Expected energy: "  << setw(15) << setprecision(8) << E_ExpectVal/L/L<<endl;
  //file << "Absolute magnetisation: "  << setw(15) << setprecision(8) << Mabs_ExpectVal/L/L<<endl;
<<<<<<< HEAD
  //ile <<"     Heat capacity, Cv: "  << setw(15) << setprecision(8) << Cv<< endl;
  //file <<"   Susceptibility, chi: "  << setw(15) << setprecision(8) << susep;

  file << T << " " << Mabs_ExpectVal/L/L << " " << E_ExpectVal/L/L << " "<< susep2 << " " << Cv << endl;
=======
  //file <<"     Heat capacity, Cv: "  << setw(15) << setprecision(8) << Cv<< endl;
  //file <<"   Susceptibility, chi: "  << setw(15) << setprecision(8) << susep;

  file << mcs << " " << Mabs_ExpectVal/L/L << " " << E_ExpectVal/L/L << endl;
>>>>>>> af80a730ea5b3db70f4ecf4fff5b18fb82ec0871

}
