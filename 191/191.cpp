#include <cstdio>
#define N (30000)
int stack[N+1],poi;
int nxtc()
{
    int t=getchar();
    if(t=='A' || t=='B')
        return t;
    return 0;
}
bool st()
{
    for(int i=0;i<N;++i)
    {
        char t=nxtc();
        if(!t)
            return (poi<0?1:0);
        if(poi<0)
            return 0;
        if(stack[poi]!=t)
            --poi;
        else stack[poi]=t,stack[++poi]=(t=='A'?'B':'A');
    }
    return 0;
}
int main()
{
    freopen("in.txt","r",stdin);
    stack[poi=0]=getchar();
    getchar();
    if(st())
        printf("YES");
    else printf("NO");
    return 0;
}
