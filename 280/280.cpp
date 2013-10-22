#include <cstdio>
#include <algorithm>
using namespace std;
#define N (30000)
#define K (100)
int n,k;
int p[N*2+1][2],poi;
int s[N+1];
int que[N+1],l;
int df(int v,int f)
{
    int rmax=-K-1,rmin=K+1;
    for(int i=s[v];i;i=p[i][1])
        if(p[i][0]!=f)
        {
            int t=df(p[i][0],v);
            rmax=max(rmax,t);
            rmin=min(rmin,t);
        }
    if(rmax==-K-1)
        return 1;
    if(rmin+rmax<0)
        return rmin+1;
    if(rmax<k)
        return rmax+1;
    que[l++]=v;
    return -k;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        p[++poi][0]=b,p[poi][1]=s[a],s[a]=poi;
        p[++poi][0]=a,p[poi][1]=s[b],s[b]=poi;
    }
    if(df(1,0)-1>=0)
        que[l++]=1;
    printf("%d",l);
    for(int i=0;i<l;++i)
        printf("\n%d",que[i]);
    return 0;
}
