#include <cstdio>
#include <cstdlib>
#define N 4
#define M (N*N)
#define TRA(x,y) ((4*x+y+1)%M)
int nxt[M];
int p[N][N];
void prt()
{
    for(int i=0;i<N;++i)
        {for(int j=0;j<N;++j)
            printf("%d ",p[i][j]);
        printf("\n");}
}
int main()
{
    freopen("in.txt","w",stdout);
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j)
            p[i][j]=TRA(i,j);
    int step=1000009;
    int x=3,y=3;
    for(int i=0;i<step;++i)
    {
        int a,b,c;
        c=rand()%7;
        a=(c==0?0:(c>3?1:-1));
        c=rand()%3;
        b=(c==0?0:(c>4?1:-1));
        if(x+a<0 || x+a>=N)
            a=-a;
        if(y+b<0 || y+b>=N)
            b=-b;
        if(rand()%2)
        {
            if(a)
                b=0;
        }
        else if(b) a=0;
        //printf("%d %d %d %d %d %d\n",x,y,x+a,y+b,a,b);

        p[x][y]=p[x+a][y+b];
        p[x+a][y+b]=0;
        x+=a,y+=b;
    }
    prt();
    return 0;
}

