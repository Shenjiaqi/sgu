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
#define N 1000001
int p[N][4],root,poi;
int find(int v)
{
  for(int i=p[0][1];i;)
    {
      if(p[i][0]==v)
	return i;
      if(p[i][0]<v)
	{
	  if(p[i][2])
	    i=p[i][2];
	  else return i;
	}
      else
	{
	  if(p[i][1])
	    i=p[i][1];
	  else return i;
	}
    }
  return 0;
}
void rotate(int x,int dir)
{
  int y=p[x][3];
  int z=p[y][3];
  if(p[y][dir]!=x)
    {cout<<'!'<<endl;}
  int udir=(dir==1?2:1);
  p[y][dir]=p[x][udir];
  if(p[x][udir])
    p[p[x][udir]][3]=y;
  p[x][udir]=y;
  if(y==p[z][1])
    p[z][1]=x;
  else p[z][2]=x;
  p[x][3]=z;
  p[y][3]=x;
}
void splay(int x,int v)
{
  for(;;)
    {
      int y=p[x][3];
      if(y==v)
	{
	  //rotate(x,p[y][1]==x?1:2);
	  break;
	}
      else
	{
	  int z=p[y][3];
	  if(v==z)
	    {
	      rotate(x,p[y][1]==x?1:2);
	      break;
	    }
	  int l1=p[z][1]==y?1:2;
	  int l2=p[y][1]==x?1:2;
	  rotate(x,l2);
	  rotate(x,l1);
	  /*
	  if(z==v)
	    {
	      rotate(x,p[y][1]==x?1:2);
	    }
	  else if(p[y][1]==x)
	    {
	      if(p[z][1]==y)
		{
		  rotate(y,1);
		  rotate(x,1);
		}
	      else
		{
		  rotate(x,1);
		  rotate(x,2);
		}
	    }
	  else
	    {
	      if(p[z][1]==y)
		{
		  rotate(x,2);
		  rotate(x,1);
		}
	      else
		{
		  rotate(y,2);
		  rotate(x,2);
		}
		}*/
	}
    }
}
void insert(int i)
{
  int pos=find(i);
  if(pos && p[pos][0]==i)
    return ;
  ++poi,p[poi][0]=i,p[poi][1]=p[poi][2]=0,p[poi][3]=pos;
  if(pos && p[pos][0]<i)
    p[pos][2]=poi;
  else p[pos][1]=poi;
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
void del(int v)
{
  int pos=find(v);
  if(pos && p[pos][0]==v)
    {
      splay(pos,0);
      if(p[pos][1]==0)
	p[0][1]=p[pos][1];
      else if(p[pos][2]==0)
	p[0][1]=p[pos][2];
      else
	{
	  int i;
	  for(i=p[pos][2];p[i][1];i=p[i][1])
	    ;
	  splay(i,0);
	  p[0][1]=i;
	  p[i][3]=0;
	  p[i][1]=p[pos][1];
	  p[p[pos][1]][3]=i;
	}
    }
}
int main()
{
  freopen("in","r",stdin);
  int a[]={4, 3, 2, 5, 6,0,7,11,13,29};
  for(int i=0;i<100000;++i)
    insert(rand());
  /*  pt(p[0][1]);
  cout<<endl<<endl;
  del(a[1]);
  del(11);
  cout<<endl<<endl;*/
  pt(p[0][1]);
  return 0;
}
