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
typedef long long ll;
typedef pair<int,int> ppi;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
unsigned long long dp[20][10];
unsigned long long po[20];
int callen(unsigned long long v)
{
  int r(0);
  for(;v;++r)
    v/=10;
  return r;
}
unsigned long long cal(unsigned long long v,int len,int lst)
{
  if(len<1)
    return 1;
  unsigned long long tmp=v;
  tmp/=po[len-1];
  tmp%=10;
  unsigned long long r(0);
  for(int i=0;i<tmp;++i)
    if(i!=3 || lst!=1)
      r+=dp[len][i];
  if(lst!=1 || tmp!=3)
    r+=cal(v,len-1,tmp);
  return r;
}
int main()
{
  freopen("in","r",stdin);
  int t;
  scanf("%d",&t);
  po[0]=1;
  for(int i=1;i<20;++i)
    po[i]=10*po[i-1];
  dp[0][0]=1;
  for(int i=1;i<20;++i)
    {
      for(int k=0;k<10;++k)
	dp[i][0]+=dp[i-1][k];
      for(int k=1;k<10;++k)
	dp[i][k]=dp[i][0];
      dp[i][1]-=dp[i-1][3];
    }
  for(;t--;)
    {
      unsigned long long n;
      cin>>n;
      unsigned long long ans=0;
      for(unsigned long long f=1,t=((unsigned long long)1)<<63,mid;f<=t;)
	{
	  mid=(f+t)>>1;
	  if(cal(mid,callen(mid),0)-1>=n)
	    ans=mid,t=mid-1;
	  else f=mid+1;
	}
      cout<<ans<<endl;
    }
  return 0;
}
