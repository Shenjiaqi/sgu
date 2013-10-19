#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<ll,int> pp;
char s[100];
ll p[277];
bool t[277];
bool v[277];
ll gcd(ll a,ll b)
{
  return (b==0?a:gcd(b,a%b));
}
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  for(int z=1;n--;++z)
    {
      scanf("\n%s",s);
      int l=strlen(s);
      ll c=1;
      memset(p,0,sizeof(p));
      memset(v,0,sizeof(v));
      vector<int> ss;
      for(int i=l-1;i>=0;--i,c*=(ll)10)
	{
	  p[s[i]]+=c;
	  if(!v[s[i]])
	    {
	      ss.push_back(s[i]);
	      v[s[i]]=true;
	    }
	}
      ll gm;
      if(ss.size()<10)
	{
	  gm=p[ss[0]];
	  for(int i=1;i<ss.size() && gm>1;++i)
	    gm=gcd(gm,p[ss[i]]);
	}
      else
	{
	  gm=llabs(p[ss[0]]-p[ss[1]]);
	  for(int i=0;i<10 && gm>1;++i)
	    for(int j=i+1;j<10 && gm>1;++j)
	      gm=gcd(gm,llabs(p[ss[i]]-p[ss[j]]));
	}
      vector<ll> ans;
      ans.push_back(1LL);
      ll ggm=gm;
      for(ll i=2;gm>=i && i*i<=ggm;++i)
	if((gm%i)==0)
	  {
	    vector<ll> tmp;
	    for(ll z=(ll)i;(gm%i)==0;gm/=i,z*=(ll)i)
	      tmp.push_back(z);
	    for(int j=ans.size()-1;j>=0;--j)
	      for(int k=0;k<tmp.size();++k)
		ans.push_back(ans[j]*tmp[k]);
	  }
      if(gm>1)
	for(int i=ans.size()-1;i>=0;--i)
	  ans.push_back(gm*ans[i]);
      sort(ans.begin(),ans.end());
      printf("Case %d:",z);
      for(int i=0;i<ans.size();++i)
	cout<<' '<<ans[i];
      printf("\n");
    }
  return 0;
}
