#include <cstdio>
#include <set>

using namespace std;

#define N 10000

int p[N][2];

int gcd(int a,int b)
{
    return (b==0?a:gcd(b,a%b));
}

int main()
{
    freopen("in.txt","r",stdin);

    int a0,b0,n;
    scanf("%d\n%d %d",&n,&a0,&b0);
    int d=gcd(a0,b0);
    if(d)
    {
        d/=gcd(d,n);
        a0/=d,b0/=d;
    }
    int a1,b1;
    a1=(n-a0)%n;
    b1=(n-b0)%n;
    d=gcd(a1,b1);
    if(d)
    {
        d/=gcd(d,n);
        a1/=d,b1/=d;
    }
    for(;;)
    {
        if( (a0 || b0) && a0<=a1 && b0<=b1)
            a1-=a0,b1-=b0;
        else if( (a1 || b1) && a0>=a1 && b0>=b1)
            a0-=a1,b0-=b1;
        else break;
    }

    set<int> q;
    set<int>::iterator ite;
    q.insert(0);
    int ans=0;
    ite=q.begin();
    for(int a,b;ite!=q.end();++ite,++ans)
    {
        p[ans][0]=a=(*ite)>>15;
        p[ans][1]=b=(*ite)&((1<<15)-1);
        if(a+a0<n && b+b0<n)
            q.insert((*ite)+(a0<<15)+b0);
        if(a+a1<n && b+b1<n)
            q.insert(*(ite)+(a1<<15)+b1);
    }

    printf("%d",ans);

    for(int i=0;i<ans;++i)
        printf("\n%d %d",p[i][0],p[i][1]);

    return 0;
}
