#include <cstdio>
#include <cstdlib>
int main()
{
  freopen("in","w",stdout);
  int n,m,k;
  n=10,m=10,k=6;
  printf("%d %d %d",n,m,k);
  for(int i=0;i<k;++i)
    {
      printf("\n");
      for(int j=0;j<n;++j)
	{
	  for(int l=0;l<m;++l)
	    if(j<7)
	      printf("0");
	    else
	      printf("%d",(rand()%7)<2);
	  printf("\n");
	}
    }
  return 0;
}
