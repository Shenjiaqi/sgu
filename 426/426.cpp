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
#define N 50005
#define M 50005
int a[N];
int r[17][N];
int b[N];
int tmp[N];
int c[M+1];
vector<pair<int,int> > d;
int ans[M];
int add;
int n,m,kk;
bool eq(int f1,int f2,int l)
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
bool cmp(int aa,int bb)
{
  int an=1;
  for(int f=1,l=n;f<=l;)
    {
      int mid=(f+l)>>1;
      if(eq(aa,bb,mid))
	an=mid,f=mid+1;
      else l=mid-1;
    }
  return (((a[(aa+an)%n]+add)%m)<((a[(bb+an)%n]+add)%m));
}
int main()
{
  freopen("in","r",stdin);
  //freopen("out","w",stdout);
  scanf("%d%d%d",&n,&m,&kk);
  for(int i=0;i<n;++i)
    scanf("%d",a+i);
  for(int i=0;i<n;++i)
    ++c[a[i]];
  for(int i=1;i<M;++i)
    c[i]+=c[i-1];
  for(int i=n-1;i>=0;--i)
    b[--c[a[i]]]=i;
  for(int i=0,j=0;i<n;++i)
    {
      if(i && a[b[i]]!=a[b[i-1]])
	++j;
      r[0][b[i]]=j;
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
      for(int j=n-1;j>=0;--j)
	{
	  int z=(b[j]-(1<<(i-1))+n)%n;
	  tmp[--c[r[i-1][z]]]=z;
	}
      memcpy(b,tmp,sizeof(b));
      for(int j=0,k=0;j<n;++j)
	{
	  if(j && r[i-1][(b[j]+(1<<(i-1)))%n]!=r[i-1][(b[j-1]+(1<<(i-1)))%n])
	    ++k;
	  r[i][b[j]]=k;
	}
    }
  for(int i=0;i<n;++i)
    d.push_back(make_pair(a[i],i));
  sort(d.begin(),d.end(),greater< pair<int,int> >());
  --kk;
  for(int i=0;i<n;)
    {
      vector<int> tt;
      tt.push_back(d[i].second);
      for(++i;i<n && d[i].first==d[i-1].first;++i)
	tt.push_back(d[i].second);
      if(i<n)
	{
	  int bb=m-d[i-1].first;
	  int ee=m-d[i].first;
	  add=bb;
	  sort(tt.begin(),tt.end(),cmp);
	  for(int k=bb;k<ee;++k)
	    ans[k]=(a[(tt[0]+kk)%n]+k)%m;
	}
      else
	{
	  int bb=0;
	  int ee=m-d[0].first;
	  if(bb<ee)
	    {
	      add=0;
	      sort(tt.begin(),tt.end(),cmp);
	      for(int k=bb;k<ee;++k)
		ans[k]=(a[(tt[0]+kk)%n]+k)%m;
	    }
	  bb=m-d[i-1].first;
	  ee=m;
	  if(bb<ee)
	    {
	      add=bb;
	      sort(tt.begin(),tt.end(),cmp);
	      for(int k=bb;k<ee;++k)
		ans[k]=(a[(tt[0]+kk)%n]+k)%m;
	    }
	  break;
	}
    }
  for(int i=0;i<m;++i)
    printf("%d\n",ans[i]);
  return 0;
}

