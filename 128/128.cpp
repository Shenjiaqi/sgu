#include <cstdio>
#include <cstdlib>
#define N 10000
int p[N][3];
int r[N][2];
int l[N/2+1][3],poi;
int n;
int cmp1(const void *a,const void *b)
{
    int *c=(int*)a,*d=(int*)b;
    return ((*(c)==*(d))?(*(c+1)-*(d+1)):(*(c)-*(d)));
}int cmp2(const void *a,const void *b)
{
    int *c=(int*)a,*d=(int*)b;
    return ((*(c+1)==*(d+1))?(*(c)-*(d)):(*(c+1)-*(d+1)));
}
void add(int a,int b,int t)
{
    r[a][t]=b;
    r[b][t]=a;
}
bool check(int x1,int x2,int y)
{
    for(int i=0;i<poi;++i)
    {
        if(l[i][1]<=y || l[i][0]>=y || x2<=l[i][2] || x1>=l[i][2])
            continue;
        return 1;
    }
    return 0;
}
int tra()
{
    bool v[N]={0};
    v[0]=1;
    int c=1;
    for(int i=r[0][0];;)
    {
        if(v[i])
            return c;
        ++c;
        v[i]=1;
        i=v[r[i][0]]?r[i][1]:r[i][0];
    }
    return 0;
}
long long solv()
{
    if(n&1)
        return 0;
    qsort(p,n,sizeof(p[0]),cmp1);
    long long ans=0;
    for(int i=0;i<n;)
    {
        if(p[i][0]!=p[i+1][0])
            return 0;
        add(p[i][2],p[i+1][2],0);
        ans+=(long long)(p[i+1][1]-p[i][1]);
        l[poi][0]=p[i][1],l[poi][1]=p[i+1][1],l[poi][2]=p[i][0],++poi;
        i+=2;
    }
    qsort(p,n,sizeof(p[0]),cmp2);
    for(int i=0;i<n;)
    {
        if(p[i][1]!=p[i+1][1])
            return 0;
        add(p[i][2],p[i+1][2],1);
        ans+=(long long)(p[i+1][0]-p[i][0]);
        if(check(p[i][0],p[i+1][0],p[i][1]))
            return 0;
        i+=2;
    }
    if(tra()<n)
        return 0;
    return ans;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%d %d",*(p+i),*(p+i)+1);
        p[i][2]=i;
    }
    printf("%I64d",solv());
    return 0;
}
