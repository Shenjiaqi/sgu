#include <cstdio>
#include <set>
#include <cstring>
using namespace std;
#define N (13)
int n,p[N+1];
long long ans;
int swap(int &a,int &b)
{
    int tmp=a;
    a=b,b=tmp;
}
bool test()
{
    static int q[N+1];
    static int pos[N+1];
    memcpy(q,p,sizeof(q));
    for(int i=0;i<=N;++i)
        pos[q[i]]=i;
    for(;;)
    {
        int i=0;
        for(;i<=N;++i)
            if(q[i]!=i)
                break;
        if(i>N)
            return 1;
        int pos13=pos[N];
        int v=q[pos[N]-1]+1;
        if(v>=N)
            return 0;
        int vpos=pos[v];
        swap(q[vpos],q[pos13]);
        swap(pos[N],pos[v]);
    }
    return 0;
}
void df(int k)
{
    if(k==N)
    {
        if(test())
            ++ans;
    }
    else
        for(int i=k;i<=N;++i)
        {
            swap(p[k],p[i]);
            df(k+1);
            swap(p[k],p[i]);
        }
}
int main()
{
    scanf("%d",&n);
    //freopen("out.txt","w",stdout);
    for(int i=0;i<=N;++i)
        p[i]=i;
    df(N-n+1);
    printf("%lld",ans);
    return 0;
}
