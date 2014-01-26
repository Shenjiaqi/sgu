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
#define N 13
#define M (1594323+7)
const int inf=1e9;
bool vis[M][2];
int dp[M][2];
int n,s,t;
bool visnei[1<<N];
int neigh[1<<N];
char str[N+7];
int popu[1<<N];
int ocu[1<<N][2];
int calnei(int state)
{
  if(!visnei[state])
    {
      visnei[state]=true;
      int tmp=state&(-state);
      neigh[state]=calnei(state^tmp)|neigh[tmp];
    }
  return neigh[state];
}
int calp(int state)
{
  if(state==0)
    return 0;
  if(popu[state]==0)
    {
      int tmp=state&(-state);
      popu[state]=popu[tmp]+calp(state^tmp);
    }
  return popu[state];
}
int calo(int state,int d)
{
  if(state==0)
    return 0;
  if(ocu[state][d]==0)
    {
      int tmp=state&(-state);
      ocu[state][d]=ocu[tmp][d]+calo(state^tmp,d);
    }
  return ocu[state][d];
}
int cal(int a[2],int c,int st,bool empty)
{
  int d=calo(a[0],0)+calo(a[1],1);
  assert(d<M);
  if(!vis[d][st])
    {
      vis[d][st]=true;
      int tmp=-inf;
      for(int i=c;i>0;i=(i-1)&c)
	{
	  int neighb=calnei(i)^i;
	  if(calp(a[st]&neighb)>calp(i)+calp(neighb&a[st^1]))
	    {
	      a[st]|=i;
	      tmp=max(tmp,-cal(a,c^i,1^st,false));
	      a[st]^=i;
	    }
	}
      if(tmp==-inf&&!empty)
	tmp=-cal(a,c,1^st,true);
      dp[d][st]=(tmp==-inf?calp(a[st])-calp(a[st^1]):tmp);
    }
  return dp[d][st];
}
int main()
{
  scanf("%d%d%d",&n,&s,&t);
  --s,--t;
  FOR(i,0,n)
    {
      scanf("%s",str);
      FOR(j,0,n)
	if(str[j]=='1')
	  neigh[1<<i]|=1<<j;
      visnei[1<<i]=true;
    }
  FOR(i,0,n)
    scanf("%d",&popu[1<<i]);
  ocu[1][0]=1;
  ocu[1][1]=2;
  FOR(i,1,N)
    {
      ocu[1<<i][0]=ocu[1<<(i-1)][0]*3;
      ocu[1<<i][1]=ocu[1<<(i-1)][1]*3;
    }
  int tmp[2];
  tmp[0]=1<<s,tmp[1]=1<<t;
  visnei[0]=true;
  cout<<cal(tmp,(((1<<n)-1)^tmp[0])^tmp[1],0,false)<<endl;
  return 0;
}
