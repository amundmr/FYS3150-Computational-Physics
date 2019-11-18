#include "./include/lib.h"

int main(int argc, char * argv[])
{
  // Variables.
  char * outfilename, * outfilename2;
  long idum;
  int L, mcs;
  double T, T_start, T_end, T_step, E, M;
  vec Ediff(17);
  vec average = zeros<vec>(5);


  // Input arguments from command line. Aborts if there are too few.
  if (argc <= 2){
    cout<<"Wrong" << argv[0];
    cout <<"Write also output filename on same line" << endl;
    exit(1);
  }
  else {
    outfilename = argv[1];
    outfilename2 = argv[2];
  }

  input(L, mcs, T_start, T_end, T_step);

  mat spin(L,L);

  ofstream file, file2;
  file.open(outfilename);
  file2.open(outfilename2);

  file << "T M E" << endl;

  for (T = T_start; T < T_end; T += T_step)
  {
    E = M = 0.;
    for (int de = -8; de <= 8; de+=4) Ediff(de+8) = 0;
    for (int de = -8; de <= 8; de+=4) Ediff(de+8) = exp(-de/T);

    //initialize(L, T, spin, E, M);
    initialize_random(L, T, spin, E, M);

    file2 << "Monte_Carlo_Cycles" << " " << "Accepted_spins" << endl;

    int sum  = 0;
    int cycles = 1;
    //Monte Carlo:
    for (cycles ; cycles <= mcs; cycles++){

      Metropolis(L,idum,spin,E,M,Ediff,file2,cycles,sum, mcs);

      average(0) += E; average(1) += E*E;
      average(2) += M; average(3) += M*M; average(4) += fabs(M);

    }
    // Print results to file.
    output(L,cycles,T,average, file);
  }

  file.close();
  file2.close();
  return 0;
}
