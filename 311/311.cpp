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
#define N 100000
typedef long long ll;
ll p[N+1][7],poi;
void rotate(int x)
{
  int y=p[x][3];
  int z=p[y][3];
  int lx=p[y][1]==x?1:2;
  int ly=p[z][1]==y?1:2;
  int ulx=lx==1?2:1;
  if(p[y][lx]=p[x][ulx])
    p[p[x][ulx]][3]=y;
  p[y][3]=x;
  p[z][ly]=x;
  p[x][ulx]=y;
  p[x][3]=z;

  p[x][4]=p[y][4];
  p[x][5]=p[y][5];
  p[y][4]-=(p[x][0]*p[x][6]+(p[x][lx]?p[p[x][lx]][4]:0));
  p[y][5]-=(p[x][6]+(p[x][lx]?p[p[x][lx]][5]:0));
}
void splay(int x,int r)
{
  for(;;)
    {
      int y=p[x][3];
      if(y==r)
	break;
      int z=p[y][3];
      if(z==r)
	rotate(x);
      else
	{
	  int l1=p[z][1]==y?1:2;
	  int l2=p[y][1]==x?1:2;
	  if(l1==l2)
	    rotate(y),rotate(x);
	  else rotate(x),rotate(x);
	}
    }
}
void insert(ll n,ll v)
{
  int k=p[0][1];
  for(;k;)
    {
      if(p[k][0]<v)
	{
	  if(p[k][2])
	    k=p[k][2];
	  else break;
	}
      else if(p[k][1])
	k=p[k][1];
      else break;
    }
  ++poi,p[poi][0]=v,p[poi][6]=n,p[poi][1]=p[poi][2]=0,p[poi][3]=k,p[poi][4]=n*v,p[poi][5]=n;
  if(k && p[k][0]<v)
    p[k][2]=poi;
  else p[k][1]=poi;
  for(k=p[poi][3];k;k=p[k][3])
    p[k][4]+=n*v,p[k][5]+=n;
  splay(poi,0);
}
bool buy(ll n,ll v)
{
  ll num=0,money=0;
  int k=p[0][1],kf=0;
  for(;k && money<=v;)
    {
      kf=k;
      ll c=p[k][1]?p[p[k][1]][5]:0;
      ll d=p[k][1]?p[p[k][1]][4]:0;
      if(c+p[k][6]+num>=n)
	{
	  if(c+num>=n)
	    k=p[k][1];
	  else
	    {
	      num+=c;
	      money+=d;
	      break;
	    }
	}
      else
	{
	  num=num+c+p[k][6];
	  money+=(d+p[k][0]*p[k][6]);
	  k=p[k][2];
	}
    }
  if(k)
    splay(k,0);
  else if(kf)
    splay(kf,0);
  if(k==0 || money>v || money+(n-num)*p[k][0]>v)
    return false;
  if(n-num==p[k][6])
    {
      p[0][1]=p[k][2];
      p[p[k][2]][3]=0;
    }
  else
    {
      ll l=n-num;
      p[k][6]-=l;
      p[k][5]-=n;
      p[k][4]-=(l*p[k][0]+money);
      p[k][1]=0;
    }
  return true;
}
void pt(int v)
{
  if(v)
    {
      pt(p[v][1]);
      cout<<p[v][0]<<' '<<p[v][6]<<endl;
      pt(p[v][2]);
    }
}
int main()
{
  freopen("in","r",stdin);
  string t;
  ll n,v;
  for(;;)
    {
      cin>>t>>n>>v;
      if(cin.eof())
	break;
      if(t[0]=='A')
	insert(n,v);
      else if(buy(n,v))
	cout<<"HAPPY"<<endl;
      else cout<<"UNHAPPY"<<endl;
    }
  //pt(p[0][1]);
  return 0;
}
