#include <cstdio>
#include <set>
#include <cstring>
using namespace std;
#define N (100)
#define K (500)
class itm
{
public:
    int len,pre,id;
    int pa[4];
}p[N*K+N+1];
int n,m,k;
int pp;
int time[N+1];
int q[N*N*2+1][3],s[N+1],poi,S,T;
int plen[N+1];
struct cmp
{
    bool operator()(const int a,const int b)
    {
        int c=p[a].len+plen[p[a].id];
        int d=p[b].len+plen[p[b].id];
        if(c==d)
            return a<b;
        return (c<d);
    }
};
set<int,cmp> sett;
void add(int f,int t,int c)
{
    q[++poi][0]=t,q[poi][2]=c,q[poi][1]=s[f],s[f]=poi;
    q[++poi][0]=f,q[poi][2]=c,q[poi][1]=s[t],s[t]=poi;
}
void pt(int v,int l)
{
    if(p[v].id!=S)
        pt(p[v].pre,1+l);
    else printf("%d\n",l);
    printf("%d ",p[v].id);
}
bool check(int v,int u)
{
    return (p[v].pa[u/32]&(1<<(u%32)));
}
void sp()
{
    bool vis[N+1]={0};
    memset(plen,1<<6,sizeof(plen));
    plen[T]=0;
    for(;;)
    {
        int v,minl=1<<30;
        for(int i=1;i<=n;++i)
            if(!vis[i] && minl>plen[i])
                v=i,minl=plen[i];
        if(minl==(1<<30))
            break;
        vis[v]=1;
        for(int i=s[v];i;i=q[i][1])
            if(!vis[q[i][0]] && plen[q[i][0]]>minl+q[i][2])
                plen[q[i][0]]=minl+q[i][2];
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d %d %d",&n,&m,&k);
    for(int i=0;i<m;++i)
    {
        int x,y,mon;
        scanf("%d %d %d",&x,&y,&mon);
        add(x,y,mon);
    }
    scanf("%d %d",&S,&T);
    sp();
    pp=1;
    p[0].id=S;
    p[0].pa[S/32]|=(1<<(S%32));
    sett.insert(0);
    for(;;)
    {
        int v=(*sett.begin());
        int vv=p[v].id;
        ++time[vv];
        if(time[vv]==k)
            break;
        for(int i=s[vv];i;i=q[i][1])
            if(!check(v,q[i][0]))
            {
                memcpy(p+pp,p+v,sizeof(p[0]));
                p[pp].len+=q[i][2];
                p[pp].pre=v;
                p[pp].id=q[i][0];
                p[pp].pa[q[i][0]/32]|=(1<<(q[i][0]%32));
                sett.insert(pp);
                if(sett.size()>N*K)
                {
                    set<int,cmp>::iterator ite=sett.end();
                    --ite;
                    sett.erase(ite);
                }
                ++pp;
            }
        sett.erase(v);
    }
    int t=*(sett.begin());
    printf("%d ",p[t].len+plen[p[t].id]);
    pt(t,1);
    return 0;
}
