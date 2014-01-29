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
#define N 6
#define M 6
int n,m;
char str[7];
int clue[N][M][2];
int cnt[N][M][2];
int status[N][M][2];
int sum[1<<9];
int bitcnt[1<<9];
int ans[N][M];
int lu[N][M][2];
bool vis[36][6][1<<9];
int msk[36][6][1<<9];
int lst[50][3],lsti;
int getmsk(int val,int empty,int usd)
{
  if(val>35 || empty==0 || val<=0)
    return 0;
  if(!vis[val][empty][usd])
    {
      vis[val][empty][usd]=true;
      if(empty==1)
	{
	  if(val<=9 && ((1<<(val-1))&usd)==0)
	    msk[val][empty][usd]=1<<(val-1);
	}
      else
	{
	  // int unusd=(~usd)&((1<<9)-1);
	  // for(int i=0;i<min(9,val-1) && (1<<i)<=unusd;++i)
	  //   if((unusd&(1<<i)) && getmsk(val-i-1,empty-1,usd|(1<<i)))
	  //     msk[val][empty][usd]|=1<<i;
	  int tmp=usd+1;
	  tmp=tmp&(-tmp);
	  if(tmp<(1<<9))
	    {
	      msk[val][empty][usd]=getmsk(val,empty,usd|tmp);
	      int c=__builtin_ctz(tmp);
	      int mm=getmsk(val-c-1,empty-1,usd|tmp);
	      if(mm)
		msk[val][empty][usd]|=(mm|tmp);
	    }
	}
    }
  return msk[val][empty][usd];
}
bool dfs()
{
  if(lst[0][2]==0)
    return true;
  int ri=-1,m=10,pre;
  for(int i=lst[0][2],j=0;i;j=i,i=lst[i][2])
    {
      int a=lst[i][0],b=lst[i][1];
      int u=lu[a][b][1],l=lu[a][b][0];
      int mu=getmsk(clue[u][b][1],cnt[u][b][1],status[u][b][1]);
      // cout<<clue[u][b][1]<<' '<<cnt[u][b][1]<<' '<<status[u][b][1]<<' '<<mu<<endl;
      int ml=getmsk(clue[a][l][0],cnt[a][l][0],status[a][l][0]);
      mu&=ml;
      if(mu==0)
	return false;
      if(m>bitcnt[mu])
	m=bitcnt[mu],ri=i,pre=j;
    }
  int a=lst[ri][0],b=lst[ri][1];
  int u=lu[a][b][1],l=lu[a][b][0];
  int mu=getmsk(clue[u][b][1],cnt[u][b][1],status[u][b][1]);
  int ml=getmsk(clue[a][l][0],cnt[a][l][0],status[a][l][0]);
  mu&=ml;
  lst[pre][2]=lst[ri][2];
  for(;mu>0;mu^=(mu&(-mu)))
    {
      int i=__builtin_ctz((mu&(-mu)));
      clue[u][b][1]-=(i+1);
      clue[a][l][0]-=(i+1);
      --cnt[u][b][1];
      --cnt[a][l][0];
      status[u][b][1]|=(1<<i);
      status[a][l][0]|=(1<<i);
      ans[a][b]=i+1;
      if(dfs())
	return true;
      clue[u][b][1]+=(1+i);
      clue[a][l][0]+=(i+1);
      ++cnt[u][b][1];
      ++cnt[a][l][0];
      status[u][b][1]^=(1<<i);
      status[a][l][0]^=(1<<i);
    }
  lst[pre][2]=ri;
  return false;
}
int main()
{
  for(int i=1;i<(1<<9);++i)
    {
      int j=__builtin_ctz(i);
      sum[i]=j+1+sum[i^(1<<j)];
      bitcnt[i]=1+bitcnt[i^(1<<j)];
    }
  scanf("%d%d",&n,&m);
  FOR(i,0,n)
    FOR(j,0,m)
    {
      scanf("%s",str);
      if(str[0]!='.')
	{
	  clue[i][j][1]=str[0]!='X'?(str[0]-'0')*10+(str[1]-'0'):-1;
	  clue[i][j][0]=str[3]!='X'?(str[3]-'0')*10+(str[4]-'0'):-1;
	  ans[i][j]=-1;
	}
      else clue[i][j][0]=clue[i][j][1]=-1;
    }
  FOR(i,0,n)
    FOR(j,0,m)
    if(ans[i][j]==-1)
      {
	if(clue[i][j][0]>=0)
	  {
	    for(int k=j+1;k<m && ans[i][k]!=-1;++k)
	      lu[i][k][0]=j,++cnt[i][j][0];
	    // status[i][j][0]=(1<<9)-1;
	  }
	if(clue[i][j][1]>=0)
	  {
	    for(int k=i+1;k<n && ans[k][j]!=-1;++k)
	      lu[k][j][1]=i,++cnt[i][j][1];
	    // status[i][j][1]=(1<<9)-1;
	  }
      }
    else
      {
	++lsti;
	lst[lsti][0]=i;
	lst[lsti][1]=j;
	lst[lsti][2]=lst[0][2];
	lst[0][2]=lsti;
      }
  assert(dfs());
  // dfs();
  FOR(i,0,n)
    FOR(j,0,m)
    {
      if(ans[i][j]<0)
	printf("_");
      else
	printf("%d",ans[i][j]);
      printf("%c",(j==m-1?'\n':' '));
    }
  return 0;
}
