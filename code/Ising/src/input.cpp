#include <iostream>
using namespace std;

void input(int &L, int &mcs , double &T_start, double &T_end, double &T_step){

  cout << "Number(int) of spins, L: ";
  cin  >> L;
  cout << endl;
  cout << "mcs " << endl;
  cin  >> mcs;
  cout << endl;
  cout << "Initial temperature : "  << endl;
  cin  >> T_start;
  cout << endl;
  cout << "Final temperature : " << endl;
  cin  >> T_end;
  cout << endl;
  cout << "Temprature steps : " << endl;
  cin  >> T_step;
  cout << endl;

}
