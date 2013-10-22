#include <cstdio>
#define N (1000)
#define S ((N+32-1)/32+1)
int q[N+1][S];
int p[N+1][2];
int df(int i,int l,int f)
{
    int u=(p[i][0]==l?1:0);
    if(p[i][u]==f)
        return i;
    return df(p[i][u],i,f);
}
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    int r=0;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        for(char t;;)
        {
            int j;
            if(EOF==scanf("%d%c",&j,&t))
                t='\n';
            q[i][j/32]|=1<<(j%32);
            if(t=='\n')
                break;
        }
        if(q[i][0]&2)
            r=i;
    }
    int list[S]={0};
    int l=1,rl;
    list[0]|=1<<1;
    int que[N+1],poi;
    que[0]=1,poi=1;
    bool vis[N+1]={0};
    vis[r]=1;
    for(int i=1;i<n;++i)
    {
        int j;
        rl=l;
        for(int kk=poi-1;kk>=0;)
        {
            j=0;
            if(vis[l])
                for(;j<S;++j)
                    if((list[j]&q[l][j])!=q[l][j])
                        break;
            if(!vis[l] && j!=S)
                break;
            vis[l]=1;
            for(;;--kk)
                if(q[l][que[kk]/32]&(1<<(que[kk]%32)))
                    break;
            l=que[kk];
        }
        int k=(j-1)*32;
        for(int c=1;;c<<=1,++k)
            if((q[l][j]&c) && !(list[j]&c))
                break;
        que[poi++]=k;
        list[k/32]|=(1<<(k%32));
        p[k][0]=l;
        p[k][1]=0;
        if(rl==l)
        {
            if(p[l][1])
                p[l][0]=k;
            else p[l][1]=k;
        }
        else
        {
            int r1=p[l][0],r2=p[l][1];
            p[l][0]=k;
            p[l][1]=rl;
            int u=df(rl,0,l);
            if(u==r1)
                u=r2;
            else u=r1;
            if(p[rl][0])
                p[rl][1]=u;
            else p[rl][0]=u;
        }
    }

    rl=l=que[poi-1];
    for(int i=2;;)
    {
        if(!(q[l][r/32]&(r%32)))
        {
            for(;!(q[rl][i/32]&(1<<(i%32)));++i)
                ;
            l=i;
        }
        else
        {
            if(l==rl)
            {
                p[l][1]=r;
            }
            else
            {
                int r1=p[rl][0],r2=p[rl][1];
                p[rl][0]=1;
                p[rl][1]=l;
                u=df(rl,0,l);
                if(u==r1)
            }
        }
    }
}
