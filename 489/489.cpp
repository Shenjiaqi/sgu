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
#define N 10000
int dp[N][2][2];
int main()
{
  //freopen("in","r",stdin);
  int n,m;
  scanf("%d%d",&n,&m);
  if(n==1)
    printf("%d",1%m);
  else
    {
      int f=0,t=1;
      dp[1][1][f]=1;//dp[0][0][f]=1;
      for(int i=2;i<n;++i,swap(f,t))
	{
	  // dp[i][0][t]=0;
	  // for(int j=i-1;j>=0;--j)
	  //     dp[j][0][t]=(dp[j+1][0][t]+dp[j][1][f])%m;
	  dp[0][1][t]=0;
	  for(int j=1;j<=i;++j)
	    dp[j][1][t]=(dp[j-1][1][t]+dp[i-(j-1)-1][1][f])%m;
			 //dp[j-1][0][f])%m;
	}
      int ans(0);
      for(int i=0;i<n;++i)
	for(int j=0;j<2;++j)
	  {//cout<<i<<' '<<j<<' '<<dp[i][j][f]<<endl;
	    ans=(ans+dp[i][j][f])%m;
	  }
      printf("%d",(ans*2)%m);
    }

  // vector<int> tmp;
  // for(int i=0;i<n;++i)
  //   tmp.push_back(i);
  // int cnt(0);
  // for(;;)
  //   {
  //     int i;
  //     for(i=1;i<n-1;++i)
  // 	if(!((tmp[i]<tmp[i+1] && tmp[i]<tmp[i-1]) || 
  // 	     (tmp[i]>tmp[i+1] && tmp[i]>tmp[i-1])))
  // 	  break;
  //     if(i>=n-1)
  //     	{
  //     	  // FR(j,tmp)
  //     	  //   cout<<*j<<' ';
  //     	  // cout<<endl;
  //     	  ++cnt;
  // 	  cnt%=m;
  //     	}
  //     if(!next_permutation(tmp.begin(),tmp.end()))
  // 	break;;
  //   }
  // cout<<endl<<cnt<<endl;
  return 0;
}
