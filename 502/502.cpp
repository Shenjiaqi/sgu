#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <string.h>
#include <stdlib.h>
#include <functional>
using namespace std;
typedef long long ll;
int pp[17];
int qq[17];
int q[17][17];
int p[17][1<<17];
int df(int lev,int n,int msk)
{
  if(lev>=n)
    return 1;
  if(p[lev][msk]==0)
    {
      int v=0;
      for(int i=0,j=1;i<n;++i,j<<=1)
	if((j&msk)==0 && (qq[lev] || i<n-1))
	  {
	    int tmp=df(lev+1,n,msk|j);
	    v|= ( (tmp<<q[lev][i] | tmp>>(17-q[lev][i]) ) & ((1<<17)-1) );
	  }
      p[lev][msk]=v;
    }
  return p[lev][msk];
}
int ans[17];
void pt(int lev,int n,int msk,int kk)
{
  //cout<<'!'<<lev<<endl;
  for(int i=0,j=1;i<n;++i,j<<=1)
    if(((msk&j)==0) && (qq[lev] || i<n-1))
      {
	int tmp=df(lev+1,n,msk|j);
	int tmp2=(kk>>q[lev][i] | kk<<(17-q[lev][i]) ) & ((1<<17)-1);
	if(tmp&tmp2)
	  {
	    ans[i]=qq[lev];
	    pt(lev+1,n,msk|j,tmp2);
	    break;
	  }
      }
}
int main()
{
  freopen("in","r",stdin);
  ll n;
  cin>>n;
  if(n<(ll)1e17)
    {
      int l=0;
      for(;n;n/=10)
	qq[l++]=n%10;
      for(int i=0,j=1;i<l;++i,j=(j*10)%17)
	pp[i]=j%17;
      for(int i=0;i<l;++i)
	for(int j=0;j<l;++j)
	  q[i][j]=(qq[i]*pp[j])%17;
      //for(int i=0;i<l;++i) cout<<' '<<pp[i]<<' '<<qq[i]<<endl;
      if(df(0,l,0)&1)
	{
	  pt(0,l,0,1);
	  for(int i=l-1;i>=0;--i)
	    cout<<ans[i];
	  return 0;
	}
    }
  cout<<-1;
  return 0;
}
