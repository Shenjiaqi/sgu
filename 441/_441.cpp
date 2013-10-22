#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
const int mod=2007;
#define K 10
typedef long long ll;
int p[K+1][K+1];
int q[K+1][K+1];
void mul(int a[][K+1],int b[][K+1],int s)
{
  static int c[K+1][K+1];
  memset(c,0,sizeof(c));
  for(int i=0;i<=s;++i)
    for(int j=0;j<=s;++j)
      for(int k=0;k<=s;++k)
	c[i][j]=((ll)c[i][j]+(ll)a[i][k]*(ll)b[k][j])%mod;
  memcpy(a,c,sizeof(c));
}
void pt(int a[][K+1],int s)
{
  for(int i=0;i<s;++i)
    {
      for(int j=0;j<s;++j)
	cout<<a[i][j]<<' ';
      cout<<endl;
    }
  cout<<endl<<endl;
}
int main()
{
  freopen("in.txt","r",stdin);
  int n,k;
  cin>>n>>k;
  q[0][0]=1;
  for(int i=1;i<=k;++i)
    q[i][i]=1,p[i][i]=i,p[i][i-1]=1;
  for(int i=1;i<=n;i<<=1)
    {
      if(i&n)
	mul(q,p,k);
      mul(p,p,k);
    }
  cout<<q[k][0]<<endl;
  return 0;
}
