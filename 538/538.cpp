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
  //freopen("in","r",stdin);
  int ans(0);
  for(int i=0,j=0,p;EOF!=(p=getchar());++i)
    if(p==')')
      {
	if(j)
	  j=0,--ans;
	else ++ans;
      }
    else if(p=='(')
      ++ans,j=1;
    else if(!isupper(p) && !islower(p) && p!=' ')
      j=0;
  printf("%d",ans);
  return 0;
}
