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
#define N 1000
char p[N];
int dp[N+1][4][4][4][2];
#define U 0
#define D 1
#define L 2
#define R 3
#define LL 1
#define LR 2
int func[128];
char cnuf[4];
int inf;
int cal(int c,int to,int fl,int fr,int fc,int tl,int tr,int tc)
{
  if(c>=inf || tl==tr || (tl==R && tr==L))
    return inf;
  if(to>=0 && ( (tl!=to && tr!=to ) || tc==0) )
    return inf;
  if(fl==tl && fr==tr && to<0 && tc==0)
    return c;
  if(fl==tl && fr==tr && (((tl==to||to<0) && (tc&LL)) || ((tr==to||to<0) && (tc&LR))) )
    return c+1;
  if(((tc&LR) && fl==tl && !(fc&LR) && (tr==to || to<0)) ||
     ((tc&LL) && fr==tr && !(fc&LL) && (tl==to || to<0)))
    return c+3;
  if(((tc&LL) && (fc&LL) && fr==tr && (tl==to || to<0)) ||
     ((tc&LR) && (fc&LR) && fl==tl && (tr==to || to<0)))
    return c+9;
  if((tc&LL) && (tc&LR))
    return c+10;
  return inf;
}
void pt(int k,int l,int r,int c)
{
  int tmp=dp[k][l][r][c][1];
  if(k)
    {
      pt(k-1,tmp>>10,(tmp>>5)&((1<<5)-1),tmp&((1<<5)-1));
      printf("\n%c%c",cnuf[l],cnuf[r]/*,c,dp[k][l][r][c][0]*/);
    }
}
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d%s",&n,p);
  func[cnuf[L]='L']=L;
  func[cnuf[R]='R']=R;
  func[cnuf[U]='U']=U;
  func[cnuf[D]='D']=D;
  func['N']=-1;
  memset(dp,1<<6,sizeof(dp));
  inf=dp[0][0][0][0][0];
  FOR(i,0,4)
    dp[0][L][R][i][0]=0;
  FOR(i,1,n+1)
    FOR(j,0,4)
    FOR(k,0,4)
    if(k!=j)
      FOR(l,0,4)
	if(dp[i-1][j][k][l][0]<inf)
	  FOR(jj,0,4)
	    FOR(kk,0,4)
	    if(jj!=kk)
	      FOR(lll,0,4)
		{
		  int t=cal(dp[i-1][j][k][l][0],func[p[i-1]],j,k,l,jj,kk,lll);
		  if(t<dp[i][jj][kk][lll][0])
		    dp[i][jj][kk][lll][0]=t,dp[i][jj][kk][lll][1]=(j<<10)|(k<<5)|l;
		}
  int m=inf;
  int ii,jj,kk;
  FOR(i,0,4)
    FOR(j,0,4)
    FOR(k,0,4)
    if(m>dp[n][i][j][k][0])
      m=dp[n][i][j][k][0],ii=i,jj=j,kk=k;
  printf("%d",m);
  pt(n,ii,jj,kk);
  return 0;
}
