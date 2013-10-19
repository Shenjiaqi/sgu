#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
using namespace std;
typedef long long ll;
int main()
{
  freopen("in","w",stdout);
  int n,l;
  n=27,l=1000000000;
  cout<<n<<' '<<l<<endl;
  srand(38);
  for(int i=0;i<2;++i)
    {
      for(int j=0;j<n;++j)
	cout<<((rand()%l)+1)<<' ';
      cout<<endl;
    }
  return 0;
}
