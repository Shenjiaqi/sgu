#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define MAXNUMLEN 500
#define MOD (1000000000)
void pr(const int *num)
{
    printf("%d",num[num[0]]);
    for(int i=num[0]-1;i>0;--i)
        printf("%09d",num[i]);
    printf("\n");
}
int cmp(const int *a,const int *b)
{
    if(a[0]!=b[0])
        return (a[0]-b[0]);
    for(int i=a[0];i>0;--i)
        if(a[i]!=b[i])
            return (a[i]-b[i]);
    return 0;
}
void add(int *a,const int *b)
{
    int la=a[0],lb=b[0];
    int l=min(la,lb);
    a[la+1]=0;
    int i=1;
    for(;i<=l;++i)
    {
        a[i]+=b[i];
        if(a[i]>=MOD)
        {
            ++a[i+1];
            a[i]-=MOD;
        }
    }
    if(la>lb)
    {
        for(;i<=la;++i)
            if(a[i]>=MOD)
            {
                a[i]-=MOD;
                ++a[i+1];
            }
            else break;
    }
    else if(lb>la)
        for(;i<=lb;++i)
        {
            a[i]+=b[i];
            if(a[i]>=MOD)
            {
                a[i]-=MOD;
                a[i+1]=1;
            }
            else a[i+1]=0;
        }
    a[0]=max(la,lb);
    if(a[a[0]+1])
        ++a[0];
}
void sub(int *a,const int *b)
{
    /*a>=b*/
    int lb=b[0],la=a[0];
    for(int i=1;i<=la;++i)
    {
        if(i<=lb)
            a[i]-=b[i];
        else if(a[i]>=0)
            break;
        if(a[i]<0)
        {
            a[i]+=MOD;
            --a[i+1];
        }
    }
    for(;la>1 && !a[la];--la)
        ;
    a[0]=la;
}
void mul(int *a,const int *b,int *c)
{
static int _t[MAXNUMLEN+1];
    int la=a[0],lb=b[0];
    int *t;
    t=c?c:_t;
    memset(t,0,sizeof(int)*(la+lb+1));
    for(int i=1;i<=la;++i)
        for(int j=1;j<=lb;++j)
        {
            long long ta=a[i];
            long long tb=b[j];
            long long tt=t[i+j-1];
            tt+=ta*tb;
            if(tt>=(long long)MOD)
            {
                t[i+j]+=(tt/MOD);
                t[i+j-1]=(tt%MOD);
            }
            else t[i+j-1]=tt;
        }
    t[0]=t[la+lb]?(la+lb):(la+lb-1);
    if(!c)
        memcpy(a,t,sizeof(int)*(t[0]+1));
}
void div(int *a,const int *b,int *c,int *r)
{
    static int _t[MAXNUMLEN+1];
    static int d[MAXNUMLEN+1];
    static int tmp[MAXNUMLEN+1];
    static int tmp1[MAXNUMLEN+1];
    int *t;
    t=c?c:_t;
    int la=a[0],lb=b[0];
    memset(t,0,sizeof(int)*(la>=lb?la-lb+2:2));
    if(la>=lb)
    {
        memcpy(d+1,a+la-lb+1,sizeof(int)*lb);
        d[0]=lb;
    }
    else memcpy(d,a,sizeof(int)*(a[0]+1));
    for(int i=la-lb+1;i>=1;)
    {
        int mi,ma;
        /*if(d[0]==b[0])
            mi=(d[lb]-1)/(1+b[lb]),ma=(1+d[lb])/(b[lb]-1);
        else if(d[0]>b[0])
            mi=((long long)d[d[0]]*(long long)MOD)/(long long)(1+b[lb]),
            ma=(((long long)d[d[0]]+1)*(long long)MOD)/(long long)(b[lb]);
        else mi=ma=0;*/
        mi=0,ma=MOD-1;
        int mid;
        for(;;)
        {
            mid=(mi+ma)>>1;
            tmp[1]=mid;
            tmp[0]=1;
            mul(tmp,b,NULL);
            /*
            for(int j=1;j<=lb;++j)
            {
                long long tb=b[j];
                long long tm=mid;
                long long tt=tmp[j];
                tt+=tb*tm;
                if(tt>=MOD)
                {
                    tmp[j+1]=tt/MOD;
                    tmp[j]=tt%MOD;
                }
                else tmp[j]=tt,tmp[j+1]=0;
            }
            tmp[0]=(tmp[lb+1]?lb+1:lb);
            pr(tmp);
            pr(d);
            printf("%d %d\n\n\n",tmp[0],d[0]);*/
            if(cmp(tmp,d)>0)
                ma=mid-1;
            else
            {
                memcpy(tmp1,d,sizeof(int)*(d[0]+1));
                sub(d,tmp);
                if(cmp(d,b)>=0)
                {
                    mi=mid+1;
                    memcpy(d,tmp1,sizeof(int)*(tmp1[0]+1));
                }
                else break;
            }
        }
        t[i]=mid;
        //printf("mid:%d t[%d]: %d\n",mid,i,t[i]);
        if(i==1)
            break;
        for(;d[0]>1 && !d[d[0]];--d[0])
            ;
        for(int j=1+d[0];j>1;--j)
            d[j]=d[j-1];
        d[1]=a[--i];
        if(d[d[0]+1])
            ++d[0];
    }

    if(r)
        memcpy(r,d,sizeof(int)*(d[0]+1));
    if(la>=lb)
        t[0]=la-lb+1;
    else t[0]=1,t[1]=0;
    for(;t[0]>1 && !t[t[0]];--t[0])
        ;
    if(!c)
        memcpy(a,t,sizeof(int)*(t[0]+1));
}
class bignum
{
public:
    bool neg;
    int num[MAXNUMLEN+1];
    bignum(){neg=0,num[num[0]=1]=0;};
    bignum & operator+=(const bignum &b)
    {
        static int tmp[MAXNUMLEN+1];
        if(b.neg==neg)
            add(num,b.num);
        else if(cmp(num,b.num)>=0)
            sub(num,b.num);
        else
        {
            memcpy(tmp,num,sizeof(int)*(num[0]+1));
            memcpy(num,b.num,sizeof(int)*(b.num[0]+1));
            sub(num,tmp);
            neg=!neg;
        }
    }
    bignum & operator-=(const bignum &b)
    {
        static int tmp[MAXNUMLEN];
        if(neg!=b.neg)
            add(num,b.num);
        else if(cmp(num,b.num)>=0)
            sub(num,b.num);
        else
        {
            memcpy(tmp,num,sizeof(int)*(num[0]+1));
            memcpy(num,b.num,sizeof(int)*(b.num[0]+1));
            sub(num,tmp);
            neg=!neg;
        }
    }
    bignum & operator*=(const bignum &b)
    {
        mul(num,b.num,NULL);
        neg=(neg!=b.neg);
    }
    bignum & operator/=(const bignum &b)
    {
        div(num,b.num,NULL,NULL);
        neg=(neg!=b.neg);
    }
    bignum & operator=(const bignum&v)
    {
        neg=v.neg;
        memcpy(num,v.num,sizeof(int)*(v.num[0]+1));
    }
    bignum & operator=(const int v)
    {
        if(v>=0)
            num[1]=v,neg=0;
        else num[1]=-v,neg=1;
        num[0]=1;
    }
    void dr(const bignum &b,int *r)
    {
        div(num,b.num,NULL,r);
        neg=(neg!=b.neg);
    }
    void dr(const bignum &b, bignum &c)
    {
        div(num,b.num,NULL,c.num);
        c.neg=neg;
        neg=(neg!=b.neg);
        //b should be posotove
    }
    bool iszero()
    {
        return (num[0]==1 && num[1]==0);
    }
    void prt(char *w)
    {
        if(w)
            printf("%s:\n",w);
        if(neg && !iszero())
            printf("-");
        pr(num);
    }
};
bignum operator*(const bignum &a,const bignum &b)
{
    bignum c;
    c=a;
    c*=b;
    return c;
}
void gcd( bignum a, bignum b,bignum &x)
{
    bignum y,tmp;
    y=0;
    x=1;
freopen("out.txt","w",stdout);
    for(;;)
    {
    a.prt("a");
    b.prt("b");
        a.dr(b,tmp);
    a.prt("a/b");
    tmp.prt("a%b");
    printf("\n\n\n\n");
        if(tmp.iszero())
            break;
        y-=a*x;
        a=b,b=tmp;
        tmp=y,y=x,x=tmp;
    }
}
int n,b,ans;
bignum an[6];
void solv(int p1,int p2)
{
    if(p1==0)
        return;
    static bignum nc,na,nb;
    nc=1;
    na=1;
    nb=1;
    static bignum c,d,e;
    c=p1;
    d=p2;
    e=b;
    for(int i=1;i<=n;i<<=1)
    {
        if(i&n)
            na*=c,nb*=d,nc*=e;
        c=c*c;
        d=d*d;
        e=e*e;
    }
    gcd(na,nb,c);
    c.prt("c");
    na.prt("na");
    c.dr(na,d);
    d.prt("d");
    if(d.neg)
        d+=na;
    d.prt("d");

    nb*=d;
    nb.dr(na,c);
    c.prt("c");



    e=b;
    nc.dr(e,NULL);
    an[ans]=d*nb;
    if(cmp(an[ans].num,nc.num)>=0)
        ++ans;
    na-=d;
    an[ans]=na*nb;
    e=1;
    an[ans]+=e;
    if(cmp(an[ans].num,nc.num)>=0)
        ++ans;
}
static const int ii[][2]={
    //0     1     2     3     4     5     6     7     8     9
    {0,0},{0,0},{0,0},{0,0},{0,0},{0,0},{2,3},{0,0},{0,0},{0,0},
    //10    11    12    13    14    15    16    17    18    19
    {2,5},{0,0},{3,4},{0,0},{2,7},{3,5},{0,0},{0,0},{2,9},{0,0},
    //20    21    22    23    24    25    26    27     28     29    30
    {4,5},{3,7},{2,11},{0,0},{3,8},{0,0},{2,13},{0,0},{4,7},{0,0},{0,0},
    //31    32     33    34    35     36
    {0,0},{0,0},{3,11},{2,17},{5,7},{4,9}
};
void ptr(int i)
{
    if(an[i].iszero())
        printf("0");
    else
    {
        static char str[2007];
        int poi=0;
        int *a=an[i].num;
        int l=a[0];
        for(;l>0;)
        {
            long long r=0;
            for(int i=l;i>0;--i)
            {
                long long tmp=a[i];
                tmp+=r*MOD;
                r=tmp%b;
                tmp/=b;
                a[i]=tmp;
            }
            r%=(long long)b;
            str[poi++]=(char)(r<10?r+'0':r-10+'A');
            for(;l>0 && !a[l];--l)
                ;
        }
        for(;poi>1 && str[poi-1]=='0';--poi)
            ;
        for(int i=poi-1;i>=0;--i)
            printf("%c",str[i]);
    }
    printf("\n");
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d %d",&b,&n);
    if(b!=30)
    {
        if(ii[b][0])
            solv(ii[b][0],ii[b][1]);
    }
    else
    {
        solv(2,15);
        solv(6,5);
        solv(10,3);
    }
    printf("%d\n",ans+(n==1?2:0));
    if(n==1)
        printf("0\n1\n");
    for(int i=0;i<ans;++i)
        ptr(i);
    return 0;
}
