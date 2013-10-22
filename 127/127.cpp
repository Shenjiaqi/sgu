#include <cstdio>
#include <algorithm>
using namespace std;
#define N 8000
int main()
{
    freopen("in.txt","r",stdin);
    int k,n,p[N];
    scanf("%d %d",&k,&n);
    for(int i=0;i<n;++i)
        scanf("%d",p+i);
    sort(p,p+n);
    int ans(2);
    for(int i(0),l(0),r(0);i<n;++i)
    {
        if(r!=p[i]/1000)
        {
            ++ans;
            r=p[i]/1000;
            l=0;
        }
        if(l+1>k)
        {
            ++ans;
            l=0;
        }
        ++l;
    }
    printf("%d",ans);
    return 0;
}
