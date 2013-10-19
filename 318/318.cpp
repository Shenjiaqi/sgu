#include <algorithm>
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
using namespace std;
typedef long long ll;
#define N 100
#define M 100
bool p[N+1];
int q[N+1];
vector< vector<int> > g;
int main()
{
  freopen("in","r",stdin);
  int n,m;
  scanf("%d%d",&n,&m);
  g.resize(g.size()+1);
  for(int i=1;i<=n;++i)
    g[0].push_back(i);
  for(int i=0;i<m;++i)
    {
      int j;
      scanf("%d",&j);
      memset(p,0,sizeof(p));
      for(;j--;)
	{
	  int k;
	  scanf("%d",&k);
	  p[k]=1;
	  ++q[k];
	}
      j=0;
      for(int k=g.size();j<k;++j)
	{
	  vector<int> a,b;
	  for(int l=0;l<g[j].size();++l)
	    if(p[g[j][l]])
	      a.push_back(g[j][l]);
	    else b.push_back(g[j][l]);
	  if(a.size()>0 && b.size()>0)
	    g[j]=a,g.push_back(b);
	}
    }
  int sub=0;
  for(int i=0,j;i<g.size();++i)
    {
      for(j=0;j<g[i].size();++j)
	if(q[g[i][j]])
	  break;
      if(j>=g[i].size())
	++sub;
    }
  printf("%d",(int)g.size()-sub);
  return 0;
}
