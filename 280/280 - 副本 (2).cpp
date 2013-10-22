#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
#define N (30000)
int n,k;
int p[N*2+1][3],poi;
int s[N+1];
int d[N+1];
set<int,greater<int> > sett;
bool cover[N+1];
int df(int v,int f)
{
    int r(0);
    int m2,k;
    m2=0,k=-1;
    for(int i=s[v];i;i=p[i][1])
        if(p[i][0]!=f)
        {
            int tmp=((p[i][2])?p[i][2]:(p[i][2]=1+df(p[i][0],v)));
            if(tmp>=r)
                m2=r,r=tmp,k=i;
        }
    for(int i=s[v];i;i=p[i][1])
        p[(i&1)?(i+1):(i-1)][2]=1+(i==k?m2:r);
    return r;
}
int find(int v,int l,int f)
{
    if(l<=0)
        return v;
    for(int i=s[v];i;i=p[i][1])
        if(d[v]-1==d[p[i][0]])
            return find(p[i][0],l-1,v);
    return v;
}
void makecover(int v,int l,int f)
{
    //printf("!%d\n",v);
    cover[v]=1;
    if(l<=0)
        return;
    for(int i=s[v];i;i=p[i][1])
        if(p[i][0]!=f)
            makecover(p[i][0],l-1,v);

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
    for(int i=1;i<=n;++i)
    {
        d[i]=df(i,0);
        sett.insert(d[i]*(N+1)+i);
    }
    //for(int i=1;i<=n;++i)
      //  printf("%d ",d[i]);printf("\n");
    set<int,greater<int> >::iterator ite;
    ite=sett.begin();
    int que[N+1],l=0;
    for(;ite!=sett.end();++ite)
    {
        int v=(*ite)%(N+1);
        if(!cover[v])
        {
            int tmp=find(v,min(k,d[v]),0);

   // printf("!%d %d\n",v,d[v]);
            que[l++]=tmp;
            makecover(tmp,k,0);
        }
    }
    printf("%d",l);
    for(int i=0;i<l;++i)
        printf("\n%d",que[i]);
    return 0;
}
