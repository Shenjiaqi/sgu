#include <cstdio>
#include <cstdlib>
#define X 200
int main()
{
  freopen("in","w",stdout);
  int n=10;
  srand(7);
  printf("%d\n",n);
  for(int i=0;i<n;++i)
    printf("%d %d %d %d\n",rand()%X,rand()%X,rand()%X,rand()%X);
  return 0;
}
