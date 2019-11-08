#include "../include/lib.h"


void input(int &L, int &mcs , double &T_start, double &T_end, double &T_step){

  cout << "Matrix size, L (int): ";
  cin  >> L;
  cout << endl << "Monte Carlo Cycles: ";
  cin  >> mcs;
  cout << endl << "Initial temperature: "  << endl;
  cin  >> T_start;
  cout << endl << "Final temperature: " << endl;
  cin  >> T_end;
  cout << endl << "Temperature step size: " << endl;
  cin  >> T_step;
  cout << endl;
}