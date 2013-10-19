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
#include <functional>
using namespace std;
int p[1000][1000]={0};
int main()
{
  freopen("in","r",stdin);
  int n,m;
  cin>>n>>m;
  queue< pair<int,int> > que;
  for(int i=0;i<n;++i)
    for(int j=0;j<m;++j)
      {
	char t;
	cin>>t;
	if(t=='X')
	  {
	    que.push(make_pair(i,j));
	    p[i][j]=2;
	  }
      }
  int ans(0);
  const int dir[][2]={{1,0},{-1,0},{0,1},{0,-1}};
  for(;!que.empty();)
    {
      int x=que.front().first;
      int y=que.front().second;
      que.pop();
      ++ans;
      for(int i=0;i<sizeof(dir)/sizeof(dir[0]);++i)
	{
	  int xx=x+dir[i][0];
	  int yy=y+dir[i][1];
	  if( xx >= 0 && n > xx && yy >= 0 && yy < m )
	    {
	      if(p[xx][yy]<2)
		{
		  ++p[xx][yy];
		  if(p[xx][yy]==2)
		    que.push(make_pair(xx,yy));
		}
	    }
	}
    }
  cout<<ans;
  return 0;
}
