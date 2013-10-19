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
#define N 200000
int p[N][2];
int cmp(const void * a,const void * b)
{
  int *c=(int*)a, *d=(int*)b;
  if(*c==*d)
    return *(c+1)-*(d+1);
  return *c-*d;
}
int vis[N+1];
int fa[N+1][3];
typedef long long ll;
int gfa(int i)
{
  if(fa[i][0]!=i)
    fa[i][0]=gfa(fa[i][0]);
  return fa[i][0];
}
int joi(int a,int b)
{
  a=gfa(a);
  b=gfa(b);
  if(a!=b)
    {
      fa[a][0]=b,fa[b][1]+=fa[a][1],fa[b][2]+=fa[a][2];
      return 1;
    }
  return 0;
}
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  map<int,int> mapx,mapy;
  for(int i=0;i<n;++i)
    {
      scanf("%d%d",*(p+i),*(p+i)+1);
      mapx[p[i][0]]=1,mapy[p[i][1]]=1;
    }
  map<int,int>::iterator ite;
  ite=mapx.begin();
  for(int i=1;ite!=mapx.end();++ite)
    ite->second=i++;
  ite=mapy.begin();
  for(int i=1;ite!=mapy.end();++ite)
    ite->second=i++;
  for(int i=0;i<n;++i)
    p[i][0]=mapx[p[i][0]],p[i][1]=mapy[p[i][1]];
  qsort(p,n,sizeof(p[0]),cmp);
  //for(int i=0;i<n;++i)<<p[i][0]<<' '<<p[i][1]<<endl;
  for(int i=1;i<=n;++i)
    fa[i][0]=i,fa[i][1]=0,fa[i][2]=1;
  ll ans=(ll)n;
  for(int i=0;i<n;)
    {
      int j=i+1;
      int c=gfa(p[i][1]);
      ll col=fa[c][1],lev=fa[c][2];
      ll sum=col*lev;
      for(;j<n && p[i][0]==p[j][0];++j)
	{
	  int k=gfa(p[j][1]);
	  ll t1=fa[k][1],t2=fa[k][2];
	  if(joi(c,k))
	    col+=t1,lev+=t2,sum+=(t1*t2);
	}
      //cout<<'!'<<col<<' '<<lev<<' '<<sum<<endl;
      c=gfa(c);
      ans+=( col*lev - sum + (ll)(fa[c][2]-(j-i)));
      ++fa[c][1];
      i=j;
      //cout<<ans<<endl;
    }
  cout<<ans;
  return 0;
}
