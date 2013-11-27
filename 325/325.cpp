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
typedef pair<ll,ll> ppl;
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
const int N=(1e6+7);
char s[N];
char z[N];
int cnt['Z'+1];
int usd['Z'+1];
int p[N];
queue<int> pos['Z'+1];
int que(int i,int n)
{
  int r(0);
  ++i,++n;
  for(;i;i^=(i&(-i)))
    r+=p[i];
  return r;
}
void add(int i,int n,int v)
{
  ++i,++n;
  for(;i<=n;i+=(i&(-i)))
    p[i]+=v;
}
int main()
{
  scanf("%s",s);
  int l=0;
  for(;s[l];++l)
    ++cnt[s[l]];
  int odd(0);
  FOR(i,'A','Z'+1)
    if(cnt[i]&1)
      ++odd;
  if(odd>1)
    printf("-1");
  else
    {
      ll ans(0);
      // vector<ppi> t[2];
      // FOR(i,0,l)
      // 	{
      // 	  char c=s[i];
      // 	  if(usd[c]<cnt[c]/2)
      // 	    {
      // 	      t[0].push_back(ppi(c,i));
      // 	      ++usd[c];
      // 	    }
      // 	  else t[1].push_back(ppi(c,l-1-i));
      // 	}
      // reverse(t[1].begin(),t[1].end());
      // int b['Z'+1]={0};
      // for(int i=0,j=0,k=0;i<l/2;++i)
      // 	{
      // 	  for(;b[t[0][j].first]>0;++j)
      // 	    --b[t[0][j].first];
      // 	  for(;b[t[1][k].first]<0;++k)
      // 	    ++b[t[1][k].first];
      // 	  if(t[0][j].second==t[1][k].second)
      // 	    {
      // 	      z[i]=(t[0][j].first);
      // 	      if(t[0][j].first!=t[1][k].first)
      // 		--b[t[0][j].first],
      // 		  ++b[t[1][k].first];
      // 	      ++j,++k;
      // 	    }
      // 	  else if(t[0][j].second<t[1][k].second)
      // 	    {
      // 	      z[i]=(t[0][j].first);
      // 	      --b[t[0][j].first];
      // 	      ++j;
      // 	    }
      // 	  else
      // 	    {
      // 	      z[i]=(t[1][k].first);
      // 	      ++b[t[1][k].first];
      // 	      ++k;
      // 	    }
      // 	}
      for(int i=0,j=0;i<l;++i)
	{
	  if(usd[s[i]]<cnt[s[i]]/2)
	    z[l-1-j]=z[j]=s[i],++j,++usd[s[i]];
	  pos[s[i]].push(i);
	}
      if(l&1)
      	{
      	  FOR(i,'A','Z'+1)
      	    if(cnt[i]&1)
      	      z[l/2]=i;
      	}
      //cout<<z<<endl;
      FOR(i,0,l)
      	{
      	  char c=z[i];
      	  int f=pos[c].front();
      	  pos[c].pop();
      	  ans+=f-que(f,l);
      	  add(f,l,1);
      	}
      cout<<ans;
    }
  return 0;
}
