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
#include <cctype>
using namespace std;
typedef long long ll;
typedef pair<int,int> ppi;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 30000
int p[N][4];
int fa[N*2];
int q[N];
bool sel[N];
bool cmp(int a,int b)
{
  if(p[a][2]==p[b][2])
    return p[a][3]>p[b][3];
  return p[a][2]>p[b][2];
}
int que(int v)
{
  return v==fa[v]?v:fa[v]=que(fa[v]);
}
void mg(int a,int b)
{
  a=que(a),b=que(b);
  if(a!=b)
    fa[a]=b;
}
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  map<int,int> mapp;
  FOR(i,0,n)
    {
      scanf("%d%d%d%d",*(p+i),*(p+i)+1,*(p+i)+2,*(p+i)+3,*(p+i)+4);
      mapp[p[i][0]]=mapp[p[i][1]]=1;
    }
  int cnt=0;
  FR(i,mapp)
    {
      fa[cnt]=cnt;
      i->second=cnt++;
    }
  FOR(i,0,n)
    {
      p[i][0]=mapp[p[i][0]],p[i][1]=mapp[p[i][1]];
      q[i]=i;
    }
  sort(q,q+n,cmp);
  ll ans(0);
  FOR(i,0,n)
    {
      int a=p[q[i]][0],b=p[q[i]][1];
      if(que(a)!=que(b))
	mg(a,b),sel[q[i]]=true,ans+=p[q[i]][3];
    }
  cout<<ans<<endl;
  FOR(i,0,n)
    if(!sel[i])
      printf("%d ",i+1);
  FOR(i,0,n)
    if(sel[i])
      printf("%d ",i+1);
  return 0;
}
