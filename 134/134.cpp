#include <cstdio>
#include <algorithm>
using namespace std;
#define N (16000)
int p[N*2+1][3],poi,s[N+1],ans[N+1],mi;
int df(int v,int f)
{
    int r(1);
    for(int i=s[v];r-1<mi && i;i=p[i][1])
    {
        if(p[i][0]==f)
            continue;
        if(p[i][2]<0)
            p[i][2]=df(p[i][0],v);
        r+=p[i][2];
    }
    return r;
}
int test(int v)
{
    int r=0;
    for(int i=s[v];r-1<mi && i;i=p[i][1])
    {
        if(p[i][2]<0)
            p[i][2]=df(p[i][0],v);
        r=max(r,p[i][2]);
    }
    return r;
}
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=1;i<n;++i)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        p[++poi][0]=b,p[poi][1]=s[a],p[poi][2]=-1,s[a]=poi;
        p[++poi][0]=a,p[poi][1]=s[b],p[poi][2]=-1,s[b]=poi;
    }
    int ai(0);
    mi=n+1;
    for(int i=1;i<=n;++i)
    {
        int t=test(i);
        if(mi>=t)
        {
            if(mi>t)
            {
                mi=t;
                ai=0;
            }
            ans[ai++]=i;
        }
    }
    printf("%d %d",mi,ai);
    for(int i=0;i<ai;++i)
        printf("\n%d",ans[i]);
    return 0;
}
