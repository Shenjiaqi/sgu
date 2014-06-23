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
typedef pair<ld,ld> ppld;
#define PB push_back
#define FIR first
#define SEC second
#define MP make_pair
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
int n;
char s1[27],s2[27];
char s['Z'+7];
int mm;
int rec[30][2];
int bak[30][2],bki;
bool check(char *p)
{
  for(int i=0;i<n-1;++i)
    if(((p[i]+1)%n)!=p[i+1])
      return false;
  return true;
}
int mov(char *from,char *to,int a,int b,bool prt)
{
  int r=b-(n-1);
  if(r<0)
    {
      r+=n;
      if(prt)
      	for(int i=0;i<=b;++i)
      	  printf("%c",s2[from[i]]);
    }
  int j=0;
  for(int i=(a+1)%n;;i=(i+1)%n)
    {
      to[j++]=from[i];
      if(i==b)
	break;
    }
  to[j++]=from[a];
  if(prt)
    printf("%c",s2[from[a]]);
  ++r;
  for(int i=(b+1)%n;i!=a;i=(i+1)%n)
    {
      to[j++]=from[i],++r;
      if(prt)
	printf("%c",s2[from[i]]);
    }
  return r;
}
int dfs(char *x,int m,int left,int lev,int turn)
{
  if(left<0)
    return 0;
  char t[27];
  char pos[27];
  int c=0,mi=1e9,mip,chg=0;
  FOR(i,0,n)
    {
      if(m&(1<<x[i]))
	{
	  t[c]=x[i];
	  if(t[c]<mi)
	    mi=t[c],mip=c;
	  ++c;
	}
      pos[x[i]]=i;
    }
  if(pos[0]>left)
    return 0;
  FOR(i,0,c-1)
    if(t[(i+mip)%c]>t[(i+mip+1)%c])
      return 0;
  if(check(pos))
    return lev;
  bool ct=true;
  FOR(i,0,n)
    // if((m&(1<<i))==0 && i==((x[n-1]+1)%n) || (i==(x[0]-1+n)%n))
    if((m&(1<<i))==0)
      {
	int tmp0=pos[(n+i-1)%n];
	int num=mov(x,t,pos[i],tmp0,false);
	int r=dfs(t,m|(1<<i)|(1<<((n+i-1)%n)),left-num,lev+1,0);
	ct=false;
	if(r)
	  {
	    rec[lev][0]=pos[i];
	    rec[lev][1]=tmp0;
	    return r;
	  }
	int tmp1=(pos[(i+1)%n]-1+n)%n;
	if(tmp1!=tmp0)
	  {
	    num=mov(x,t,pos[i],tmp1,false);
	    r=dfs(t,m|(1<<i)|(1<<(i+1)%n),left-num,lev+1,0);
	    if(r)
	      {
		rec[lev][0]=pos[i];
		rec[lev][1]=tmp1;
		return r;
	      }
	  }
	  // {
	  //   int tmp2=n-1;
	  //   if(tmp2!=tmp1 && tmp2!=tmp0)
	  //     {
	  // 	num=mov(x,t,pos[i],tmp2,false);
	  // 	r=dfs(t,m|(1<<i),left-num,lev+1,0);
	  // 	if(r)
	  // 	  {
	  // 	    rec[lev][0]=pos[i];
	  // 	    rec[lev][1]=tmp2;
	  // 	    return r;
	  // 	  }
	  //     }
	  // }
      }
  // if(turn+1<4)
  //   {
  //     char tmp=x[0];
  //     FOR(i,0,n-1)
  // 	x[i]=x[i+1];
  //     x[n-1]=tmp;
  //     dfs(x,m,left,lev,turn+1);
  //   }
  return false;
}
void pt(int lev,char *x)
{
  if(lev==1)
    FOR(i,0,n)
      printf("%c",s2[x[i]]);
  if(lev==bki)
    {
      for(int i=0;x[i];++i)
	printf("%c",s2[x[i]]);
    }
  else
    {
      char y[27];
      mov(x,y,rec[lev][0],rec[lev][1],true);
      pt(lev+1,y);
    }
}
int main()
{
  // freopen("in","r",stdin);
  scanf("%d%s%s",&n,s1,s2);
  FOR(i,0,n)
    s[s2[i]]=i;
  FOR(i,0,n)
    s1[i]=s[s1[i]];
  int ans=1e9;
  for(int f=0,t=n*n;f<=t;)
    {
      int m=(f+t)>>1;
      int tmp=dfs(s1,0,m,1,0);
      if(tmp)
	{
	  t=m-1,ans=m;
	  memcpy(bak,rec,sizeof(bak));
	  bki=tmp;
	}
      else f=m+1;
    }
  printf("%d\n",ans);
  // pt(1,s1);
  return 0;
}
