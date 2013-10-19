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
using namespace std;
#define N 32767
int p[N+1][4],poi;
void rotate(int x)
{
  int y=p[x][3];
  int z=p[y][3];
  int ly=p[z][1]==y?1:2;
  int lx=p[y][1]==x?1:2;
  int ulx=lx==1?2:1;
  p[y][lx]=p[x][ulx];
  if(p[x][ulx])
    p[p[x][ulx]][3]=y;
  p[z][ly]=x;
  p[x][3]=z;
  p[y][3]=x;
  p[x][ulx]=y;
}
void splay(int x,int r)
{
  for(;;)
    {
      int y=p[x][3];
      if(y==r)
	break;
      rotate(x);
    }
}
int find(int v)
{
  int i=p[0][1];
  for(;i;)
    {
      if(p[i][0]<=v)
	{
	  if(p[i][2])
	    i=p[i][2];
	  else break;
	}
      else if(p[i][1])
	i=p[i][1];
      else break;
    }
  return i;
}
void insert(int v)
{
  int pos=find(v);
  ++poi;p[poi][0]=v,p[poi][1]=p[poi][2]=0,p[poi][3]=pos;
  if(pos==0 || p[pos][0]>v)
    p[pos][1]=poi;
  else p[pos][2]=poi;
  splay(poi,0);
}
void pr(int v)
{
  if(v)
    {
      pr(p[v][1]);
      cout<<p[v][0]<<endl;
      pr(p[v][2]);
    }
}
int main()
{
  freopen("in","r",stdin);
  int n;
  cin>>n;
  typedef long long ll;
  ll ans=0;
  for(int i=0;i<n;++i)
    {
      int t;
      cin>>t;
      insert(t);
#define INF 100000001
      int v=INF;
      int z=p[0][1];
      if(p[z][1])
	{
	  int j=p[z][1];
	  for(;p[j][2];j=p[j][2])
	    ;
	  v=min(v,t-p[j][0]);
	}
      if(p[z][2])
	{
	  int j=p[z][2];
	  for(;p[j][1];j=p[j][1])
	    ;
	  v=min(v,p[j][0]-t);
	}
      if(v==INF)
	ans+=t;
      else
	ans+=v;
      //cout<<'!'<<v<<endl;
    }
  cout<<ans;
  //cout<<endl;
  //pr(p[0][1]);
  return 0;
}
