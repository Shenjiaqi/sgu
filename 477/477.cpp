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
typedef pair<int,int> ppi;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define N 5000
#define M 5000
int p[N],q[M];
void cal(vector<ppi> &a,int *b,int s,int dis)
{
  a.resize(0);
  for(int i=0;i<s;)
    {
      int tmp=b[i]-dis;
      for(++i;i<s && b[i]-b[i-1]<=dis*2;++i)
	;
      a.push_back(ppi(tmp,b[i-1]+dis));
    }
}
bool check(vector<ppi> &a,vector<ppi> &b,int dis)
{
  for(int i=0,j=0;i<a.size() && j<b.size();)
    if(a[i].second<=b[j].first)
      ++i;
    else if(a[i].first>=b[j].second)
      ++j;
    else
      {
	if(min(a[i].second,b[j].second)
	   -max(a[i].first,b[j].first)>dis)
	  return false;
	if(a[i].second>b[j].second)
	  ++j;
	else ++i;
      }
      
  return true;
}
int main()
{
  freopen("in","r",stdin);
  int n,m,d;
  scanf("%d%d%d",&n,&m,&d);
  vector<int> pp,qq;
  FOR(i,0,n)
    {
      scanf("%d",p+i);
      if(i)
	pp.push_back((p[i]-p[i-1]+1)>>1);
    }
  pp.push_back(1);
  sort(pp.begin(),pp.end());
  pp.resize(unique(pp.begin(),pp.end())-pp.begin());
  FOR(i,0,m)
    {
      scanf("%d",q+i);
      if(i)
	qq.push_back((q[i]-q[i-1]+1)>>1);
    }
  qq.push_back(1);
  sort(qq.begin(),qq.end());
  qq.resize(unique(qq.begin(),qq.end())-qq.begin());
  int ans=1e9,ai,bi;
  vector<ppi> ppp;
  vector<ppi> qqq;
  cal(qqq,q,m,qq[(int)qq.size()-1]);
  for(int i=0,j=qq.size()-1;i<pp.size() && j>=0;++i)
    {
      cal(ppp,p,n,pp[i]);
      for(;ppp.size()+qqq.size()<ans;)
	{
	  if(check(ppp,qqq,d))
	    {
	      ans=ppp.size()+qqq.size();
	      ai=pp[i],bi=qq[j];
	      break;
	    }
	  --j;
	  if(j>=0)
	    cal(qqq,q,m,qq[j]);
	  else break;
	}
    }
  if(ans<1e9)
    printf("%d %d",ai,bi);
  else printf("No solution");
  return 0;
}
