#include <cstdio>
#define N (100)
#define P (10000)
int n,p,b,q[N+1][2],r[N+1];
int gcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1,y=0;
        return a;
    }
    int tmp=gcd(b,a%b,x,y);
    int x_=y,y_=x-(a/b)*y;
    x=x_,y=y_;
    return tmp;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d %d %d",&n,&p,&b);
    for(int i=0;i<n;++i)
    {
        scanf("%d",r+i);
        r[i]%=p;
    }
    int li=0,ii=p;
    for(;li<n && (b%ii);++li)
        ii=gcd(r[li],ii,q[li][0],q[li][1]);
    if(b%ii)
        printf("NO");
    else
    {
        printf("YES\n");
        for(int i=li-1,j=1;i>=0;--i)
        {
            q[i][0]=(q[i][0]*j)%p;
            if(q[i][0]<0)
                q[i][0]+=p;
            j=(j*q[i][1])%p;
        }
        for(int i=0;i<n;++i)
            printf("%d ",((q[i][0]*(b/ii))%p));
    }
    return 0;
}
