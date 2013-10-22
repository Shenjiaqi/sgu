#include <cstdio>
#include <cstring>
using namespace std;
void multi(int *a,int &diga,const int *b,int digb)
{
    static int tmp1[N];
    static int tmp2[N];
    memcpy(tmp1,a,sizeof(int)*diga);
    memcpy(tmp2,b,sizeof(int)*digb);
    memset(a,0,sizeof(int)*N);
    for(int i=0;i<diga;++i)
        for(int j=0;j<digb;++j)
        {
            a[j+i]+=tmp1[i]*tmp2[j];
            if(a[i+j]>=10)
                a[i+j]-=10,a[i+j+1]+=1;
        }
    if(a[diga+digb])
        diga=diga+digb+1;
    else diga=diga+digb;
}
void divide(int *a,int &diga,const int *b,int digb)
{
    static int tmp1[N];
    static int tmp2[N];
    static int tmp3[N];
    memcpy(tmp1,a,sizeof(int)*diga);
    memcpy(tmp2,b,sizeof(int)*digb);
    memset(a,0,sizeof(int)*N);
    if(digb>=diga)
    {
        memcpy(tmp3,tmp2+digb-diga,sizeof(int)*diga);
        for(int i;;)
        {

        }
    }
}
void addd(int *a,int &diga,int *b,int &digb)
{
    if(diga<digb)
    {
        for(int i=diga;i<digb;++i)
            a[i]=b[i];
        a[digb]=0;
    }
    else a[diga]=0;
    for(int i=0;i<min(diga,digb);++i)
    {
        a[i]+=b[i];
        if(a[i]>=10)
        {
            a[i]-=10;
            a[i+1]+=1;
        }
    }
    if(diga<digb)
    {
        for(;diga<digb;++diga)
            if(a[diga]>=10)
                a[diga]-=10,a[diga+1]+=1;
            else break;
        diga=digb;
    }
    else
        for(int i=digb;i<diga;++i)
            if(a[i]>=10)
                a[i]-=10,++a[i+1];
    if(a[diga])
        ++diga;
}
bool grte(int *a,int diga,int *b,int digb)
{
    if(diga>digb)
        return 1;
    if(diga<digb)
        return 0;
    for(int i=diga-1;i>=0;++i)
        if(a[i]<b[i])
            return 0;
    return 1;
}
int sub(int *a,int &diga,int *b,int digb)
{
    if(grte(a,diga,b,digb))
    {
        for(int i=0;i<digb;++i)
            if(a[i]>=b[i])
                a[i]-=b[i];
            else a[i]=10+a[i]-b[i],--a[i+1];
        for(int i=digb;i<diga;++i)
            if(a[i]<0)
                a[i]=9,--a[i+1];
            else break;
        for(;diga>1 && !a[diga-1];--diga)
            ;
        return 0;
    }
    static int tmp[N];
    memcpy(tmp,a,sizeof(int)*diga);
    int c=0;
    for(int i=0;i<diga;++i)
        if(b[i]>=tmp[i]+c)
            a[i]=b[i]-tmp[i]-c,c=0;
        else a[i]=10+b[i]-tmp[i]-c,c=1;
    for(;diga<digb;++diga)
        if(c)
        {
            if(b[diga])
                a[diga]=b[diga]-1,c=0;
            else a[diga]=9;
        }
        else a[diga]=b[diga];
    for(;diga>1 && !a[diga];--diga)
        ;
    return 1;
}
class bignum
{
public:
    bool sign;
#define N 2007
    int num[N];
    int tmp[N];
    int dig;
    //-------------------------------------------
    bignum(){dig=1;sign=0;memset(num,0,sizeof(num));};
    void pow(int);
    void cpy(const bignum &);
    void div(const bignum &);
    void mul(const bignum &);
    void clear(){sign=0;memset(num,0,dig*sizeof(int));dig=1;};
    void prt();
    void minus(const bignum &);
    void add(const bignum &);
};
void bignum::add(const bignum & a)
{
    if(sign==a.sign)
        addd(num,dig,a.num,a.dig);
    else
    {
        if(sub(num,dig,a.num,a.dig))
            sign=0;
        else sign=1;
    }
}
void bignum::minus(const bignum &a)
{
    if(sign==a.sign)
        sign=sub(num,dig,a.num.a.dig);
    else
        addd(num,dig,a.num,a.dig);
}
void div(const bignum &a)
{
    divide(num,dig,a.num,a.dig);
    if(sign!=a.sign)
        sign=1;
}
void bignum::cpy(const bignum &a)
{
    sign=a.sign;
    memcpy(num,a.num,a.dig*sizeof(int));
    dig=a.dig;
}
void bignum::pow(int e)
{
    int tmpdig=1;
    tmp[0]=1;
    for(int i=1;i<=e;i<<=1)
    {
        if(i&e)
            mul(tmp,tmpdig,num,dig);
        mul(num,dig,num,dig);
    }
    memcpy(num,tmp,tmpdig*sizeof(int));
    if(sign && (e&1)==0)
        sign=0;
    dig=tmpdig;
}
int main()
{
    int b,n;
    scanf("%d %d",&b,&n);
    return 0;
}
