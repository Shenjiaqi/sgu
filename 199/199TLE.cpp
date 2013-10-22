#include <cstdio>
#include <cstdlib>
#include <unistd.h>
#define N 100000
int p[N][5];
int q[(N+2)*4][4];
void init(int a,int b,int l)
{
    if(l==1)
    {
        q[1][2]=-1;
        q[1][3]=1;
    }
    q[l][0]=a,q[l][1]=b;
    if(a<b)
    {
        init(a,(a+b)/2,2*l);
        init((a+b)/2+1,b,2*l+1);
    }
}
int get(int a,int b,int l)
{
    if(b<q[l][0] || a>q[l][1])
        return -1;
    if(q[l][3])
        return q[l][2];
    int tmp=get(a,b,2*l+1);
    if(tmp>=0)
        return tmp;
    return get(a,b,2*l);
}
bool set(int a,int b,int k,int l)
{
    if(a>q[l][1] || b<q[l][0])
        return 0;
    if(a<=q[l][0] && b>=q[l][1])
    {
        if(q[l][3])
        {
            if(q[l][2]<0 || p[q[l][2]][3]<p[k][3])
            {
                q[l][2]=k;
                return 1;
            }
            else return 0;
        }
    }
    if(q[l][3])
    {
        q[l*2][3]=q[l*2+1][3]=1;
        q[l*2+1][2]=q[l*2][2]=q[l][2];
    }
    q[l][3]=0;
    bool tmp=set(a,b,k,2*l);
    bool tmp2=set(a,b,k,2*l+1);
    if(tmp2 && tmp)
    {
        q[l][3]=1;
        q[l][2]=k;
        return 1;
    }
    return 0;
}
int cmp1(const void *a,const void *b)
{
    return (*((int*)a+1)-*((int*)b+1));
}
int cmp(const void *a,const void *b)
{
    int *c=(int*)a,*d=(int*)b;
    return (*c==*d?(*(d+1)-*(c+1)):(*c-*d));
}
void pt(int t)
{
    if(p[t][4]>=0)
        pt(p[t][4]);
    printf("%d ",p[t][2]+1);
}
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d %d",*(p+i),*(p+i)+1);
        p[i][2]=i;
    }
    qsort(p,n,sizeof(p[0]),cmp1);
    int vmax=0;
    for(int i=0,r=-1;i<n;++i)
    {
        if(p[i][1]!=r)
            ++vmax,r=p[i][1];
        p[i][1]=vmax;
    }
    qsort(p,n,sizeof(p[0]),cmp);
    init(1,vmax,1);
    int lmax=0,li;
    for(int i=0;i<n;++i)
    {
        int tmp,pre;
        pre=get(1,p[i][1],1);
        p[i][3]=pre>=0?p[pre][3]+1:1;
        p[i][4]=pre;
        if(p[i][3]>lmax)
            lmax=p[i][3],li=i;
        set(p[i][1]+1,vmax,i,1);
    }
    printf("%d\n",lmax);
    pt(li);
    return 0;
}
