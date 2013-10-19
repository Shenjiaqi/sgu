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
#define N 1000
typedef pair<int,int> pp;
list <pp> p;
int main()
{
  freopen("in","r",stdin);
  for(char t;scanf("%c",&t)!=EOF;)
    {
      int a,b;
      scanf("%d%d\n",&a,&b);
      if(t=='+')
	{
	  int r=0;
	  for(list<pp>::iterator ite=p.begin();ite!=p.end();++ite)
	    if(ite->first>=a && ite->second<=b)
	      ++r;
	  printf("%d\n",r);
	  p.push_front(pp(a,b));
	}
      else
	{
	  for(list<pp>::iterator ite=p.begin();ite!=p.end();++ite)
	    if(ite->first==a && ite->second==b)
	      {
		p.erase(ite);
		break;
	      }
	}
    }
  return 0;
}
