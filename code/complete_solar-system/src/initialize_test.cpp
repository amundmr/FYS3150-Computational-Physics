#include "../include/lib.h"

// This initializer initializes only the Earth-Sun scenario with a perfectly circular orbit for testing the verlet solver

// The masses are relative to the mass of the sun.

System initialize()
{
    System system;

    // Sun
    arma::vec init_r_Sun = { 0,0,0 };
    arma::vec init_v_Sun = { 0,0,0 };
    std::string name = "Sun";
    Body Sun(name, 1, init_r_Sun, init_v_Sun);
    system.add(Sun);

    // Earth
    arma::vec init_r_Earth = { 1, 0, 0};
    arma::vec init_v_Earth = { 0,2*M_PI/365.2442, 0 }; //The 2 in front of M_PI was changed intil the earth escaped. 2.282 was found as the lowest escape velocity
    name = "Earth";
    Body Earth(name, 3.04043263333E-6, init_r_Earth, init_v_Earth);
    system.add(Earth);


    return system;
}
