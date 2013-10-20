#include <cstdio>
#include <cstdlib>
#include <cmath>
int main()
{
    freopen("out.txt","w",stdout);
    int n=300;
    printf("%d\n",n);
    double a=10.0;
    double b=0;
    for(double a=0.5;a<7.5;a+=0.5)
    {
        printf("%f %f 1.7\n",float(10.0*cos(a)),float(10.0*sin(a)));
    }
//    printf("%d %d %d",0,);
    return 0;
}
