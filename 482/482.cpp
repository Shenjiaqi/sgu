#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
using namespace std;
typedef long long ll;
#define N 50
#define L 100
int dp[2][N*L+1][L+1][3];
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  int p[N];
  for(int i=0;i<n;++i)
    scanf("%d",p+i);
  int b(0);
  for(int i=0,pre=0;i<n;pre=p[i++])
    b+=(2+abs(pre-p[i]));
  b+=p[n-1];
  for(int i=0,ll=0;i<n;ll+=p[i++])
    {
      int f=i&1;
      int t=1^f;
      dp[f][0][0][0]=1;
      for(int j=0;j<=ll;++j)
	for(int k=0;k<=L;++k)
	  {
	    if(dp[f][j][k][0]>0)
	      {
		int tmp=j+p[i];
		if(tmp<=N*L && dp[t][tmp][k][0]<dp[f][j][k][0])
		  {
		    for(int l=0;l<3;++l)
		      dp[t][tmp][k][l]=dp[f][j][k][l];
		    dp[t][tmp][k][1+i/32]|=(1<<(i%32));
		    //cout<<'!'<<i<<' '<<tmp<<' '<<k<<' '<<dp[t][tmp][k][0]<<endl;
		  }
		if(dp[t][j][p[i]][0]<dp[f][j][k][0]+abs(k-p[i])+2)
		  {
		    dp[t][j][p[i]][0]=dp[f][j][k][0]+abs(k-p[i])+2;
		    dp[t][j][p[i]][1]=dp[f][j][k][1];
		    dp[t][j][p[i]][2]=dp[f][j][k][2];
		    //dp[t][j][p[i]][1+i/32]|=(1<<(i%32));
		    //cout<<i<<' '<<j<<' '<<p[i]<<' '<<dp[t][j][p[i]][0]<<endl;
		  }
	      }
	  }
      memset(dp[f],0,sizeof(dp[0]));
    }
  //cout<<b<<endl;
  for(int i=L*N;i>0;--i)
    for(int j=1;j<=L;++j)
      if(dp[1&n][i][j][0]>0 && dp[1&n][i][j][0]+j-1>=b/2)
	{
	  printf("%d\n",i);
	  int output[N],num(0);
	  for(int k=0;k<n;++k)
	    if(dp[1&n][i][j][1+k/32]&(1<<(k%32)))
	      output[num++]=k+1;
	  printf("%d\n",num);
	  for(int i=0;i<num;++i)
	    printf("%d ",output[i]);
	  return 0;
	}
  printf("0\n0");
  return 0;
}
