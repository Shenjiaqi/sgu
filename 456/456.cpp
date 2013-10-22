#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;
typedef long long ll;
int main()
{
  freopen("in.txt","r",stdin);
  double s,p;
  int m;
  cin>>s>>m>>p;
  p/=100.0;
  double x;
  for(double f=0,t=1e9;t-f>1e-7;)
    {
      double n=(f+t)/(double)2.0;
      double r=s;
      for(int i=0;i<m && r>0 ;++i)
	{
	  double z=r*p;
	  if(n>z)
	    r-=(n-z);
	  else break;
	}
      if(r<=1e-5)
	x=t=n;
      else f=n;
    }
  printf("%.5lf",x);
  return 0;
}
