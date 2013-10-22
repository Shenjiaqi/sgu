#include <cstdio>
#include <cstdlib>
#define N 101
int p[N][N];
void add(int i,int j)
{
    p[i][j]=p[j][i]=1;
}
int main()
{
    freopen("in.txt","w",stdout);
    int n;
    n=100;
    printf("%d\n",n);
    srand(n);
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
            if((rand()&7)<2)
                add(i,j);
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
            if(p[i][j])
                printf("%d ",j);
        printf("0\n");
    }
}
