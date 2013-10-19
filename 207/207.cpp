#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <string.h>
#include <stdlib.h>
#include <functional>
using namespace std;
typedef long long ll;
int main()
{
  freopen("in","r",stdin);
  int n,m,y;
  cin>>n>>m>>y;
  double q[1000];
  for(int i=0,j;i<n;++i)
    {
      cin>>j;
      q[i]=(double)j*(double)m/(double)y;
    }
  for(int i=0;i<n;++i)
    m-=(int)q[i];
  for(int i=0;i<m;++i)
    {
      double dt=-1;
      int j=0;
      for(int k=0;k<n;++k)
	if(dt<(q[k]-(int)q[k]))
	  {
	    dt=q[k]-(int)q[k];
	    j=k;
	  }
      q[j]=1.0+(int)q[j];
    }
  for(int i=0;i<n;++i)
    cout<<(int)q[i]<<' ';
  return 0;
}
