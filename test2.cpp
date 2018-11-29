#include <iostream>
#include <vector>

using namespace std;


int main(int argc, char ** argv) {

  int nx = atoi(argv[1]);
  int ny = atoi(argv[2]);
  int nz = atoi(argv[3]);
  int c = 0;


  if ( true ) 
    {

      vector<vector<double> > v1(ny);
      for (int i=0; i<ny; i++)
	v1[i].resize(nx);
      
      for (int z = 0 ; z < nz ; z++ ) 
	{
	  
	  for (int i=0; i<ny; i++)
	    {
	      double s = 0;
	      for (int j=0; j<nx; j++)
		{
		  s += v1[i][j];
		  c++;
		}
	    }
	}
      
    }



  
  if ( false )
    {
      vector<vector<double> * > v2(ny);
      for (int i=0; i<ny; i++)
	{
	  vector<double> * t = new vector<double>;
	  t->resize(nx);
	  v2[i] = t;
	}
      
       for (int z = 0 ; z < nz ; z++ ) 
	{
	  
	  for (int i=0; i<ny; i++)
	    {
	      double s = 0;
	      for (int j=0; j<nx; j++)
		{
		  //vector<double> * t = v2[i];
		  s += (*v2[i])[j];
		  c++;
		}
	    }
	}
    }






  if ( false )
    {
      vector<vector<double> * > v2(ny);
      for (int i=0; i<ny; i++)
	{
	  vector<double> * t = new vector<double>;
	  t->resize(nx);
	  v2[i] = t;
	}
      

      for (int z = 0 ; z < nz ; z++ ) 
	{
	  
	  vector< vector<double> * >::iterator i1 = v2.begin();
	  while ( i1 != v2.end() ) 
	    {

	      vector<double>::iterator i2 = (*i1)->begin();

	      double s = 0;
	      while ( i2 != (*i1)->end() )
		{		  
		  s += *i2;
		  i2++;
		  c++;
		}

	      i1++;
	    }

	}
    }

  cout << "c = " << c << "\n";

  exit(0);
}
