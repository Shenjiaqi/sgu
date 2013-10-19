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
ll ans;
int p[10];
ll cc[17];
vector<int> li,ri;
ll cal(vector<int> &b,int s,ll bound,ll aa,bool equ)
{
  int n=b.size();
  if(s<n)
    {
      if(p[0])
	return (aa-aa*(ll)p[0]/(ll)s);
      return aa;
    }
  else if(s>n)
    return 0;
  ll r(0);
  ll zz=aa;
  int ii=n;
  for(int i=n-1;i>=0 && r<=bound;--i)
    {
      for(int j=(i==n-1?1:0);j<b[i] && r<=bound;++j)
	if(p[j])
	  r+=(zz*p[j]/(i+1));
      if(p[b[i]]>0)
	{
	  zz=zz*(ll)p[b[i]]/(ll)(i+1);
	  --p[b[ii=i]];
	  if(i==0 && equ)
	    ++r;
	}
      else break;
    }
  for(;ii<n;++ii)
    ++p[b[ii]];
  return r;
}
void dfs(int v,int left,int all,ll aa)
{
  if(left>0)
    {
      int a,b;
      a=(v==0?left-1:left);
      b=(v==9?left:0);
      for(int i=a;i>=b;--i)
	{
	  p[v]=i;
	  dfs(v+1,left-i,all,aa/cc[i]);
	  p[v]=0;
	}
    }
  else
    {
      ll tmp=cal(li,all,(ll)(1e15+7),aa,false);
      ll tmp2=cal(ri,all,tmp+2,aa,true);
      if(tmp2-tmp==2)
	++ans;
    }
}
int main()
{
  //freopen("in","r",stdin);
  ll l,r;
  cin>>l>>r;
  cc[0]=1;
  for(int i=1;i<17;++i)
    cc[i]=cc[i-1]*(ll)i;
  for(ll i=l;i;i/=(ll)10)
    li.push_back(i%(ll)10);
  for(ll i=r;i;i/=(ll)10)
    ri.push_back(i%(ll)10);
  for(int i=li.size();i<=ri.size();++i)
    dfs(0,i,i,cc[i]);
  cout<<(ans<<1);
  return 0;
}
