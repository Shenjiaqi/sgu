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
#define N 107
ld c[N],p[N][N],q[N];
ld ans;
ld di;
// void dfs(int mi,int left,ld acu,int cnt,int mx)
// {
//   if(left==0)
//     {
//       ans+=acu*cnt/di;
//       return ;
//     }
//   if(mi<2)
//     return ;
//   if(mi==2)
//     {
//       if(0==(left&1))
// 	{
// 	  if(mx==0)
// 	    mx=2;
// 	  if(mi-1>=(mx+1)/2)
// 	    cnt+=left;
// 	  ans+=acu*cnt*q[left]/p[left/2][left/2]/di;
// 	}
//       return ;
//     }
//   for(int i=0,j=left/mi;i<=j;++i)
//     {
//       dfs(min(mi-1,left),left,acu/p[i][i],cnt,mx);
//       if(mx==0)
// 	mx=mi;
//       acu*=p[left][mi]/mi;
//       left-=mi;
//       if(mi-1>=(mx+1)/2)
// 	cnt+=mi;
//     }
// }
void dfs(int mi,int left,ld acu,int cnt)
{
  if(left==0)
    {
      ans+=acu*cnt;
      return ;
    }
  if(mi<2)
    return ;
  if(mi==2)
    {
      if(0==(left&1))
	{
	  if(cnt==0)
	    cnt=left;
	  ans+=cnt*acu*q[left]/p[left/2][left/2];
	}
      return ;
    }
  int rcnt=cnt;
  for(int i=0,j=left/mi;i<=j;++i)
    {
      dfs(min(mi-1,left),left,acu/p[i][i],cnt);
      if(rcnt==0)
	cnt+=mi;
      acu*=p[left][mi]/mi;
      left-=mi;
    }
}

int main()
{
  // int n;
  // scanf("%d",&n);
  c[0]=1,c[1]=0;
  FOR(i,2,N)
    c[i]=(ld)(i-1)*(c[i-1]+c[i-2]);
  FOR(i,0,N)
    {
      p[i][0]=1;
      FOR(j,1,i+1)
	p[i][j]=p[i][j-1]*(ld)(i-j+1);
    }
  q[0]=1;
  for(int i=2;i<N;i+=2)
    q[i]=q[i-2]*p[i][2]/2;
  for(int i=2;i<=100;++i)
    {
      di=c[i];
      ans=0;
      dfs(i,i,1,0);
      printf("\"%.10lf\",",(double)(ans/c[i]));
    }
  return 0;
}
