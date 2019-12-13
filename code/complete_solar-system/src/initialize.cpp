#include "../include/lib.h"

// This initializer initializes the Sun-Earth-Jupiter scenario with changing Jupiter mass.

// Position and velocity data is gathered from NASA's HORIZONS Web-Interface on December 4th.
// Distance is given in astronomical units (AU). The speed is in AU/day.
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
    arma::vec init_v_Earth = { 0,2*M_PI/365.2442, 0 };
    name = "Earth";
    Body Earth(name, 3.04043263333E-6, init_r_Earth, init_v_Earth);
    system.add(Earth);

    // Jupiter
    arma::vec init_r_Jupiter = { 3.143318263784830E-01, -5.220576747406893E+00, 1.461909341681729E-02 };
    arma::vec init_v_Jupiter = { 7.440259444224412E-03, 8.132434945072271E-04, -1.698183247945803E-04 };
    name = "Jupiter";
    Body Jupiter(name, 954.79194E-3, init_r_Jupiter, init_v_Jupiter); // Changig the mass from -6 to -5 and -3 (original mass, 10x and 1000x)
    system.add(Jupiter);

    return system;
}
