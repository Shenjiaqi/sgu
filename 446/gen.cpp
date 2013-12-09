#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <functional>
#include <cctype>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
typedef pair<double,double> ppd;
#define PB push_back
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
vector<ppd> p;
map<ppi,int> mapp;
int main()
{
  int n=1000;
  double xx,yy;
  xx=yy=0;
  FOR(i,0,n)
    {
      for(;;)
	{
	  int x=rand()%100;
	  int y=rand()%100;
	  if(mapp.find(ppi(x,y))==mapp.end())
	    {
	      p.PB(ppd(xx+=(double)x,yy+=(double)y));
	      mapp[ppi(x,y)]=1;
	      break;
	    }
	}
    }
  xx/=n,yy/=n;
  cout<<n<<endl;
  FR(i,p)
    cout<<i->FIR<<' '<<i->SEC<<endl;
  double ang=acos(0.1);//(double)((rand()%100)+1)/101.00;
  FR(i,p)
    {
      double x=cos(ang)*(i->FIR-xx)-(i->SEC-yy)*sin(ang);
      double y=sin(ang)*(i->FIR-xx)+cos(ang)*(i->SEC-yy);
      printf("%.16lf %.16lf\n",x,y);
    }
  cout<<ang<<endl;
  return 0;
}
