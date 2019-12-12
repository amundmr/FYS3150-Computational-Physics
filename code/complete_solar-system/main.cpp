#include "./include/lib.h"

int main()
{
    System system = initialize();

    int N = 100000;
    double tot_years = 1000;
    system.solve(N, tot_years);
}
