#include <cstdio>
#include <cstdlib>
using namespace std;
int gcd(int a,int b,int &r,int &s)
{
    if(b==0)
    {
        r=1;
        s=0;
        return a;
    }
    int tmp=gcd(b,a%b,r,s);
    int tr=s;
    int ts=r-(a/b)*s;
    r=tr,s=ts;
    return tmp;
}
int main()
{
    freopen("in.txt","r",stdin);
    int x1,x2,p,k;
    scanf("%d %d %d %d",&x1,&x2,&p,&k);
    int a,b;
    int c=gcd(x1,x2,a,b);
    if(p==0)
    {
        if((k&1)==0)
            printf("YES\n%d %d %d %d",k/2,k/2,0,0);
        else
        {
            b=x1/c;
            a=b*x2/x1;
            if((b+a)&1 && (b+a)<=k)
            {
                int tmp=k-(b+a);
                printf("YES\n%d %d %d %d",0,a,b+tmp/2,tmp/2);
            }
            else printf("NO");
        }
    }
    else if(0==(p%c))
    {
        a=p/c*a,b=p/c*b;
        int tmp=abs(a)+abs(b);
        if(k>=tmp && ((k-tmp)&1)==0)
        {
            printf("YES\n");
            tmp=k-tmp;
            if(a>=0)
            {
                printf("%d %d",a+tmp/2,tmp/2);
            }
            else printf("%d %d",tmp/2,-a+tmp/2);
            printf(" %d %d",(b>0?b:0),(b>0?0:-b));
        }
        else printf("NO");
    }
    else printf("NO");
    return 0;
}
