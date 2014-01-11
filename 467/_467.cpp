#include <cstdio>
int main()
{
  int p;
  for(int i=1;EOF!=scanf("%d",&p);++i)
    {
      int r=0;
      if(p<=0)
	r=0;
      else if(p<=78)
	r=1;
      else if(p<=95)
	r=2;
      else if(p<=99)
	r=3;
      else r=4;
      printf("Case #%d: %d\n",i,r);
    }
  return 0;
}

