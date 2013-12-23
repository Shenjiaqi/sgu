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
int s[2][10][13];
int len[2][10];
int z[13];
int msk[2][10][13];
void calmsk(const char *a,const char *b,int la,int lb,int m[13])
{
  int t[13][13]={0};
  t[la][lb]=1;
  memset(m,0,sizeof(m));
  for(int i=la;i>=0;--i)
    for(int j=lb;j>=0;--j)
      if( (i+1<=la && t[i+1][j]) || (i+1<=la && j+1<=lb && t[i+1][j+1] &&
				     a[i]==b[j]) )
	{
	  t[i][j]=1;
	  if(a[i]==b[j])
	    m[j]|=1<<i;
	}
	  
}
bool test(int left)
{
  int lz=strlen(z);
  FOR(i,0,2)
    FOR(j,0,n[i])
    calmsk(s[i][j],z,len[i][j],lz,msk[i][j]);
  FOR(i,0,n[0])
    if(msk[0][i][0]==0)
      return false;
  int v=(1<<n[1])-1;
  FOR(i,0,n[1])
    if(msk[1][i][0]==0)
      v^=(1<<i);
  return dfs(0,v,left);
}
int main()
{
  scanf("%d%d",&n[0],&n[1]);
  FOR(i,0,2)
    FOR(j,0,n[i])
    {
      s[i][j][0]='A';
      scanf("%s",s[i][j]+1);
      len[i][j]=strlen(s[i][j]);
    }
  int c=0;
  FOR(i,1,n[0])
    if(len[c]>len[i])
      c=i;
  map<char,int> mapp;
  FOR(i,0,len[c])
    mapp[s[0][c][i]]=1;
  int cnt=0;
  FR(i,mapp)
    i->SEC=++cnt;
  for(int m=(1<<(len[c]-1))-1;m>=0;--m)
    {
      z[0]='A';
      int l=1;
      ll hs=0;
      for(int i=1;i<len[c];++i)
	if((1<<(i-1))&m)
	  {
	    z[l++]=s[0][c][i];
	    hs=(hs<<4)|mapp[s[0][c][i]];
	  }
      z[l]=0;
      if(mappp.find(hs)==mappp.end() && test(len[c]-l))
	{
	  for(int i=0;;++i)
	    {
	      if(i<cj)
		{
		  for(int j=0;j<lev[i][0];++j)
		    printf("?");
		  if(lev[i][1])
		    printf("*");
		}
	      else
		printf("*");
	      if(z[i])
		printf("%c",z[i]);
	      else return 0;
	    }
	}
      mappp[hs]=1;
    }
  printf("OOPS");
  return 0;
}
