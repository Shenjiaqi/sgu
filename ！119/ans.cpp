#include <cstdio>
#include <algorithm>

using namespace std;

#define N 10001

int p[N];

int gcd(int a,int b)
{
    return (b==0?a:gcd(b,a%b));
}

int main()
{
    freopen("in.txt","r",stdin);

    int a,b,n;
    scanf("%d\n%d %d",&n,&a,&b);

    int d=gcd(a,b);
    d=n/gcd(n,d);
    for(int i=0;i<d;++i)
        p[i]=(((i*a)%n)<<15)+(i*b)%n;

    sort(p,p+d);

    printf("%d",d);
    for(int i=0;i<d;++i)
        printf("\n%d %d",p[i]>>15,p[i]&((1<<15)-1));

    return 0;
}
