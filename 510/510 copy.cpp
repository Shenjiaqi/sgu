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
#include <cctype>
using namespace std;
typedef long long ll;
typedef pair<int,int> ppi;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define MSK ((1LL<<4)-1)
#define ST(a,b,c) ((v&((~(MSK))<<(lev<<2)))|((c&MSK)<<(lev<<2)))
#define FT(a,b,c) ((a>>(b<<2))&((1LL<<(c<<2))-1))
int len[1000];
ll v;
int val[13];
ll tmp[1000];
int nnum,from,to;
void dfs(int lev,int lim)
{
  if(lev<lim)
    for(int i=0;i<lim && i<=val[lev-1]+1 && nnum<to-from;++i)
      {
	val[lev]=i;
	dfs(lev+1,lim);
      }
  else
    {
      int cnt(0);
      FOR(i,0,lim)
	{
	  FOR(j,i,lim)
	    {
	      tmp[cnt]=1;
	      FOR(k,i,j+1)
		tmp[cnt]=(tmp[cnt]<<4)|val[k];
	      ++cnt;
	    }
	}
      sort(tmp,tmp+cnt);
      int z=unique(tmp,tmp+cnt)-tmp;
      if(z>from && z<=to)
	if(len[z]!=lim)
	  {
	    ++nnum,len[z]=lim;
	    if(z==13)
	      {
		FOR(i,0,lim)
		  cout<<(char)(val[i]+'a');
		cout<<endl;
	      }
	  }
      //cout<<"z"<<z<<endl;
    }
}
int main()
{
  freopen("in","r",stdin);
  int n=5;
  FOR(i,5,6)
    {
      if(i<5)
	from=0;
      else from=(i-1)*i/2;
      to=i*(i+1)/2;
      nnum=0;
      cout<<i<<' '<<from<<' '<<to<<'!'<<endl;
      dfs(1,i);
      cout<<"!!"<<nnum<<endl;
      FOR(j,from,to+1)
	if(len[j]==i)
	  cout<<j<<' ';
      cout<<endl;
    }
  return 0;
}
