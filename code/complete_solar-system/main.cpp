#include "./include/lib.h"

int main()
{
    System system = initialize();

    int N = 1000;
    double tot_years = 10;
    system.solve(N, tot_years);
}
