#include <cstdio>
#include <set>
using namespace std;
#define N 15000
int p[N+1][4];
struct cmp
{
    bool operator()(const int a,const int b)
    {
        if(p[a][0]==p[b][0])
                return a<b;
        return p[a][0]>p[b][0];
    }
};
set<int,cmp> sett;
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d %d %d",*(p+i),*(p+i)+1,*(p+i)+2);
        p[i][3]=p[i][0]+p[i-1][3];
        p[i][0]=p[i][3]-p[i][1];
    }
    int ans=n,cmax=p[n][2]+1;
    for(int i=n,cost=0;i>0;--i)
    {
        cost+=p[i][2];
        sett.insert(i);
        for(set<int,cmp>::iterator ite=sett.begin(),itmp;ite!=sett.end();)
        {
            int k=*ite;
            if(p[k][0]>p[i-1][3])
            {
                cost-=p[k][2];
                itmp=ite++;
                sett.erase(itmp);
            }
            else break;
        }
        if(cmax>cost)
            ans=i,cmax=cost;
    }
    for(int i=ans;i<=n;++i)
        if(p[i][0]<=p[ans-1][3])
            printf("%d\n",i);
    return 0;
}
