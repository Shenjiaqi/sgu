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
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
typedef pair<double,double> ppd;
#define PB push_back
#define MP make_pair
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 100007
int pos[N],poi;
vector<ppi> p[N*2];
vector<int> v[N];
vector<ppi> c;
int res[N],resi;
int n,m,q;
int dfs(int v)
{
  int r=N;
  FR(i,p[v])
    {
      if(i->SEC>=0)
	i->FIR=dfs(i->SEC);
      r=min(r,i->FIR);
    }
  sort(p[v].begin(),p[v].end());
  return r;
}
void fi(int v)
{
  FR(i,p[v])
    {
      if(i->SEC>=0)
	fi(i->SEC);
      else
	{
	  res[++resi]=i->FIR;
	}
    }
}
int main()
{
  scanf("%d%d%d",&n,&m,&q);
  FOR(i,0,m)
    {
      int a,b;
      scanf("%d%d",&a,&b);
      c.PB(MP(a,i));
      FOR(j,0,b)
	{
	  int d;
	  scanf("%d",&d);
	  v[i].PB(d);
	}
    }
  sort(c.begin(),c.end());
  FR(i,c)
    {
      int j=i->SEC;
      int id=0;
      FR(k,v[j])
	{
	  if(pos[*k]>0)
	    {
	      id=pos[*k];
	      break;
	    }
	}
      if(id==0)
	{
	  id=++poi;
	  p[0].PB(MP(n,id));
	}
      FR(k,v[j])
	{
	  pos[*k]=++poi;
	  p[id].PB(MP(n,poi));
	}
    }
  queue<int> left;
  FOR(i,1,n+1)
    {
      p[pos[i]].PB(MP(i,-1));
    }
  dfs(0);
  fi(0);
  FOR(i,0,q)
    {
      int a;
      scanf("%d",&a);
      printf("%d\n",res[a]);
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
  return 0;
}
