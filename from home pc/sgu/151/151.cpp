#include <cstdio>
#include <cmath>
#define DETA (1e-13)
int main()
{
    freopen("in.txt","r",stdin);
    double c,b,m;
    scanf("%lf%lf%lf",&c,&b,&m);
    double a;
    //if(b*b+c*c<m*m*2.0+1e-13)
    if(b*b+c*c<m*m*2.0)
        a=-1;
    else a=sqrt((b*b+c*c-m*m*2.0)*2.0);
    //if((a<=DETA) || (a+b<=c+DETA) || (a+c<=b+DETA)|| (c+b<=a+DETA))
    if(a<0 || (a+b<c) || (a+c<b)|| (c+b<a))
    {
        printf("Mission impossible");
        return 0;
    }
    double x;
        x=(c*c-b*b)/((double)2.0*a);
    if(fabs(a)<DETA)
        x=0;
    double y=sqrt(m*m-x*x);
    printf("%.5lf %.5lf\n",x,y);
    printf("%.5lf %.5lf\n",-(a)/(double)2.0,(double)0);
    printf("%.5lf %.5lf",(a)/(double)2.0,(double)0);
    return 0;
}
