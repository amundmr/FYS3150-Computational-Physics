#include "../include/lib.h"

void input(int &N, double &t_end, arma::mat&position, arma::mat&velocity){

  cout << "Number of steps: ";
  cin  >> N;
  cout << endl << "Time: ";
  cin  >> t_end;
  cout << endl << "Initial x-position: "  << endl;
  cin  >> position(0,0);
  cout << endl << "Initial y-position: "  << endl;
  cin  >> position(1,0);
  cout << endl << "Initial velocity in x-dir: " << endl;
  cin  >> velocity(0,0);
  cout << endl;
}
