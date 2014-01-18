#include <cstdio>
#include <cassert>
#include <iostream>
#include <map>
using namespace std;
typedef long long ll;
struct cmp
{
  bool operator()(const ll &a,const ll&b)const
  {
    return a>b;
  };
};
int main()
{
  int n,m,k;
  assert(n<26);
  scanf("%d%d%d",&n,&m,&k);
  int p[100];
  for(int i=0;i<n;++i)
    scanf("%d",p+i);
  int cnt=0,nneg=0;
  ll mi=10;
  map<ll,int,cmp> mapp;
  for(int i=0;i<(1<<n);++i)
    if(__builtin_popcount(i)==m)
    {
      ll v=1;
      for(int j=0;(1LL<<j)<=i;++j)
	if((1LL<<j)&i)
	  v*=(ll)p[j];
      ++cnt;
      mapp[v]++;
    }
  for(;;)
    {
      typeof(mapp.begin()) ii=mapp.begin();
      // cout<<ii->second<<endl;
      if(k>ii->second)
	k-=ii->second;
      else
	{
	  cout<<ii->first<<endl;
	  break;
	}
      mapp.erase(mapp.begin());
    }
  return 0;
}
