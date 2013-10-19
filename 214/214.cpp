#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <string.h>
#include <stdlib.h>
#include <functional>
using namespace std;
typedef long long ll;
char sigma[201];
char stra[2001];
char strb[2001];
int p[200][200];
int q[200],qq[200];
ll ans[2000][2000];
int ia[2000],ib[2000];
char ii[200],iii[200];
ll mia[2000],mib[2000];
char ansa[4001],ansb[4001];
int trace[2000][2000];
int main()
{
  freopen("in","r",stdin);
  int n;
  map<char,int> mapp;
  for(n=0;;++n)
    {
      scanf("%c",sigma+n);
      if(sigma[n]=='\n')
	break;
      mapp[sigma[n]]=n;
    }
  int na,nb;
  for(na=0;;++na)
    {
      scanf("%c",stra+na);
      if(stra[na]=='\n')
	break;
    }
  for(nb=0;;++nb)
    {
      scanf("%c",strb+nb);
      if(strb[nb]=='\n')
	break;
    }
  for(int i=0;i<n;++i)
    {
      q[i]=1e9;
      for(int j=0;j<n;++j)
	{
	  scanf("%d",*(p+i)+j);
	  if(q[i]>p[i][j])
	    {
	      q[i]=p[i][j];
	      ii[i]=sigma[j];
	    }
	}
    }
  for(int i=0;i<n;++i)
    {
      qq[i]=1e9;
      for(int j=0;j<n;++j)
	if(qq[i]>p[j][i])
	  qq[i]=p[j][i],iii[i]=sigma[j];
    }
  for(int i=0;i<na;++i)
    ia[i]=mapp[stra[i]];
  for(int i=0;i<nb;++i)
    ib[i]=mapp[strb[i]];
  for(int i=0;i<na;++i)
    mia[i]=(i?mia[i-1]:0)+(ll)q[ia[i]];
  for(int i=0;i<nb;++i)
    mib[i]=(i?mib[i-1]:0)+(ll)qq[ib[i]];
  memset(ans,1<<6,sizeof(ans));
  for(int i=0;i<na;++i)
    for(int j=0;j<nb;++j)
      {
	ll aa=(ll)q[ia[i]]+(i>0?ans[i-1][j]:mib[j]);
	ll bb=(ll)qq[ib[j]]+(j>0?ans[i][j-1]:mia[i]);
	ll cc=p[ia[i]][ib[j]];
	if(i>0)
	  {
	    if(j>0)
	      cc+=ans[i-1][j-1];
	    else cc+=mia[i-1];
	  }
	else if(j>0)
	  cc+=mib[j-1];
	ans[i][j]=min(aa,min(bb,cc));
	if(cc <=aa && cc<=bb)
	  trace[i][j]=3;
	else if(aa<=bb)
	  trace[i][j]=2;
	else trace[i][j]=1;
      }
  cout<<ans[na-1][nb-1]<<endl;
  int pa,pb;
  pa=pb=0;
  for(int i=na-1,j=nb-1;;)
    {
      if(trace[i][j]==3)
	{
	  ansa[pa++]=stra[i];
	  ansb[pb++]=strb[j];
	  --i,--j;
	}
      else if(trace[i][j]==2)
	{
	  ansa[pa++]=stra[i];
	  ansb[pb++]=ii[ia[i]];
	  --i;
	}
      else
	{
	  ansa[pa++]=iii[ib[j]];
	  ansb[pb++]=strb[j];
	  --j;
	}
      if(i<0)
	{
	  for(;j>=0;--j)
	    {
	      ansa[pa++]=iii[ib[j]];
	      ansb[pb++]=strb[j];
	    }
	  break;
	}
      else if(j<0)
	{
	  for(;i>=0;--i)
	    {
	      ansa[pa++]=stra[i];
	      ansb[pb++]=ii[ia[i]];
	    }
	    break;
	}
    }
  for(int i=pa-1;i>=0;--i)
    printf("%c",ansa[i]);
  printf("\n");
  for(int i=pb-1;i>=0;--i)
    printf("%c",ansb[i]);
  return 0;
}
