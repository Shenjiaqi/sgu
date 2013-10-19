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
#define R 2000
#define A 2000
int a[N];
int b[N];
int main()
{
  freopen("in","r",stdin);
  int n,r;
  scanf("%d%d",&n,&r);
  for(int i=0;i<n;++i)
    scanf("%d",a+i);
  int ans(0);
  for(int f=0,t=n*A+1;f<=t;)
    {
      int m=(f+t)>>1;
      memcpy(b,a,sizeof(b));
      int nn2,nn3;
      nn2=nn3=0;
      int p[40][2]={0},pi=0;
      if(r&1)
	{
	  int c=m;
	  for(int i=0;i<n && c;++i)
	    if(b[i]&1)
	      --c,b[i]-=3;
	  for(int i=0;i<n && c>1;++i)
	    for(;b[i]>=6 && c>1;)
	      c-=2,b[i]-=6;
	  if(m-c)
	    p[pi][0]=r-3,p[pi][1]=m-c,++pi;
	  if(c)
	    p[pi][0]=r,p[pi][1]=c,++pi;
	}
      else p[pi][0]=r,p[pi][1]=m,++pi;
      for(int i=0;i<n;++i)
	{
	  if(b[i]&1)
	    {
	      ++nn3;
	      b[i]-=3;
	    }
	  nn2+=b[i]/2;
	}
      for(int j=0,k=pi;k>j && nn3>1;++j)
	if(p[j][0]>=6)
	  {
	    int tmp=p[j][0]/6;
	    int ntmp=nn3/(2*tmp);
	    if(ntmp>0)
	      {
		nn3-=ntmp*2*tmp;
		p[pi][0]=p[j][0]-6*tmp;
		p[pi][1]=ntmp;
		p[j][1]-=ntmp;
		++pi;
	      }
	    if(nn3>1 && p[j][1]>0)
	      {
		ntmp=min(p[j][0]/6,nn3/2);
		nn3-=ntmp*2;
		p[pi][0]=p[j][0]-ntmp*6;
		p[j][1]-=1;
		p[pi][1]=1;
		++pi;
	      }
	  }
      for(int j=0,k=pi;k>j && nn3;++j)
	{
	  if(p[j][0]>=3 && p[j][1]>0)
	    {
	      int tmp=min(p[j][1],nn3);
	      nn3-=tmp;
	      p[j][1]-=tmp;
	      p[pi][0]=p[j][0]-3;
	      p[pi][1]=tmp;
	      ++pi;
	    }
	}
      if(nn3<=0)
	for(int j=0;j<pi && nn2>0;++j)
	  nn2-=p[j][1]*(p[j][0]/2);
      if(nn3<=0 && nn2<=0)
	ans=m,t=m-1;
      else f=m+1;
    }
  printf("%d",ans);
  return 0;
}
