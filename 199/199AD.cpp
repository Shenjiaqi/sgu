#include <cstdio>
#include <cstdlib>
#define max(a,b) ((a)>(b)?(a):(b))
#define N 100000
int p[N+1][4];
int q[N+1];
int cmp(const void *a,const void *b)
{
    int *c=(int*)a,*d=(int*)b;
    return (*c==*d?(*(d+1)-*(c+1)):(*c-*d));
}
void pt(int t)
{
    if(p[t][3]>0)
        pt(p[t][3]);
    printf("%d ",p[t][2]);
}
int que(int l,int r)
{
    return p[r][3];
}
void modify(int f,int t,int v)
{
    for(int i=f;i<=t;i+=i&(-i))
        if(p[q[i]][3]<p[v][3])
            q[i]=v;
}
int pos(int a,int f,int l)
{
    for(--l;f<=l;)
    {
        int mid=(f+l)>>1;
        if(p[q[mid]][1]==p[a][1])
            return mid;
        if(p[q[mid]][1]<p[a][1])
            f=mid+1;
        else l=mid-1;
    }
    return f;
}
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d %d",*(p+i),*(p+i)+1);
        p[i][2]=i;
    }
    qsort(p+1,n,sizeof(p[0]),cmp);
    int lmax=0,li,l=1;
    q[0]=0;
    for(int i=1;i<=n;++i)
    {
        if(i && p[i][0]==p[i][0] && p[i][1]==p[i-1][1])
            continue;
        int tmp=pos(i,0,l);
        q[tmp]=i;
        if(tmp==l)
            li=i,++l;
        p[i][3]=q[tmp-1];
    }
    printf("%d\n",l-1);
    pt(q[l-1]);
    return 0;
}
