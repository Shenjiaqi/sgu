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
    /*if(left==1)
    {
        ++ans;
        return ;
    }*/
    if(lev>=n)
        return;
    int tmp=n*(n-lev)-__builtin_popcount(m1);
    if(lev<n-1)
        tmp-=__builtin_popcount(m2);
    /*if(lev<n-2)
        tmp-=n*(n-lev-2)*2/3;*/
    if(tmp<left)
        return;
    int i;
    if(m1==0 && m2==0)
        ++add,i=1;
    else i=m1;
    for(;i<lim;)
    {
        int tmp=i^m1;
        df(lev+1,(m2|(tmp<<2)|(tmp>>2))&(lim-1),((tmp<<1)|(tmp>>1))&(lim-1),left-__builtin_popcount(tmp));
        i=(i+1)|m1;
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
    printf("%I64d",ans);
    return 0;
}

