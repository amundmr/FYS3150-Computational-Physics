## Testing effect of Iteration points and infinity approximation

You can choose either to test how different approximations of $\rho_{max}$ changes the time spent, and the error, or test how different number of integration points, N, changes time and error.

To compile code for N-testing, edit the makefile to compile main.cpp.\
To compile code for $\rho_{max}$-testing, edit the makefile to compile main_rho.cpp

PS: If you get compile errors saying undefined reference to init, Jacobi_method etc, just run make again. Also make sure you have Python3 available in the console you run the executable main.exe from if you want plotting.
