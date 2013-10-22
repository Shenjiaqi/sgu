#include <cstdio>
#define N 10000
int p[2*N+1][4];
int s[N+1];
int df(int v,int f)
{
    int r(0);
    for(int i=s[v];i;i=p[i][2])
    {
        if(p[i][0]==f)
            continue;
        if(!p[i][3])
            p[i][3]=df(p[i][0],v)+p[i][1];
        if(r<p[i][3])
            r=p[i][3];
    }
    return r;
}
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    int poi(0);
    for(int i=2;i<=n;++i)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        p[++poi][0]=a,p[poi][1]=b,p[poi][2]=s[i],s[i]=poi;
        p[++poi][0]=i,p[poi][1]=b,p[poi][2]=s[a],s[a]=poi;
    }
    for(int i=1;i<=n;++i)
        printf("%d\n",df(i,i));
    return 0;
}
