#include <cstdio>
#define N (1000)
int p[N+1][N/32+2];
int q[N+1][2];
int rl,l;
int que[N+1],poi;
int list[N/32+2];
int head;
bool vis[N+1];
void makecircle(int rl)
{
    if(p[head][rl/32]&(1<<(rl%32)))
    {
        q[head][(q[head][0]?1:0)]=rl;
        q[rl][1]=head;
    }
    else
    {
        int v=q[head][q[head][0]?0:1];
        int u=head;
        for(int tmp;;tmp=u,u=v,v=(q[v][0]==tmp?q[v][1]:q[v][0]))
            if((p[v][head/32]&(1<<(head%32))) && (p[u][rl/32]&(1<<(rl%32))))
                break;
        q[head][q[head][0]?1:0]=v;
        q[v][(q[v][0]==u?0:1)]=head;
        q[rl][1]=u;
        q[u][(q[u][0]==v?0:1)]=rl;
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        for(;;)
        {
            int j;
            char t;
            if(EOF==scanf("%d%c",&j,&t))
                t='\n';
            p[i][j/32]|=(1<<(j%32));
            if(t=='\n')
                break;
        }
    rl=l=que[poi++]=1;
    head=1;
    list[0]|=2;
    for(int i=1;i<n;++i)
    {
        int j=0;
        if(!vis[l])
            for(;j<n/32+1;++j)
                if((list[j]&p[l][j])!=p[l][j])
                    break;
    //printf("%d\n",l);
        if(vis[l] || j>n/32)
        {
            vis[l]=1;
            l=que[--poi];
            --i;
            continue;
        }
        int k=j*32;
        for(int m=1;;m<<=1,++k)
            if(0==(m&list[j]) && (m&p[l][j]))
                break;
    //printf("!%d %d %d %d\n",rl,k,l,(int)(p[1][0]&2));
        if(rl==l)
        {
            q[l][1]=k;
        }
        else
        {
            makecircle(rl);
            head=q[l][0];
            q[head][q[head][0]==l?0:1]=0;
            q[l][0]=k;
        }
        q[k][0]=l;
        q[k][1]=0;
        que[poi++]=k;
        list[k/32]|=1<<(k%32);
        rl=l=k;
    }
    //return 0;
    makecircle(rl);
    for(int i=q[head][1];head!=1;)
    {
        int t=i;
        i=head;
        head=q[head][q[head][0]==t?1:0];
    }
    for(int i=0,j=q[head][1];i<=n;++i)
    {
        printf("%d ",head);
        int t=j;
        j=head;
        head=q[head][q[head][0]==t?1:0];
    }
    return 0;
}
