#include <cstdio>
#define N 1000
int main()
{
    int k,n;
    freopen("in.txt","r",stdin);
    scanf("%d %d",&n,&k);
    int b=n-(k%n);
    int d;
    for(d=1;((d*b)%n)!=n-1/*gcd(n,b)==1*/;++d)
        ;
    bool p[N]={0};
    for(int j=0;j!=n-1;j=(j+d)%n)
        p[j]=1;
    int x=(k+b)/n;
    for(int j=0;j<n;++j)
        printf("%d ",(p[j]?x-1:x));
    return 0;
}
