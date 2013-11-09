#include <cstdio>
#include <cstring>
using namespace std;
#define N 4
#define SWP(a,b) ((a)^=(b),(b)^=(a),(a)^=(b))
int p[N][N];
const int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};
bool mask[N][N];
void pt()
{
    printf("\n");
    for(int i=0;i<N;++i)
        {for(int j=0;j<N;++j)
            printf("%d ",p[i][j]);printf("\n");}
}
void getpos(int v,int &x,int &y)
{
    for(x=0;x<N;++x)
        for(y=0;y<N;++y)
            if(p[x][y]==v)
                return;
}
bool vis[N][N];
bool df(int x,int y,int x0,int y0)
{
    if(x==x0 && y==y0)
        return 1;
    vis[x][y]=1;
    for(int i=0;i<4;++i)
    {
        int x_=x+dir[i][0];
        int y_=y+dir[i][1];
        if(x_<0 || y_<0 || x_>=N || y_>=N || mask[x_][y_] || vis[x_][y_])
            continue;
        SWP(p[x][y],p[x_][y_]);
        if(df(x_,y_,x0,y0))
            return 1;
        SWP(p[x][y],p[x_][y_]);
    }
    return 0;
}
bool getto(int x0,int y0)
{
    int x,y;
    getpos(0,x,y);
    memset(vis,0,sizeof(vis));
    return df(x,y,x0,y0);
}
bool mov(int v,int xv_,int yv_)
{
    int xv,yv;
    getpos(v,xv,yv);
    int dirx=xv_<xv?-1:1;
    int diry=yv_<yv?-1:1;
    for(;xv!=xv_ || yv!=yv_;)
    {
        int x0,y0;
        if(xv!=xv_ && !mask[xv+dirx][yv])
            x0=xv+dirx,y0=yv;
        else if(yv!=yv_ && !mask[xv][yv+diry])
            x0=xv,y0=yv+diry;
        else return 0;
        mask[xv][yv]=1;
        if(!getto(x0,y0))
            return 0;
        mask[xv][yv]=0;
        SWP(p[xv][yv],p[x0][y0]);
        xv=x0,yv=y0;
    }
    mask[xv_][yv_]=1;
    pt();
    return 1;
}
bool movl(int l)
{
    if(!mov(1+4*l,l,0) || !mov(2+4*l,l,1))
        return 0;
    if(!mov(3+4*l,l,3) || !mov(4+4*l,l+1,3))
        return 0;
    mask[l][3]=0;
    if(!mov(3+4*l,l,2))
        return 0;
    mask[1+4*l][3]=0;
    if(!mov(4+4*l,l,3))
        return 0;
    return 1;
}
bool check()
{
    if(!mov(1,0,0) || !mov(2,0,1) || !mov(3,0,2))
        return 0;
    if(!mov(3,1,2) && !mov(3,1,3) && !mov(3,0,3))
        return 0;
    return 1;
}
int main()
{
    freopen("in.txt","r",stdin);
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            scanf("%d",*(p+i)+j);
    printf("%s",(check()?"YES":"NO"));
    return 0;
}
