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
  int n=3;
  printf("%d\n",n);
  srand(41);
  for(int i=0;i<n;++i)
    {
      for(int j=0;j<n;++j)
	printf("%c",(rand()%50)>25?'1':'0');
      printf("\n");
    }
  return 0;
}
