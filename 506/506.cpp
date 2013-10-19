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
int main()
{
  freopen("in","r",stdin);
  string a,b;
  cin>>a>>b;
  int p[100];
  memset(p,-1,sizeof(p));
  ll ans(0);
  int la=a.length();
  int lb=b.length();
  for(int i=0;i<la;++i)
    {
      for(int j=lb-1;j>=0;--j)
	if(b[j]==a[i])
	  {
	    if(j==0)
	      p[j]=i;
	    else
	      p[j]=p[j-1];
	  }
      if(p[lb-1]>=0)
	ans+=(1+p[lb-1]);
    }
  cout<<ans;
  return 0;
}
