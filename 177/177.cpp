#include <cstdio>
#define M 5000
int p[M][5];
int ans;
int n,m;
void df(int x1,int y1,int x2,int y2,int l)
{
    if(x1>x2 || y1>y2)
        return;
    if(l>=m)
        ans+=(x2-x1+1)*(y2-y1+1);
    else
    {
        if(!(x1>p[l][2]||y1>p[l][3]||x2<p[l][0]||y2<p[l][1]))
        {
            if(x1<p[l][0])
            {
                df(x1,y1,p[l][0]-1,y2,l+1);
                x1=p[l][0];
            }
            if(y1<p[l][1])
            {
                df(x1,y1,x2,p[l][1]-1,l+1);
                y1=p[l][1];
            }
            if(x2>p[l][2])
            {
                df(p[l][2]+1,y1,x2,y2,l+1);
                x2=p[l][2];
            }
            if(y2>p[l][3])
            {
                df(x1,p[l][3]+1,x2,y2,l+1);
                y2=p[l][3];
            }
            if(p[l][4]==(int)'w')
                ans+=(x2-x1+1)*(y2-y1+1);
        }
        else df(x1,y1,x2,y2,l+1);
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d %d",&n,&m);
    for(int i=m-1;i>=0;--i)
    {
        char c;
        scanf("%d %d %d %d %c",*(p+i),*(p+i)+1,*(p+i)+2,*(p+i)+3,&c);
        if(p[i][0]>p[i][2])
            p[i][0]^=p[i][2],p[i][2]^=p[i][0],p[i][0]^=p[i][2];
        if(p[i][1]>p[i][3])
            p[i][1]^=p[i][3],p[i][3]^=p[i][1],p[i][1]^=p[i][3];
        p[i][4]=c;
    }
    df(1,1,n,n,0);
    printf("%d",ans);
    return 0;
}
