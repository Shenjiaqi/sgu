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
#include <cctype>
using namespace std;
typedef long long ll;
typedef pair<int,int> ppi;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 100
#define M 100
queue<ppi> p[M];
int q[N][2];
int ans[N][2];
int main()
{
  freopen("in","r",stdin);
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=0;i<n;++i)
    scanf("%d%d",*(q+i),*(q+i)+1);
  for(int t=0,c=0;;)
    {
      int mv=1e9;
      for(int i=0;i<m;++i)
	if(p[i].size()>0 && p[i].front().first<mv)
	  mv=p[i].front().first;
      if(mv==1e9 && c>=n)
	break;
      if(mv<1e9 && (c>=n || mv<=q[c][0]-t))
	{
	  t+=mv;
	  for(int i=0;i<m;++i)
	    if(p[i].size()>0 && p[i].front().first==mv)
	      {
		ans[p[i].front().second][1]=t;
		p[i].pop();
	      }
	    else if(p[i].size()>0)
	      p[i].front().first-=mv;
	}
      else
	{
	  int z=0;
	  for(int i=0;i<m;++i)
	    {
	      if(p[i].size()>0)
		p[i].front().first-=(q[c][0]-t);
	      if(p[i].size()<p[z].size())
		z=i;
	    }
	  t=q[c][0];
	  for(;c<n && t==q[c][0];++c)
	    {
	      p[z].push(ppi(q[c][1],c));
	      ans[c][0]=z+1;
	    }
	}
    }
  for(int i=0;i<n;++i)
    printf("%d %d\n",ans[i][0],ans[i][1]);
  return 0;
}
