#include <cstdio>
int main()
{
    freopen("in.txt","r",stdin);
    double x,y,z;
    scanf("%lf %lf %lf",&x,&y,&z);
    y-=x;
    y*=60.0;
    if(z>=y-(1e-15))
        printf("%.7lf",1.0);
    else
    {
        double a=y*y;
        y-=z;
        printf("%.7lf",((double)1.0-y*y/a));
    }
    return 0;
}
