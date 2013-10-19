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
using namespace std;
typedef long long ll;
int p[10];
int ans;
int dfs(int f,int t,int num,int l,int all)
{
  if(l==all)
    return (num<=t && num>=f)?1:0;
  int r(0);
  for(int i=l==0?1:0;i<10 && r<3;++i)
    if(p[i])
      {
	--p[i];
	r+=dfs(f,t,num*10+i,l+1,all);
	++p[i];
      }
  return r;
}
int main()
{
  //freopen("in","r",stdin);
  int a,b;
  cin>>a>>b;
  for(int i=a;i<=b;++i)
    {
      memset(p,0,sizeof(p));
      int n=0;
      for(int j=i;j;j/=10)
	++p[j%10],++n;
      if(dfs(a,b,0,0,n)==2)
	++ans;
    }
  cout<<ans<<endl;
  return 0;
}
