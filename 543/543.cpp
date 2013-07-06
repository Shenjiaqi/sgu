#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
#define N 2000
bool test(int o3,int even,int num,int r)
{
    int p[12][2],poi;
    poi=0;
    if(r&1)
    {
        int k=min(o3,num);
        if(k>0)
        {
            p[poi][0]=r-3,p[poi][1]=k,++poi;
            o3-=k;
        }
        if(num>k)
            p[poi][0]=r,p[poi][1]=num-k,++poi;
    }
    else
        p[poi][0]=r,p[poi][1]=num,++poi;
    for(int i=0;o3>1 && i<poi;++i)
    {
        int nump=(p[i][0]/6);
        if(nump>0 && p[i][1])
        {
            if((o3>>1)>=nump)
            {
                int numn=min(p[i][1],(o3>>1)/nump);
                o3-=numn*nump*2;
                if(p[i][1]-numn>0)
                    p[poi][0]=p[i][0],p[poi][1]=p[i][1]-numn,++poi;
                p[i][1]=numn;
                p[i][0]%=6;
            }
            else
            {
                int numn=o3>>1;
                p[i][1]-=1;
                o3-=numn*2;
                p[poi][0]=p[i][0]-numn*6,p[poi][1]=1,++poi;
            }
        }
    }
    for(int i=0;o3>0 && i<poi;++i)
    {
        if(p[i][0]>=3 && p[i][1]>0)
        {
            int numn=min(o3,p[i][1]);
            o3-=numn;
            if(numn<p[i][1])
                p[poi][0]=p[i][0],p[poi][1]=p[i][1]-numn,++poi;
                //p.push_back(pp(p[i].first,p[i].second-numn));
            p[i][1]=numn;
            p[i][0]-=3;
        }
    }
    if(o3>0)
        return false;
    for(int i=0;even>0 && i<poi;++i)
        if(p[i][0]>1 && p[i][1]>0)
            even-=(p[i][0]>>1)*p[i][1];
    return even<=0;
}
int main()
{
    freopen("in.txt","r",stdin);
    int n,r;
    scanf("%d%d",&n,&r);
    int ans(0);
    int odd,even,con;
    odd=even=con=0;
    int all(0);
    for(int i=0;i<n;++i)
    {
        int a;
        scanf("%d",&a);
        all+=a;
        if(a&1)
        {
            odd+=1;
            a-=3;
        }
        even+=(a>>1);
        con+=(a/6);
    }
    int ma,mi;
    ma=(all+r-2-1)/(r-2)+1;
    mi=(all+r-1)/r;
    for(;mi<=ma;)
    {
        int mid=(ma+mi)>>1;
        bool flag;
        if((r&1) && odd<mid)
        {
            int tmp=min((mid-odd>>1),con);
            flag=test(odd+tmp*2,even-3*tmp,mid,r);
        }
        else flag=test(odd,even,mid,r);
        if(flag)
            ans=mid,ma=mid-1;
        else mi=mid+1;
    }
    printf("%d",ans);
    return 0;
}
