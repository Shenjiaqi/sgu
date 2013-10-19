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
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define N 100000
#define M 100000
#define Q 200000
map<int,int> mapp[N+1];
map<int,int> mapp2[N+1];
int fa[N+Q+1][3],fai;
int gfa(int v)
{
  return fa[v][1]==v?v:fa[v][1]=gfa(fa[v][1]);
}
void joi(int a,int b)
{
  a=gfa(a);
  b=gfa(b);
  if(a!=b)
    {
      ++fai;
      if(mapp2[fa[a][0]].size()>mapp2[fa[b][0]].size())
	swap(a,b);
      for(map<int,int>::iterator ite=mapp2[fa[a][0]].begin(),ite2;ite!=mapp2[fa[a][0]].end();)
	{
	  int tmp=gfa(ite->first);
	  mapp2[fa[b][0]][tmp]=1;
	  ite2=ite++;
	  mapp2[fa[a][0]].erase(ite2);
	  mapp[fa[tmp][2]].erase(fa[a][0]);
	  mapp[fa[tmp][2]][fa[b][0]]=1;
	}
      fa[fai][0]=fa[b][0];
      if(mapp[fa[a][2]].size()>mapp[fa[b][2]].size())
	swap(a,b);
      fa[a][1]=fa[b][1]=fai;
      fa[fai][1]=fai;
      fa[fai][2]=fa[b][2];
      for(map<int,int>::iterator ite=mapp[fa[a][2]].begin(),ite2;ite!=mapp[fa[a][2]].end();)
	{
	  mapp[fa[b][2]][ite->first]=1;
	  ite2=ite++;
	  mapp[fa[a][2]].erase(ite2);
	}
    }
}
int main()
{
  freopen("in","r",stdin);
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;++i)
    fa[i][0]=fa[i][1]=fa[i][2]=i;
  fai=n;
  for(int i=0,a,b;i<m;++i)
    {
      scanf("%d%d",&a,&b);
      mapp[a][b]=1;
      mapp2[b][a]=1;
    }
  int q;
  scanf("%d",&q);
  for(int i=0,t,a,b;i<q;++i)
    {
      scanf("%d%d%d",&t,&a,&b);
      if(t==1)
	{
	  int tmp=fa[gfa(a)][2];
	  printf("%s\n",mapp[tmp].find(fa[b][0])!=mapp[tmp].end()?"YES":"NO");
	}
      else
	joi(a,b);
    }
  return 0;
}
