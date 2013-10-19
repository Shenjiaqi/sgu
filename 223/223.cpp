#include <cstdio>
#include <map>
using namespace std;
typedef long long ll;
#define N (10)
#define K (N*N)
int check(int v)
{
  int r=0;
  for(int c=1,m=0;c<=v;c<<=1)
    if(m && c&v)
      return -1;
    else if(c&v)
      ++r,m=1;
    else m=0;
  return r;
}
void fill(map<int,ll> & mapp,int width,int conf,int left,ll num)
{
  int msk=(~conf)&(width-1);
  for(int i=msk;;i=(i-1)&msk)
    {
      int nn=check(i);
      if(nn<0)
	continue;
      if(nn<=left)
	mapp[(((i<<1)|i|(i>>1))&(width-1))*(K+1)+left-nn]+=num;
      if(i==0)
	break;
    }
}
int main()
{
  freopen("in","r",stdin);
  int n,k;
  scanf("%d%d",&n,&k);
  map<int,ll> mapp[2];
  mapp[0][k]=1;
  for(int i=0,f,t;i<n;++i)
    {
      f=i&1,t=1-f;
      for(map<int,ll>::iterator ite=mapp[f].begin();ite!=mapp[f].end();++ite)
	fill(mapp[t],1<<n,(ite->first)/(K+1),(ite->first)%(K+1),ite->second);
      mapp[f].clear();
    }
  ll ans=ll(0);
  for(map<int,ll>::iterator ite=mapp[n&1].begin();ite!=mapp[n&1].end();++ite)
    if((ite->first%(K+1))==0)
      ans+=ite->second;
  printf("%lld",ans);
  return 0;
}
