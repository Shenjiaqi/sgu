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
#include <cctype>
using namespace std;
typedef long long ll;
typedef pair<int,int> ppi;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
int main()
{
  freopen("in","w",stdout);
  int n=14;
  cout<<n<<endl;
  for(int i=0;i<n;++i)
    {
      for(int j=0;j<30;++j)
	cout<<(char)((rand()%('z'-'a'))+'a');
      cout<<endl;
    }
  return 0;
}
