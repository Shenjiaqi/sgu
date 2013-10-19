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
#define N 50001
int n;
ll l;
ll a[2][N][2];
int pos[N][2];
ll p[N*7][3];
int poi;
ll s[N];
int gp(double v,ll ar[][2],int f,int t)
{
  for(;f<=t;)
    {
      int m=(f+t)>>1;
      if(v>=ar[m][0])
	f=m+1;
      else t=m-1;
    }
  return f;
}
int cmpll(const void *c,const void *d)
{
  ll *cc=(ll*)c,*dd=(ll*)d;
  return *cc-*dd;
}
ll md(ll a,ll b)
{
  ll tmp=llabs(a-b);
  return min(l-tmp,tmp);
}
void add(int time,int po,ll val)
{
  p[poi][0]=time,p[poi][1]=po,p[poi][2]=md(a[0][po][0],val)-md(a[0][(po-1+n)%n][0],val);
  ++poi;
}
int main()
{
  freopen("in","r",stdin);
  cin>>n>>l;
  for(int i=0;i<2;++i)
    {
      for(int j=0;j<n;++j)
      {
	cin>>a[i][j][0];
	//scanf("%I64d",&a[i][j][0]);
	--a[i][j][0];
	a[i][j][1]=j+1;
      }
      qsort(a[i],n,sizeof(a[0][0]),cmpll);
    }
  for(int i=0;i<n;++i)
    {
      pos[i][0]=gp(a[1][i][0],a[0],0,n-1)%n;
      double tmp=a[1][i][0]+l/(double)2.0;
      while(tmp>=l)
	tmp-=l;
      pos[i][1]=gp(tmp,a[0],0,n-1)%n;
    }
  for(int i=0;i<n;++i)
    for(int j=0;j<2;++j)
      {
	int k=(pos[i][j]-i+n)%n;
	//if(i==2 && j==1)
	//cout<<k<<"!"<<endl;
	if(k>1)
	  add(k,pos[i][j],a[1][i][0]);
	k=(k+1)%n;
	int o=(pos[i][j]+1)%n;
	int z=(1+(pos[(i+1)%n][j]))%n;
	for(;o!=z && o!=p[i][j^1];k=(k+1)%n,o=(o+1)%n)
	  if(k>1)
	    add(k,o,a[1][i][0]);
      }
  ll det(0);
  ll now(0);
  for(int i=0;i<n;++i)
    {
      now+=md(a[0][i][0],a[1][i][0]);
      //cout<<i<<' '<<md(a[0][i][0],a[1][(i-1+n)%n][0])<<' '<<md(a[0][(i-1+n)%n][0],a[1][(i-1+n)%n][0])<<endl;
      det+=(s[i]=(md(a[0][i][0],a[1][(i-1+n)%n][0])-md(a[0][(i-1+n)%n][0],a[1][(i-1+n)%n][0])));
    }
  qsort(p,poi,sizeof(p[0]),cmpll);
  ll minv;
  int minp;
  minv=now,minp=0;
  /*for(int i=0;i<poi;++i)
    cout<<p[i][0]<<' '<<p[i][1]<<' '<<p[i][2]<<endl;*/
  //for(int i=0;i<n;++i)
  //cout<<s[i]<<' ';
  //cout<<endl<<det<<endl;
  for(int i=1,j=0;i<n;++i)
    {
      //cout<<'!'<<now<<endl;
      for(;j<poi && p[j][0]<=i;++j)
	{
	  int po=p[j][1];
	  ll va=p[j][2];
	  if(s[po]!=va)
	    det+=(va-s[po]),s[po]=va;
	}
      now+=det;
      //cout<<"i "<<i<<endl;
      /*int ss(0);
      for(int k=0;k<n;++k)
	{
	  cout<<s[k]<<' ';
	  ss+=s[k];}*/
      //cout<<"det "<<det<<' '<<"ss "<<ss<<endl;
      if(now<minv)
	minv=now,minp=i;
    }
  //cout<<'!'<<now<<endl;
  ll mss=((ll)1)<<62;
  int mssi=0;
  for(int i=0;i<n;++i)
    {
      ll sum(0);
      for(int j=0;j<n;++j)
	{
	  sum+=md(a[0][j][0],a[1][(j-i+n)%n][0]);
	  //cout<<md(a[0][j][0],a[1][(j-i+n)%n][0])<<' ';
	}
      //cout<<endl;
      //cout<<"!!"<<sum<<endl;
      if(mss>sum)
	mss=sum,mssi=i;
      }
  if(mss!=minv || mssi!=minp)
    return 1;
  //cout<<mss<<endl;
  cout<<minv<<endl;
  for(int i=0;i<n;++i)
    cout<<a[1][(i-minp+n)%n][1]<<' ';
  //printf("%d ",a[0][i][1]);
  //cout<<poi<<'!'<<'!'<<endl;
  return 0;
}
