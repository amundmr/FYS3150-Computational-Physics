#include "./include/lib.h"

//Main program
int main(int argc, char* argv[] ){
  char *outfilename;
  long idum;
  int L, mcs;
  vec w(17), avarage(5);
  double T, T_start, T_end, T_step, E, M;


  //Input arguments from command line. Aborts if there are too few
  if (argc <= 1){
    cout<<"Wrong" << argv[0];
    cout <<"Write also output filename on same line" << endl;
    exit(1);
  }
  else {
    outfilename = argv[1];
  }


  input(L, mcs, T_start, T_end, T_step);
  mat spinn(L,L);
  idum = -1; //random starting point

  for (T = T_start; T<= T_end; T += T_step){
    E = M = 0.;

    for (int de = -8; de <= 8 ;de++) w[de+8] = 0;
    for (int de = -8; de <= 8 ;de+=4) w[de+8] = exp(-de/T);

    //Array for expectation values
    for(int i = 0; i < 5; i++) avarage[i] = 0;
    initilize(L, T, spinn, E, M);


    //Monte Carlo:
      for (int cycles = 1; cycles <= mcs; cycles++){
        Metropolis(L,idum,spinn,E,M,w);

        avarage(0) += E; avarage(1) += E*E;
        avarage(2) += M; avarage(3) += M*M; avarage(4) += fabs(M);

      }


  }

  //print results;
  output(L,mcs,T,avarage, outfilename);

  return 0;
}

int periodic_boundary_conditions(int i, int limit, int add)
{
  return (i + limit + add) % limit;
}
