#include <cstdio>
#include <algorithm>
using namespace std;
#define N (10)
#define M (100)
int p[N][3],q[M+1];
int m,n,l;
bool test(int left,int mi)
{
    if(left<=0)
        return true;
    if(mi>l || mi-1+q[left]>l)
        return false;
    bool w=1;
    for(int i=0;i<n;++i)
        if(p[i][2]<mi && p[i][0])
        {
            if(i && p[i-1][2]<mi && p[i][0]==p[i-1][0] && p[i][1]==p[i-1][1])
                continue;
            int r=p[i][2];
            p[i][2]=mi+p[i][1];
            if(test(left-p[i][0],mi+1))
                return 1;
            p[i][2]=r;
            w=false;
        }
    if(w)
        return test(left,mi+1);
    return false;
}
int cmp( int a, int b)
{
    if(p[a][0]!=p[b][0])
        return p[a][0]>p[b][0];
    if(p[a][1]!=p[b][1])
        return p[a][1]<p[b][1];
    return a<b;
}
void swp(int a,int b)
{
    int tmp;
    tmp=p[b][0],p[b][0]=p[a][0],p[a][0]=tmp;
    tmp=p[b][1],p[b][1]=p[a][1],p[a][1]=tmp;
    tmp=p[b][2],p[b][2]=p[a][2],p[a][2]=tmp;
}
int uu(int mm)
{
    int a,b,r;
    for(a=q[mm-1],b=((mm+p[0][0]-1)/p[0][0])*(p[0][1]+1);a<=b;)
    {
        l=(a+b)/2;
        int tmp=test(mm,1);
        //printf("!!!%d %d\n",tmp,l);
        if(tmp)
            b=l-1,r=l;
        else a=l+1;
        for(int i=0;i<n;++i)
            p[i][2]=0;
    }
    return r;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&m,&n);
    for(int i=0;i<n;++i)
        scanf("%d%d",*(p+i),*(p+i)+1);
    for(int i=0;i<n;++i)
        for(int j=n-1;j>i;--j)
            if(!cmp(j-1,j))
                swp(j-1,j);
    if(n>5)
        n=5;
    for(int i=1;i<=m;++i)
        q[i]=uu(i);
    printf("%d",q[m]);
    return 0;
}
