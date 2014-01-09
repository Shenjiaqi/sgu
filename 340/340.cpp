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
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
typedef pair<double,double> ppd;
#define PB push_back
#define MP make_pair
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
char buf[128007];
int main()
{
  for(;getbeg();)
    {
      char type=getnxt();
      if(type=='l')
	{
	  printf("<i>%s</i>",buf);
	}
      else if(type=='d')
	printf("%s",buf);
      else if(type=='o')
	printf("&nbsp;%s&nbsp;",buf);
      else if(type=='u')
	{
	  type=getnxt();
	  printf("<sup>");
	  if(type=='p')
	    {
	      for(;;)
		{
		  scanf("%c",type);
		  if(type=='}')
		    break;
		  if(type!=' ')
		    printf("%c",type);
		}
	    }
	  else
	    {
	      getnxt();
	      printf("%s",buf);
	    }
	  printf("</sup>");
	}
      getend();
    }
}
