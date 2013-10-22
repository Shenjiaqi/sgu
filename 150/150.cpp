#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    double x1,y1,x2,y2;
    int n;
    scanf("%lf %lf %lf %lf %d",&x1,&y1,&x2,&y2,&n);
    if(fabs(x1-x2)<(1e-3) || fabs(y1-y2)<(1e-3))
    {
        printf("no solution");
        return 0;
    }
    double x,y,dx,dy;
    x=x1,y=y1;

    dx=(x1<x2?1:-1);
    dy=(y1<y2?1:-1);

    double nyx,ny,dnyx,dny;
    int p;
    for(int i=0;i<n;++i)
    {
        if(fabs(x-x2)<(1e-7) || fabs(y-y2)<(1e-7))
        {
            printf("no solution");
            return 0;
        }
        nyx=(y2-y1)*(x+dx-x1)/(x2-x1)+y1;
        ny=y+dy;
        dnyx=fabs(nyx-y1);
        dny=fabs(ny-y1);
        if(fabs(dnyx-dny)<1e-7)
            x+=dx,y+=dy,p=0;
        else if(dnyx<dny)
            x+=dx,p=1;
        else
            y+=dy,p=2;
    }
    if(p==0)
        x=min(x,x-dx),y=min(y,y-dy);
    else if(p==1)
        x=min(x,x-dx),y=min(y,y+dy);
    else x=min(x,x+dx),y=min(y,y-dy);
    if(x>=0)
        x+=0.1;
    else x-=0.5;
    if(y>=0)
        y+=0.1;
    else y-=0.1;
    printf("%d %d",(int)(x),(int)(y));
    return 0;
}
