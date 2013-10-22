#include <cstdio>
typedef long long ll;
ll ans;
int n,k;
int add;
int lim;
int p(int i)
{
    int r=1;
    for(;i>0;--i)
        r*=i;
    return r;
}
int cc(int a,int b)
{
    int r= p(a+b)/(p(a)*p(b));
    return r;
}
void df(int lev,int m1,int m2,int left)
{
    if(left<0)
        return;
    if(!left)
    {
        ans+=cc(n-lev,add);
        return;
    }
    if(lev>=n)
        return;
    int tmp=n*(n-lev)-__builtin_popcount(m1);
    if(lev<n-1)
        tmp-=__builtin_popcount(m2);
    /*if(n-lev>2)
        tmp-=n*(n-lev-2)/2;*/
    if(tmp<left)
        return;
    if(m1==0 && m2==0)
        ++add;
    for(int i=(m1?m1:1);i<lim;i=(i+1)|m1)
    {
        int tmp=i^m1;
        df(lev+1,(m2|(tmp<<2)|(tmp>>2))&(lim-1),((tmp<<1)|(tmp>>1))&(lim-1),left-__builtin_popcount(tmp));
    }
    if(0==m1 && m2==0)
        --add;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&k);
    lim=1<<n;
    df(0,0,0,k);
    /*
    for(int i=1;i<(1<<n);++i)
        df(1,((i<<2)|(i>>2))&((1<<n)-1),((i<<1)|(i>>1))&((1<<n)-1),k-__builtin_popcount(i));*/
    printf("%I64d",ans);
    return 0;
}
