#include <cstdio>
#define N (16000)
int p[N*2+1][3],n,poi;
int v[N+1],s[N+1];
int df(int u,int f)
{
    int r=v[u];
    for(int i=s[u];i;i=p[i][1])
    {
        if(p[i][0]==f)
            continue;
        if((1<<31)==p[i][2])
            p[i][2]=df(p[i][0],u);
        if(p[i][2]>0)
            r+=p[i][2];
    }
    return r;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",v+i);
    for(int i=1;i<n;++i)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        p[++poi][0]=b,p[poi][1]=s[a],s[a]=poi,p[poi][2]=1<<31;
        p[++poi][0]=a,p[poi][1]=s[b],s[b]=poi,p[poi][2]=1<<31;
    }
    int ans=1<<31;
    for(int i=1;i<=n;++i)
    {
        int a=df(i,0);
        if(a>ans)
            ans=a;
    }
    printf("%d",ans);
    return 0;
}
