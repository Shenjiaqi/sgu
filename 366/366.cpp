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
int val[101][21][2];
int dp[20][2001][22];
int main()
{
  freopen("in","r",stdin);
  int n,k;
  scanf("%d%d",&n,&k);
  for(int i=0;i<n;++i)
    {
      int a,b;
      scanf("%d%d",&a,&b);
      int c=a-b+50;
      if(val[c][0][0]<k)
	{
	  int d=++val[c][0][0];
	  val[c][d][0]=a+b;
	  val[c][d][1]=i+1;
	}
      else
	{
	  int t=1e9;
	  int it=0;
	  for(int j=1;j<=val[c][0][0];++j)
	    if(t>val[c][j][0])
	      t=val[c][j][0],it=j;
	  if(t<a+b)
	    val[c][it][0]=a+b,val[c][it][1]=i+1;
	}
    }
  for(int i=0;i<101;++i)
    for(int j=1;j<=val[i][0][0];++j)
      for(int l=2;l<=val[i][0][0]-j+1;++l)
	if(val[i][l][0]>val[i][l-1][0])
	  val[i][l][0]^=val[i][l-1][0],val[i][l][1]^=val[i][l-1][1],
	    val[i][l-1][0]^=val[i][l][0],val[i][l-1][1]^=val[i][l][1],
	    val[i][l][0]^=val[i][l-1][0],val[i][l][1]^=val[i][l-1][1];
  /*for(int i=0;i<101;++i)
    if(val[i][0][0])
      {
	cout<<i<<endl;
	for(int j=1;j<=val[i][0][0];++j)
	  cout<<val[i][j][0]<<' '<<val[i][j][1]<<endl;
	cout<<endl;
	}*/
  for(int i=0;i<101;++i)
    if(val[i][0][0])
      for(int j=1;j<=val[i][0][0];++j)
	{
	  for(int l=k-2;l>=0;--l)
	    for(int m=0;m<=2000-val[i][j][0];++m)
	      if(dp[l][m][0] && (dp[l+1][m+i][0]==0 || dp[l+1][m+i][1]<dp[l][m][1]+val[i][j][0]) )
		{
		  for(int o=2;o<=2+l;++o)
		    dp[l+1][m+i][o]=dp[l][m][o];
		  dp[l+1][m+i][0]=1;
		  dp[l+1][m+i][1]=dp[l][m][1]+val[i][j][0];
		  dp[l+1][m+i][2+l+1]=val[i][j][1];
		}
	  if(dp[0][i][0]==0 || dp[0][i][1]<val[i][j][0])
	    dp[0][i][0]=1,
	      dp[0][i][1]=val[i][j][0],
	      dp[0][i][2]=val[i][j][1];
	}
  int ansc,ansd;
  ansc=2001,ansd=-1;
  for(int i=0;i<=2000;++i)
    if(dp[k-1][i][0])
    {
      int t=abs(i-50*k);
      int tt=abs(ansc-50*k);
      if(t<tt || (t==tt && ansd<dp[k-1][i][1]))
	ansc=i,ansd=dp[k-1][i][1];
    }
  cout<<(((ansc-50*k)+ansd)/2)<<' '<<((ansd-(ansc-50*k))/2)<<endl;
  sort(&dp[k-1][ansc][2],&dp[k-1][ansc][2+k]);
  for(int i=2;i<2+k;++i)
    cout<<dp[k-1][ansc][i]<<' ';
  return 0;
}
