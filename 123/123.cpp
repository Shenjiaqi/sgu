#include <cstdio>
int main()
{
    long long a,b,ans(0);
    a=0,b=1;
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        a+=b;
        a^=b,b^=a,a^=b;
        ans+=a;
    }
    printf("%I64d",ans);
    return 0;
}
