#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
#define max(a,b) ((a)>(b)?(a):(b))
#define N 100000
int p[N+1][5];
int q[N+1];
/*
int cmp1(const void *a,const void *b)
{
    return (*((int*)a+1)-*((int*)b+1));
}*/
int cmp(const void *a,const void *b)
{
    int *c=(int*)a,*d=(int*)b;
    return (*c==*d?(*(d+1)-*(c+1)):(*c-*d));
}
void pt(int t)
{
    if(p[t][4]>0)
        pt(p[t][4]);
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
struct cmp2
{
    bool operator()(int a,int b)
    {
        return p[a][1]<p[b][1];
    }
};
set<int,cmp2 > sett;
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
    /*qsort(p+1,n,sizeof(p[0]),cmp1);
    int vmax=0;
    for(int i=1,r=-1;i<=n;++i)
    {
        if(p[i][1]!=r)
            ++vmax,r=p[i][1];
        p[i][1]=vmax;
    }*/
    qsort(p+1,n,sizeof(p[0]),cmp);
    int lmax=0,li;
    sett.insert(0);
    for(int i=1;i<=n;++i)
    {
        set<int,cmp2>::iterator ite1,ite2;
        ite1=ite2=sett.lower_bound(i);
        --ite1;
        if(ite2!=sett.end() && p[*ite2][1]==p[i][1])
            sett.erase(ite2);
        p[i][3]=p[p[i][4]=*ite1][3]+1;
        if(p[i][3]>lmax)
            lmax=p[i][3],li=i;
        ite1=sett.insert(i).first;
        for(++ite1;ite1!=sett.end() && p[i][3]>=p[*ite1][3];)
        {
            ite2=ite1;
            ++ite1;
            sett.erase(ite2);
        }
    }
    printf("%d\n",lmax);
    pt(li);
    return 0;
}
