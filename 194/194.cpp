#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 200
int p[N*N/2-N+1][4],n,m,S,T,q[N+3][N+3];
int in[N+1],out[N+1],s[N+3],d[N+3],an;
bool bfs()
{
    memset(s,0,sizeof(s));
    memset(d,0,sizeof(d));
    int que[N+3],f,l;
    que[0]=S,f=0,l=1;
    d[S]=1;
    for(;f<l;++f)
    {
        int t=que[f];
        for(int i=1;i<=T;++i)
            if(q[t][i]>0 && !d[i])
            {
                que[l++]=i;
                d[i]=d[t]+1;
            }
    }
    return d[T];
}
int dfs(int v,int f)
{
    if(v==T)
        return f;
    int r=f,i=s[v];
    for(;f>0 && i<=T;++i)
        if(q[v][i]>0 && d[v]+1==d[i])
        {
            int t=dfs(i,min(q[v][i],f));
            q[v][i]-=t;
            q[i][v]+=t;
            f-=t;
            if(f==0)
                break;
        }
    s[v]=i;
    return (r-f);
}
int mf()
{
    int r(0);
    for(;bfs();)
        for(int tmp;tmp=dfs(S,an);)
            r+=tmp;
    return r;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;++i)
    {
        int a,b;
        scanf("%d %d %d %d",*(p+i),*(p+i)+1,*(p+i)+2,*(p+i)+3);
        out[p[i][0]]+=p[i][2];
        in[p[i][1]]+=p[i][2];
        q[p[i][0]][p[i][1]]=p[i][3]-p[i][2];
    }
    S=n+1,T=n+2;
    for(int i=1;i<=n;++i)
        if(in[i]<out[i])
            q[i][T]=out[i]-in[i];
        else
        {
            q[S][i]=in[i]-out[i];
            an+=q[S][i];
        }
    if(mf()==an)
    {
        printf("YES");
        for(int i=0;i<m;++i)
            printf("\n%d",p[i][2]+q[p[i][1]][p[i][0]]);
    }
    else printf("NO");
    return 0;
}
