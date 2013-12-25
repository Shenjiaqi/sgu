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
typedef pair<ld,ld> ppld;
#define PB push_back
#define FIR first
#define SEC second
#define MP make_pair
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
int n,m,k;
vector<ppi> p;
vector<int> a,b;
bool check1()
{
  sort(p.begin(),p.end());
  int j=0;
  for(;j<p.size() && p[j].FIR==p[0].FIR;++j)
    a.PB(p[j].SEC);
  if(p.size()>0)
    b.PB(p[0].FIR);
  for(int k=j;k<p.size();)
    {
      int c=p[k].FIR;
      b.PB(c);
      for(int l=0;l<j;++l,++k)
	if(k>=p.size() || p[k].FIR!=c || p[k].SEC!=p[l].SEC)
	  return false;
    }
  return true;
}
bool check3(vector<int> &c,int w)
{
  int i=c.size()-1;
  bool e=false;
  if(i>=0 && (c[i]==w || c[i]==1))
    e=true;
  for(;i>=0;)
    {
      int j=i;
      for(--i;i>=0 && abs(c[i]-c[i+1])==1;--i)
	;
      int num=j-i;
      if((num&1))
	{
	  if(num>1)
	    {
	      if(!e)
		return false;
	    }
	}
      c.resize(i+2);
      if(i<0)
	return true;
      if((abs(c[i]-c[i+1])&1)==0)
	return false;
      e=false;
      c.resize(i+1);
    }
  return true;
}
bool check2(vector<int> &c,int w)
{
  if(!check3(c,w))
    {
      reverse(c.begin(),c.end());
      return check3(c,w);
    }
  return true;
}
int main()
{
  int n,m,k;
  scanf("%d%d%d",&n,&m,&k);
  p.resize(k);
  FOR(i,0,k)
    scanf("%d%d",&p[i].FIR,&p[i].SEC);
  if(check1())
    if(check2(a,m) && check2(b,n))
      {
	printf("YES");
	return 0;
      }
  printf("NO");
  return 0;
}
