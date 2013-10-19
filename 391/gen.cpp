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
bool h[100];
int main()
{
  freopen("in","w",stdout);
  for(int i=0;i<(1<<13);++i)
    {
      cout<<13<<' '<<13<<' '<<(__builtin_popcount(i))<<endl;
      for(int j=1;j<=i;j<<=1)
	if(j&i)
	  cout<<"4 "<<(__builtin_ctz(j)+1)<<endl;
    }
  return 0;
}
