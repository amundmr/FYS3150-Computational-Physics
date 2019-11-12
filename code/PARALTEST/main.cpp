#include "./include/lib.h"

/* Use parameters: L = 2, MCc = 1000000, Initial temp = 0.9, Final temp: 1, temp step: 0.1 */

int main(int argc, char * argv[])
{
  // Variables.
  char * outfilename; long idum; int L, mcs; double T, T_start, T_end, T_step, E, M;
  vec Ediff(17);
  double E_avg, EE_avg, M_avg, MM_avg, Mfabs;
/*
  int nb_procs, rank;

  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &nb_procs);
  MPI_Comm_rank(MPI_COMM_WORLD, &rank);
*/
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

  for (T = T_start; T < T_end; T += T_step)
  {
    //Resetting all parametres for each temperature step
    E_avg =0.0, EE_avg = 0.0; M_avg = 0.0; MM_avg = 0.0; Mfabs = 0.0;
    E = M = 0.0;

    for (int de = -8; de <= 8; de+=4) Ediff(de+8) = 0;
    for (int de = -8; de <= 8; de+=4) Ediff(de+8) = exp(-de/T);


    initialize(L, T, spin, E, M);
    //Start timing
    auto tStart = std::chrono::high_resolution_clock::now();

    //Want to parallellize this loop over MC cycles
    omp_set_num_threads(2);
    int cycles;
    #pragma omp parallel
    {
      int x, y, ix, iy, deltaE;
      random_device rd; //Creates a random seed with a RNG
      mt19937_64 gen(rd()+omp_get_thread_num()); //Initialize PRNG with rd as seed
      uniform_real_distribution<double> interval_rand(0.0, 1.0);
    //Monte Carlo:
    #pragma omp parallel for reduction(+:E_avg,EE_avg,M_avg,MM_avg,Mfabs) 
    for (cycles = 1; cycles <= mcs; cycles++){

      /*
        // Initialize RNG (Mersenne Twister) in our interval
        mt19937::result_type seed = time(0);//+omp_get_thread_num();  //Include last command to get different seed for each thread
        auto interval_rand = bind(uniform_real_distribution<double>(0.0,1.0),mt19937_64(seed));
      */


        for (int y = 0;  y < L; y++)
        {
          for (int x = 0; x < L; x++)
          {
            // Random position in lattice.

            int ix = (int) (interval_rand(gen) * (double)L);
            int iy = (int) (interval_rand(gen) * (double)L);
            int deltaE = 2 * spin(iy,ix)
                           * (spin(iy,periodic_boundary_conditions(ix,L,-1))
                           + spin(periodic_boundary_conditions(iy,L,-1),ix)
                           + spin(iy,periodic_boundary_conditions(ix,L,1))
                           + spin(periodic_boundary_conditions(iy,L,1),ix));

            // Metropolis test:
            if (interval_rand(gen) <= Ediff((int) deltaE +8)){
              spin(iy,ix) *= -1;    //flipp spin
              M += (double) 2*spin(iy,ix);
              E += (double) deltaE;
            }
          }
        }

      E_avg += E;
      EE_avg += E*E;
      M_avg += M;
      MM_avg += M*M;
      Mfabs += fabs(M);
    }
    cout << "Threads used: " << omp_get_num_threads() <<endl;
    }//this bracket ends the parallellization

    //Stop timing and print time spent
    auto tFinish = std::chrono::high_resolution_clock::now();
    double timeSpent = std::chrono::duration_cast<std::chrono::seconds>( tFinish - tStart ).count();
    cout << "Time spent: " << timeSpent << endl;
    output(L,mcs,T, outfilename, E_avg, M_avg, EE_avg, MM_avg, Mfabs);
  }
  // Print results to file.


  return 0;
}
