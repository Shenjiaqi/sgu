#include <stdio.h>
//#include <math.h>
#define TAG 987654321
#define MOD 1000000000
/*
111111111
119357639
380642361
388888889
611111111
619357639
880642361
888888889
*/
int main()
{
    /*
    long long t=sqrt(TAG)/10;
    long long a=t*10+1;
    long long b=t*10+9;
    for(;a<=MOD || b<=MOD;a+=10,b+=10)
    {
        if((a*a)%MOD==TAG)
            printf("%lld\n",a);
        if((b*b)%MOD==TAG)
            printf("%lld\n",b);
    }*/
    int n;
    scanf("%d",&n);
    if(n<=8)
        printf("0");
    else if(n==9)
        printf("8");
    else
    {
        printf("72");
        for(int i=n-9-1;i;--i)
            printf("0");
    }
    return 0;
}
