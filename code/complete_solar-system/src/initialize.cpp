#include "../include/lib.h"

// This initializer initializes Mercury for perihelion testing.

// Position and velocity data is gathered from NASA's HORIZONS Web-Interface on December 4th.
// Distance is given in astronomical units (AU). The speed is in AU/day.
// The masses are relative to the mass of the sun.

System initialize()
{
    System system;

    // Sun
    arma::vec init_r_Sun = { 0, 0,0 };
    arma::vec init_v_Sun = { 0,0,0};
    std::string name = "Sun";
    Body Sun(name, 1, init_r_Sun, init_v_Sun);
    system.add(Sun);

    // Mercury
    arma::vec init_r_mercury = { 0.3075,0, 0 };
    arma::vec init_v_mercury = { 0, 12.44/ 365.2442, 0 };
    name = "Mercury";
    Body Mercury(name, 0.16601E-6, init_r_mercury, init_v_mercury);
    system.add(Mercury);


    return system;
}
