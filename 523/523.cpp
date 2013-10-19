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
  int n,m;
  cin>>n>>m;
  int floor[101]={0};
  int p[100];
  for(int i=0;i<n;++i)
    {
      cin>>p[i];
      floor[p[i]]=1;
    }
  for(int i=0;;)
    {
      for(;i<n && floor[p[i]]==0;++i)
	;
      if(i>=n)
	break;
      int dir=(m<p[i]?1:-1);
      for(int j=m;;j+=dir)
	if(floor[j])
	  {
	    cout<<j<<' ';
	    floor[j]=0;
	    if(j==p[i])
	      break;
	  }
      m=p[i];
    }
  return 0;
}
