#include <cstdio>
int main()
{
    int k;
    scanf("%d",&k);
    /*
    int ans(1);
    if(((k-1)%3)==0)
        ++ans;
    if(1==k)
        ++ans;
    if(1==k)
        ++ans;
    if(((k-1)%3)==0)
        ++ans;
    if(((k-1)%6)==0)
        ++ans;
    if(1==k)
        ++ans;
    if(1==k)
        ++ans;*/
    if(k==1)
        printf("8");
    else
    {
        --k;
        if(!(k%3))
        {
            if(!(k%2))
                printf("4");
            else printf("3");
        }
        else printf("1");
    }
    //printf("%d",ans);
    return 0;
}
