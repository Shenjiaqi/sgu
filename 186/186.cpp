#include <cstdio>
#include <algorithm>
using namespace std;
#define N 100
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    int p[N];
    for(int i=0;i<n;++i)
        scanf("%d",p+i);
    sort(p,p+n);
    int ans=0;
    for(int i=0,j=n-1;i<j;++i)
        for(;i<j && p[i];--p[i])
        {
            p[j-1]+=p[j]+1;
            --j;
            ++ans;
        }
    printf("%d",ans);
    return 0;
}
