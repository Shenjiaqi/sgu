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
  if(n<30)
    {
      if(n!=21)
	cout<<-1;
      else cout<<1;
    }
  else
    {
      int k=n/14;
      n%=14;
      if(n<=12 && n>=2)
	cout<<k;
      else cout<<-1;
    }
  return 0;
}
