#include "../include/lib.h"

// This initializer initializes all the planets in our solar system.

// Position and velocity data is gathered from NASA's HORIZONS Web-Interface on December 4th.
// Distance is given in astronomical units (AU). The speed is in AU/day.
// The masses are relative to the mass of the sun.

System initialize()
{
    System system;

    // Sun
    arma::vec init_r_Sun = { -3.563810715624083E-03, 7.491531638305828E-03, 1.655676692094727E-05 };
    arma::vec init_v_Sun = { -8.416936736783392E-06, -1.691302871706155E-06, 2.317246937383506E-07 };
    std::string name = "Sun";
    Body Sun(name, 1, init_r_Sun, init_v_Sun);
    system.add(Sun);

    // Mercury
    arma::vec init_r_mercury = { -3.789504580698334E-01, 4.684689046008077E-02, 3.766865405775025E-02 };
    arma::vec init_v_mercury = { -8.789165321660380E-03, -2.677452607091479E-02, -1.381988914711348E-03 };
    name = "Mercury";
    Body Mercury(name, 0.16601E-6, init_r_mercury, init_v_mercury);
    system.add(Mercury);

    // Venus
    arma::vec init_r_Venus = { 5.512474009280770E-01, -4.625170301656080E-01, -3.844917418296085E-02 };
    arma::vec init_v_Venus = { 1.293735582197075E-02, 1.535405440007813E-02, -5.361297362506485E-04 };
    name = "Venus";
    Body Venus(name, 2.4478383E-6, init_r_Venus, init_v_Venus);
    system.add(Venus);

    // Earth
    arma::vec init_r_Earth = { 3.132510181850079E-01, 9.408798933562862E-01, -2.445960295895797E-05 };
    arma::vec init_v_Earth = { -1.658326502114002E-02, 5.457306983631608E-03, 3.435230178256237E-07 };
    name = "Earth";
    Body Earth(name, 3.04043263333E-6, init_r_Earth, init_v_Earth);
    system.add(Earth);

    // Mars
    arma::vec init_r_Mars = { -1.517244805986132E+00, -5.641694237784014E-01, 2.517687292167273E-02 };
    arma::vec init_v_Mars = { 5.457896140806998E-03, -1.189618745170077E-02, -3.831343751998104E-04 };
    name = "Mars";
    Body Mars(name, 0.3227151E-6, init_r_Mars, init_v_Mars);
    system.add(Mars);

    // Jupiter
    arma::vec init_r_Jupiter = { 3.143318263784830E-01, -5.220576747406893E+00, 1.461909341681729E-02 };
    arma::vec init_v_Jupiter = { 7.440259444224412E-03, 8.132434945072271E-04, -1.698183247945803E-04 };
    name = "Jupiter";
    Body Jupiter(name, 954.79194E-6, init_r_Jupiter, init_v_Jupiter);
    system.add(Jupiter);

    // Saturn
    arma::vec init_r_Saturn = { 3.657070132789199E+00, -9.338230694329200E+00, 1.678617534114833E-02 };
    arma::vec init_v_Saturn = { 4.885086010917011E-03, 2.018138129297058E-03, -2.296367951127687E-04 };
    name = "Saturn";
    Body Saturn(name, 285.8860E-6, init_r_Saturn, init_v_Saturn);
    system.add(Saturn);

    // Uranus
    arma::vec init_r_Uranus = { 1.628553516795673E+01, 1.130130084336537E+01, -1.690078173510427E-01 };
    arma::vec init_v_Uranus = { -2.271171950542976E-03, 3.048002560061897E-03, 4.094563976070707E-05 };
    name = "Uranus";
    Body Uranus(name, 43.66244E-6, init_r_Uranus, init_v_Uranus);
    system.add(Uranus);

    // Neptune
    arma::vec init_r_Neptune = { 2.922078894168849E+01, -6.446132961812087E+00, -5.406767451617470E-01 };
    arma::vec init_v_Neptune = { 6.549682924120025E-04, 3.084034662862140E-03, -7.831425805432258E-05 };
    name = "Neptune";
    Body Neptune(name, 51.51389E-6, init_r_Neptune, init_v_Neptune);
    system.add(Neptune);

    return system;
}
