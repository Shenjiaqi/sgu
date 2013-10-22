#include <cstdio>
#include <set>
using namespace std;
#define N 6000
int p[N*2+1][7];
int n;
struct cmp
{
    bool operator()(const int a,const int b)
    {
        if(p[a][0]==p[b][0])
            return a<b;
        return (p[a][0]<p[b][0]);
    }
};
void pt(int v)
{
    if(v<n)
        printf("%d ",v+1);
    else
    {
        pt(p[v][1]);
        pt(p[v][2]);
    }
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d",&n);
    set<int,cmp> sett;
    for(int i=0;i<n;++i)
    {
        double t;
        scanf("%lf",&t);
        p[i][0]=(int)(t*1000000-2000000);
        p[i][5]=p[i][3]=max(p[i][0],0);
        p[i][6]=p[i][4]=min(p[i][0],0);
        if(p[i][0]>100000 || p[i][0]<-100000)
        {
            printf("no");
            return 0;
        }
        sett.insert(i);
    }
    printf("yes\n");
    for(int i=0;i<n-1;++i)
    {
        int a=*(sett.begin());
        int b=*(sett.rbegin());
        p[i+n][0]=p[a][0]+p[b][0];
        if(p[a][5]+p[b][3]>100000 || p[a][6]+p[b][4]<-100000)
            a^=b,b^=a,a^=b;
        p[i+n][1]=a;
        p[i+n][2]=b;
        p[i+n][3]=max(p[a][3],p[a][0]+p[b][3]);
        p[i+n][4]=min(p[a][4],p[a][0]+p[b][4]);
        p[i+n][5]=max(p[b][5],p[b][0]+p[a][5]);
        p[i+n][6]=min(p[b][6],p[b][0]+p[a][6]);
        sett.erase(a);
        sett.erase(b);
        sett.insert(i+n);
    }
    pt(*(sett.begin()));
    return 0;
}
