#include <cstdio>
long long gcd(long long a,long long b)
{
    return (b==0?a:gcd(b,a%b));
}
int df(long long a,long long b,int l)
{
    if((a+b)&1)
        return -1;
    if(a==b)
        return l;
    if(!(a&1))
    {
        long long tmp=gcd(a,b);
        a/=tmp;
        b/=tmp;
    }
    if(a<b)
        a^=b,b^=a,a^=b;
    a-=b;
    b<<=1;
    return df(a,b,l+1);
}
int main()
{
    freopen("in.txt","r",stdin);
    long long a,b;
    scanf("%I64d %I64d",&a,&b);
    printf("%d",( (a==0 || b==0 )?0:df(a,b,1)));
    return 0;
}
