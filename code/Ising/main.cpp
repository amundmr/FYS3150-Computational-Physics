#include "./include/lib.h"

int main(int argc, char * argv[])
{
  // Variables.
  char * outfilename; long idum; int L, mcs; double T, T_start, T_end, T_step, E, M;
  vec Ediff(17), average(5);


  // Input arguments from command line. Aborts if there are too few.
  if (argc <= 1){
    cout<<"Wrong" << argv[0];
    cout <<"Write also output filename on same line" << endl;
    exit(1);
  }
  else {
    outfilename = argv[1];
  }

  input(L, mcs, T_start, T_end, T_step);

  mat spin(L,L);
  idum = -1; // Random starting point.

  ofstream file;
  file.open(outfilename);

  for (T = T_start; T < T_end; T += T_step)
  {
    E = M = 0.;
    for (int de = -8; de <= 8; de+=4) Ediff(de+8) = 0;
    for (int de = -8; de <= 8; de+=4) Ediff(de+8) = exp(-de/T);

    //Array for expectation values.
    for (int i = 0; i < 5; i++) average(i) = 0;
    initialize(L, T, spin, E, M);

    file << "MC_samples M E" << endl;
    //Monte Carlo:
    for (int cycles = 1; cycles <= mcs; cycles++){
      Metropolis(L,idum,spin,E,M,Ediff);

      average(0) += E; average(1) += E*E;
      average(2) += M; average(3) += M*M; average(4) += fabs(M);
      // Print results to file.
      output(L,cycles,T,average, file);
    }
  }

  file.close();
  return 0;
}
