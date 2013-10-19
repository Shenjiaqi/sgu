#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
using namespace std;
typedef long long ll;
#define N 2000
#define M 2000
#define K 200000
int sc[M+1];
int cc[K+1][2],ci;
int pp[K+1][3];
int fa[N+1];
bool usd[K+1];
void add(int a,int b,int c,int p)
{
  ++ci,cc[ci][0]=ci,cc[ci][1]=sc[c],sc[c]=ci;
  pp[ci][0]=p,pp[ci][1]=a,pp[ci][2]=b;
}
int gfa(int v)
{
  return fa[v]==v?v:fa[v]=gfa(fa[v]);
}
void join(int a,int b)
{
  a=gfa(a);
  b=gfa(b);
  if(a!=b)
    fa[a]=b;
}
int main()
{
  freopen("in","r",stdin);
  int n,m,k;
  scanf("%d%d%d",&n,&m,&k);
  typedef pair<int,int> pa;
  multimap<pa,int> mapp;
  for(int i=0;i<k;++i)
    {
      int a,b,c,p;
      scanf("%d%d%d%d",&a,&b,&c,&p);
      add(a,b,c,p);
      mapp.insert(make_pair(pa(p,ci),ci));
    }
  for(int i=1;i<=n;++i)
    fa[i]=i;
  multimap<pa,int>::iterator ite,ite2;
  ite=mapp.begin();
  for(int i=1;i<n;)
    {
      int v=ite->second;
      if(gfa(pp[v][1])!=gfa(pp[v][2]))
	{
	  join(pp[v][1],pp[v][2]);
	  usd[v]=true;
	  ++i;
	  ++ite;
	}
      else
	{
	  ite2=ite++;
	  mapp.erase(ite2);
	}
    }
  if(ite!=mapp.end())
    mapp.erase(ite,mapp.end());
  int minv=2e9,mini;
  for(int i=1;i<=m;++i)
    {
      for(int j=1;j<=n;++j)
	fa[j]=j;
      int cn(0);
      for(int j=sc[i];j;j=cc[j][1])
	{
	  int v=cc[j][0];
	  if(usd[v])
	      mapp.erase(pa(pp[v][0],v));
	  if(gfa(pp[v][1])!=gfa(pp[v][2]))
	    {
	      join(pp[v][1],pp[v][2]);
	      ++cn;
	    }
	}
      ite=mapp.begin();
      int now=0;
      for(;now<minv && cn<n-1;++ite)
	{
	  int v=ite->second;
	  if(gfa(pp[v][1])!=gfa(pp[v][2]))
	    {
	      join(pp[v][1],pp[v][2]);
	      now+=(ite->first).first;
	      ++cn;
	    }
	}
      if(now<minv)
	minv=now,mini=i;
      for(int j=sc[i];j;j=cc[j][1])
	{
	  int t=cc[j][0];
	  if(usd[t])
	    mapp.insert(make_pair(pa(pp[t][0],t),t));
	}
    }
  printf("%d %d ",minv,mini);
  for(int i=1;i<=n;++i)
    fa[i]=i;
  int cnt(0);
  for(int i=sc[mini];i;i=cc[i][1])
    {
      int t=cc[i][0];
      if(usd[t])
	mapp.erase(pa(pp[t][0],t));
      if(gfa(pp[t][1])!=gfa(pp[t][2]))
	{
	  join(pp[t][1],pp[t][2]);
	  ++cnt;
	}
    }
  ite=mapp.begin();
  vector<int> o;
  for(;cnt<n-1;++ite)
    {
      int t=ite->second;
      if(gfa(pp[t][1])!=gfa(pp[t][2]))
	{
	  ++cnt;
	  o.push_back(t);
	  join(pp[t][1],pp[t][2]);
	}
    }
  cout<<o.size()<<endl;
  for(int i=0;i<o.size();++i)
    printf("%d ",o[i]);
  return 0;
}
