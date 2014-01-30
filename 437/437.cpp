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
#define N 31
int n,k;
int chklst[N];
int val[N],cnt;
int grp[7];
vector<int> ingrp[N];
int lev[N],ri[N],li[N];
int mlev[7],mr[7],ml[7];
inline void mm(int idx,int tmp)
{
  mlev[lev[idx]]^=tmp;
  mr[ri[idx]]^=tmp;
  ml[li[idx]]^=tmp;
  FR(i,ingrp[idx])
    grp[*i]^=tmp;
}
inline int getmsk(int idx)
{
  int msk=mlev[lev[idx]]&mr[ri[idx]]&ml[li[idx]];
  FR(i,ingrp[idx])
    msk&=grp[*i];
  return msk;
}
bool check(int idx)
{
  int tmp=chklst[idx];
  if(tmp>idx && val[tmp]==0)
    return getmsk(chklst[idx])!=0;
  return true;
}
void dfs(int idx)
{
  if(idx>=N)
    ++cnt;
  else if(val[idx])
    dfs(idx+1);
  else
    {
      int msk=getmsk(idx);
      int tmp=0;
      for(;msk;)
	{
	  tmp^=msk&(-msk);
	  mm(idx,tmp);
	  if(check(idx))
	    dfs(idx+1);
	  tmp=msk&(-msk);
	  if(cnt>=n)
	    {
	      val[idx]=__builtin_ctz(tmp)+1;
	      return ;
	    }
	  msk^=tmp;
	}
      mm(idx,tmp);
    }
}
int main()
{
  // freopen("in","r",stdin);
  ingrp[0].PB(0);
  ingrp[1].PB(0);
  ingrp[2].PB(1);
  ingrp[3].PB(0),ingrp[3].PB(1);
  ingrp[4].PB(0);
  ingrp[5].PB(0),ingrp[5].PB(2);
  ingrp[6].PB(2);
  ingrp[7].PB(1);
  ingrp[8].PB(1);
  ingrp[9].PB(0),ingrp[9].PB(1),ingrp[9].PB(3);
  ingrp[10].PB(0),ingrp[10].PB(2),ingrp[10].PB(3);
  ingrp[11].PB(2);
  ingrp[12].PB(2);
  ingrp[13].PB(1),ingrp[13].PB(4);
  ingrp[14].PB(1),ingrp[14].PB(3),ingrp[14].PB(4);
  ingrp[15].PB(3);
  ingrp[16].PB(2),ingrp[16].PB(3),ingrp[16].PB(5);
  ingrp[17].PB(2),ingrp[17].PB(5);
  ingrp[18].PB(4);
  ingrp[19].PB(4);
  ingrp[20].PB(3),ingrp[20].PB(4),ingrp[20].PB(6);
  ingrp[21].PB(3),ingrp[21].PB(5),ingrp[21].PB(6);
  ingrp[22].PB(5);
  ingrp[23].PB(5);
  ingrp[24].PB(4);
  ingrp[25].PB(4),ingrp[25].PB(6);
  ingrp[26].PB(6);
  ingrp[27].PB(5),ingrp[27].PB(6);
  ingrp[28].PB(5);
  ingrp[29].PB(6);
  ingrp[30].PB(6);
  ri[2]=ri[7]=0;
  ri[0]=ri[3]=ri[8]=ri[13]=ri[18]=1;
  ri[1]=ri[4]=ri[9]=ri[14]=ri[19]=ri[24]=2;
  ri[5]=ri[10]=ri[15]=ri[20]=ri[25]=3;
  ri[6]=ri[11]=ri[16]=ri[21]=ri[26]=ri[29]=4;
  ri[12]=ri[17]=ri[22]=ri[27]=ri[30]=5;
  ri[23]=ri[28]=6;
  li[6]=li[12]=0;
  li[1]=li[5]=li[11]=li[17]=li[23]=1;
  li[0]=li[4]=li[10]=li[16]=li[22]=li[28]=2;
  li[3]=li[9]=li[15]=li[21]=li[27]=3;
  li[2]=li[8]=li[14]=li[20]=li[26]=li[30]=4;
  li[7]=li[13]=li[19]=li[25]=li[29]=5;
  li[18]=li[24]=6;
  memset(chklst,1<<7,sizeof(chklst));
  FOR(i,n,24)
    chklst[i]=i+5;
  FOR(i,0,2)
    lev[i]=0;
  FOR(i,2,7)
    lev[i]=1;
  FOR(i,7,13)
    lev[i]=2;
  FOR(i,13,18)
    lev[i]=3;
  FOR(i,18,24)
    lev[i]=4;
  FOR(i,24,29)
    lev[i]=5;
  FOR(i,29,31)
    lev[i]=6;
  scanf("%d%d",&k,&n);
  FOR(i,0,7)
    mlev[i]=mr[i]=ml[i]=grp[i]=((1LL<<k)-1LL);
  FOR(i,0,N)
    scanf("%d",val+i);
  bool c=true;
  FOR(i,0,31)
    if(val[i]>0)
      {
	int msk=getmsk(i);
	int tmp=(1<<(val[i]-1));
	if(msk&tmp)
	  mm(i,tmp);
	else
	  c=false;
      }
  if(c)
    dfs(0);
  if(cnt<n)
    {
      printf("No way");
    }
  else
    {
      printf("Found\n");
      FOR(i,0,N)
	printf("%d ",val[i]);
    }
  return 0;
}
