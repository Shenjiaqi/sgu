#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;
map<int,ll> mapp,mapp2;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int n,k;
    //scanf("%d%d",&n,&k);
    for(int n=1;n<=10;++n)
    {
        for(int k=0;k<=n*n;++k)
        {
            map<int,ll>::iterator ite;
            mapp.clear();
            mapp2.clear();
            mapp[0]=1;
            int lim=(1<<n)-1;
            ll ans=0;
            for(int i=0;i<n;++i)
            {
                ite=mapp.begin();
                for(;ite!=mapp.end();++ite)
                {
                    int t=(*ite).first;
                    ll t2=(*ite).second;
                    int l1=((t/101)>>10)&lim;
                    int l2=((t/101))&lim;
                    int num=t%101;
                    for(int j=l1;j<=lim;j=(j+1)|l1)
                    {
                        int tmp=j^l1;
                        int tc=num+__builtin_popcount(tmp);
                        if(tc>k)
                        {
                            j=j+((j)&(-j))-1;
                        }
                        else if(tc==k)
                            ans+=t2;
                        else
                        {
                            int ll1=(l2 | tmp<<2 | tmp>>2)&lim;
                            int ll2=(tmp<<1 | tmp>>1)&lim;
                            int ll=tc+(n-i)*n;
                            if(i<n-1)
                            {
                                ll-=__builtin_popcount(ll1);
                                if(i<n-2)
                                {
                                    ll-=__builtin_popcount(ll2);
                                    if(i<n-3)
                                        ll-=n*(n-i-3)/2-2;
                                }
                            }
                            if(ll>=k)
                                mapp2[101*((ll1<<10)|ll2)+tc]+=t2;
                        }
                    }
                }
                mapp.clear();
                mapp2.swap(mapp);
            }
            if(((n+k)%30)==0)
                printf("\n");
            printf(", \"%I64d\" ",ans);
        }
    }
    return 0;
}
