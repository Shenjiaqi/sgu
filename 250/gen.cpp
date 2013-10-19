#include <cstdio>
#include <cstdlib>
#include <time.h>
#define N (20)
int main()
{
  srand(time(NULL));
  freopen("in","w",stdout);
  printf("%d %d\n",N,N);
  for(int i=0;i<N;++i)
    {
      for(int j=0;j<N;++j)
	printf("%d ",(rand()%7>0?0:1));
      printf("\n");
    }
  return 0;
}
