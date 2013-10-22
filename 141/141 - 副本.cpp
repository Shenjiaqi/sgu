#include <cstdio>
#include <cstdlib>
typedef long long ll;
ll gcd(ll a,ll b,ll &x,ll &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    ll tmp=gcd(b,a%b,y,x);
    y-=(a/b)*x;
    return tmp;
}
int main()
{
    freopen("in.txt","r",stdin);
    ll x1,x2,p,k;
    scanf("%I64d%I64d%I64d%I64d",&x1,&x2,&p,&k);
    ll a,b,d;
    d=gcd(x1,x2,a,b);
    if(p%d)
    {
        printf("NO");
        return 0;
    }
    a*=p/d,b*=p/d;
    ll xx,yy;
    xx=x2/d;
    yy=x1/d;
    if(a>0)
        xx=-xx;
    else yy=-yy;
    ll u=abs(a)+abs(b);
    for(;u>k;)
    {
        a+=xx,b+=yy;
        ll tmp=abs(a)+abs(b);
        if(tmp>u)
            a-=2*xx,b-=2*yy,tmp=abs(a)+abs(b);
        if(tmp>u)
            break;
        u=tmp;
    }
    if(u>k)
    {
        printf("NO");
        return 0;
    }
    if((u+k)&1)
    {
        if(((xx+yy)&1)==0)
        {
            printf("NO");
            return 0;
        }
        a+=xx,b+=yy;
        u=abs(a)+abs(b);
        if(u>k)
            a-=2*xx,b-=2*yy,u=abs(a)+abs(b);
        if(u>k)
        {
            printf("NO");
            return 0;
        }
    }
    printf("YES\n");
    if(a>0)
        printf("%I64d %I64d",a,(ll)0);
    else printf("%I64d %I64d",(ll)0,-a);
    printf(" ");
    ll tmp=(k-u)>>1;
    if(b>0)
        printf("%I64d %I64d",b+tmp,tmp);
    else printf("%I64d %I64d",tmp,-b+tmp);
    return 0;
}
