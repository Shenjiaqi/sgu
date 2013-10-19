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
int main()
{
  freopen("in","w",stdout);
  int n=30;
  cout<<n<<endl;
  int ll=500;
  cout<<'a'<<endl;
  cout<<"16";
  for(int i=0;i<16;++i)
    cout<<" a";
  cout<<endl;
  ll-=16;
  for(int i=1;i<n;++i)
    {
      int t=min(16,ll);
      ll-=16;
      cout<<t;
      for(int j=0;j<t;++j)
	cout<<" "<<i;
      cout<<endl;
    }
  return 0;
}
