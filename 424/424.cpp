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
  int n;
  scanf("%d",&n);
  if(n==1)
    printf("1 0");
  else if(n==2)
    printf("2 1\n1 2");
  else if(n==3)
    printf("3 3\n1 2\n2 3\n1 3");
  else
    {
      printf("%d %d\n",n,(n-2)*2);
      for(int i=3;i<=n;++i)
	printf("1 %d\n2 %d\n",i,i);
    }
  return 0;
}
