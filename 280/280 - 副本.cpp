#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
#define N (30000)
int n,k;
int p[N*2+1][2],poi;
int s[N+1];
int d[N+1];
int que[N+1],l;
set<int> sett;
bool cover[N+1];
int find(int v,int l,int f)
{
    if(l<=0)
        return v;
    for(int i=s[v];i;i=p[i][1])
        if(p[i][0]!=f && !cover[p[i][0]])
            return find(p[i][0],l-1,v);
    return v;
}
void makecover(int v,int l,int f)
{
    if(!cover[v])
    {
        cover[v]=1;
        sett.erase(d[v]*(N+1)+v);
    }
    for(int i=s[v];i;i=p[i][1])
        if(p[i][0]!=f)
        {
            if(l>0)
                makecover(p[i][0],l-1,v);
            else if(!cover[p[i][0]])
            {
                sett.erase(d[p[i][0]]*(N+1)+p[i][0]);
                sett.insert((--d[p[i][0]])*(N+1)+p[i][0]);
            }
        }
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
        ++d[a],++d[b];
    }
    for(int i=1;i<=n;++i)
        sett.insert(d[i]*(N+1)+i);
    for(;!sett.empty();)
    {
        int v=*(sett.begin())%(N+1);
        int t=find(v,k,0);
        que[l++]=t;
        makecover(t,k,0);
    }
    printf("%d",l);
    for(int i=l-1;i>=0;--i)
        printf("\n%d",que[i]);
    return 0;
}
