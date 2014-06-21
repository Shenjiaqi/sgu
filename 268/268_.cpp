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
#define K 27
int n;
char s1[K],s2[K],t[K];
char s['Z'+1];
int ans;
inline int add(int v)
{
  return (v+1)%n;
}
inline int su(int v)
{
  return (v-1+n)%n;
}
bool check(char *x)
{
  for(int i=x[0],j=0;j<n;++j,add(i))
    if(x[j]!=i)
      return false;
  return true;
}
bool dfs(int idx,char *x,int msk,int left)
{
  for(int i=idx;;i=add(i))
    {
      cout<<s2[x[i]]<<' ';
      if(i==(idx+n-1)%n)
	{
	  cout<<endl;
	  break;
	}
    }
  if(left-(n-x[idx])%n<0)
    return false;
  char pos[K];
  FOR(i,0,n)
    pos[x[i]]=i;
  FOR(i,0,n)
    if(0==(msk&(1<<x[i])) && add(i)!=idx)
      {
	int a=pos[su(x[i])];
	int b=pos[add(x[i])];
	int aa=(a-i+n)%n;
	int bb=(b-i+n)%n;
	if(aa>bb && (left-((n-x[add(i)])%n))>=0)
	  {
	    bool c=false;
	    for(int j=add(i);!c && j!=b;j=add(j))
	      c=msk&(1<<x[j]);
	    for(int j=su(i);!c && j!=a;j=su(j))
	      c=msk&(1<<x[j]);
	    if(!c)
	      {
		cout<<"!"<<endl;
		char tmp=x[i];
		for(int j=i;j!=(idx+n-1)%n;add(j))
		  x[j]=x[add(j)];
		x[(idx+n-1)%n]=tmp;
		if(check(x))
		  return true;
		if(dfs(i,x,msk|(1<<x[i])|(1<<su(x[i]))|(1<<add(x[i])),left-(((i+1-idx+n)%n))))
		  return true;;
		for(int j=(idx+n-1)%n;j!=i;j=su(j))
		  x[j]=x[su(j)];
		x[i]=tmp;
	      }
	  }
      }
  return false;
}
int main()
{
  scanf("%d%s%s",&n,s1,s2);
  FOR(i,0,n)
    s[s2[i]]=i;
  FOR(i,0,n)
    t[i]=s[s1[i]];
  ans=1e9;
  for(int f=0,to=n*n;f<=to;)
    {
      int m=(f+to)>>1;
      if(dfs(0,t,0,m))
	{
	  ans=m;
	  to=m-1;
	}
      else f=m+1;
    }
  FOR(i,0,n)
    cout<<s2[t[i]]<<' ';cout<<endl;
  cout<<ans<<endl;
  return 0;
}
