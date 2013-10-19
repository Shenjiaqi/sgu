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
#define M 30
char p[N*2][M+1];
int dp[N][2][1<<N][2];
int idt[N][2][N][2];
int len[N*2];
char ans[M*N*2+1];
void pt(int l,int k,int left,int off)
{
  //cout<<l<<' '<<k<<' '<<left<<' '<<off<<endl;
  // if(left==(1<<l))
  //   {
  //     int leng=idt[l][1^k][l][k]+len[l];
  //     leng=(leng+1)>>1;
  //     for(int i=0;i<leng;++i)
  // 	ans[off++]=p[l+N*k][i];
  //   }
  // else
    {
      int z=dp[l][k][left][1]>>20;
      int k_=dp[l][k][left][1]&1;
      int lleft=(dp[l][k][left][1]&((1<<20)-1))>>1;
      //cout<<z<<' '<<lleft<<' '<<dp[l][k][left][1]<<endl;
      if(lleft)
	{
	  int leng=idt[z][k_][l][k];
	  for(int i=0;i<leng;++i)
	    ans[off++]=p[l+N*k][i];
	  pt(z,k_,lleft,off);
	}
      else
       	for(int i=0;i<((idt[l][1^k][l][k]+len[l]+1)>>1);++i)
       	  ans[off++]=p[l+N*k][i];
   }
}
int dfs(int l,int k,int left)
{
  int rleft=left;
  if(dp[l][k][rleft][0]==0)
    {
      for(int i=left;i;i^=(i&(-i)))
	{
	  int h=i&(-i);
	  int z=__builtin_ctz(h);
	  if(idt[z][0][l][0]+len[z]<=len[l] || idt[z][0][l][1]+len[z]<=len[l])
	    left^=h;
	}
      if(left==0)
	dp[l][k][rleft][0]=idt[l][k^1][l][k]+len[l];
      else
	{
	  int r=1e9,rr=0;
	  for(int i=left;i;i^=(i&(-i)))
	    {
	      int h=i&(-i);
	      int z=__builtin_ctz(h);
	      int tmp=dfs(z,0,left);
	      if(tmp+2*idt[z][0][l][k]<r)
		r=tmp+2*idt[z][0][l][k],rr=(z<<20)|((left)<<1);
	      tmp=dfs(z,1,left);
	      if(tmp+2*idt[z][1][l][k]<r)
		r=tmp+2*idt[z][1][l][k],rr=(z<<20)|((left)<<1)|1;
	    }
	  dp[l][k][rleft][1]=rr;
	  dp[l][k][rleft][0]=r;
	}
    }
  return dp[l][k][rleft][0];
}
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  FOR(i,0,n)
    {
      scanf("%s",*(p+i));
      len[i]=strlen(p[i]);
      FOR(j,0,len[i])
	p[N+i][j]=p[i][len[i]-1-j];
      len[N+i]=len[i];
    }
  for(int i=0;i<n;++i)
    for(int ii=0;ii<2;++ii)
      for(int j=0;j<n;++j)
	for(int jj=0;jj<2;++jj)
	  {
	    int a=i+ii*N;
	    int b=j+jj*N;
	    for(int off=0;off<=len[b];++off)
	      {
		idt[i][ii][j][jj]=off;
		for(int k=0;idt[i][ii][j][jj]==off && k<len[a] && k+off<len[b];++k)
		  if(p[a][k]!=p[b][k+off])
		    idt[i][ii][j][jj]=1e9;
		if(idt[i][ii][j][jj]==off)
		  break;
	      }
	  }
  int mm=1e9;
  int a,b;
  for(int i=0;i<n;++i)
    for(int j=0;j<2;++j)
      {
	int tmp=dfs(i,j,(1<<n)-1);
	if(tmp<mm)
	  mm=tmp,a=i,b=j;
      }
  //cout<<mm<<endl;
  pt(a,b,(1<<n)-1,0);
  printf("%s",ans);
  int z=strlen(ans)-1;
  if(mm&1)
    --z;
  for(;z>=0;--z)
    printf("%c",ans[z]);
  return 0;
}
