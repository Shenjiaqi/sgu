#include <stdio.h>

#define V 100
#define F 100
#define INF (50*100+1)

int p[F][V][2];
int a[F][V];
int f,v;

void wr(int k,int l)
{
    if(k<0)
        return ;

    wr(k-1,p[k][l][1]-1);

    printf("%d ",p[k][l][1]+1);
}

int main()
{
    freopen("in.txt","r",stdin);

    scanf("%d %d",&f,&v);
    for(int i=0;i<f;++i)
        for(int j=0;j<v;++j)
        {
            scanf("%d",a[i]+j);
            p[i][j][0]=-INF;
        }

    p[0][0][0]=a[0][0];
    p[0][0][1]=0;
    for(int i=1;i<v-f+1;++i)
        if(p[0][i-1][0]<a[0][i])
            p[0][i][0]=a[0][i],p[0][i][1]=i;
        else    p[0][i][0]=p[0][i-1][0],p[0][i][1]=p[0][i-1][1];

    for(int i=1;i<f;++i)
        for(int j=i;j<v-f+i+1;++j)
            if(p[i][j-1][0]<a[i][j]+p[i-1][j-1][0])
                p[i][j][0]=a[i][j]+p[i-1][j-1][0],
                p[i][j][1]=j;
            else    p[i][j][0]=p[i][j-1][0],
                    p[i][j][1]=p[i][j-1][1];

    printf("%d\n",p[f-1][v-1][0]);
    wr(f-2,p[f-1][v-1][1]-1);
    printf("%d",p[f-1][v-1][1]+1);

    return 0;
}
