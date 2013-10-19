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
  freopen("in","w",stdout);
  int n,m,k;
  srand(13);
  n=5000,m=70,k=(rand()%n)+1;
  cerr<<n<<' '<<m<<' '<<k<<endl;
  cout<<n<<' '<<m<<' '<<k<<endl;
  for(int i=0;i<n;++i)
    cout<<(rand()%(100)>1?1:0)<<' ';
  return 0;
}
