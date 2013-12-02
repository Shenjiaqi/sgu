#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
using namespace std;
#define H 20
#define W 20
bool white[H][W];
int main()
{
  int T;
  scanf("%d",&T);
  for(;T--;)
    {
      int h,w,n;
      scanf("%d%d%d",&h,&w,&n);
      memset(white,0,sizeof(white));
      int cnt=0;
      for(int i=1;i<h-1;++i)
	for(int j=1;j<w-1;++j)
	  {
	    if(((i+j)&1)==0&&cnt<n)
	      {
		white[i][j]=true;
		++cnt;
	      }
	  }
      if(cnt<n)
	printf("Impossible\n");
      else
	for(int i=0;i<h;++i)
	  {
	    for(int j=0;j<w;++j)
	      printf("%c",white[i][j]?'#':'.');
	    printf("\n");
	  }
      printf("\n");
    }
  return 0;
}
