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
#define X 10000
#define N 200
bool p[X+1];
int q[N];
int main()
{
  freopen("in","r",stdin);
  int n,x;
  cin>>n>>x;
  for(int i=0;i<n;++i)
    cin>>q[i];
  int ans[N];
  int ani=0;
  for(int i=0;i<n;++i)
    {
      memset(p,0,sizeof(p));
      p[0]=true;
      for(int j=0;j<n;++j)
	if(i!=j)
	  for(int k=x-q[j];k>=0;--k)
	    if(p[k])
	      p[k+q[j]]=true;
      if(!p[x])
	ans[ani++]=q[i];
    }
  cout<<ani<<endl;
  for(int i=0;i<ani;++i)
    cout<<ans[i]<<' ';
  return 0;
}
