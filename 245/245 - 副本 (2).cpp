#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
#define N (300)
int p[N][N];
int n,m;
int u[128];
int x,y;
int bonus[9];
int ans;
int pp[N][N];
int q[N][N];
int qq[N][N];
bool vis[N][N];
int maxv;
void maskp(int i,int j,int k)
{
    if(i>0)
    {
        if(j>0) q[i-1][j-1]+=k;
        if(j<m-1) q[i-1][j+1]+=k;
    }
}
void maskr(int i,int j,int l)
{
    for(int x=-1;x<2;++x)
        for(int y=-1;y<2;++y)
        {
            if((!x&&!y)||(x&&y))
                continue;
            for(int t1=x+i,t2=y+j;t1>=0&&t2>=0&&t1<n&&t2<m;t1+=x,t2+=y)
            {
                q[t1][t2]+=l;
                if(p[t1][t2]) break;
            }
        }
}
static const int cc[8][2]={{-1,-2},{-1,2},{-2,-1},{-2,1},{1,-2},{1,2},{2,-1},{2,1}};
void maskk(int i,int j,int k)
{
    for(int o=0;o<8;++o)
    {
        int t1=i+cc[o][0];
        int t2=j+cc[o][1];
        if(t1>=0 && t2>=0 && t1<n && t2<m)
            q[t1][t2]+=k;
    }
}
void maskm(int i,int j,int k)
{
    for(int r=-1;r<2;++r)
        for(int s=-1;s<2;++s)
        {
            if(!r && !s)
                continue;
            int t1=r+i,t2=s+j;
            if(t1>=0 && t2>=0 && t1<n &&t2<m)
                q[t1][t2]+=k;
        }
}
void maskb(int i,int j,int k)
{
    for(int dirx=-1;dirx<2;++dirx)
        if(dirx)
            for(int diry=-1;diry<2;++diry)
                if(diry)
                    for(int ii=i+dirx,jj=j+diry;ii>=0 && ii<n&& jj>=0 && jj<m;ii+=dirx,jj+=diry)
                    {
                        q[ii][jj]+=k;
                        if(p[ii][jj]) break;
                    }
}
void mask(int i,int j)
{
    switch(p[i][j])
    {
        case 2: maskp(i,j,1);break;
        case 3: maskr(i,j,1);break;
        case 4: maskk(i,j,1);break;
        case 5: maskb(i,j,1);break;
        case 6: maskb(i,j,1); maskr(i,j,1); break;
        case 7: maskm(i,j,1);break;
        default: break;
    }
}
void cal()
{
    for(int i=0;i<n;++i)
        for(int j=0;j<m;++j)
            if(p[i][j]>1)
                mask(i,j);
}
void umask(int a,int b)
{
    switch(p[a][b])
    {
        case 2: maskp(a,b,-1);break;
        case 3: maskr(a,b,-1);break;
        case 4: maskk(a,b,-1);break;
        case 5: maskb(a,b,-1);break;
        case 6: maskr(a,b,-1),maskb(a,b,-1);break;
        case 7: maskm(a,b,-1);break;
        default: break;
    }
}
void dfm(int a,int b)
{
    if(pp[a][b])
        maxv+=bonus[pp[a][b]],pp[a][b]=0,umask(a,b);

    for(int i=-1;i<=1;++i)
        for(int j=-1;j<=1;++j)
        {
            if(!i &&!j) continue;
            int t1=a+i,t2=b+j;
            if(t1>=0 && t1<n && t2>=0 && t2<m && pp[t1][t2]!=1 )
            {
                if(!q[t1][t2] && !vis[t1][t2])
                {
                    vis[t1][t2]=1;
                    dfm(t1,t2);
                }
                else if(q[t1][t2])
                    ans=max(ans,maxv+bonus[pp[t1][t2]]-bonus[8]);
            }
        }
}
void dfk(int a,int b)
{
    if(pp[a][b])
        maxv+=bonus[pp[a][b]],pp[a][b]=0,umask(a,b);

    /*for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
            printf("%d ",(int)pp[i][j]);
        printf("\n");
    }printf("%d %d %d\n\n",maxv,a,b);*/
    for(int i=0;i<8;++i)
    {
        int t1=cc[i][0]+a;
        int t2=cc[i][1]+b;
        if(t1<n && t1>=0 && t2<m&&t2>=0 && pp[t1][t2]!=1 )
        {
            if(!q[t1][t2] && !vis[t1][t2])
            {
                vis[t1][t2]=1;
                dfk(t1,t2);
            }
            else if(q[t1][t2])
                ans=max(ans,maxv+bonus[pp[t1][t2]]-bonus[8]);
        }
    }
}
void dfb(int a,int b)
{
    if(pp[a][b])
        maxv+=bonus[pp[a][b]],pp[a][b]=0,umask(a,b);

    for(int dx=-1;dx<2;++dx)
        if(dx)
            for(int dy=-1;dy<2;++dy)
                if(dy)
                    for(int i=a+dx,j=b+dy;i>=0 && i<n && j>=0 && j<m;i+=dx,j+=dy)
                    {
                        if(pp[i][j]==1 || vis[i][j])
                            break;
                        if(!q[i][j])
                        {
                            vis[i][j]=1;
                            dfb(i,j);
                            break;
                        }
                        else
                            ans=max(ans,maxv+bonus[pp[i][j]]-bonus[8]);
                        if(pp[i][j])
                            break;
                    }
}
void dfr(int a,int b)
{
    if(pp[a][b])
        maxv+=bonus[pp[a][b]],pp[a][b]=0,umask(a,b);
    for(int dx=-1;dx<2;++dx)
        for(int dy=-1;dy<2;++dy)
        {
            if((!dx&&!dy) || (dy &&dx))
                continue;
            //printf("%d %d\n",dx,dy);
            for(int i=a+dx,j=b+dy;i>=0&&j>=0&&i<n&&j<m;i+=dx,j+=dy)
            {
                if(pp[i][j]==1 || vis[i][j])
                    break;
                if(q[i][j])
                    ans=max(ans,maxv+bonus[pp[i][j]]-bonus[8]);
                else
                {
                    vis[i][j]=1;
                    dfr(i,j);
                    break;
                }
                if(pp[i][j])
                    break;
            }
        }
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d %d\n",&n,&m);
    u['.']=0,u['#']=1,u['@']=0;
    u['P']=2,u['R']=3,u['K']=4,
    u['B']=5,u['Q']=6,u['M']=7;
    for(int i=2;i<=8;++i)
        scanf("%d",bonus+i);
    for(int i=0;i<n;++i)
    {
        char t;
        scanf("%c",&t);
        for(int j=0;j<m;++j)
        {
            scanf("%c",&t);
            p[i][j]=u[t];
            if(t=='@')
                x=i,y=j;
        }
    }
    cal();
    memcpy(qq,q,sizeof(qq));
    /*
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
            printf("%d ",(int)q[i][j]);
        printf("\n");
    }*/

    memcpy(pp,p,sizeof(pp));
    maxv=0;
    for(int r=maxv;;)
    {
        dfk(x,y);
        memset(vis,0,sizeof(vis));
        if(r==maxv)
            break;
        r=maxv;
    }
    ans=max(maxv,ans);

    memcpy(pp,p,sizeof(pp));
    memcpy(q,qq,sizeof(qq));
    maxv=0;
    for(int r=maxv;;)
    {
        dfm(x,y);//
        memset(vis,0,sizeof(vis));
        if(r==maxv)
            break;
        r=maxv;
    }
    ans=max(maxv,ans);

    memcpy(pp,p,sizeof(pp));
    memcpy(q,qq,sizeof(qq));
    maxv=0;
    for(int r=maxv;;)
    {
        dfb(x,y);
        memset(vis,0,sizeof(vis));
        if(r==maxv)
            break;
        r=maxv;
    }
    ans=max(maxv,ans);

    memcpy(pp,p,sizeof(pp));
    memcpy(q,qq,sizeof(qq));
    maxv=0;
    for(int r=maxv;;)
    {
        dfr(x,y);
        memset(vis,0,sizeof(vis));
        if(r==maxv)
            break;
        r=maxv;
    }
    ans=max(maxv,ans);
    printf("%d",ans);
    return 0;
}
