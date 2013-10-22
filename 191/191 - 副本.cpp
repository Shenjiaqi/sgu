#include <cstdio>
#define N 30000
char s;
char nxtc()
{
    for(char t;;)
    {
        if(EOF==scanf("%c",&t))
            return 0;
        if(t=='A' || t=='B')
            return ((t==s)?'A':'B');
    }
    return 0;
}
bool sa();
bool sb()
{
    char t=nxtc();
    if(t=='A')
        return 1;
    if(t=='B')
    {
        if(sa() && sb())
            return 1;
        return 0;
    }
    return 0;
}
bool sa()
{
    char t=nxtc();
    if(t=='B')
        return 1;
    else if(t=='A')
    {
        if(sb() && sa())
            return 1;
        return 0;
    }
    return 0;
}
bool check()
{
    if(!sa())
        return 0;
    if(EOF==scanf("%c",&s))
        return 1;
    return 0;
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%c",&s);
    printf("%s",(check()?"YES":"NO"));
    return 0;
}
