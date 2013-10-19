#include <cstdio>
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
#include <string.h>
#include <stdlib.h>
#include <functional>
using namespace std;
typedef long long ll;
bool chk(int f,int t,int p[])
{
  if(f==t)
    return true;
  if(f+1==t)
    return p[f]!=p[t];
  if(f+2==t)
    return (p[f]==p[f+1] || p[f+1]==p[f+2] || p[f]!=p[f+2]);
  else if(f+3==t)
    {
      if(p[f+1]==p[t-1])
	return p[f]!=p[t];
      if(!(p[f]==p[f+1] || p[f+1]==p[f+2] || p[f]!=p[f+2]) || 
	 !(p[t]==p[t-1] || p[t-1]==p[t-2] || p[t]!=p[t-2]))
	return true;
      return ((p[f]-(p[f+2]<=p[f]?1:0)) ^ (p[t]-(p[t-2]<=p[t]?1:0)));
    }
  return false;
}
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  int p[5];
  for(int i=0;i<n;++i)
    scanf("%d",p+i);
  bool ans;
  if(n<=4)
    ans=chk(0,n-1,p);
  else
    {
      int n1=chk(0,3,p);
      int n2=chk(1,4,p);
      if(n1==0 || n2==0)
	ans=true;
      else
	{
	  int tmp=p[0];
	  for(int i=1;i<tmp;++i)
	    {
	      p[0]=i;
	      n1+=(int)chk(0,3,p);
	    }
	  p[0]=tmp;
	  tmp=p[4];
	  for(int i=1;i<tmp;++i)
	    {
	      p[4]=i;
	      n2+=(int)chk(1,4,p);
	    }
	  p[4]=tmp;
	  ans=n1^n2;
	}
    }
  printf("%s",(ans?"FEDOR":"SERGEY"));
  return 0;
}
