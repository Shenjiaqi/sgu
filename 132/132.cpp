#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t1[(1<<14)+1],t2[(1<<14)+1];
int *cost1=t1,*cost2=t2;
int m,n;
bool check(int v)
{
    for(int i=3;i<=v;i<<=1)
        if((i&v)==i)
            return 0;
    return 1;
}
void fill(int a,int b,int c,int l,int v,int o)
{
    if( (b&(l>>1)) && (b&(l>>2)) )
        return;
    if(l>=(1<<n))
    {
        cost2[(b<<n)|c]=min(cost2[(b<<n)|c],o+v);
    }
    else if(((a&b)&l))
    {
        if((c&l))
            fill(a,b^l,c^l,l<<1,v+1,o);
        else return;
    }
    else
    {
        if(((b&l)&c))
            fill(a,b^l,c^l,l<<1,v+1,o);
        if((c&l) && (c&(l<<1)))
            fill(a,b,(c^l)^(l<<1),l<<1,v+1,o);
        fill(a,b,c,l<<1,v,o);
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d %d",&m,&n);
    memset(cost1,1<<6,sizeof(t1));
    memset(cost2,1<<6,sizeof(t1));
    cost1[0]=0;
    for(int i=0;i<m;++i)
    {
        char t;
        scanf("%c",&t);
        int v=0;
        for(int j=0;j<n;++j)
        {
            scanf("%c",&t);
            v=(v<<1)|(t=='.'?1:0);
        }
        for(int j=0;j<(1<<n);++j)
            for(int k=0;k<(1<<n);++k)
                if(cost1[(j<<n)|k]<(1<<20))
                    fill(j,k,v,1,0,cost1[(j<<n)|k]);
        int *tmp=cost1;
        cost1=cost2,cost2=tmp;
        memset(cost2,1<<6,sizeof(t1));
    }
    int ans=1<<20;
    for(int i=0;i<(1<<n);++i)
        if(check(i))
            for(int j=0;j<(1<<n);++j)
                if(((i&j)==0) && check(j))
                    ans=min(ans,cost1[(i<<n)|j]);
    printf("%d",ans);
    return 0;
}
