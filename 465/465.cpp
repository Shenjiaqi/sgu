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
typedef pair<int,int> ppi;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define N 100
#define M (N*N)
int p[N];
int path[N][N];
int q[M][3];
// int cal(int l1,int l2,int l,int d)
// {
//   int r=(l2+l-l1)>>1;
//   return (r>=d && r<=l-d)?r:-1;
// }
int main()
{
  freopen("in","r",stdin);
  int n,m,r;
  scanf("%d%d%d",&n,&m,&r);
  FOR(i,0,n)
    scanf("%d",p+i);
  if(n==1 && r==0)
    {
      cout<<0<<endl;
      return 0;
    }
  //r<<=1;
  memset(path,1<<6,sizeof(path));
  FOR(i,0,m)
    {
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      --a,--b;
      //c<<=1;
      path[a][b]=path[b][a]=c;
      q[i][0]=a,q[i][1]=b,q[i][2]=c;
    }
  FOR(i,0,n)
    path[i][i]=0;
  for(int j=0;j<n;++j)
    for(int i=0;i<n;++i)
      if(i!=j && path[i][j]<1e8)
	for(int k=0;k<n;++k)
	  if(j!=k && i!=k && path[j][k]<1e8)
	    path[i][k]=min(path[i][k],path[i][j]+path[j][k]);
  for(int i=0;i<n;++i)
    for(int j=1+i;j<n;++j)
      if(path[i][j]>=1e8)
	{
	  cout<<-1;
	  return 0;
	}
  ll ans=1e17+1;
#define L 20001
  //vector<int> dd[L];
  for(int i=0;i<m;++i)
    {
      int a=q[i][0],b=q[i][1],c=q[i][2];
      if(c>=2*r)
	{
	  ll t1,t2;
	  t1=t2=0;
	  for(int j=0;j<n;++j)
	    t1+=(ll)p[j]*(ll)(min(path[j][a]+r,path[j][b]+c-r)),
	      t2+=(ll)p[j]*(ll)(min(path[j][b]+r,path[j][a]+c-r));
	  ans=min(ans,min(t1,t2));
	  // vector<int> cc;
	  // int wa;
	  // wa=0;
	  // cc.push_back(r);
	  // cc.push_back(c-r);
	  // ll la(0);
	  // for(int j=0;j<n;++j)
	  //   {
	  //     la+=(ll)p[j]*(ll)min(path[j][a]+r,path[j][b]+c-r);
	  //     int tmp=cal(path[j][a],path[j][b],c,r);
	  //     if(tmp>=0)
	  // 	{
	  // 	  if(tmp>20000)
	  // 	    return 0;
	  // 	  cc.push_back(tmp),dd[tmp].push_back(j),wa+=p[j];
	  // 	}
	  //     else if(path[j][a]<=path[j][b])
	  // 	wa+=p[j];
	  //     else wa-=p[j];
	  //   }
	  // ans=min(ans,la);
	  // sort(cc.begin(),cc.end());
	  // cc.resize(unique(cc.begin(),cc.end())-cc.begin());
	  // for(int i=0;i<cc.size();++i)
	  //   {
	  //     if(i)
	  // 	la+=(ll)(wa)*(ll)(cc[i]-cc[i-1]);
	  //     for(int j=0;j<dd[cc[i]].size();++j)
	  // 	{
	  // 	  int tmp=dd[cc[i]][j];
	  // 	  wa-=p[tmp]*2;
	  // 	}
	  //     dd[cc[i]].resize(0);
	  //     ans=min(ans,la);
	  //   }
	}
    }
  if(ans<1e17)
    printf("%.5lf",(double)ans/(double)1e4);
  else cout<<-1;
  return 0;
}
