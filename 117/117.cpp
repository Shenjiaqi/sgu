#include <stdio.h>

int gcd(int a,int b)
{
    return (b==0?a:gcd(b,a%b));
}

int can(int t,int m,int k)
{
    if(m==1 || t==1)
        return t%k==0;

    int d=gcd(t,k);
    return can(d,m-1,k/d);
}

int main()
{
    freopen("in.txt","r",stdin);

    int n,m,k;
    scanf("%d %d %d\n",&n,&m,&k);

    int ans=0;
    for(int i=0,t;i<n;++i)
    {
        scanf("%d",&t);
        if(can(t,m,k))
            ++ans;
    }

    printf("%d",ans);

    return 0;
}
