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
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define N 50
#define M 500
int p[2*M+1][3],poi;
int s[N+1];
int esti[N+1][2];
int ans;
ll r1,r2;
int mm;
int n,m;
void add(int f,int t,int c)
{
  ++poi,p[poi][0]=t,p[poi][1]=s[f],s[f]=poi,p[poi][2]=c;
}
bool dfs(int mid,int i,int lim,int val,int est)
{
  if(val+est>lim)
    return false;
  if(i>n)
    {
      if(((r2|(1LL<<mid))>>1)==((1LL<<n)-1))
	return false;
      return true;
    }
  if(i==mid)
    return dfs(mid,i+1,lim,val,est);
  if(r2==0)
    {
      r2|=(1LL<<i);
      for(int j=s[i];j;j=p[j][1])
	{
	  int t=p[j][0];
	  if(t!=mid)
	    esti[t][1]+=p[j][2];
	}
      return dfs(mid,i+1,lim,val,est);
    }
  r2|=(1LL<<i);
  //int cut(0);
  int tmp=est;
  for(int j=s[i];j;j=p[j][1])
    {
      int t=p[j][0];
      if(t!=mid)
	{
	  /*if(t<i)
	    {
	      if((r2&(1LL<<t))==0)
		cut+=p[j][2];
	    }
	  else*/
	  if(t>i)
	    {
	      if(esti[t][0]>esti[t][1])
		{
		  if(esti[t][0]<esti[t][1]+p[j][2])
		    est+=(esti[t][0]-esti[t][1]);
		  else est+=p[j][2];
		}
	      esti[t][1]+=p[j][2];
	    }
	}
    }
  if(dfs(mid,i+1,lim,val+esti[i][0]/*cut*/,est-min(esti[i][0],esti[i][1])))
    return true;
  r2^=(1LL<<i);
  //cut=0;
  for(int j=s[i];j;j=p[j][1])
    {
      int t=p[j][0];
      if(t!=mid)
	{
	  /*if(t<i)
	    {
	      if(r2&(1LL<<t))
		cut+=p[j][2];
	  else}*/
	  if(t>i)
	    {
	      esti[t][1]-=p[j][2];
	      if(esti[t][0]<esti[t][1])
		{
		  if(esti[t][0]+p[j][2]>esti[t][1])
		    tmp+=(esti[t][1]-esti[t][0]);
		  else tmp+=p[j][2];
		}
	      esti[t][0]+=p[j][2];
	    }
	}
    }
  if(dfs(mid,i+1,lim,val+esti[i][1]/*cut*/,tmp-min(esti[i][0],esti[i][1])))
    return true;
  for(int j=s[i];j;j=p[j][1])
    {
      int t=p[j][0];
      if(t>i && t!=mid)
	esti[t][0]-=p[j][2];
    }
  return false;
}
void pt()
{
  cout<<ans<<endl;
  vector<int> road;
  for(int i=1;i<=n;++i)
    if(i!=mm)
      for(int j=s[i];j;j=p[j][1])
	{
	  int t=p[j][0];
	  if(t>i && t!=mm)
	    {
	      bool a=r1&(1LL<<i);
	      bool b=r1&(1LL<<t);
	      if(a!=b)
		road.push_back((j+1)>>1);
	    }
	}
  cout<<road.size()<<endl;
  for(int i=0;i<road.size();++i)
    cout<<road[i]<<' ';
}
int main()
{
  freopen("in","r",stdin);
  scanf("%d%d",&n,&m);
  for(int i=0,f,t,c;i<m;++i)
    {
      scanf("%d%d%d",&f,&t,&c);
      add(f,t,c);
      add(t,f,c);
    }
  ans=M*11;
  for(int i=1;i<=n;++i)
    for(int j=1;j<=n;++j)
      if(i!=j)
	{
	  int sum(0);
	  for(int k=s[j];sum<ans && k;k=p[k][1])
	    if(p[k][0]!=i)
	      sum+=p[k][2];
	  if(sum<ans)
	    {
	      ans=sum;
	      r1=1LL<<j;
	      mm=i;
	    }
	}
  for(int i=1;i<=n;++i)
    {
      for(int a=0,b=ans-1;a<=b;)
	{
	  int mid=(a+b)>>1;
	  r2=0;
	  memset(esti,0,sizeof(esti));
	  if(dfs(i,1,mid,0,0))
	    b=mid-1,ans=mid,r1=r2,mm=i;
	  else a=mid+1;
	}
    }
  pt();
  return 0;
}
