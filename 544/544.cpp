#include <cstdio>
#include <iostream>
#include <algorithm>
#include <utility>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;
#define N 500
#define K N
typedef long long ll;
const ll mod=1e9+9;
int dp[2][N+1][K+1];
int main()
{
  freopen("in.txt","r",stdin);
  int n,k;
  scanf("%d%d",&n,&k);
  if((n+k)&1)
    {
      printf("0");
      return 0;
    }
  typedef pair<int,int> pp;
  vector<pp> p;
  for(int i=0;i<2;++i)
    for(int j=0;j<n;++j)
      {
	int v;
	scanf("%d",&v);
	p.push_back(pp(v,i));
      }
  sort(p.begin(),p.end());
  dp[0][0][0]=1;
  int x=(k+n)>>1;
  int y=x-k;
  int nn[2]={0};
  for(int i=0;i<2*n;++i)
    {
      int f=i&1;
      int t=f^1;
      memset(dp[t],0,sizeof(dp[t]));
      for(int j=0;j<=min(x,i>>1);++j)
	for(int l=0;l<=min(y,(i>>1)-j);++l)
	  {
	    ll tmp;
	    int a,b;
	    if(p[i].second==0)
	      tmp=nn[1]-(j+l),a=j+1,b=l;
	    else tmp=nn[0]-(j+l),a=j,b=l+1;
	    if(tmp>0 && a<=x && b<=y)
	      dp[t][a][b]=((ll)dp[t][a][b]+((ll)dp[f][j][l]*tmp)%mod)%mod;
	    dp[t][j][l]=(dp[t][j][l]+dp[f][j][l])%mod;
	  }
      ++nn[p[i].second];
    }
  printf("%d",dp[0][x][y]);
  return 0;
}
