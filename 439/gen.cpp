#include <cstdio>
#include <stdlib.h>
int main()
{
  int n,m;
  n=100000;
  m=n-1;
  freopen("in","w",stdout);
  printf("%d %d\n",n,m);
  for(int i=0;i<n;++i)
    printf("%c",((rand()%('Z'-'A'+1)/26)+'A'));
  printf("\n");
  for(int i=0;i<m;++i)
    printf("%c",((rand()%('Z'-'A'+1)/26)+'A'));
  return 0;
}
