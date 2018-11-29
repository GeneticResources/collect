#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

extern "C" int dgesdd_(char *jobz, int *m, int *n, double *a, 
		       int *lda, double *s, double *u, int *ldu, 
		       double *vt, int *ldvt, double *work, int *lwork, 
		       int *iwork, int *info);

int main() {
  

  time_t start,end;
  int m, n, i, j, lwork, iwork;

  double *work;
  char JOBZ[1];
  static int INFO;
  double dif;

  m=n=10;


  vector<double> u(m*m);
  vector<double> v(n*n);
  vector<double> s(m);
  vector<double> mat(n*m);
  
  double * pU = &u[0];
  double * pV = &v[0];
  double * pS = &s[0];
  double * pM = &mat[0];
  
  JOBZ[0]='S';
  
  // Copy over matrix into 1D vector form

  int pos = 0;
  for (i=0;i<m;i++)
    for (j=i;j<n;j++)
      mat[pos++] = a[i][j];
  

  // Determine amount of storage space needed

  lwork=-1;
  iwork=(8*m);
  work = (double*) malloc(2*sizeof(double));
  
  
  /* Subroutine  int dgesdd_(char *jobz, integer *m, integer *n, doublereal *
     a, integer *lda, doublereal *s, doublereal *u, integer *ldu, 
     doublereal *vt, integer *ldvt, doublereal *work, integer *lwork, 
     integer *iwork, integer *info)
  */
  
  dgesdd_(JOBZ, &m, &n, pMat, &m, pS, pU, &m, pV, &n, work, &lwork, &iwork, &INFO);
  
  // Return code INFO (should be 0, int)
  // lwork size = work[0];
  
  lwork= (int) work[0];
  work = (double*) malloc(lwork*sizeof(double));
  
  //   vector<double> work(lwork);
  //   double * pWork = &work[0];

  dgesdd_(JOBZ, &m, &n, pMat, &m, pS, pU, &m, pV, &n, work, &lwork, &iwork, &INFO);

  if ( INFO < 0 ) 
    error("Invalid argument in LAPACK DGESDD\n");
  else if ( INFO > 0 )
    error("LAPACK DGESDD failed to converge\n");
  
  
  for (i=0;i<m;i++)
    {
      cout << s[i] << "\n";
      cout << "\n";
    }
  
   

  free(work);
  
}



