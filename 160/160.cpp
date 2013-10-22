#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define N 10000
#define M 1000
int p[M][2];
int q[M][2];
int n,m;
void pt(int v)
{
    if(!v)
        return ;
    pt(q[v][1]);
    printf("%d ",q[v][0]);
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d %d",&n,&m);
    int ans(0);
    for(int i=1;i<=n;++i)
    {
        int t;
        scanf("%d",&t);
        t%=m;
        for(int j=1;j<m;++j)
            if(q[j][0] && !q[(t*j)%m][0])
            {
                p[(t*j)%m][0]=i,p[(t*j)%m][1]=j;
                ans=max(ans,(t*j)%m);
            }
        if(!p[t][0])
            p[t][0]=i,p[t][1]=0,ans=max(ans,t);
        memcpy(q,p,sizeof(q));
    }
    if(!ans)
        printf("1");
    else
    {
        printf("%d\n",ans);
        pt(ans);
    }
    return 0;
}
