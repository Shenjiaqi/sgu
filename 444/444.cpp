#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;
#define N 1000007
int p[N+1];
int main()
{
  freopen("in.txt","r",stdin);
  int x,y;
  scanf("%d%d",&x,&y);
  x%=y;
  int c=0;
  for(int poi=0;;)
    {
      ++c;
      if(x==0)
	{
	  printf("%d 0",poi);
	  break;
	}
      else if(p[x])
	{
	  printf("%d %d",(p[x]-1),(poi-p[x]+1));
	  break;
	}
      p[x]=poi+1;
      x=(x*10)%y;
      ++poi;
    }
  return 0;
}
