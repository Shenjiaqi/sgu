#include <cstdio>
#include <set>
using namespace std;
#define N (100)
int p[N+1];
struct cmp
{
    bool operator()(const int a,const int b)
    {
        if(p[a]==p[b])
            return a<b;
        return p[a]>p[b];
    }
};
set<int,cmp> sett;
int main()
{
    freopen("in.txt","r",stdin);
    int n,all(0);
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",p+i);
        all+=p[i];
        sett.insert(i);
    }
    printf("%d",(all>>1));
    set<int,cmp>::iterator ite;
    int r,a,b;
    r=b=*(--sett.end());
    for(int i=0;i<all;i+=2)
    {
        if(r==*(--sett.end()))
        {
            sett.erase(r);
            --p[r];
            b=*(sett.begin());
            sett.erase(b);
            --p[b];
            sett.insert(b);
            if(p[r])
            {
                printf("\n%d %d",r,b);
                sett.insert(r);
            }
            else
            {
                printf("\n%d %d",b,r);
                r=b;
            }
        }
        else
        {
            sett.erase(r);
            --p[r];
            b=*(sett.end());

        }
    }
    return 0;
}
