#include <cstdio>
#include <algorithm>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    int n,m;
    scanf("%d%d",&n,&m);
    int ans(0);
    for(int i=0;i<n;++i)
    {
        int t,r;
        scanf("%d",&t);
        r=1;
        for(int j=0;j<m;++j)
            r*=t;
        ans+=max(0,r);
    }
    printf("%d",ans);
    return 0;
}
