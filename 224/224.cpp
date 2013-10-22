#include <cstdio>
typedef long long lld;
int n,k,lim;
lld ans;
void df(int l,int a,int b,int c,int left)
{
    if(!left)
        ++ans;
    else if(l>=n || (n-l)<left)
        return;
    else
    {
        df(l+1,(a<<1)&lim,b,c>>1,left);
        int u=(~(a|b|c))&lim;
        for(int i;u;u-=i)
        {
            i=u&(-u);
            df(l+1,((a|i)<<1)&lim,b|i,(c|i)>>1,left-1);
        }
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&k);
    if(k>n)
        printf("0");
    else
    {
        lim=(1<<n)-1;
        df(0,0,0,0,k);
        printf("%I64d",ans);
    }
    return 0;
}
