#include <cstdio>
int main()
{
  int s,p;
  scanf("%d %d",&s,&p);
  int t=0;
  if(s<p)
    {
      t=1;
      if(p>=s+5*60)
	{
	  t=2;
	  if(p>=s+15*60)
	    {
	      t=3;
	      if(p>=s+30*60)
		t=4;
	    }
	}
    }
  printf("%d",t);
  return 0;
}
