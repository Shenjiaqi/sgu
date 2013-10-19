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
#define N 20000
int p[N][2];
int getbound(const vector<int> &c,int &l,int &r,int &u,int &d)
{
  r=l=p[c[0]][0],u=d=p[c[0]][1];
  for(int i=1;i<c.size();++i)
    {
      int j=c[i];
      l=min(l,p[j][0]);
      r=max(r,p[j][0]);
      u=max(u,p[j][1]);
      d=min(d,p[j][1]);
    }
}
int getbound(int n,int &l,int &r,int &u,int &d)
{
  l=r=p[0][0],u=d=p[0][1];
  for(int i=1;i<n;++i)
    {
      l=min(l,p[i][0]);
      r=max(r,p[i][0]);
      u=max(u,p[i][1]);
      d=min(d,p[i][1]);
    }
}
bool det1(int m,const vector<int> &c)
{
  if(c.size()<2)
    return true;
  if(m==0)
    return false;
  int l,r,u,d;
  getbound(c,l,r,u,d);
  if((abs(r-l)<=m) && (abs(u-d)<=m))
    return true;
  return false;
}
bool det2(int m,const vector<int> &c)
{
  if(c.size()<3)
    return true;
  int pos[4];
  getbound(c,pos[0],pos[1],pos[2],pos[3]);
  for(int i=0;i<2;++i)
    for(int j=0;j<2;++j)
      {
	int x=pos[i],y=pos[2+j];
	vector<int> cc;
	for(int k=0;k<c.size();++k)
	  if(abs(p[c[k]][0]-x)>m || abs(p[c[k]][1]-y)>m)
	    cc.push_back(c[k]);
	if(det1(m,cc))
	  return true;
      }
  return false;
}
bool det3(int n,int m)
{
  int pos[4];
  getbound(n,pos[0],pos[1],pos[2],pos[3]);
  for(int i=0;i<2;++i)
    for(int j=0;j<2;++j)
      {
	int x1=pos[i],y1=pos[2+j];
	vector<int> c;
	for(int k=0;k<n;++k)
	  if(abs(p[k][0]-x1)>m || abs(p[k][1]-y1)>m)
	    c.push_back(k);
	if(det2(m,c))
	  return true;
      }
  return false;
}
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;++i)
    scanf("%d%d",*(p+i),*(p+i)+1);
  int ans=0;
  for(ll f=1,l=(int)2e9;f<=l;)
    {
      int m=(int)((f+l)/(ll)2);
      if(det3(n,m))
	ans=m,l=m-1;
      else f=m+1;
    }
  printf("%d",ans);
  return 0;
}
