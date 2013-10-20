#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
#define N 100
int all,p[N];
struct cmp
{
    bool operator()(const int a,const int b)
    {
        if(p[a]==p[b])
            return a<b;
        return p[a]>p[b];
    }
};
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    scanf("%d",&n);
    set<int,cmp> sett;
    for(int i=0;i<n;++i)
    {
        scanf("%d",p+i);
        all+=p[i];
        sett.insert(i);
    }
    printf("%d",(all>>1));
    int a,b;
    a=*(sett.begin());
    sett.erase(a);
    for(int i=0;i<all;i+=2)
    {
        b=*(sett.begin());
        sett.erase(b);
        if(p[a]<p[b])
            a^=b,b^=a,a^=b;
        printf("\n%d %d",1+a,1+b);
        --p[a],--p[b];
        if(p[b])
            sett.insert(b);
    }
    return 0;
}
