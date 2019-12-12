#include "../include/lib.h"

//This initializer initializes only the Earth-Sun scenario with a perfectly circular orbit
// The masses are relative to the mass of the sun.

System initialize()
{
    System system;

    // Sun
    arma::vec init_r_Sun = {0,0,0 };
    arma::vec init_v_Sun = { 0,0,0 };
    std::string name = "Sun";
    Body Sun(name, 1, init_r_Sun, init_v_Sun);
    system.add(Sun);

    // Earth
    arma::vec init_r_Earth = { 0 , 1 , 0 };
    arma::vec init_v_Earth = { 2*M_PI/365.2442 , 0 , 0 }; //2pi is divided by days in a year to get the speed in AU/day
    name = "Earth";
    Body Earth(name, 3.04043263333E-6, init_r_Earth, init_v_Earth);
    system.add(Earth);

    return system;
}
