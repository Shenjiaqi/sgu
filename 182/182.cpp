#include <cstdio>
int pos(int l,int k)
{
    if(l==1)
        return 1;
    int c=l>>1;
    if(k>c)
        return pos(l-c,l-k+1);
    else return (l-c+pos(c,c-k+1));
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,q;
    scanf("%d %d",&n,&q);
    printf("%d",pos(n,q));
    return 0;
}
