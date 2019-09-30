#include <armadillo>
#include <cmath>
#include <iostream>
#include <fstream>

using namespace std;
using namespace arma;

mat init(double Rho_N, int N);                //Takes Rho_N (approx infty) and integrations points N, returns tridiag mat.
mat Jacobi_method(mat A, int N);              //Takes matrix to find eigvals and N, returns vector with eigvals.
vec arma_eig(mat A);                          //Armadillos function for finding Eigenvalues, returns vector with eigvals.
double averageError(vec jacobi_eigenvalues);  //Calculating average error of the four first eigenvalues
void consoleout(int N, vec arma_eigenvalues, vec jacobi_eigenvalues, double t_arma, double t_jacobi);

ofstream ofile;

int main() {
  int i = 0;

  //Writing to file for plotting
  string filename = "N-VS-Error";
  ofile.open(filename);

  for (i = 1; i < 5; i++){

    double Rho_N = 10.0;                //Defining the approximation of infinity
    int N = i*100;                      //Defining number of integration points

    mat A = init(Rho_N, N);             //Defining tridiagonal matrix

    //Timing armadillo's eigenvalue solver
    clock_t t0, t1;
    t0 = clock();
    vec arma_eigvals = arma_eig(A);     //Defining armadillos eigenvalues
    t1 = clock();
    double t_arma = (double (t1 - t0))/CLOCKS_PER_SEC;

    //Timing jacobi's eigenvalue solver
    t0 = clock();
    vec eigvals = Jacobi_method(A,N);   //Defining jacobi's eigenvalues
    t1 = clock();
    double t_jacobi = (double (t1 - t0))/CLOCKS_PER_SEC;

    eigvals = sort(eigvals);                                  //Sorting eigenvalues from Jacobi's method
    int eigval;
    vec arma_eigenvalues(4); vec jacobi_eigenvalues(4);       //Declaring vectors for the four first elements

    for (eigval = 0 ; eigval < 4; eigval++){                  //Filling the vectors with the eigenvalues
      arma_eigenvalues(eigval) = arma_eigvals(eigval);
      jacobi_eigenvalues(eigval) = eigvals(eigval);
    }

    //Printing to console
    consoleout(N, arma_eigenvalues, jacobi_eigenvalues, t_arma, t_jacobi);

    //Writing N as X-value and average error to Y-value for python plotting with plotter.py
    ofile << N << " " << averageError(jacobi_eigenvalues) << " " << t_jacobi << endl;

  }

  ofile.close();

  //Calling python for plotting
  system("python3 plotter.py N-VS-Error");

  return 0;
}

double averageError(vec jacobi_eigenvalues) { //Calculates the average of the error for the first four eigenvalues.
  vec correctAnswer = {3.0, 7.0, 11.0, 15.0};
  vec diff = abs(correctAnswer-jacobi_eigenvalues);
  double avgDiff = accu(diff) / diff.n_elem;
  return avgDiff;
}



void consoleout(int N, vec arma_eigenvalues, vec jacobi_eigenvalues, double t_arma, double t_jacobi) {
  //Printing to console
  cout << "Integration points, N: " << N << endl;
  cout << "Eigenvalues from arma solver: " << endl;
  cout << arma_eigenvalues << endl;
  cout << "Time spent on arma solver: " << t_arma << "s" << endl;
  cout << "-----------------------------------" << endl;
  cout << "Eigenvalues from our Jacobi solver: " << endl;
  cout << jacobi_eigenvalues << endl;
  cout << "Time spent on our solver: " << t_jacobi << "s" << endl;
  cout << "===================================" << endl;
}
