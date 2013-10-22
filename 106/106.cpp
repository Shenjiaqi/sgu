#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

long long gcd(long long a,long long b)
{
    return (b==0?a:gcd(b,a%b));
}

int main()
{
    freopen("in.txt","r",stdin);

    long long a,b,c,x1,x2,y1,y2;
    scanf("%I64d %I64d %I64d\n%I64d %I64d\n%I64d %I64d",&a,&b,&c,&x1,&x2,&y1,&y2);

    if(a==0 && b==0)
    {
        if(c==0)
            printf("%I64d",(x2-x1+1)*(y2-y1+1));
        else printf("0");
    }
    else if(a==0)
    {
        if(c%b || c/b>y2 || c/b<y1)
            printf("0");
        else printf("%I64d",(x2-x1+1));
    }
    else if(b==0)
    {
        if(c%a || c/a<x1 || c/a>x2)
            printf("0");
        else printf("%I64d",(y2-y1+1));
    }
    else
    {
        long long d;

        d=gcd(abs(a),abs(b));
        if(c%d)
            printf("0");
        else
        {
            long long a_,b_,x[2],y[2],t0,t1;

            a_=abs(a/d),b_=abs(b/d);
            x[0]=0,y[0]=1;
            x[1]=1,y[1]=0;
            t0=x[0]*a_+y[0]*b_;
            t1=x[1]*a_+y[1]*b_;

            for(long long tmp,tmpx,tmpy,tmpt;t1!=1;)
            {
                tmp=t0/t1;
                tmpx=x[0]-tmp*x[1];
                tmpy=y[0]-tmp*y[1];
                tmpt=t0-t1*tmp;
                t0=t1,x[0]=x[1],y[0]=y[1];
                t1=tmpt,x[1]=tmpx,y[1]=tmpy;
            }

            x[1]*=(-c)/d;
            y[1]*=(-c)/d;

            b_=b/d,a_=a/d;
            long long r1,r2,r3,r4;
            r1=(x1-x[1])/(b_)+((x1>x[1] && (x1-x[1])%b_)?1:0);
            r2=(x2-x[1])/(b_)+((x2<x[1] && (x2-x[1])%b_)?-1:0);
            r3=(y1-y[1])/(-a_)+((y1>y[1] && (y1-y[1])%a_)?-1:0);
            r4=(y2-y[1])/(-a_)+((y2<y[1] && (y2-y[1])%a_)?1:0);

            if(r1>r2)
                x1=r2,r2=r1,r1=x1;
            if(r3>r4)
                x1=r4,r4=r3,r3=x1;

            r1=max(r1,r3);
            r2=min(r2,r4);

            printf("%I64d",r2>=r1?(1+r2-r1):0);
        }
    }

    return 0;
}
