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
typedef pair<ll,ll> ppl;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 50000
vector<map<int,int> > mapp;
int ans[N+1];
vector<int> p[N+1];
int val[N+1];
const int inf=~(1<<31);
int mg(int a,int b)
{
  map<int,int> &c=mapp[a],&d=mapp[b];
  int r=inf;
  for(map<int,int>::iterator i=d.begin(),j;i!=d.end();)
    {
      int val=i->first;
      if(c.find(val)==c.end())
	{
	  c[val]=1;
	  j=c.find(val);
	  if(j!=c.begin())
	    {
	      --j;
	      r=min(val-j->first,r);
	      ++j;
	    }
	  ++j;
	  if(j!=c.end())
	    r=min(j->first-val,r);
	}
      else r=0;
      j=i++;
      d.erase(j);
    }
  return r;
}
int dfs(int v)
{
  ans[v]=inf;
  if(p[v].size()==0)
    {
      int r=mapp.size();
      mapp.resize(r+1);
      mapp[r][val[v]]=1;
      return r;
    }
  vector<int> c;
  FR(i,p[v])
    {
      c.push_back(dfs(*i));
      ans[v]=min(ans[v],ans[*i]);
    }
  int ii=c[0];
  FOR(i,1,c.size())
    if(mapp[c[i]].size()>mapp[ii].size())
      ii=c[i];
  FR(i,c)
    if(*i!=ii)
      ans[v]=min(ans[v],mg(ii,*i));
  return ii;
}
int main()
{
  freopen("in","r",stdin);
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=2,j;i<=n;++i)
    {
      scanf("%d",&j);
      p[j].push_back(i);
    }
  for(int i=n-m+1;i<=n;++i)
    {
      scanf("%d",val+i);
    }
  dfs(1);
  for(int i=1;i<=n-m;++i)
    printf("%d ",ans[i]);
  return 0;
}
