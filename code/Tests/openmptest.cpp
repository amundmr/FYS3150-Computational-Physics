//  OpenMP program to compute vector norm by adding two other vectors
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>
#include  <omp.h>
#include <ctime>
#include <chrono>

using namespace std; // note use of namespace
int main (int argc, char* argv[])
{
  // read in dimension of vector
  int n = atoi(argv[1]);
  double *a, *b, *c;
  int i;
  int thread_num;
  double wtime, Norm2, s, angle;
  cout << "  Perform addition of two vectors and compute the norm-2." << endl;
  /*omp_set_num_threads(4);
  thread_num = omp_get_max_threads ();
  cout << "  The number of processors available = " << omp_get_num_procs () << endl ;
  cout << "  The number of threads available    = " << thread_num <<  endl;
  cout << "  The matrix order n                 = " << n << endl;
*/
  s = 1.0/sqrt( (double) n);
  //wtime = omp_get_wtime ( );
  // Allocate space for the vectors to be used
  a = new double [n]; b = new double [n]; c = new double [n];
  // Define parallel region
  auto t1 = std::chrono::high_resolution_clock::now();






# pragma omp parallel for default(shared) private (angle, i) reduction(+:Norm2)
  // Set up values for vectors  a and b
  for (i = 0; i < n; i++){
      angle = 2.0*M_PI*i/ (( double ) n);
      a[i] = s*(sin(angle) + cos(angle));
      b[i] =  s*sin(2.0*angle);
      c[i] = 0.0;
  }
  // Then perform the vector addition
  for (i = 0; i < n; i++){
     c[i] += a[i]+b[i];
  }
  // Compute now the norm-2
  Norm2 = 0.0;
  for (i = 0; i < n; i++){
     Norm2  += c[i]*c[i];
  }
// end parallel region
auto t2 = std::chrono::high_resolution_clock::now();
auto duration = std::chrono::duration_cast<std::chrono::microseconds>( t2 - t1 ).count();
  //wtime = omp_get_wtime ( ) - wtime;
  cout << "time spent: " << duration << endl;
  cout << setiosflags(ios::showpoint | ios::uppercase);
  cout << setprecision(10) << setw(20) << "Time used  for norm-2 computation=" << wtime  << endl;
  cout << " Norm-2  = " << Norm2 << endl;
  // Free up space
  delete[] a;
  delete[] b;
  delete[] c;
  return 0;
}
