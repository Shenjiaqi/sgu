#include <cstdio>
#define N (10)
int p[N][3];
int ans;
int r1=0,r2;
int m,n;
void df(int mm,int ii)
{
    if(mm<=0)
    {
        ans=ii-1;
        printf("%d\n",ans);
    }
    else
    {
        if(ii+(mm+r1-1)/r1-1>=ans)
            return;
        bool w=0;
        for(int i=0;i<n;++i)
        {
            if(p[i][0] && p[i][2]<ii)
            {
                int tmp=p[i][2];
                p[i][2]=ii+p[i][1];
                df(mm-p[i][0],ii+1);
                p[i][2]=tmp;
                w=1;
            }
        }
        if(!w)
            df(mm,ii+1);
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;++i)
    {
        int tmp;
        scanf("%d%d",*(p+i),*(p+i)+1);
        if(p[i][0]>r1)
            r1=p[i][0],r2=p[i][1];
    }
    ans=(m/r1+1)*(r2+1);
    df(m,1);
    printf("%d",ans);
    return 0;
}
