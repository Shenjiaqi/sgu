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
int p[103][103];
int main()
{
  freopen("in","r",stdin);
  int n,m;
  cin>>n>>m;
  int ans(0);
  for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)
      {
	char t;
	cin>>t;
	p[i][j]=t-'0';
	if(p[i][j])
	  ans+=2;
      }
  for(int i=1;i<=n+1;++i)
    for(int j=1;j<=m+1;++j)
      ans+=abs(p[i][j]-p[i-1][j])+abs(p[i][j]-p[i][j-1]);
  cout<<ans;
  return 0;
}
