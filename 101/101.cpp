#include <stdio.h>

#define N 7

int n;
int degree[N]={0};
int seq[101],poi=0;
int p[N][N]={0};
int domino[100][2];

void wr()
{
    for(int f,t,i=1;i<poi;++i)
    {
        f=seq[i-1];
        t=seq[i];
        for(int j=0;j<n;++j)
        {
            if(f==domino[j][0]&&t==domino[j][1])
            {
                domino[j][0]=domino[j][1]=N;
                printf("%d +",1+j);
                break;
            }
            if(t==domino[j][0]&&f==domino[j][1])
            {
                domino[j][0]=domino[j][1]=N;
                printf("%d -",1+j);
                break;
            }
        }
        if(i<poi-1)
            printf("\n");
    }
}

void travel(int s)
{
    if(degree[s]>0)
        for(int i=0;i<N;++i)
            while(p[s][i]>0)
            {
                --degree[s],--degree[i];
                --p[s][i],--p[i][s];
                travel(i);
            }
    seq[poi++]=s;
}

int main()
{
    freopen("in.txt","r",stdin);

    scanf("%d",&n);

    for(int f,t,i=0;i<n;++i)
    {
        scanf("\n%d %d",&f,&t);

        domino[i][0]=f;
        domino[i][1]=t;
        ++p[f][t],++p[t][f];
        ++degree[f],++degree[t];
    }

    int start,odd;

    odd=0;
    start=domino[0][0];
    for(int i=0;i<N;++i)
        if(degree[i]&1)
            start=i,++odd;

    if(n==1)
        printf("1 +");
    else if(odd!=2 &&odd!=0)
        printf("No solution");
    else
    {
        travel(start);

        if(poi-1==n)
            wr();
        else printf("No solution");
    }

    return 0;
}
