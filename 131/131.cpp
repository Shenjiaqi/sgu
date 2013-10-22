#include <cstdio>
#include <cstring>
using namespace std;
#define N (9)
#define M (9)
long long ina[1<<M],inb[1<<M],*s,*t;
int n,m;
void fill(int u1,int u2,int l,long long num)
{
    if(l>1 && ((1<<(l-2))&u1)==0)
        return ;
    if(l>=m)
    {
        u1&=((1<<m)-1);
        if(u1!=(1<<m)-1)
            return;
        //printf("%d %d\n",(u2&((1<<m)-1)),u1);
        t[u2&((1<<m)-1)]+=num;
        return ;
    }
    int tmp=1<<l;
    if((u1&tmp)==0)
    {
        if((u2&tmp)==0 && (u2&(tmp<<1))==0)
            fill(u1|tmp,u2|(tmp)|(tmp<<1),l+1,num);
            //| a
            //|aa
        if((u2&tmp)==0)
            fill(u1|tmp,u2|tmp,l+1,num);
            //|
            //|aa
        if((u1&(tmp<<1))==0 && (u2&(tmp<<1))==0)
            fill(u1|tmp|(tmp<<1),u2|(tmp<<1),l+1,num);
            //|aa
            //|a
        if((u1&(tmp<<1))==0 && (u2&tmp)==0)
            fill(u1|tmp|(tmp<<1),u2|tmp,l+1,num);
            //|a
            //|aa
    }
    else
    {
        if((u1&(tmp<<1))==0 && (u2&tmp)==0 && (u2&(tmp<<1))==0)
            fill(u1|(tmp<<1),u2|tmp|(tmp<<1),l+1,num);
            //|aa
            //|xa
        if((u2&tmp)==0 && (u2&(tmp<<1))==0)
            fill(u1,u2|tmp|(tmp<<1),l+1,num);
            //| a
            //|xa
    }
    fill(u1,u2,l+1,num);
}
int main()
{
    freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&m);
    s=ina,t=inb;
    s[(1<<m)-1]=1;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<(1<<m);++j)
        {
            if(!s[j])
                continue;
            //printf("%d %d %d\n",i,j,s[j]);
            fill(j|(1<<m),1<<m,0,s[j]);
        }
        memset(s,0,sizeof(ina));
        long long *tmp=t;
        t=s,s=tmp;
    }
    printf("%I64d",s[(1<<m)-1]);
    return 0;
}
