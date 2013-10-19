#include <cstdio>
#include <cstdlib>
#define Q (999)
#define C (999)
#define N (222204)
bool occ[1+Q][1+C];
int main()
{
  freopen("in","w",stdout);
  int q,c,n,t;
  q=Q,c=C;
  n=20000,t=1000000000;
  printf("%d %d %d %d\n",q,c,n,t);
  for(int i=0;i<n;++i)
    {
      for(;;)
	{
	  int x=(rand()%Q+1);
	  int y=(rand()%C+1);
	  if(occ[x][y])
	    continue;
	  occ[x][y]=1;
	  printf("%d %d\n",x,y);
	  break;
	}
    }
  return 0;
}
