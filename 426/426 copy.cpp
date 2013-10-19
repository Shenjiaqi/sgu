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
#define N 50000
#define M 50000
int n,m,k;
int a[N];
int b[2][M];
int c[N];
vector< pair<int,int> > d;
int add;
int ans[M];
int r[16][N];
bool equ(int f1,int f2,int l)
{
  for(int i=0;(1<<i)<=l;++i)
    if((1<<i)&l)
      {
	if(r[i][f1]!=r[i][f2])
	  return false;
	f1=(f1+(1<<i))%n;
	f2=(f2+(1<<i))%n;
      }
  return true;
}
bool cmp(int v1,int v2)
{
  int len=1;
  ite=mapp.find(min(v1,v2)*(N+1)+max(v1,v2));
  if(ite==mapp.end())
    {
      for(int f=1,l=n;f<=l;)
	{
	  int mid=(f+l)>>1;
	  if(equ(v1,v2,mid))
	    len=mid,f=mid+1;
	  else l=mid-1;
	}
      mapp.in
    }
  return ( ((a[(v1+len)%n]+add)%m) < ((a[(v2+len)%n]+add)%m) );
}
int main()
{
  freopen("in","r",stdin);
  scanf("%d%d%d",&n,&m,&k);
  for(int i=0;i<n;++i)
    scanf("%d",a+i);
  for(int i=0;i<n;++i)
    ++c[a[i]];
  for(int i=1;i<M;++i)
    c[i]+=c[i-1];
  for(int i=n-1;i>=0;--i)
    b[0][--c[a[i]]]=i;
  for(int i=0,j=0;i<n;++i)
    {
      if(i && a[b[0][i]]!=a[b[0][i-1]])
	++j;
      r[0][b[0][i]]=j;
    }
  for(int i=1;(1<<i)<=n;++i)
    {
      memset(c,0,sizeof(c));
      for(int j=0;j<n;++j)
	++c[r[i-1][j]];
      for(int j=1;j<M;++j)
	{
	  c[j]+=c[j-1];
	  if(c[j]==n)
	    break;
	}
      int f=1-(i&1);
      int t=1-f;
      for(int j=n-1;j>=0;--j)
	{
	  int z=(b[f][j]-(1<<(i-1))+n)%n;
	  b[t][--c[r[i-1][z]]]=z;
	}
      for(int j=0,k=0;j<n;++j)
	{
	  if(j && (r[i-1][b[t][j]]!=r[i-1][b[t][j-1]] ||
		   r[i-1][(b[t][j]+(1<<(i-1)))%n]!=r[i-1][(b[t][j-1]+(1<<(i-1)))%n]) )
	    ++k;
	  r[i][b[t][j]]=k;
	}
    }
  for(int i=0;i<n;++i)
    d.push_back(make_pair(a[i],i));
  sort(d.begin(),d.end());
  --k;
  for(int i=n-1;i>=0;)
    {
      vector<int> t;
      for(int j=d[i].first;i>=0 && j==d[i].first;--i)
	t.push_back(d[i].second);
      if(i>=0)
	{
	  add=m-d[i+1].first;
	  sort(t.begin(),t.end(),cmp);
	  for(int j=m-d[i+1].first;j<m-d[i].first;++j)
	    ans[j]=(a[(t[0]+k)%n]+j)%m;
	}
      else
	{
	  add=0;
	  sort(t.begin(),t.end(),cmp);
	  for(int j=0;j<m-d[n-1].first;++j)
	    ans[j]=(a[(t[0]+k)%n]+j)%m;
	  add=m-d[0].first;
	  //sort(t.begin(),t.end(),cmp);
	  for(int j=m-d[0].first;j<m;++j)
	    ans[j]=(a[(t[0]+k)%n]+j)%m;
	}
    }
  for(int i=0;i<m;++i)
    printf("%d\n",ans[i]);
  return 0;
}
