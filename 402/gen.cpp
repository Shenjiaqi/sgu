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
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define N 50
#define M 500
bool p[N][N];
int main()
{
  freopen("in","w",stdout);
  srand(1001);
  int n=N;
  int m=170;
  cout<<n<<' '<<m<<endl;
  for(int i=0;i<m;++i)
    {
      for(;;)
	{
	  int f=rand()%n;
	  int t=rand()%n;
	  int c=rand()%5;
	  if(!p[f][t] && f!=t)
	    {
	      p[f][t]=p[t][f]=true;
	      ++f,++t,++c;
	      cout<<f<<' '<<t<<' '<<c<<endl;
	      break;
	    }
	}
    }
  return 0;
}
