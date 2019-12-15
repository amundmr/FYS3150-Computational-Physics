#include "./include/lib.h"

int main()
{
    System system = initialize();

    int N = 2E8;
    double tot_years = 100;
    system.solve(N, tot_years);
}
