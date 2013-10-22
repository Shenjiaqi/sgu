#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define CARRY (1000000000)
struct bignum
{
    long long num[30];
    int l;
}aa[2],cc[2],tmp;
void output(bignum &a)
{
    int l=max(0,a.l-1);
    while(l>0 && a.num[l]==0)
        --l;
    printf("%d",(int)a.num[l]);
    for(--l;l>=0;--l)
            printf("%09d",(int)a.num[l]);
}
void cpy(bignum &a,bignum &b)
{
    b.l=a.l;
    memcpy(b.num,a.num,sizeof(a.num));
}
void mul(bignum &a,bignum &b,bignum &c)
{
    c.l=0;
    memset(c.num,0,sizeof(c.num));
    int m(0);
    for(int i=0;i<a.l;++i)
        for(int j=0;j<b.l;++j)
        {
            c.num[i+j]+=a.num[i]*b.num[j];
            if(c.num[i+j]>=CARRY)
            {
                c.num[i+j+1]+=c.num[i+j]/CARRY;
                c.num[i+j]%=CARRY;
                m=max(m,i+j+1);
            }
            else m=max(m,i+j);
        }
    for(;c.num[m]>=CARRY;++m)
    {
        c.num[m+1]=c.num[m]/CARRY;
        c.num[m]%=CARRY;
    }
    c.l=m+1;/*
    output(a);printf(" a\n");
    output(b);printf(" b\n");
    output(c);printf(" c\n\n");*/
}
void sub(bignum &a,bignum &b,bignum &c)
{
    long long carry=0;
    c.l=1;
    for(int i=0;i<a.l;++i)
    {
        if(a.num[i]-carry<b.num[i])
        {
            c.num[i]=CARRY+a.num[i]-carry-b.num[i];
            carry=1;
        }
        else
        {
            c.num[i]=a.num[i]-carry-b.num[i];
            carry=0;
        }
        if(c.num[i])
            c.l=i+1;
    }
}
bool less(bignum a,bignum b)
{
    if(a.l<b.l)
        return 1;
    int l=max(0,a.l-1);
    return (a.num[l]<b.num[l]);
}
void cal(int l,int k)
{
    for(int i=1,j=0;i<=l;i<<=1)
    {
        if(i&l)
        {
            mul(aa[j],cc[k],tmp);
            cpy(tmp,cc[k]);
        }
        mul(aa[j],aa[j],aa[j^1]);
        j^=1;
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int a,b;
    scanf("%d %d",&a,&b);
    aa[0].l=1,aa[0].num[0]=(long long)a;
    cc[0].l=cc[1].l=1;
    cc[0].num[0]=1,cc[1].num[0]=1;
    cal(b,0);
    aa[0].l=1,aa[0].num[0]=(long long)b;
    cal(a,1);
    if(less(cc[0],cc[1]))
    {
        printf("-");
        sub(cc[1],cc[0],tmp);
    }
    else
        sub(cc[0],cc[1],tmp);
    output(tmp);
    return 0;
}
