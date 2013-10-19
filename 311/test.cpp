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
int p[100001][4],poi;
void rotate(int x,int d)
{
  int y=p[x][3];
  int z=p[y][3];
  int ly=p[z][1]==y?1:2;
  int ud=d==1?2:1;
  p[y][d]=p[x][ud];
  p[p[x][ud]][3]=y;
  p[x][ud]=y;
  p[y][3]=x;
  p[x][3]=z;
  p[z][ly]=x;
}
void splay(int x,int v)
{
  for(;;)
    {
      int y=p[x][3];
      if(y==v)
	break;
      int z=p[y][3];
      int lx=p[y][1]==x?1:2;
      int ly=p[z][1]==y?1:2;
      if(z==v)
	{
	  rotate(x,lx);
	}
      else
	{
	  rotate(x,lx);
	  rotate(x,ly);
	}
    }
}
int find(int v)
{
  int i;
  for(i=p[0][1];i;)
    {
      if(p[i][0]==v)
	break;
      if(p[i][0]<v)
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
  if(pos && p[pos][0]==v)
    return ;
  ++poi,p[poi][0]=v,p[poi][1]=p[poi][2]=0,p[poi][3]=pos;
  if(pos==0)
    p[0][1]=poi;
  else p[pos][p[pos][0]<v?2:1]=poi;
  splay(poi,0);
}
void pt(int i)
{
  if(i)
    {
      pt(p[i][1]);
      cout<<p[i][0]<<endl;
      pt(p[i][2]);
    }
}
int main()
{
  freopen("in","r",stdin);
  for(int i=0;i<100000;++i)
    {
      insert(rand());
      find(rand());
    }
  pt(p[0][1]);
  return 0;
}
