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
  int n,t1,t2;
  cin>>n>>t1>>t2;
  int a=0,t=0;
  for(bool f1=true,f2=true;f1 || f2;)
    {
      ++t;
      if(f1 && (t%t1==0))
	++a;
      if(f2 && (t%t2==0))
	  ++a;
      if(f1 && (t%t1==0) && a>=n)
	f1=false;
      if(f2 && (t%t2==0) && a>=n)
	f2=false;
    }
  cout<<a<<' '<<t;
  return 0;
}
