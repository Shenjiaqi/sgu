#include <cstdio>
#include <cmath>
void gcd(int a,int b,int &x,int &y)
{
    if(b==0)
    {
        x=1,y=0;
        return;
    }
    gcd(b,a%b,y,x);
    y=y-a/b*x;
}
int main()
{
    int n=5;
    int f=pow(10,n);
    int l=f/10;
    for(int i=0;i<f;++i)
        if(i>=l)
        {
            if(((i*i)%f)==i)
                printf("%d\n",i);
        }
    return 0;
}
