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
#define N 13
#define M 50
int p[N][N];
int q[M][3];
int lev[N];
int t[N];
int n,m;
int re[N];
int est[1<<N];
int cnt[N+1][2],cni;
bool check(int k)
{
  ++cni;
  FOR(i,0,m)
    if(k&q[i][2])
      {
	if(((q[i][2])&k)==q[i][2])
	  {
	    if(cnt[N][0]==cni)
	      return false;
	    cnt[N][0]=cni;
	  }
	else
	  {
	    int tmp=(((1<<q[i][0])&k)?1:0);
	    if(cnt[q[i][tmp]][tmp]==cni)
	      return false;
	    cnt[q[i][tmp]][tmp]=cni;
	  }
      }
  return true;
}
int dfs(int k)
{
  if(est[k]==0)
    {
      if(check(k))
	est[k]=1;
      else
	{
	  est[k]=1e9;
	  for(int i=k&(k-1);i>(k^i);i=(i-1)&k)
	    est[k]=min(est[k],dfs(i)+dfs(i^k));
	}
    }
  return est[k];
}
bool check2(int msk,int le,int left)
{
  ++cni;
  FOR(i,0,m)
    if((q[i][2]&left)==0 && (q[i][2]&msk)!=q[i][2] && (q[i][2]&msk))
      {
	int tmp=(((1<<q[i][0])&msk)?1:0);
	if(cnt[t[q[i][tmp]]][tmp]==cni)
	  return false;
	cnt[t[q[i][tmp]]][tmp]=cni;
      }
  return true;
}
bool test(int lim,int left,int l)
{
  if(left==0)
    return true;
  if(l+est[left]>lim)
    return false;
  int pre=left&(-left);
  left^=pre;
  int lst;
  t[lst=__builtin_ctz(pre)]=l;
  for(int i=left;i;i=(i-1)&left)
    if(est[pre|i]==1 && check2(pre|i,l,left^i))
      {
	lev[l]=pre|i;
	for(int j=(lev[l]^lst)&lev[l];j;j^=(j&(-j)))
	  t[__builtin_ctz(j)]=l;
	lst=lev[l];
	if(test(lim,left^i,l+1))
	  return true;
      }
  lev[l]=pre;
  return test(lim,left,l+1);
}
int main()
{
  freopen("in","r",stdin);
  scanf("%d%d",&n,&m);
  FOR(i,0,m)
    {
      char tmp[3];
      scanf("%s",tmp);
      p[q[i][0]=tmp[0]-'a'][q[i][1]=tmp[1]-'a']=1;
      q[i][2]=(1<<q[i][0])|(1<<q[i][1]);
    }
  int ans=0;
  FOR(i,1,(1<<n))
    if(dfs(i)==1e9 || dfs(i)==0)
      return 1;
  for(int f=dfs((1<<n)-1),t=n;f<=t;)
    {
      int mid=(f+t)>>1;
      if(test(mid,(1<<n)-1,0))
	{
	  ans=mid,t=mid-1;
	  memcpy(re,lev,sizeof(lev[0])*(ans));
	}
      else
	f=mid+1;
    }
  if(ans==0)
    return 1;
  printf("%d\n",ans);
  FOR(i,0,ans)
    {
      for(int j=re[i];j;j^=(j&(-j)))
	printf("%c",(char)(__builtin_ctz(j)+'a'));
      printf("\n");
    }
  return 0;
}
