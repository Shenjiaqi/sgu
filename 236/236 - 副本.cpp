#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
#define N (50)
int p[N+1][N+1][2];
int tra[N+1][N+1];
long long path[N+1][N+1];
int list[N],poi;
int cmp(const void *a,const void *b)
{
    int *c=(int*)a,*d=(int*)b;
    double e=p[*c][*(c+1)][0],
        f=p[*d][*(d+1)][0];
    e/=(double)p[*c][*(c+1)][1];
    f/=(double)p[*d][*(d+1)][1];
    if(fabs(e-f)<1e-13)
        return 0;
    return (e<f?1:-1);
}
void bt(int f,int t)
{
    if(tra[f][t])
    {
        bt(f,tra[f][t]);
        bt(tra[f][t],t);
    }
    else
        list[poi++]=f;
}
long long shift(int k)
{
    long long r=1;
    if(k>=32)
    {
        r<<=31;
        return (r<<(k-31));
    }
    return r<<k;
}
bool check(long long pa,long long pb,int v,int f,int t)
{
    long long r=pa&pb;
    long long tmp=shift(v);
    r^=tmp;
    //printf("%d %d %d %lld\n",f,v,t,r);
    if(f==t)
    {
        tmp=shift(f);
        return (r^tmp)==0;
    }
    return r==0;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    printf("%d %d",N,(N*N)-N);
    for(int i=1;i<=N;++i)
        for(int j=1;j<=N;++j)
            if(i!=j)
                printf("\n%d %d %d %d",i,j,rand()%100+1,rand()%100+1);
    return 0;
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        scanf("%d%d",&p[a][b][0],&p[a][b][1]);
        path[a][b]=shift(a)|shift(b);
    }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            for(int k=1;k<=n;++k)
                if(j!=i && k!=i && p[j][i][0] && p[i][k][0] && check(path[j][i],path[i][k],i,j,k))
                {
                    int a=p[j][i][0]+p[i][k][0];
                    int b=p[j][i][1]+p[i][k][1];
                    if(p[j][k][0]==0 || (double)p[j][k][0]/(double)p[j][k][1]<(double)a/(double)b)
                        p[j][k][0]=a,p[j][k][1]=b,tra[j][k]=i,path[j][k]=path[j][i]|path[i][k];
                }
    int r=-1;
    double max=0;
    for(int i=1;i<=n;++i)
        if(p[i][i][1] && max<(double)p[i][i][0]/(double)p[i][i][1])
            r=i,max=(double)p[i][i][0]/(double)p[i][i][1];
    if(r<0)
        printf("0");
    else
    {
        bt(r,r);
        printf("%d\n",poi);
        for(int i=0;i<poi;++i)
            printf("%d ",list[i]);
    }
    return 0;
}
