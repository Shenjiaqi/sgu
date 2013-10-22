#include <cstdio>
#include <algorithm>
using namespace std;
#define N 65537
int p[N],*q[N];
unsigned int r[N+1];
int n;
void add(int v)
{
    for(int i=v;i<=n;i+=(i&(-i)))
        ++r[i];
}
unsigned int que(int v)
{
    unsigned int a(0);
    for(int i=v;i;i-=(i&(-i)))
        a+=r[i];
    return a;
}
bool cmp(const int *a,const int *b)
{
    return (*a<*b);
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d",p+i);
        q[i]=p+i;
    }
    sort(q,q+n,cmp);
    for(int i=0,j=0,r=-1;i<n;++i)
        if(*q[i]!=r)
            r=*q[i],*q[i]=++j;
        else *q[i]=j;
    unsigned int ans(0);
    for(int i=0;i<n;++i)
    {
        ans+=i-que(p[i]);
        add(p[i]);
    }
    printf("%u",ans);
    return 0;
}
