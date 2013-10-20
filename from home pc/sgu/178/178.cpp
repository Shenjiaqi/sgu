#include <cstdio>
__int64 l;
bool test(int n)
{
    __int64 s=n;
    for(int i=0;i<=n;++i)
        if((s=s+s+1)>=l)
            return 1;
    return 0;
}
int main()
{
    //freopen("in.txt","r",stdin);
    scanf("%I64d",&l);
    int f=0,l=50;
    for(int m;f<=l;)
    {
        m=(f+l)>>1;
        if(test(m))
            l=m-1;
        else f=m+1;
    }
    printf("%d",f);
    return 0;
}
