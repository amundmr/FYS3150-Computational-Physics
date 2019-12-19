#include <iostream>
using namespace std;

class SolarSystem{
  public: //Access specifier
    void coolSaying(){//Function inside class
      cout << "Wewos" << endl;
    }

};

int main()
{

  SolarSystem solarObject; //Declaring solarObject the object of the class SolarSystem
  solarObject.coolSaying(); //Calling the object with a dot separator and then the wanted function…
  return 0;
}
