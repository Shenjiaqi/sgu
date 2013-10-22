#include <cstdio>
#include <cstring>
using namespace std;
#define N 100
#define M 5
#define P 10000
int te,m,p;
int num[N+1];
int tra[1<<M][1<<M];
int matr[1<<M][1<<M];
void read()
{
    for(;;)
    {
        char t;
        scanf("%c",&t);
        if(t==' ')
            break;
        num[te++]=(int)(t-'0');
    }
    for(int i=0,j=te-1;i<j;++i,--j)
        num[i]^=num[j],num[j]^=num[i],num[i]^=num[j];
    scanf("%d %d",&m,&p);
}
bool check(int a,int b)
{
    for(int i=1;i<m;++i,a>>=1,b>>=1)
        if( ((a&1) == (b&1)) && ((a&1)==((a&2)>>1)) && ((b&2)==(a&2)) )
            return 0;
    return 1;
}
int gen()
{
    for(int i=0;i<(1<<m);++i)
        for(int j=0;j<(1<<m);++j)
            if(check(i,j))
                matr[i][j]=1;
}
int t1[1<<M][1<<M],t2[1<<M][1<<M];
void mul(int a[1<<M][1<<M],int b[1<<M][1<<M])
{
    memcpy(t1,a,sizeof(t1));
    memcpy(t2,b,sizeof(t2));
    for(int i=0;i<(1<<m);++i)
        for(int j=0;j<(1<<m);++j)
        {
            a[i][j]=0;
            for(int k=0;k<(1<<m);++k)
                a[i][j]=(a[i][j]+t1[i][k]*t2[k][j])%p;
        }
}
int cal()
{
    for(int i=0;i<te;++i)
        if(num[i])
        {
            --num[i];
            break;
        }
        else num[i]=9;
    gen();
    for(int i=0;i<(1<<m);++i)
        tra[i][i]=1;
    for(;te;)
    {
        if(num[0]&1)
            mul(tra,matr);
        mul(matr,matr);
        for(int i=0;i<te;++i)
        {
            if(i && (num[i]&1))
                num[i-1]+=5;
            num[i]>>=1;
        }
        if(!num[te-1])
            --te;
    }
    int ans(0);
    for(int i=0;i<(1<<m);++i)
        for(int j=0;j<(1<<m);++j)
        {
            ans+=tra[i][j];
            ans%=p;
        }
    return ans;
}
int main()
{
    freopen("in.txt","r",stdin);
    read();
    printf("%d",cal());
    return 0;
}
