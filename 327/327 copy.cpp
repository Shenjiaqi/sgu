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
#define N 14
#define L 30
char p[N][L+1];
char * q[N];
int lll[N];
bool c[N][L+1][L+1];
char tmp[(L+1)*N*2+1];
bool chg[N][(L+1)*N*2+1];
int n;
int cmp(const void *a,const void *b)
{
  char *c=*(char**)a,*d=*(char**)b;
  return strlen(d)-strlen(c);
}
bool check(char *a,int o1,int o2)
{
  for(;o1<o2;++o1,--o2)
    if(a[o1]!=a[o2])
      return false;
  return true;
}
bool check(int lev,int len,int off)
{
  int l=lll[lev];
  if(len&1)
    {
      int mid=len>>1;
      if(l+off-1<=mid || off>=mid)
	return true;
      if(mid-off>=l+off-1-mid)
	return c[lev][l-((l+off-1-mid)<<1)-1][l-1];
      return c[lev][0][(mid-off)*2];
    }
  int mm=len>>1;
  if(l+off-1<=mm || off>mm)
    return true;
  if(mm-off+1<=off+l-1-mm)
    return c[lev][0][((mm-off+1)<<1)-1];
  return c[lev][l-((l+off-1-mm)<<1)][l-1];
}
bool dfs(int len,int lft,int le)
{
  if(!lft)
    return true;
  for(int i=0;i<=le+1;++i)
    {
      for(int j=lft;j;j^=(j&(-j)))
	{
	  int k=__builtin_ctz(j);
	  if(check(k,len,i))
	    {
	      int ii=0;
	      bool flg=true;
	      for(;flg && ii+i<=le && ii<lll[k];++ii)
		if(tmp[ii+i]!=q[k][ii])
		  flg=false;
	      if(flg)
		{
		  for(;ii<lll[k];)
		    tmp[ii+i]=q[k][ii]
	    }
	}
    }
}
int main()
{
  freopen("in","r",stdin);
  scanf("%d",&n);
  FOR(i,0,n)
    {
      scanf("%s",p[i]);
      q[i]=p[i];
    }
  qsort(q,n,sizeof(q[0]),cmp);
  int ans=0;
  FOR(i,0,n)
    ans+=(lll[i]=strlen(q[i]));
  for(int i=0;i<n;++i)
    {
      int l=lll[i];
      for(int j=0;j<l;++j)
	{
	  c[i][0][j]=check(q[i],0,j);
	  c[i][j][l-1]=check(q[i],j,l-1);
	}
    }
  for(int f=1,t=ans*2;f<=t;)
    {
      int mid=(f+t)>>1;
      memset(tmp,0,sizeof(tmp));
      if(dfs(mid))
	ans=mid,t=mid-1;
      else f=mid+1;
    }
  memset(tmp,0,sizeof(tmp));
  dfs(ans,(1<<n)-1,-1);
  printf("%s",tmp);
  return 0;
}
