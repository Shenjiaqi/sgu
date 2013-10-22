#include <cstdio>
#include <cmath>
#define N (10000)
double p[N][2];
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    double tmpx,tmpy,tx,ty;
    tx=ty=tmpx=tmpy=0;
    for(int i=0;i<n;++i)
    {
        scanf("%lf%lf",*(p+i),*(p+i)+1);
        if(i&1)
            tmpx-=p[i][0],tmpy-=p[i][1];
        else tmpx+=p[i][0],tmpy+=p[i][1];
        if(tx>=p[i][0]-1e-4)
            tx=p[i][0]-1.0;
        if(ty>=p[i][1]-1e-4)
            ty=p[i][1]-1.0;
    }
    if((n&1)==0 && (fabs(tmpx)>(1e-13) || fabs(tmpy)>(1e-13)))
    {
        printf("NO");
        return 0;
    }
    printf("YES\n");
    if(n&1)
        tx=tmpx,ty=tmpy;
    for(int i=0;i<n;++i)
    {
        printf("%.3lf %.3lf\n",tx,ty);
        tx=2.0*p[i][0]-tx;
        ty=2.0*p[i][1]-ty;
    }
    return 0;
}
