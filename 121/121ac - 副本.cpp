#include <cstdio>
#include <cstring>
using namespace std;
#define N 101
int zz[N*N*2][2],poi;
int s[N];
int x[N];
int d[N],c[N];
int e[N];
int color[N][N];
int n;
void add(int a,int b)
{
    zz[++poi][0]=b,zz[poi][1]=s[a],s[a]=poi;
    ++d[a];
}
void paint(int a,int b,int k)
{
    color[a][b]=color[b][a]=k;
    e[a]|=k,e[b]|=k;
    ++c[a],++c[b];
}
void unpaint(int a,int b,int k)
{
    color[a][b]=color[b][a]=0;
    e[a]^=k,e[b]^=k;
    --c[a],--c[b];
}
bool df(int f)
{
    if(e[f]==3 || d[f]<2)
        return 0;
    int col=((e[f]&1)?2:1);
    for(int i=x[f];i;i=zz[i][1])
        if(!color[f][zz[i][0]])
        {
            paint(f,zz[i][0],col);
            if(d[zz[i][0]]-c[zz[i][0]]==1 && df(zz[i][0]))
                unpaint(f,zz[i][0],col);
            else
            {
                x[f]=i;
                return 0;
            }
        }
    return 1;
}
bool sol()
{
    for(int i=1;i<=n;++i)
        if(d[i]>1)
        {
            if(!e[i])
            {
                paint(i,zz[s[i]][0],((e[i]&1)?2:1));
                if(df(zz[s[i]][0]))
                    return 1;
            }
            if(df(i))
                return 1;
        }
    return 0;
}
void pt(int m,int f)
{
    if(m==0)
        return;
    pt(zz[m][1],f);
    printf("%d ",(color[f][zz[m][0]]>0?color[f][zz[m][0]]:1));
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
            add(i,t);
        }
    memcpy(x,s,sizeof(x));
    if(sol())
        printf("No solution");
    else
        for(int i=1;i<=n;++i)
        {
            pt(s[i],i);
            printf("0");
            if(i!=n)
                printf("\n");
        }
    return 0;
}
