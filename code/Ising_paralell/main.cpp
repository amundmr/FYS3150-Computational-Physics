#include "./include/lib.h"

int main(int argc, char * argv[])
{
  // Variables.
  char * outfilename, * outfilename2;
  long idum;
  int L, mcs;
  double T, T_start, T_end, T_step, E, M;
  vec Ediff(17);
  //Måtte ta bort vektoren og bruke konstanta fordi det ikke funke med vektoren mellom kjerna i MPI
  //E_avg osv e kjernens individuelle double, mens tE_avg e etter dem e summert
  double E_avg, EE_avg, M_avg, MM_avg, Mfabs;
  double tE_avg, tEE_avg, tM_avg, tMM_avg, tMfabs;
  //vec average = zeros<vec>(5);

  //Parallellisering initialisering
  int numprocs, my_rank;
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

  // Input arguments from command line. Aborts if there are too few.
  if (my_rank == 0 && argc <= 2){
    cout<<"Wrong" << argv[0];
    cout <<"Write also output filename on same line" << endl;
    exit(1);
  }
  if (my_rank == 0 && argc > 2) {
    outfilename = argv[1];
    outfilename2 = argv[2];
    //input(L, mcs, T_start, T_end, T_step);
    L = stoi(argv[3]);
    mcs = stoi(argv[4]);
    T_start = stod(argv[5]);
    T_end = stod(argv[6]);
    T_step = stod(argv[7]);
  }



  //Sende alle variabler fra thread 0 ut til alle andre:
  MPI_Bcast (&L, 1, MPI_INT, 0, MPI_COMM_WORLD);
  MPI_Bcast (&T_start, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  MPI_Bcast (&T_end, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  MPI_Bcast (&T_step, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  MPI_Bcast (&mcs, 1, MPI_INT, 0, MPI_COMM_WORLD);

  //Definere prosessindividuelle parametre for MC loop
  int no_intervals = mcs/numprocs;
  int myloop_begin = my_rank*no_intervals + 1;
  int myloop_end = (my_rank + 1)*no_intervals;
  if( (my_rank == numprocs-1) && (myloop_end<mcs) ) myloop_end = mcs;

  mat spin(L,L);
  //idum = -1; // Random starting point.
  ofstream file, file2;
  file.open(outfilename);
  file2.open(outfilename2);
  if(my_rank == 0){ //Vil bare at dette skal kjøre i thread 1 der filene er åpnet

    file << "T M E Susceptibility Cv" << endl;
    file2 << "Monte_Carlo_Cycles" << " " << "Accepted_spins" << endl;
  }

  //MPI tidtaker
  double TimeStart, TimeEnd, TotalTime;
  TimeStart = MPI_Wtime();

  for (T = T_start; T < T_end; T += T_step)
  {
    //Resette alle parametre er viktig.
    E_avg =0.0, EE_avg = 0.0; M_avg = 0.0; MM_avg = 0.0; Mfabs = 0.0;
    tE_avg =0.0, tEE_avg = 0.0; tM_avg = 0.0; tMM_avg = 0.0; tMfabs = 0.0;
    E = M = 0.0;

    for (int de = -8; de <= 8; de+=4) Ediff(de+8) = 0;
    for (int de = -8; de <= 8; de+=4) Ediff(de+8) = exp(-de/T);

    initialize(L, T, spin, E, M);
    //initialize_random(L, T, spin, E, M);

    int waitNspins = 10000;
    int sum  = 0;
    //Monte Carlo:
    for (int cycles = myloop_begin; cycles <= myloop_end; cycles++){

      Metropolis(L,idum,spin,E,M,Ediff,cycles,sum, mcs);
      if (cycles >= waitNspins){
      E_avg += E;
      EE_avg += E*E;
      M_avg += M;
      MM_avg += M*M;
      Mfabs += fabs(M);
      }

    }

    //Summere sammen alle E_avg fra hvert thread til tE_avg
    MPI_Reduce(&E_avg, &tE_avg, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&EE_avg, &tEE_avg, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&M_avg, &tM_avg, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&MM_avg, &tMM_avg, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&Mfabs, &tMfabs, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);


    if (my_rank == 0){
      output(L,mcs-waitNspins,T,file, tE_avg, tM_avg, tEE_avg, tMM_avg, tMfabs);
      cout << "Tempiteration: " << T << endl;
    }
  }

  TimeEnd = MPI_Wtime();
  TotalTime = TimeEnd-TimeStart;
  if ( my_rank == 0 ){
    cout << "Time spent: " << TotalTime << "s. Number of processors: " << numprocs << endl;
    file.close();
    file2.close();
  }

  //end MPI
  MPI_Finalize ();

  return 0;
}
