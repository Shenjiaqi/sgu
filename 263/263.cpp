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
#define N 1000000
int p[N+1];
int q[N+1];
int m[N+1];
void add(int a[],int pos,int num)
{
  for(;pos<=N;pos+=(pos&(-pos)))
    a[pos]+=num;
}
void put(int x,int c)
{
  add(m,x,c);
  if(q[x]==0)
    {
      if( (x==0 || q[x-1]==0) && (x==N || q[x+1]==0))
	add(p,x,1);
      else if((x==0 || q[x-1]==0) && x<N && q[x+1])
	{
	  add(p,x,1);
	  add(p,x+1,-1);
	}
      else if(x<N && q[x+1] && x && q[x-1])
	add(p,x+1,-1);
    }
  q[x]+=c;
}
int que(int a[],int pos)
{
  int r(0);
  for(;pos;pos^=(pos&(-pos)))
    r+=a[pos];
  return r;
}
int getpos(int c,bool beg)
{
  int f=1,t=N;
  int r=0;
  for(;f<=t;)
    {
      int mid=(f+t)>>1;
      int tmp=que(p,mid);
      if(tmp==c)
	{
	  if(beg)
	    t=mid-1,r=mid;
	  else if(q[mid])
	    f=mid+1,r=mid;
	  else t=mid-1;
	}
      else if(tmp<c)
	f=mid+1;
      else t=mid-1;
    }
  return r;
}
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  for(;n--;)
    {
      char cmd[10];
      scanf("%s",cmd);
      if(cmd[0]=='p')
	{
	  int x,c;
	  scanf("%d%d",&x,&c);
	  put(x,c);
	}
      else if(cmd[0]=='t')
	{
	  if(cmd[1]=='p')
	    {
	      int t,x,c;
	      scanf("%d%d%d",&t,&x,&c);
	      put(getpos(t,true)+x-1,c);
	    }
	  else if(cmd[1]=='o')
	    {
	      printf("%d towers\n",que(p,N));
	    }
	  else // tcubes
	    {
	      int t,x;
	      scanf("%d%d",&t,&x);
	      printf("%d cubes in %dth column of %dth tower\n",q[x-1+getpos(t,true)],
		     x,t);
	    }
	}
      else if(cmd[0]=='c')
	{
	  int t;
	  scanf("%d",&t);
	  printf("%d cubes in %dth tower\n",que(m,getpos(t,false))-que(m,getpos(t,true)-1),t);
	}
      else if(cmd[0]=='l')
	{
	  int t;
	  scanf("%d",&t);
	  printf("length of %dth tower is %d\n",t,(getpos(t,false)-getpos(t,true)+1));
	}
    }
  return 0;
}
