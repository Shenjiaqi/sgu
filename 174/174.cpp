#include <cstdio>
#include <map>
#include <utility>
#define N 200000
using namespace std;
int father[N+1];
int que(int a)
{
    if(father[a]==a)
        return a;
    return (father[a]=que(father[a]));
}
void add(int a,int b)
{
    a=que(a);
    b=que(b);
    if(a!=b)
        father[a]=b;
}
map< pair<int,int> , int > mapp;
int an(int m)
{
    for(int i=1;i<=m;++i)
    {
        father[i]=i;
        int x1,y1,x2,y2,a(0),b(0);
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        if(x1==x2 && y1==y2)
            return i;
        map< pair<int,int> , int >::iterator ite=mapp.find(make_pair(x1,y1));
        if(ite!=mapp.end())
            a=(*ite).second;
        if(a)
            add(a,i);
        else mapp.insert(make_pair(make_pair(x1,y1),i));
        ite=mapp.find(make_pair(x2,y2));
        if(ite!=mapp.end())
            b=(*ite).second;
        if(b)
        {
            if(a)
            {
                if(que(a)==que(b))
                    return i;
                add(a,b);
            }
            add(b,i);
        }
        else mapp.insert(make_pair(make_pair(x2,y2),i));
    }
    return 0;
}
int main()
{
    freopen("in.txt","r",stdin);
    int m;
    scanf("%d",&m);
    printf("%d",an(m));
    return 0;
}
