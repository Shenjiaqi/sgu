#include <cstdio>
#include <cstring>
using namespace std;
#define N (50)
#define M (10)
#define L (200)
#define K (N)
int n,m,l,k;
int mm[M][2];
long long ll[L];
int matr[K][K];
void mul(int res[][K],const int a[][K],const int b[][K])
{
    static int ta[K][K],tb[K][K];
    memcpy(ta,a,sizeof(ta));
    memcpy(tb,b,sizeof(tb));
    memset(res,0,sizeof(int)*K*K);
    for(int i=0;i<k;++i)
        for(int j=0;j<k;++j)
            for(int z=0;z<k;++z)
                if(ta[i][z] && tb[z][j])
                    res[i][j]^=1;
}
void tra(int *a,int d)
{
    static int tmp[K][K];
    static int tt[K][K];
    memcpy(tmp,matr,sizeof(tmp));
    memset(tt,0,sizeof(tt));
    for(int i=0;i<k;++i)
        tt[i][i]=1;
    for(int i=1;i<=d;i<<=1)
    {
        if(i&d)
            mul(tt,tt,tmp);
        mul(tmp,tmp,tmp);
    }
    static int ttt[K];
    memset(ttt,0,sizeof(ttt));
    for(int i=0;i<k;++i)
        for(int j=0;j<k;++j)
            if(a[j]&&tt[j][i])
                ttt[i]^=1;
    for(int i=0;i<k;++i)
        a[i]=ttt[i];
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d %d %d %d",&n,&m,&k,&l);
    for(int i=0;i<m;++i)
        scanf("%d %d",*(mm+i),*(mm+i)+1);
    for(int i=0;i<l;++i)
    {
        char st1[K+3],st2[K+3];
        scanf("%s%s",st1,st2);
        long long t=0;
        for(int j=0;j<k-1;++j)
        {
            t<<=1;
            if(st1[j+1]=='1' && st2[j]=='1')
                t|=1;
        }
        t<<=1;
        if(st2[k-1]!=st1[0])
            t|=1;
        ll[i]=t;
    }
    //----------------
    for(int i=0;i<l;++i)
    {
        //long long z=1<<(1+__builtin_ctzll(ll[i]>>1));
        long long z=(ll[i]>>1);
        z<<=1;
        z&=(-z);
        if(z)
        {
            for(int j=0;j<l;++j)
                if( (j!=i) && (z&ll[j]))
                    ll[j]^=ll[i];
        }
    }
    int a[K]={0};
    for(int i=0;i<l;++i)
        if(ll[i]&1)
        {
            long long t=ll[i]>>1;
            if(t && (t-(t&(-t)))==0)
                a[__builtin_ctzll(t)]=1;
        }
    //---------------
    for(int i=0;i<k;++i)
        matr[i][(i+1)%k]=1;
    for(int i=0;i<k-1;++i)
        matr[i][0]=a[k-i-2];
    /*for(int i=0;i<k;++i)
    {
        for(int j=0;j<k;++j)
            printf("%d ",matr[i][j]);
        printf("\n");
    }*/
    //---------------
    char t[N+3];
    int org[N];
    scanf("%s",t);
    for(int i=0;i<n;++i)
        org[i]=(t[i]=='1'?1:0);
    for(int i=m-1;i>=0;--i)
        tra(org+mm[i][0]-1,mm[i][1]);
    for(int i=0;i<n;++i)
        printf("%d",org[i]);
    return 0;
}
