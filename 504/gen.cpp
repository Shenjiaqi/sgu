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
#define N 700
int main()
{
  freopen("in","w",stdout);
  int h,w;
  h=w=700;
  printf("%d %d",h,w);
  for(int i=0;i<h;++i)
    {
      printf("\n");
      for(int j=0;j<w;++j)
	printf("%c",('a'+((rand()&15)>13?1:0)));
    }
  return 0;
}
