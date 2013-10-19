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
#define N 9
char p[N][N+1];
char q[N][N+1];
void gpos(int &x,int &y)
{
  for(x=0;x<h;++x)
    for(y=0;y<w;++y)
      if(p[x][y]=='X')
	return ;
}
bool test(int num)
{
  dfs(num,x,y);
}
int main()
{
  //freopen("in","r",stdin);
  int h,w;
  scanf("%d %d",&h,&w);
  FOR(i,0,h)
    sacnf("%s",p+i);
  int x,y;
  memcpy(q,p,sizeof(q));
  gpos(x,y);
  int ans(9);
  for(int f=1,t=9;f<=t;)
    {
      int m=(f+t)>>1;
      if(test(m))
	t=m-1,ans=m;
      else f=m+1;
    }
  printf("%d\n",ans);
  return 0;
}
