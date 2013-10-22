#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define N 100
#define M 100
bool vis[N][M];
string block[M];
int cal(int x,int y)
{
  //cout<<x<<' '<<y<<endl;
  int r=block[y][x]-'0';
  if(!vis[y][x])
    {
      vis[y][x]=true;
      //cout<<r<<endl;
      return r;
    }
  return (r>>1);
}
int main()
{
  int n,m;
  freopen("in.txt","r",stdin);
  cin>>n>>m;
  for(int i=0;i<n;++i)
    cin>>block[i];
  string path;
  cin>>path;
  int dir[2];
  dir[0]=1,dir[1]=0;
  int x,y;
  x=y=0;
  int ans=0;
  for(int i=0;i<path.length();++i)
    {
      if(path[i]=='L')
	{
	  int tmp=-dir[1];
	  dir[1]=dir[0],dir[0]=tmp;
	}
      else if(path[i]=='R')
	{
	  int tmp=dir[1];
	  dir[1]=-dir[0],dir[0]=tmp;
	}
      else
	{
	  int x_=x+dir[0],y_=y-dir[1];
	  if(x_==x)
	    {
	      if(x<m)
		ans+=cal(x,min(y,y_));
	      if(x)
		ans+=cal(x-1,min(y,y_));
	      y=y_;
	    }
	  else
	    {
	      if(y<n)
		ans+=cal(min(x,x_),y);
	      if(y>0)
		ans+=cal(min(x,x_),y-1);
	      x=x_;
	    }
	}
    }
  cout<<ans;
  return 0;
}
