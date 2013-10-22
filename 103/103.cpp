#include <stdio.h>

#define N 300
#define M 14000
#define INF (200*200*300+1)

int road[(M+1)*2][2],poi;
int p[N+1];
int time[N+1][4];
int t[N+1];
int c[N+1][N+1];
int pre[N+1];
bool cover[N+1];
int n,m;
int source,dest;

void pr(int i)
{
    if(pre[i])
    {
        pr(pre[i]);
        printf(" ");
    }
    printf("%d",i);
}

int remain(int now,int i,int &r)
{
    if(now<time[i][2])
    {
        r=time[i][2]-now;
        return time[i][3];
    }

    int t;

    t=(now-time[i][2])%(time[i][0]+time[i][1]);
    if(t<time[i][1-time[i][3]])
    {
        r=time[i][1-time[i][3]]-t;
        return (1-time[i][3]);
    }

    r=time[i][0]+time[i][1]-t;
    return time[i][3];
}

int wait(int now,int from,int to)
{
    if(time[from][3]!=time[to][3] &&
       time[from][2]==time[to][2] &&
       time[from][0]==time[to][1] &&
       time[from][1]==time[to][0])
        return INF;

    for(;;)
    {
        int r1,c1,r2,c2;

        c1=remain(now,from,r1);
        c2=remain(now,to,r2);
        if(c1==c2 || now>=INF)
            break;

        now+=(r1<r2?r1:r2);
    }

    return now;
}

int main()
{
    freopen("in.txt","r",stdin);

    scanf("%d %d\n%d %d",&source,&dest,&n,&m);

    for(int i=1;i<=n;++i)
    {
        char color;
        scanf("\n%c %d %d %d",&color,*(time+i)+2,*(time+i),*(time+i)+1);

        time[i][3]=((color=='B')?0:1);
    }

    for(int i=0;i<m;++i)
    {
        int f,t,cost;
        scanf("\n%d %d %d",&f,&t,&cost);

        c[f][t]=c[t][f]=cost;

        road[++poi][0]=f;
        road[poi][1]=p[t];
        p[t]=poi;

        road[++poi][0]=t;
        road[poi][1]=p[f];
        p[f]=poi;
    }

    for(int i=1;i<=n;++i)
        t[i]=INF;
    t[source]=0;
    for(;;)
    {
        int mint,minl;

        mint=INF;
        for(int i=1;i<=n;++i)
            if(cover[i]==0 && t[i]<mint)
                mint=t[i],minl=i;

        if(minl==dest || mint==INF)
            break;

        cover[minl]=1;

        for(int i=p[minl];i;i=road[i][1])
        {
            int j;

            j=road[i][0];
            if(cover[j]==0 && c[minl][j]+t[minl]<t[j])
            {
                int w=wait(t[minl],minl,j);
                if(c[minl][j]+w<t[j])
                    t[j]=c[minl][j]+w,pre[j]=minl;
            }
        }
    }
//for(int i=1;i<=n;++i)printf("!%d\n",t[i]);
    if(t[dest]==INF)
        printf("0");
    else
    {
        printf("%d\n",t[dest]);
        pr(dest);
    }

    return 0;
}
