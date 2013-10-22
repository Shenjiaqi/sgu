#include <cstdio>
#define N (10000)
int main()
{
    freopen("in.txt","r",stdin);
    int p[N+1]={0};
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;++i)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        ++p[a];
        ++p[b];
    }
    long long ans(0);
    for(int i=1;i<=n;++i)
    {
        long long t=p[i];
        t*=t;
        ans+=t;
    }
    printf("%I64d",ans);
    return 0;
}
