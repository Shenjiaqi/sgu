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
//int list[N*N+1][2],poi;
int rr;
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
    for(int k=i-1;k>=0;--k)
    {
        q[k][j]+=l;
        if(p[k][j]) break;
    }
    for(int k=i+1;k<n;++k)
    {
        q[k][j]+=l;
        if(p[k][j]) break;
    }
    for(int k=j-1;k>=0;--k)
    {
        q[i][k]+=l;
        if(p[i][k]) break;
    }
    for(int k=j+1;k<m;++k)
    {
        q[i][k]+=l;
        if(p[i][k]) break;
    }
}
void maskk(int i,int j,int k)
{
    if(i>0)
    {
        if(j>=2) q[i-1][j-2]+=k;
        if(j<m-2) q[i-1][j+2]+=k;
        if(i>=2)
        {
            if(j>=1) q[i-2][j-1]+=k;
            if(j<m-1) q[i-2][j+1]+=k;
        }
    }
    if(i<n-1)
    {
        if(j>=2) q[i+1][j-2]+=k;
        if(j<m-2) q[i+1][j+2]+=k;
        if(i<n-2)
        {
            if(j>=1) q[i+2][j-1]+=k;
            if(j<m-1) q[i+2][j+1]+=k;
        }
    }
}
void maskm(int i,int j,int k)
{
    if(i>0)
    {
        q[i-1][j]+=k;
        if(j>0) q[i-1][j-1]+=k;
        if(j<m-1) q[i-1][j+1]+=k;
    }
    if(j>0) q[i][j-1]+=k;
    if(j<m-1) q[i][j+1]+=k;
    if(i<n-1)
    {
        q[i+1][j]+=k;
        if(j>0) q[i+1][j-1]+=k;
        if(j<m-1) q[i+1][j+1]+=k;
    }
}
void maskb(int i,int j,int k)
{
    for(int ii=i+1,jj=j+1;ii<n&&jj<m;++ii,++jj)
    {
        q[ii][jj]+=k;
        if(p[ii][jj]) break;
    }
    for(int ii=i-1,jj=j-1;ii>=0 && jj>=0;--ii,--jj)
    {
        q[ii][jj]+=k;
        if(p[ii][jj]) break;
    }
    for(int ii=i+1,jj=j-1;ii<n&&jj>=0;++ii,--jj)
    {
        q[ii][jj]+=k;
        if(p[ii][jj]) break;
    }
    for(int ii=i-1,jj=j+1;ii>=0&&jj<m;--ii,++jj)
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
            if(pp[i][j]>1)
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
void dfp(int a,int b,int v)
{
    maxv=max(maxv,v);
    /*if(p[a][b]==1)
        return;*/
    if(a>=n-1)
        return;
    for(int i=-1;i<2;++i)
        if(b+i>=0 && b+i<m)
        {
            int t=b+i;
            if(q[a+1][t])
            {
                int tmp=bonus[pp[a+1][t]]-bonus[8];
                if(tmp<0)
                    tmp=0;
                maxv=max(maxv,v+tmp);
            }
            else
            {
                int r=0;
                if(pp[a+1][t] && i!=0)
                {
                    umask(a+1,t);
                    dfp(a+1,t,v+bonus[pp[a+1][t]]);
                    mask(a+1,t);
                }
                if(!i)
                    dfp(a+1,t,v);
            }
        }
}
void dfr(int a,int b)
{
    /*if(pp[a][b]==1)
        return;*/
    vis[a][b]=1;
    if(pp[a][b]>2)
        maxv+=bonus[pp[a][b]],pp[a][b]=0,umask(a,b);
    for(int i=-1;i<=1;++i)
        for(int j=-1;j<=1;++j)
            if(i==0 || j==0)
            {
                int t1=a+i,t2=b+j;
                if(t1>=0 && t1<n && t2>=0 && t2<m)
                {
                    if(!q[t1][t2] && !vis[t1][t2])
                        dfr(t1,t2);
                    else if(q[t1][t2])
                        rr=max(rr,bonus[pp[t1][t2]]-bonus[8]);//[poi][0]=t1,list[poi][1]=t2,++poi;
                }
            }
}
/*
int re()
{
    int r=0;
    for(int i=0;i<poi;++i)
        r=max(r,bonus[p[list[i][0]][list[i][1]]]-bonus[8]);
    return r;
}*/
void dfm(int a,int b)
{
    //printf("%d %d %d\n",a,b,(int)vis[a][b]);
    /*if(pp[a][b]==1)
        return;*/
    vis[a][b]=1;
    if(pp[a][b]>2)
        maxv+=bonus[pp[a][b]],pp[a][b]=0,umask(a,b);
    for(int i=-1;i<=1;++i)
        for(int j=-1;j<=1;++j)
        {
            int t1=a+i,t2=b+j;
            if(t1>=0 && t1<n && t2>=0 && t2<m)
            {
                if(!q[t1][t2] && !vis[t1][t2])
                    dfm(t1,t2);
                else if(q[t1][t2])
                    rr=max(rr,bonus[pp[t1][t2]]-bonus[8]);//list[poi][0]=t1,list[poi][1]=t2,++poi;
            }
        }
}
void dfb(int a,int b)
{
    /*if(pp[a][b]==1)
        return;*/
    vis[a][b]=1;
    if(pp[a][b])
        maxv+=bonus[pp[a][b]],pp[a][b]=0,umask(a,b);
    for(int i=-1;i<=1;++i)
        if(i)
            for(int j=-1;j<=1;++j)
                if(j)
                {
                    int t1=a+i,t2=b+j;
                    if(t1>=0 && t1<n && t2>=0 && t2<m)
                    {
                        if(!q[t1][t2] && !vis[t1][t2])
                            dfb(t1,t2);
                        else if(q[t1][t2])
                            rr=max(rr,bonus[pp[t1][t2]]-bonus[8]);//list[poi][0]=t1,list[poi][1]=t2,++poi;
                    }
                }
}
void dfk(int a,int b)
{
    /*if(pp[a][b]==1)
        return;*/
    vis[a][b]=1;
    if(pp[a][b])
        maxv+=bonus[pp[a][b]],pp[a][b]=0,umask(a,b);
    if(a>0)
    {
        if(b>1)
        {
            if(!q[a-1][b-2] && !vis[a-1][b-2])
                dfk(a-1,b-2);
            else if(q[a-1][b-2])
                rr=max(rr,bonus[pp[a-1][b-2]]-bonus[8]);//list[poi][0]=a-1,list[poi][1]=b-2,++poi;
        }
        if(b<m-2)
        {
            if(!q[a-1][b+2] && !vis[a-1][b+2])
                dfk(a-1,b+2);
            else if(q[a-1][b+2])
                rr=max(rr,bonus[pp[a-1][b+2]]-bonus[8]);//list[poi][0]=a-1,list[poi][1]=b+2,++poi;
        }
        if(a>1)
        {
            if(b>0)
            {
                if(!q[a-2][b-1] && !vis[a-2][b-1])
                    dfk(a-2,b-1);
                else if(q[a-2][b-1])
                    rr=max(rr,bonus[pp[a-2][b-1]]-bonus[8]);//list[poi][0]=a-2,list[poi][1]=b-1,++poi;
            }
            if(b<m-1)
            {
                if(!q[a-2][b+1] && !vis[a-2][b+1])
                    dfk(a-2,b+1);
                else if(q[a-2][b+1])
                    rr=max(rr,bonus[pp[a-2][b+1]]-bonus[8]);//list[poi][0]=a-2,list[poi][1]=b+1,++poi;
            }
        }
    }
    if(a<n-1)
    {
        if(b>1)
        {
            if(!q[a+1][b-2] && !vis[a+1][b-2])
                dfk(a+1,b-2);
            else if(q[a+1][b-2])
                rr=max(rr,bonus[pp[a+1][b-2]]-bonus[8]);//list[poi][0]=a+1,list[poi][1]=b-2,++poi;
        }
        if(b<m-2)
        {
            if(!q[a+1][b+2] && !vis[a+1][b+2])
                dfk(a+1,b+2);
            else if(q[a+1][b+2])
                rr=max(rr,bonus[pp[a+1][b+2]]-bonus[8]);//list[poi][0]=a+1,list[poi][1]=b+2,++poi;
        }
        if(a<n-2)
        {
            if(b>0)
            {
                if(!q[a+2][b-1] && !vis[a+2][b-1])
                    dfk(a+2,b-1);
                if(q[a+2][b-1])
                    rr=max(rr,bonus[pp[a+2][b-1]]-bonus[8]);//list[poi][0]=a+2,list[poi][1]=b-1,++poi;
            }
            if(b<m-1)
            {
                if(!q[a+2][b+1] && !vis[a+2][b+1])
                    dfk(a+2,b+1);
                if(q[a+2][b+1])
                    rr=max(rr,bonus[pp[a+2][b+1]]-bonus[8]);//list[poi][0]=a+2,list[poi][1]=b+1,++poi;
            }
        }
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d %d\n",&n,&m);
    u['.']=0,u['#']=1,u['@']=0;
    u['P']=2,u['R']=3,u['K']=4,u['B']=5,u['Q']=6,u['M']=7;
    {
        char t;
        for(int i=2;i<=8;++i)
            scanf("%d%c",bonus+i,&t);
    }
    for(int i=0;i<n;++i)
    {
        char t;
        for(int j=0;j<m;++j)
        {
            scanf("%c",&t);
            p[i][j]=u[t];
            if(t=='@')
                x=i,y=j;
        }
        scanf("%c",&t);
    }
    memcpy(pp,p,sizeof(pp));
    cal();

    for(int i=0;i<n;++i)
    {
        for(int j=0;j<m;++j)
            printf("%d",(int)q[i][j]);
        printf("\n");
    }
    if(q[x][y])
    {
        printf("0");
        return 0;
    }

    memcpy(qq,q,sizeof(qq));
    maxv=0;
//
    dfp(x,y,0);
    ans=max(ans,maxv);

    maxv=0;
    for(int r=maxv;!q[x][y];)
    {
        //poi=0;//
        rr=0;
        dfr(x,y);
        memset(vis,0,sizeof(vis));
        if(r==maxv)
            break;
        r=maxv;
    }
    maxv+=rr;//re();
    ans=max(ans,maxv);

    memcpy(pp,p,sizeof(pp));
    maxv=0;
    memcpy(q,qq,sizeof(qq));
    for(int r=maxv;;)
    {
        //poi=0;//
        rr=0;
        dfk(x,y);
        memset(vis,0,sizeof(vis));
        if(r==maxv)
            break;
        r=maxv;
    }
    maxv+=rr;//re();
    ans=max(maxv,ans);

    memcpy(pp,p,sizeof(pp));
    maxv=0;
    memcpy(q,qq,sizeof(qq));
    //memset(vis,0,sizeof(vis));
    for(int r=maxv;;)
    {
        rr=0;//poi=0;
        dfm(x,y);//
        memset(vis,0,sizeof(vis));
        if(r==maxv)
            break;
        r=maxv;
    }
    maxv+=rr;//re();
    ans=max(maxv,ans);

    memcpy(pp,p,sizeof(pp));
    maxv=0;
    memcpy(q,qq,sizeof(qq));
    //memset(vis,0,sizeof(vis));
    for(int r=maxv;;)
    {
        rr=0;//poi=0;
        dfb(x,y);//
        memset(vis,0,sizeof(vis));
        if(r==maxv)
            break;
        r=maxv;
    }
    maxv+=rr;//re();
    ans=max(maxv,ans);

    printf("%d",ans);
    return 0;
}
