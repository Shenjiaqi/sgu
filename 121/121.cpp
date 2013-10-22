#include <cstdio>
#define N 101
int zz[N*N*2][2],poi;
int s[N];
bool v[N];
bool u[N];
int pre[N];
int dep[N];
int color[N][N];
int n;
void add(int a,int b)
{
    zz[++poi][0]=b,zz[poi][1]=s[a],s[a]=poi;
    zz[++poi][0]=a,zz[poi][1]=s[b],s[b]=poi;
}
void paint(int a,int b,int c)
{
    //printf("!%d %d %d\n",a,b,c);
    color[a][b]=color[b][a]=c;
}
bool df(int f,int z)
{
    v[f]=1;
    int c=0;
    for(int i=s[f];i;i=zz[i][1])
    {
        int tmp=zz[i][0];
        if(tmp!=z && !u[tmp])
        {
            ++c;
            if(v[tmp])
            {
                if(1&(dep[f]-dep[tmp]))
                {
                    int k=f,j=dep[f];
                    for(;k!=tmp;k=pre[k],--j)
                    {
                        u[k]=1;
                        paint(k,pre[k],1+(j&1));
                    }
                    u[tmp]=1;
                    paint(tmp,f,1+(j&1));
                    v[f]=0;
                    return 0;
                }
            }
            else
            {
                pre[tmp]=f;
                dep[tmp]=dep[f]+1;
                if(df(tmp,f)==0)
                {
                    v[f]=0;
                    return 0;
                }
            }
        }
    }
    if(c==0)
    {
        printf("!!\n");
        u[f]=1;
        for(int k=f,j=dep[f];k!=pre[k];--j,k=pre[k])
        {printf("%d %d %d\n",k,pre[k],1+(j&1));
            paint(k,pre[k],1+(j&1));
            u[pre[k]]=1;
        }
        v[f]=0;
        return 0;
    }
    v[f]=0;
    return 1;
}
bool sol()
{
    for(int i=1;i<=n;++i)
    {
        pre[i]=i;
        dep[i]=0;
        if(!u[i] && df(i,i))
            return 1;
    }
    return 0;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        for(int t;;)
        {
            scanf("%d",&t);
            if(t==0)
                break;
            if(t>i)
                add(i,t);
        }
    if(sol())
        printf("No solution");
    else
        for(int i=1;i<=n;++i)
        {
            for(int j=s[i];j;j=zz[j][1])
                printf("%d ",(color[i][zz[j][0]]>0?color[i][zz[j][0]]:1));
            printf("0\n");
        }
    return 0;
}
