#include <cstdio>
#include <map>
using namespace std;
#define N (10)
typedef long long ll;
#define MP(a,b,c) ((a<<20)|(b<<8)|c);
#define GL(v) ((v)>>20)
#define GR(v) (((v>>8))&((1<<N)-1))
#define GLEFT(v) (v&((1<<8)-1))
int mp(int a,int b,int c)
{
  return MP(a,b,c);
}
void fill(const int & conf,ll num,map <int,ll> & mapp,const int& width)
{
  int l=GL(conf),r=GR(conf),left=GLEFT(conf);
  int msk=(1<<width)-1;
  int z=(~(l|r))&msk;
  for(int i=z;;i=(i-1)&z)
    {
      int tmp=__builtin_popcount(i);
      if(tmp<=left && (l!=msk || r!=msk))
	{
	  if((mapp[mp(msk&((l|i)<<1),((r|i)>>1),left-tmp)]+=num)<0)
	    printf("!!!\n");
	}
      if(i==0)
	break;
    }
}
ll cal(int n,int k)
{
  map<int,ll> mapp[2];
  mapp[0][mp(0,0,k)]=1;
  for(int i=0;i<n;++i)
    {      
      int f=i&1,t=1-f;
      for(map<int,ll>::iterator ite=mapp[f].begin();ite!=mapp[f].end();++ite)
	fill(ite->first,ite->second,mapp[t],n);
      mapp[f].clear();
    }
  int c=n&1;
  ll ans(0);
  for(map<int,ll>::iterator ite=mapp[c].begin();ite!=mapp[c].end();++ite)
    if(GLEFT(ite->first)==0)
      ans+=ite->second;
  return ans;
}
int main()
{
  int n,k;
  //freopen("out","w",stdout);
  for(int i=1;i<=10;++i)
    {
      for(int j=0;j<=2*i;++j)
	printf("\"%lld\",",cal(i,j));
      printf("\n");
    }
  return 0;
}
