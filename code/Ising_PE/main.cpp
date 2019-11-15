#include "./include/lib.h"

/* HOW TO FUCKING RUN THIS BS PARALELL SHITFUCK: compile med mpiCC, etter compilation kjør "mpirun -np 4 ./main.exe out" */
/*FLOW:
Kjører hele dåsan som vanlig.
Lag en energi-spacing som blir bredden av søylene i histogrammet, ser ut som at 4 kan være et greit tall for 20x20 lættis
Ta energien av hver eneste lattice sweep og tell de som går inn under E = 1-4, 4-8, 8-12 osv opp til så mye som trengs.
Til slutt bør alle boksene bli normalisert slik at arealet til sammen er 1, og da har vi en probdist.
*/
//ofstream ofile;

int main(int argc, char * argv[])
{
  // Variables.
  char * outfilename; long idum; int L, mcs; double T, T_start, T_end, T_step, E, M;
  vec Ediff(17);
  double E_avg, EE_avg, M_avg, MM_avg, Mfabs;
  double tE_avg, tEE_avg, tM_avg, tMM_avg, tMfabs;

  int numprocs, my_rank;
  MPI_Comm comm;
  MPI_Status status;
  MPI_File fh;
  MPI_Init(&argc, &argv);
  comm = MPI_COMM_WORLD;
  MPI_File_open( comm, argv[1], MPI_MODE_RDWR | MPI_MODE_CREATE, MPI_INFO_NULL, &fh );
  MPI_Comm_size(comm, &numprocs);
  MPI_Comm_rank(comm, &my_rank);


  // Input arguments from command line. Aborts if there are too few.
  if (my_rank == 0 && argc <= 1){
    cout<<"Wrong" << argv[0];
    cout <<"Write also output filename, temperature and numer of MC cycles on same line" << endl;
    exit(1);
  }
  if (my_rank == 0 && argc > 1) {
    //outfilename = argv[1];
    //input(L, mcs, T_start, T_end, T_step);
    //ofile.open(outfilename);
    ofile << "T:    Energy variance:    Magnetization:   Energy:   AbsMagnet:   HeatCap:   Susceptibility:" << endl;

  }



  //input(L, mcs, T_start, T_end, T_step);
  L = 20; mcs = 1000000; T = 2.4;


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

      //if (cycles > 0.2*mcs){
        char buf[42];
        snprintf(buf,42,"%f \n",E);
        MPI_File_write_ordered( fh, buf, strlen(buf), MPI_CHAR, &status );

      //}
/*
      E_avg += E;
      EE_avg += E*E;
      M_avg += M;
      MM_avg += M*M;
      Mfabs += fabs(M);*/
    }
/*
    MPI_Reduce(&E_avg, &tE_avg, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&EE_avg, &tEE_avg, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&M_avg, &tM_avg, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&MM_avg, &tMM_avg, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
    MPI_Reduce(&Mfabs, &tMfabs, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
*/
    if(my_rank == 0){
    //output(L,mcs,T, ofile, tE_avg, tM_avg, tEE_avg, tMM_avg, tMfabs);
    // Print results to file.
    cout << "Tempiteration: " << T << endl;
    }

  TimeEnd = MPI_Wtime();
  TotalTime = TimeEnd-TimeStart;
  if ( my_rank == 0 ){
    cout << "Time spent: " << TotalTime << "s. Number of processors: " << numprocs << endl;
    //ofile.close();
  }
  MPI_File_close( &fh );
  //end MPI
  MPI_Finalize ();

  return 0;
}
