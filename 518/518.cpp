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
int p[200][200];
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;++i)
    for(int j=0;j<n;++j)
      scanf("%d",*(p+i)+j);
  bool vis[2][200];
  memset(vis,0,sizeof(vis));
  vis[0][0]=true;
  int k;
  scanf("%d",&k);
  for(int i=0;i<k;++i)
    {
      int r;
      scanf("%d",&r);
      int f=i&1,t=1-(i&1);
      for(int j=0;j<n;++j)
	if(vis[f][j])
	  for(int l=0;l<n;++l)
	    if(r==p[j][l])
	      vis[t][l]=true;
      memset(vis[f],0,sizeof(vis[f]));
    }
  int ans(0);
  for(int i=0;i<n;++i)
    if(vis[k&1][i])
      ++ans;
  cout<<ans<<endl;
  for(int i=0;i<n;++i)
    if(vis[k&1][i])
      cout<<(i+1)<<' ';
  return 0;
}
