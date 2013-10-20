#include <iostream>
using namespace std;
int main()
{
  int n;
  cin>>n;
  long long p[21][10][2]={0};
  for(int i=0;i<10;++i)
    p[1][i][0]=1;
  for(int i=2;i<=n;++i)
    for(int j=0;j<10;++j)
      {
	for(int k=j;k<10;++k)
	  p[i][k][0]+=p[i-1][j][0];
	for(int k=j-1;k>=0;--k)
	  p[i][k][1]+=p[i-1][j][0];
	for(int k=j;k>=0;--k)
	  p[i][k][1]+=p[i-1][j][1];
      }
  long long ans(0);
  for(int i=0;i<10;++i)
    ans+=(p[n][i][0]+p[n][i][1]);
  cout<<ans;
  return 0;
}
