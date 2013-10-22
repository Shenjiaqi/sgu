#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define L (1000)
#define K (9)
#define N (L/K+1)
#define MOD ((int)(1e9))
int p[N],lp;
int mi[N],lmi;
int f[N],lf,l[N],ll;
void mid()
{
    lmi=max(ll,lf);
    for(int i=0;i<lmi;++i)
    {
        long long t=f[i];
        t+=l[i];
        if(mi[i])
            ++t;
        if(t>=MOD)
            mi[i+1]=1,mi[i]=(int)(t-MOD);
        else mi[i+1]=0,mi[i]=(int)t;
    }
    if(mi[lmi])
        ++lmi;
    for(int i=lmi-1,j=0;i>=0;--i)
    {
        long long t=mi[i];
        if(j)
            t+=MOD;
        j=(int)t&1;
        mi[i]=(t>>=1);
    }
    if(mi[lmi-1]==0)
        --lmi;
}
int tm[N],lt;
void squ()
{
    memset(tm,0,sizeof(tm));
    lt=2*lmi-1;
    for(int i=0;i<lmi;i++)
        for(int j=0;j<lmi;++j)
        {
            long long t1=mi[i];
            t1*=(long long)mi[j];
            t1+=tm[i+j];
            if(t1>=MOD)
            {
                tm[i+j+1]+=t1/MOD;
                if(i+j+2>lt)
                    lt=i+j+2;
            }
            tm[i+j]=t1%MOD;
        }
}
bool cmp()
{
    if(lf<ll)
        return 1;
    else if(lf>ll)
        return 0;
    for(int i=lf-1;i>=0;--i)
        if(f[i]<l[i])
            return 1;
        else if(f[i]>l[i])
            return 0;
    return 1;
}
int compare()
{
    if(lt<lp)
        return -1;
    if(lt>lp)
        return 1;
    for(int i=lt-1;i>=0;--i)
        if(tm[i]!=p[i])
            return (tm[i]-p[i]);
    return 0;
}
void setl()
{
    memcpy(l,mi,sizeof(l));
    ll=lmi;
    for(int i=0;i<ll;++i)
    {
        if(l[i]==0)
            l[i]=MOD-1;
        else {--l[i];break;}
    }
    if(l[ll-1]==0)
        --ll;
}
void setf()
{
    memcpy(f,mi,sizeof(f));
    lf=lmi;
    int i=0;
    for(i=0;i<lf;++i)
        if(f[i]==MOD-1)
            f[i]=0;
        else {++f[i];break;}
    if(i==lf)
        f[lf++]=1;
}
int main()
{
    freopen("in.txt","r",stdin);
    {
        char tmp[L+1];
        scanf("%s",tmp);
        int l=strlen(tmp);
        lp=(l+K-1)/K;
        char *c=tmp;
        for(int i=lp-1;i>=0;--i)
        {
            int j=0;
            if(i==lp-1)
                if(l%K)
                    j=K-(l%K);
            for(;c<tmp+l && j<K;++j)
                p[i]=p[i]*10+(int)(*c++-'0');
        }
    }
    f[0]=1,lf=1;
    ll=((L/2)+K-1)/K;
    l[ll-1]=1;
    for(int i=0;i<(L/2)%K;++i)
        l[ll-1]*=10;
    int c;
    for(;cmp();)
    {
        mid();
        squ();
        /*
        if(ll<2)
        {
    printf("\n\n");
    for(int i=lf-1;i>=0;--i)
        printf("%09d",f[i]);
    printf("\n\n");
    printf("\n\n");
    for(int i=lmi-1;i>=0;--i)
        printf("%09d",mi[i]);
    printf("\n\n");
    printf("\n\n");
    for(int i=ll-1;i>=0;--i)
        printf("%09d",l[i]);
    printf("\n\n");
    printf("%d\n",c);
        }*/
        c=compare();
        if(c==0)
            break;
        if(c>0)
            setl();
        else setf();

    }/*
    printf("\n\n");
    for(int i=lf-1;i>=0;--i)
        printf("%09d",f[i]);
    printf("\n\n");
    printf("\n\n");
    for(int i=lmi-1;i>=0;--i)
        printf("%09d",mi[i]);
    printf("\n\n");
    printf("\n\n");
    for(int i=ll-1;i>=0;--i)
        printf("%09d",l[i]);
    printf("\n\n");
    printf("%d\n",c);*/
    if(c<=0)
    {
        memcpy(l,mi,sizeof(f));
        ll=lmi;
    }
    printf("%d",l[ll-1]);
    for(int i=ll-2;i>=0;--i)
        printf("%09d",l[i]);
    return 0;
}
