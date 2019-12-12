#include "./include/lib.h"

int main()
{
    System system = initialize();

    int N = 10000;
    double tot_years = 2;
    system.solve(N, tot_years);
}
