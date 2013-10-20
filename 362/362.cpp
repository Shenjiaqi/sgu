#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
  int n,m,is,js;
  cin>>n>>m>>is>>js;
  int p[10][10]={0};
  const int dir[][2]={{1,0},{0,-1},{-1,0},{0,1}};
  const char d[]={'D','L','U','R'};
  for(--is,--js;;)
    {
      if(p[is][js])
        break;
      p[is][js]=1;
      for(int i=0;i<4;++i)
        {
          int x=is+dir[i][0];
          int y=js+dir[i][1];
          if(x >= 0 && x <n && y >= 0 && y <m && !p[x][y])
            {
              is=x,js=y;
              printf("%c",d[i]);
              break;
            }
        }
    }
  return 0;
}
