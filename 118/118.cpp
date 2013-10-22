#include <cstdio>

#define N 1000

int p[N];

int f(int k)
{
    if(k<10)
        return k;
    int r=0;
    while(k)
    {
        r+=k%10;
        k/=10;
    }
    return f(r);
}

int main()
{
    freopen("in.txt","r",stdin);

    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,c;
        scanf("\n%d",&n);
        for(int i=0;i<n;++i)
            scanf(" %d",p+i);
        int ans=0;
        for(int i=n-1;i>=0;--i)
            ans=f((ans+1)*f(p[i]));
        printf("%d",ans);
        if(t)
            printf("\n");
    }
    return 0;
}
