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
  int rr[7];
  for(int i=0;i<7;++i)
    cin>>rr[i];
  string c;
  cin>>c;
  int ans(0);
  if(rr[0]>=0 && rr[1])
    {
      if(c=="RED")
	ans+=7;
      ans+=rr[0]*8;
    }
  for(int i=1;i<7;++i)
    if(rr[i])
      ans+=i+1;
  cout<<ans;
  return 0;
}
