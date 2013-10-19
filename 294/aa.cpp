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
  int n;
  cin>>n;
  int ans(0);
  for(int i=1;i<=n;++i)
    if((n%i)==0)
      ans+=i;
  cout<<ans;
  return 0;
}
