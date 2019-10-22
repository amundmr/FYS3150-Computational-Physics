#include "./include/gqlib.h"

#define EPS 3.0e-14
#define MAXIT 10
#define ZERO 1.0E-10

//   Main function beginning
int main()
{

  int N = 15; //odd in order to find the roots
  double a = -5.0, b = 5.0;
  double alf = 0.0;


  double *x = new double [N];          //Mesh points for brute force Legandre
  double *w = new double [N];          //Weights Legandre
  double *xgl = new double [N+1];      //mesh points [0,inf] from Laguerre
  double *wgl = new double [N+1];      //Weights Laguerre
  double *t   = new double [N];        //mesh points theta angle [0,pi]
  double *p   = new double [N];        //mesh points phi angle [0,2pi]
  double *wg_t   = new double [N];     //weight theta
  double *wg_p   = new double [N];     //weight phi

  double exact = 5*M_PI*M_PI/(16.0*16.0);

  // These arrays are used for improved Gauss-Legendre, mapping of
  // x \in [-1,1] to x \in [0, infinity)

  // set up the mesh points and weights

  gauleg(a, b, x, w, N); //Legandre
  gauss_laguerre(xgl,wgl, N, alf); //Laguerre
  gauleg(0,M_PI,t,wg_t,N); //Laguerre
  gauleg(0,2*M_PI, p,wg_p, N); //Laguerre

  //Legandre-loop:
  double int_gauss = 0.;
  for (int i = 0; i<N;i++){
  for (int j = 0;j<N;j++){
  for (int k = 0;k<N;k++){
  for (int l = 0;l<N;l++){
  for (int m = 0;m<N;m++){
  for (int n = 0;n<N;n++){

    int_gauss += w[i]*w[j]*w[k]*w[l]*w[m]*w[n]
    *int_function(x[i],x[j],x[k],x[l],x[m],x[n]);

  }}}}}} //end Legandre


  //Gauss-Laguerre method
  double int_gausslag = 0.;
  for (int i = 1;i<=N;i++){
  for (int j = 1;j<=N;j++){
  for (int k = 0;k < N;k++){
  for (int l = 0;l < N;l++){
  for (int m = 0;m < N;m++){
  for (int n = 0;n < N;n++){

    int_gausslag += wgl[i]*wgl[j]*wg_t[k]*wg_t[l]*wg_p[m]*wg_p[n]
    *func_polar_laguerre(xgl[i],xgl[j],t[k],t[l],p[m],p[n]);

  }}}}}} //end Laguerre

  //  final output
  cout  << setiosflags(ios::showpoint | ios::uppercase);
  cout << "Gaussian-Legendre quad = "<< setw(20) << setprecision(15)  << int_gauss <<"  Absolutt error  " <<fabs(int_gauss-exact)<< endl;
  cout << "Gaussian-Laguerre quad = "<< setw(20) << setprecision(15)  <<  int_gausslag <<"  Absolutt error  " <<fabs(int_gausslag -exact)<< endl;

  delete [] x;
  delete [] w;
  delete [] xgl;
  delete [] wgl;
}  // end of main program



//Integrand function in polar coordinates for Gaussian Laguerre
double func_polar_laguerre(double r1,double r2, double t1, double t2,  double p1, double p2){

  double cosb = cos(t1)*cos(t2) + sin(t1)*sin(t2)*cos(p1-p2);
  double deno = r1*r1+r2*r2-2*r1*r2*cosb;
  double f = exp(-3*(r1+r2))*r1*r1*r2*r2*sin(t1)*sin(t2)/sqrt(deno);

  if(deno > ZERO)
    return f;
  else
    return 0;
} // end of function func_polar_laguerre

/*
** The function
**              gauleg()
** takes the lower and upper limits of integration x1, x2, calculates
** and return the abcissas in x[0,...,n - 1] and the weights in w[0,...,n - 1]
** of length n of the Gauss--Legendre n--point quadrature formulae.
*/

void gauss_laguerre(double *x, double *w, int n, double alf)
{
	int i,its,j;
	double ai;
	double p1,p2,p3,pp,z,z1;

	for (i=1;i<=n;i++) {
		if (i == 1) {
			z=(1.0+alf)*(3.0+0.92*alf)/(1.0+2.4*n+1.8*alf);
		} else if (i == 2) {
			z += (15.0+6.25*alf)/(1.0+0.9*alf+2.5*n);
		} else {
			ai=i-2;
			z += ((1.0+2.55*ai)/(1.9*ai)+1.26*ai*alf/
				(1.0+3.5*ai))*(z-x[i-2])/(1.0+0.3*alf);
		}
  for (its=1;its<=MAXIT;its++) {
    p1=1.0;
    p2=0.0;
    for (j=1;j<=n;j++) {
      p3=p2;
      p2=p1;
      p1=((2*j-1+alf-z)*p2-(j-1+alf)*p3)/j;
    }
    pp=(n*p1-(n+alf)*p2)/z;
    z1=z;
    z=z1-p1/pp;
    if (fabs(z-z1) <= EPS) break;
  }
  if (its > MAXIT) cout << "too many iterations in gaulag" << endl;
  x[i]=z;
  w[i] = -exp(gammln(alf+n)-gammln((double)n))/(pp*n*p2);
	}
}
// end function gaulag

double gammln( double xx)
{
	double x,y,tmp,ser;
	static double cof[6]={76.18009172947146,-86.50532032941677,
		24.01409824083091,-1.231739572450155,
		0.1208650973866179e-2,-0.5395239384953e-5};
	int j;

	y=x=xx;
	tmp=x+5.5;
	tmp -= (x+0.5)*log(tmp);
	ser=1.000000000190015;
	for (j=0;j<=5;j++) ser += cof[j]/++y;
	return -tmp+log(2.5066282746310005*ser/x);
}

// end function gammln
//#undef EPS
//#undef MAXIT
