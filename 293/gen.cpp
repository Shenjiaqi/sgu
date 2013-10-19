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
  int n=2000;
  printf("%d\n",n);
  srand(130);
  for(int i=0;i<2*n-1;++i)
    printf("%c",((rand()%2)?'Q':'C'));
  return 0;
}
