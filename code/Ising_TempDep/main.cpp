#include "./include/lib.h"

/* Use parameters: L = 2, MCc = 1000000, Initial temp = 0.9, Final temp: 1, temp step: 0.1 */
/* HOW TO FUCKING RUN THIS BS PARALELL SHITFUCK: compile med mpiCC, etter compilation kjør "mpirun -np 4 ./main.exe out" */

ofstream ofile;

int main(int argc, char * argv[])
{
  // Variables.
  char * outfilename; long idum; int L, mcs; double T, T_start, T_end, T_step, E, M;
  vec Ediff(17);
  double E_avg, EE_avg, M_avg, MM_avg, Mfabs;
  double tE_avg, tEE_avg, tM_avg, tMM_avg, tMfabs;

  int numprocs, my_rank;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
  MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

  // Input arguments from command line. Aborts if there are too few.
  if (my_rank == 0 && argc <= 1){
    cout<<"Wrong" << argv[0];
    cout <<"Write also output filename on same line" << endl;
    exit(1);
  }
  if (my_rank == 0 && argc > 1) {
    outfilename = argv[1];
    input(L, mcs, T_start, T_end, T_step);
    ofile.open(outfilename);
    ofile << "T:    Energy variance:    Magnetization:   Energy:   AbsMagnet:   HeatCap:   Susceptibility:" << endl;

  }

  //input(L, mcs, T_start, T_end, T_step);
  //L = 2; mcs = 1000000; T_start = 1; T_end = 2; T_step = 1;


  int no_intervals = mcs/numprocs;
  int myloop_begin = my_rank*no_intervals + 1;
  int myloop_end = (my_rank + 1)*no_intervals;
  if( (my_rank == numprocs-1) && (myloop_end<mcs) ) myloop_end = mcs;

  //Broadcast common variables to all nodes
  MPI_Bcast (&L, 1, MPI_INT, 0, MPI_COMM_WORLD);
  MPI_Bcast (&T_start, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  MPI_Bcast (&T_end, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);
  MPI_Bcast (&T_step, 1, MPI_DOUBLE, 0, MPI_COMM_WORLD);

  mat spin(L,L);
  //Starting with random seed for each proc
  idum = -1-my_rank;// Random starting point.

  double TimeStart, TimeEnd, TotalTime;
  TimeStart = MPI_Wtime();

  for (T = T_start; T < T_end; T += T_step)
  {
    //Resetting all parametres for each temperature step
    E_avg =0.0, EE_avg = 0.0; M_avg = 0.0; MM_avg = 0.0; Mfabs = 0.0;
    tE_avg =0.0, tEE_avg = 0.0; tM_avg = 0.0; tMM_avg = 0.0; tMfabs = 0.0;
    E = M = 0.0;

    for (int de = -8; de <= 8; de+=4) Ediff(de+8) = 0;
    for (int de = -8; de <= 8; de+=4) Ediff(de+8) = exp(-de/T);

    initialize(L, T, spin, E, M);

    //Monte Carlo:
    for (int cycles = myloop_begin; cycles <= myloop_end; cycles++){
      Metropolis(L,idum,spin,E,M,Ediff);

      E_avg += E;
      EE_avg += E*E;
      M_avg += M;
      MM_avg += M*M;
      Mfabs += fabs(M);
    }

    MPI_Reduce(&E_avg, &tE_avg, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&EE_avg, &tEE_avg, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&M_avg, &tM_avg, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&MM_avg, &tMM_avg, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&Mfabs, &tMfabs, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if(my_rank == 0){
    output(L,mcs,T, ofile, tE_avg, tM_avg, tEE_avg, tMM_avg, tMfabs);
    // Print results to file.
    cout << "Tempiteration: " << T << endl;
    }
  }
  TimeEnd = MPI_Wtime();
  TotalTime = TimeEnd-TimeStart;
  if ( my_rank == 0 ){
    cout << "Time spent: " << TotalTime << "s. Number of processors: " << numprocs << endl;
    ofile.close();
  }

  //end MPI
  MPI_Finalize ();


  return 0;
}
