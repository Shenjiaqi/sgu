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
int n[2];
char buf[2][10][15];
char bak[15];
int sta[2][10];
int mmm[17];
int msk[2][10][15];
int lev[17][2],zk;
bool tab[15][15];
bool substr(const char *a,const char *b)
{
  int i,j;
  i=j=0;
  for(;a[i] && b[j];++i)
    if(a[i]==b[j])
      ++j;
  return b[j]==0;
}
int mm(int v)
{
  if(v==0)
    return 0;
  return mmm[__builtin_ctz(v&(-v))];
}
bool fill(int v,int k,int left,int st[2][10])
{
  if(v==0)
    {
      zk=k;
      return true;
    }
  if(bak[k]==0)
    return false;
  int s[2][10];
  for(int i=0;i<=left;++i)
    {
      bool c=true;
      int vv=v;
      for(int j=0;c && j<2;++j)
	for(int l=0;c && l<n[j];++l)
	  {
	    if(j==0 || (v&(1<<l)))
	      {
		s[j][l]=(st[j][l]<<(i+1))&msk[j][l][k+1];
		if(s[j][l]==0)
		  {
		    if(j==0)
		      c=false;
		    else vv^=(1<<l);
		  }
	      }
	  }
      lev[k][0]=i;
      if(c)
	{
	  lev[k][1]=0;
	  if(fill(vv,k+1,left-i,s))
	    return true;
	}
      vv=v;
      c=true;
      for(int j=0;c && j<2;++j)
	for(int l=0;c && l<n[j];++l)
	  {
	    if(j==0 || (v&(1<<l)))
	      {
		s[j][l]=mm((st[j][l]<<(i+1))&((1<<15)-1))&msk[j][l][k+1];
		if(s[j][l]==0)
		  {
		    if(j==0)
		      c=false;
		    else vv^=(1<<l);
		 }
	      }
	  }
      if(c)
	{
	  lev[k][1]=1;
	  if(fill(vv,k+1,left-i,s))
	    return true;
	}
    }
  return false;
}
void cal(const char *f, const char *t,int m[15])
{
  int lf=strlen(f);
  int lt=strlen(t);
  memset(tab,0,sizeof(tab));
  tab[lf][lt]=true;
  for(int i=lf;i>=0;--i)
    for(int j=lt;j>=0;--j)
      if((i+1<=lf && tab[i+1][j]) || (i+1<=lf && j+1<=lt && tab[i+1][j+1] && f[i]==t[j]))
	tab[i][j]=true;
  memset(m,0,sizeof(m));
  for(int i=0;i<=lf;++i)
    for(int j=0;j<=lt;++j)
      if(f[i]==t[j] && tab[i][j])
	m[j]|=(1<<i);
}
bool test(int l)
{
  for(int i=1;i<n[0];++i)
    if(!substr(buf[0][i],bak))
      return false;
  int v=0;
  for(int i=0;i<n[1];++i)
    if(substr(buf[1][i],bak))
      v|=(1<<i);
  for(int i=0;i<2;++i)
    for(int j=0;j<n[i];++j)
      if(i==0 || (v&(1<<j)))
	{
	  cal(buf[i][j],bak,msk[i][j]);
	  sta[i][j]=1;
	}
  return fill(v,0,l,sta);
}
int main()
{
  mmm[16]=1<<16;
  for(int i=15;i>=0;--i)
    mmm[i]=mmm[i+1]|(1<<i);
  scanf("%d%d",&n[0],&n[1]);
  FOR(i,0,2)
    FOR(j,0,n[i])
    {
      buf[i][j][0]=1;
      if(EOF==scanf("%s",buf[i][j]+1))
	return 1;
    }
  int l=strlen(buf[0][0]);
  int mil=100;
  for(int i=0;i<n[0];++i)
    mil=min(mil,(int)strlen(buf[0][i]));
  map<char,int> mapp;
  for(int i=strlen(buf[0][0])-1;i>0;--i)
    mapp[buf[0][0][i]]=1;
  int cnt=0;
  FR(i,mapp)
    i->SEC=++cnt;
  assert(cnt<16);
  map<ll,int> mappp;
  for(int i=(1<<(l-1))-1;i>=0;--i)
    {
      bak[0]=1;
      int j=1;
      for(int k=1;k<l;++k)
	if((1<<(k-1))&i)
	  bak[j++]=buf[0][0][k];
      bak[j]=0;
      ll tmp=0;
      for(int k=1;k<j;++k)
	tmp=(tmp<<4)|mapp[bak[k]];
      if(mappp.find(tmp)==mappp.end() && mil>=j && test(mil-j))
	{
	  for(int k=1;;++k)
	    {
	      int kk=k-1;
	      if(kk<zk)
		{
		  for(int l=0;l<lev[kk][0];++l)
		    printf("?");
		  if(lev[kk][1])
		    printf("*");
		}
	      else
		printf("*");
	      if(bak[k]==0)
		break;
	      printf("%c",bak[k]);
	    }
	  return 0;
	}
      mappp[tmp]=1;
    }
  printf("OOPS");
  return 0;
}
