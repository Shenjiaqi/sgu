#include <cstdio>
#include <algorithm>
using namespace std;
#define N (500000)
int p[N+1][3],n;
int q[N+1][2],s[N+1],qi;
int ans[N+1],an;
void df(int v)
{
    for(int i=s[v];i;i=q[i][1])
    {
        int tmp=q[i][0];
        df(tmp);
        int m=max(p[tmp][0],p[tmp][1]);
        if(i==s[v])
        {
            p[v][1]=p[tmp][0];
            p[v][2]=tmp;
        }
        else
        {
            p[v][1]+=m;
            if(p[v][1]<p[v][0]+p[tmp][0])
                p[v][2]=tmp,p[v][1]=p[v][0]+p[tmp][0];
        }
        p[v][0]+=m;
    }
    if(s[v])
        ++p[v][1];
}
void dfs(int v,int m)
{
    for(int i=s[v];i;i=q[i][1])
    {
        int tmp=q[i][0];
        if(m==1 && tmp==p[v][2])
        {
            ans[an++]=tmp;
            dfs(tmp,0);
        }
        else dfs(tmp,(p[tmp][0]>p[tmp][1]?0:1));
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=2;i<=n;++i)
    {
        int v;
        scanf("%d",&v);
        q[++qi][0]=i,q[qi][1]=s[v],s[v]=qi;
    }
    df(1);
    if(!p[1][0]&&!p[1][1])
        printf("0");
    else
    {
        if(p[1][0]>p[1][1])
            dfs(1,0);
        else dfs(1,1);
        sort(ans,ans+an);
        printf("%d000\n",max(p[1][0],p[1][1]));
        for(int i=0;i<an;++i)
            printf("%d ",ans[i]);
    }
    return 0;
}
