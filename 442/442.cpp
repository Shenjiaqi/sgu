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
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
typedef pair<double,double> ppd;
#define PB push_back
#define MP make_pair
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
#define N 10007
char s[N];
typedef vector<ll> bn;
bn dp[2][2][2];
const ll base=1e16;
vector<ppi> z[10][10][2];
void add(bn &a,const bn&b)
{
  ll carry=0;
  int i=0;
  for(;i<b.size();++i)
    {
      if(a.size()<=i)
	a.resize(i+1);
      carry=carry+a[i]+b[i];
      a[i]=carry%base;
      carry/=base;
    }
  for(;carry>0;++i)
    {
      if(a.size()<=i)
	a.resize(i+1);
      carry=carry+a[i];
      a[i]=carry%base;
      carry/=base;
    }
}
// void mul(bn &to,const bn&from,ll v)
// {
//   ll c=0;
//   to.resize(0);
//   for(int i=0;i<from.size();++i)
//     {
//       c=c+(ll)from[i]*v;
//       to.PB(c%base);
//       c/=base;
//     }
//   if(c>0)
//     to.PB(c);
// }
void muladd(bn &to,const bn&from,ll v)
{
  ll carry=0;
  int i=0;
  for(i=0;i<from.size();++i)
    {
      if(to.size()<i+1)
	to.resize(i+1);
      carry=carry+to[i]+(ll)from[i]*v;
      to[i]=(carry%base);
      carry/=base;
    }
  for(;carry>0;++i)
    {
      if(to.size()<i+1)
	to.resize(i+1);
      carry+=to[i];
      to[i]=carry%base;
      carry/=base;
    }
}
void pt(bn &v)
{
  int i=v.size();
  if(i>0)
    {
      --i;
      printf("%lld",v[i]);
      for(--i;i>=0;--i)
	printf("%016lld",v[i]);
    }
  else printf("0");
}
void cal(int f,int l,bn &ans)
{
  int from,to;
  from=0,to=1;
  int len=l-f+1;
  int ff=f;
  for(;f<l;++f,--l)
    {
      bool cnt=false;
      FOR(i,0,2)
	FOR(j,0,2)
	{
	  dp[to][i][j].resize(0);
	  if(dp[from][i][j].size()>0)
	    cnt=true;
	}
      if(!cnt)
	break;
      int v1=s[f]-'0';
      int v2=s[l]-'0';
      FR(k,z[v1][v2][f==ff?1:0])
	{
	  int e=k->FIR;
	  int c=(e>>2)&3;
	  int b=(e)&3;
	  if(dp[from][c][b].size()>0)
	    {
	      int num=k->SEC;
	      if(num>0)
		{
		  int a=e>>6;
		  int d=(e>>4)&3;
		  muladd(dp[to][a][d],dp[from][c][b],num);
		}
	    }
	}
      swap(from,to);
    }
  if(len&1)
    {
      int v1=s[f]-'0';
      int num[2][2]={0};
      for(int i=(f==ff?1:0);i<10;++i)
	FOR(a,0,2)
	  {
	    int v=i*2;
	    if((v+a)%10==v1)
	      ++num[(v+a)/10][a];
	  }
      FOR(i,0,2)
	FOR(j,0,2)
	if(dp[from][i][j].size()>0 && num[i][j]>0)
	  muladd(ans,dp[from][i][j],num[i][j]);
    }
  else
    {
      add(ans,dp[from][0][0]);
      add(ans,dp[from][1][1]);
    }
}
int main()
{
  FOR(v1,0,10)
    FOR(v2,0,10)
    {
      int lst[2][2][2][2][2]={0};
      FOR(i,0,10)
	for(int j=0;j<10;++j)
	  {
	    int v=i+j;
	    FOR(a,0,2)
	      if((v+a)%10==v1)
		{
		  int c=(v+a)/10;
		  FOR(b,0,2)
		    if((v+b)%10==v2)
		      {
			int d=(v+b)/10;
			++lst[a][d][c][b][0];
			if(i!=0)
			  ++lst[a][d][c][b][1];
		      }
		  }
	  }
      FOR(a,0,2)
	FOR(d,0,2)
	FOR(c,0,2)
	FOR(b,0,2)
	{
	  int t=(a<<6)|(d<<4)|(c<<2)|(b);
	  int tmp=lst[a][d][c][b][0];
	  if(tmp>0)
	    z[v1][v2][0].PB(MP(t,tmp));
	  tmp=lst[a][d][c][b][1];
	  if(tmp>0)
	    z[v1][v2][1].PB(MP(t,tmp));
	}
    }
  for(;scanf("%s",s)!=EOF;)
    {
      int len=strlen(s);
      assert(len<N);
      if(len==1 && s[0]=='0')
	break;
      bn ans;
      FOR(i,0,2)
	FOR(j,0,2)
	dp[0][i][j].resize(0);
      dp[0][0][0].PB(1);
      cal(0,len-1,ans);
      if(len>1 && s[0]=='1')
	{
	  FOR(i,0,2)
	    FOR(j,0,2)
	    dp[0][i][j].resize(0);
	  dp[0][1][0].PB(1);
	  cal(1,len-1,ans);
	}
      pt(ans);
      printf("\n");
    }
  return 0;
}
