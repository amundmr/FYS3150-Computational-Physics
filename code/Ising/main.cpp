#include "./include/lib.h"

int main(int argc, char * argv[])
{
  // Variables.
  char * outfilename; long idum; int L, mcs; double T, T_start, T_end, T_step, E, M;
  vec Ediff(17);
  vec average = zeros<vec>(5);


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
  //idum = -1; // Random starting point.

  ofstream file, file2;
  file.open(outfilename);
  file2.open("accepted_spins.csv");

  for (T = T_start; T < T_end; T += T_step)
  {
    E = M = 0.;
    for (int de = -8; de <= 8; de+=4) Ediff(de+8) = 0;
    for (int de = -8; de <= 8; de+=4) Ediff(de+8) = exp(-de/T);

    //initialize(L, T, spin, E, M);
    initialize_random(L, T, spin, E, M);

    file << "MC_samples M E" << endl;

    int sum  = 0;
    //Monte Carlo:
    for (int cycles = 1; cycles <= mcs; cycles++){

      Metropolis(L,idum,spin,E,M,Ediff,file2,cycles,sum);

      average(0) += E; average(1) += E*E;
      average(2) += M; average(3) += M*M; average(4) += fabs(M);


      // Print results to file.
      output(L,cycles,T,average, file);
    }
  }

  file.close();
  file2.close();
  return 0;
}
