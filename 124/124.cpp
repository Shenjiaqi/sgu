#include <cstdio>
#include <algorithm>
using namespace std;
#define K (10000)
int main()
{
    freopen("in.txt","r",stdin);
    int p[K][4],k;
    scanf("%d",&k);
    for(int i=0;i<k;++i)
        scanf("%d %d %d %d",*(p+i),*(p+i)+1,*(p+i)+2,*(p+i)+3);
    int x,y;
    scanf("%d %d",&x,&y);
    int cr(0);
    for(int i=0;i<k;++i)
    {
        int x1,y1,x2,y2;
        x1=p[i][0],y1=p[i][1],x2=p[i][2],y2=p[i][3];
        if((x1==x2 && x==x1 && ((y1<=y && y<=y2)||(y1>=y && y>=y2))) ||
           (y1==y2 && y==y1 && ((x1<=x && x<=x2)||(x1>=x && x>=x2))))
        {
            printf("BORDER");
            return 0;
        }
        if(y2!=y1 && x1>x && ( (y1<=y && y<=y2) || (y1>=y && y>=y2) ))
        {
            if(y!=max(y1,y2))
                ++cr;
        }
    }
    printf("%s",(cr&1?"INSIDE":"OUTSIDE"));
    return 0;
}
