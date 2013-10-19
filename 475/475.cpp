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
#define N 10
#define M 1000
int msk;
int w[N],t[N],s[N];
int c[M],D[M],d[M];
int ww[1<<N],tt[1<<N],ss[1<<N];
ll tim[2][1<<N];
void dfs(int v)
{
  if(v==0 || ww[v])
    return ;
  int tmp=v^(v&(-v));
  dfs(tmp);
  int z=__builtin_ctz(v&(-v));
  ww[v]=ww[tmp]+w[z];
  tt[v]=max(tt[tmp],t[z]);
  ss[v]=ss[tmp]+s[z];
}
inline ll cal(int riv,int frm,int to)
{
  return (ll)ss[frm^to]+(ll)max(tt[msk^to],(ww[to]>c[riv]?D[riv]:d[riv]));
}
int main()
{
  freopen("in","r",stdin);
  int n,m;
  scanf("%d%d",&n,&m);
  FOR(i,0,n)
    scanf("%d%d%d",w+i,t+i,s+i);
  FOR(i,0,m)
    scanf("%d%d%d",c+i,D+i,d+i);
  msk=(1<<n)-1;
  FOR(i,1,msk+1)
    dfs(i);
  FOR(i,1,msk+1)
    tim[0][i]=ss[i];
  for(int i=0;i<m;++i)
    {
      int frm=i&1;
      int to=1^frm;
      memset(&tim[to],0,sizeof(tim[to]));
      for(int j=1;j<=msk;++j)
	for(int k=1;k<=msk;++k)
	  {
	    ll tmp=cal(i,j,k)+tim[frm][j];
	    if(tim[to][k]==0 || tim[to][k]>tmp)
	      tim[to][k]=tmp;
	  }
    }
  ll ans=1e17;
  int cc=0;
  FOR(i,1,msk+1)
    if(ans>tim[m&1][i]+ss[i])
      ans=tim[m&1][i]+ss[i],cc=i;
  cout<<ans;
  return 0;
}
