#include "./include/lib.h"

int main()
{
    System system = initialize();

    int N = 1;
    double tot_years = 0.1;
    system.solve(N, tot_years);
}
