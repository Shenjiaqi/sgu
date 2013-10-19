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
typedef pair<int,int> pp;
vector<pp> p;
vector<int> xx,yy;
int n,m,k;
bool chk(vector<int> &v,int lim)
{
  if(v.size()<2)
    return true;
  for(int i=1;i<v.size();++i)
    if(((v[i]-v[i-1])&1)==0)
      return false;
  int a=0,b=v.size()-1;
  if(v[a]==1)
    for(++a;a<=b && v[a]-1==v[a-1];++a)
      ;
  if(v[b]==lim)
    for(--b;a<=b && v[b]+1==v[b+1];--b)
      ;
  vector<int> z;
  for(;a<=b;)
    {
      int cnt(1);
      for(++a;a<=b && v[a]==v[a-1]+1;++a)
	++cnt;
      if(cnt>1 && (cnt&1))
	return false;
      z.push_back(cnt);
      if(a<=b)
	{
	  if(((v[a]-v[a-1])&1)==0)
	    return false;
	  z.push_back(v[a]-v[a-1]);
	}
    }
  for(int i=0;i<z.size();i+=2)
    if(z[i]==1)
      {
	for(;;)
	  {
	    int j=i+2;
	    for(;j<z.size() && z[j]!=1;j+=2)
	      ;
	    if(j>=z.size())
	      break;
	    for(int k=i+1,l=j-1;k<l;++k,--l)
	      if(z[k]!=z[l])
		return false;
	    i=j;
	  }
	break;
      }
  return true;
}
bool check(vector<int> &v)
{
  int s1=v.size();
  int s2=p.size();
  if(s2==0)
    return true;
  if(s2%s1)
    return false;
  for(int i=0;i<s2;)
    for(int j=0;j<s1;++j,++i)
      if( (j && p[i].first!=p[i-1].first) || p[i].second!=v[j])
	return false;
  return true;
}
void cal()
{
  for(int i=0;i<k;++i)
    {
      int x,y;
      scanf("%d%d",&x,&y);
      p.push_back(pp(x,y));
      xx.push_back(x);
      yy.push_back(y);
    }
  sort(xx.begin(),xx.end());
  xx.resize(unique(xx.begin(),xx.end())-xx.begin());
  if(chk(xx,m))
    {
      sort(yy.begin(),yy.end());
      yy.resize(unique(yy.begin(),yy.end())-yy.begin());
      if(chk(yy,n))
	{
	  sort(p.begin(),p.end());
	  if(check(yy))
	    {
	      for(int i=0;i<p.size();++i)
		swap(p[i].first,p[i].second);
	      sort(p.begin(),p.end());
	      if(check(xx))
		{
		  printf("YES");
		  return ;
		}
	    }
	}
    }
  printf("NO");
}
int main()
{
  freopen("in","r",stdin);
  for(;EOF!=scanf("%d%d%d",&n,&m,&k);)
    {
      p.resize(0);
      xx.resize(0);
      yy.resize(0);
      cal();
      cout<<endl;
    }
  return 0;
}
