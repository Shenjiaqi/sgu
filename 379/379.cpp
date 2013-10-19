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
#include <string.h>
#include <stdlib.h>
#include <functional>
using namespace std;
typedef long long ll;
int flor[100];
int fr[101];
int can(int num,ll limit,int capacity,int time)
{
  int l=0;
  memset(fr,0,sizeof(fr));
  for(;fr[l]<num;)
    {
      ++l;
      fr[l]=fr[l-1]+flor[l-1];
    }
  for(;num>0 ;--l)
      if(num>fr[l-1])
	{
	  int tmp=(min(num-fr[l-1],fr[l]-fr[l-1])+capacity-1)/capacity;
	  limit-=((ll)tmp*(ll)2*(ll)l*(ll)time);
	  if(limit<0)
	    return 0;
	  num-=tmp*capacity;
	  for(int i=tmp*capacity,j=l;j>0 && i>0;--j)
	    {
	      int tt=min(fr[j]-fr[j-1],i);
	      i-=tt,fr[j]-=tt;
	    }
	}
  return 1;
}
int main()
{
  freopen("in","r",stdin);
  int n,c,p,t;
  cin>>n>>c>>p>>t;
  int sum=0;
  for(int i=0;i<n;++i)
    {
      cin>>flor[i];
      sum+=flor[i];
    }
  int ans=0;
  for(int f=0,l=sum;f<=l;)
    {
      int m=(f+l)>>1;
      if(can(m,t,c,p))
	ans=m,f=m+1;
      else l=m-1;
    }
  cout<<ans;
  return 0;
}
