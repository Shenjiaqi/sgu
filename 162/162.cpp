#include <cstdio>
#include <cmath>
double hi(double a,double b,double c)
{
    double p=(a+b+c)/(double)2.0;
    return (sqrt(p*(p-a)*(p-b)*(p-c))*(double)2.0/c);
    //return (sin(acos((a*a+c*c-b*b)/((double)2.0*a*c)))*a);
}
double solv(double ab,double ac,double ad,double bc,double bd,double cd)
{
    double ta=hi(ab,bd,ad);
    double tb=hi(ac,cd,ad);
    double tp=(bc+ta+tb)/(double)2.0;
    double s=sqrt(tp*(tp-ta)*(tp-tb)*(tp-bc));
    return (((double) ad)*s/(double)3.0);
}
int main()
{
    freopen("in.txt","r",stdin);
    int ab,ac,ad,bc,bd,cd;
    scanf("%d %d %d %d %d %d",&ab,&ac,&ad,&bc,&bd,&cd);
    printf("%.4lf",solv(ab,ac,ad,bc,bd,cd));
    printf("\n%.4lf",solv(ac,ad,ab,cd,bc,bd));
    printf("\n%.4lf",solv(ab,ac,ad,bc,bd,cd));
    return 0;
}
