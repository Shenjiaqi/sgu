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
#define C 1000
#define K 1000
#define PER 17
int q[C][K];
ll p[C][(K+1)/PER+3];
ll tmp[(K+1)/PER+3];
const ll mod=1LL<<(PER*3);
int c,k;
int z[C];
vector<int> ans;
vector<pair<int,pair<int,int> > > aans;
bool cmp(int a,int b)
{
  for(int i=k/PER;i>=0;--i)
    if(p[a][i]!=p[b][i])
      return p[a][i]>p[b][i];
  return a>b;
}
void sub(vector<ll> &a,ll v)
{
  if(a[0]<v)
    {
      a[0]=mod+a[0]-v;
      int i=1;
      for(;a[i]==0;++i)
	a[i]=mod-1;
      --a[i];
    }
  else a[0]-=v;
  for(int i=a.size()-1;i>0 && a[i]==0;--i)
    a.pop_back();
}
void shift(vector<ll> &a,int s)
{
  int i=0;
  for(;i<a.size();++i)
    a[i]<<=s;
  --i;
  if(a[i]>=mod)
    {
      a.push_back(a[i]/mod);
      a[i]%=mod;
    }
}
void pt()
{
  vector<ll> lft;
  lft.push_back(8);
  for(int i=k-1;i>=0 && (lft.size()>1 || lft[0]);--i)
    {
      for(int j=0;j<ans.size() && (lft.size()>1 || lft[0]);++j)
	{
	  int t=ans[j];
	  if(q[t][i])
	    {
	      int zz=q[t][i];
	      if(lft.size()==1 && lft[0]<=zz)
		zz=lft[0];
	      aans.push_back(make_pair(t+1,make_pair(i,zz)));
	      sub(lft,zz);
	    }
	}
      shift(lft,3);
    }
  printf("%d",(int)aans.size());
  for(int i=0;i<aans.size();++i)
    printf("\n%d %d %d",aans[i].first,aans[i].second.first,aans[i].second.second);
}
int main()
{
  freopen("in","r",stdin);
  scanf("%d%d",&c,&k);
  const ll lim=1LL<<((k%PER)*3);
  FOR(i,0,c)
    {
      FOR(j,0,k)
	{
	  scanf("%d",*(q+i)+j);
	  p[i][j/PER]+=((ll)q[i][j])<<((j%PER)*3);
	  if(p[i][j/PER]>=mod)
	    p[i][j/PER+1]+=p[i][j/PER]/mod,p[i][j/PER]%=mod;
	}
      z[i]=i;
      if(p[i][k/PER]>=lim || p[i][k/PER+1])
	{
	  ans.push_back(i);
	  pt();
	  return 0;
	}
    }
  sort(z,z+c,cmp);
  for(int i=0;i<c && (tmp[k/PER]<lim && tmp[k/PER+1]==0);++i)
    {
      int t=z[i];
      for(int j=0;j<=k/PER;++j)
	{
	  tmp[j]+=p[t][j];
	  if(tmp[j]>=mod)
	    tmp[j+1]+=tmp[j]/mod,tmp[j]%=mod;
	}
      ans.push_back(t);
    }
  if(tmp[k/PER]<lim && 0==tmp[k/PER+1])
    printf("NO SOLUTION");
  else pt();
  return 0;
}
