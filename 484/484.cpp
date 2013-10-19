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
#define N 100
#define M 100
char p[N][M+1];
int main()
{
  freopen("in","r",stdin);
  int n,m;
  scanf("%d%d",&n,&m);
  int x,y;
  for(int i=0;i<n;++i)
    {
      cin>>p[i];
      for(int j=0;j<m;++j)
	if(p[i][j]=='P')
	  x=i,y=j;
    }
  int pos=y;
  for(int i=x+1;n>i;++i)
    {
      if(p[i][pos]=='\\')
	{
	  ++pos;
	  if(pos<m && p[i][pos]=='\/')
	    pos=-1;
	}
      else if(p[i][pos]=='/')
	{
	  --pos;
	  if(pos>=0 && p[i][pos]=='\\')
	    pos=-1;
	}
      if(pos<0 || pos>=m)
	{
	  pos=-2;
	  break;
	}
    }
  printf("%d",(1+pos));
  return 0;
}
