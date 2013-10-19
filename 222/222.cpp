#include <cstdio>
typedef long long ll;
#define N (10)
#define K (N*N)
#define M (N)
ll nk[N+1][M+1][K+1];
ll df(int n,int m,int k)
{
  if(n<k || m<k)
    return (ll)0;
  if(k==0)
    return 1;
  if(nk[n][m][k])
    return nk[n][m][k];
  nk[n][m][k]=df(n-1,m,k);
  nk[n][m][k]+=df(n-1,m-1,k-1)*(ll)m;
  return nk[n][m][k];
}
int main()
{
  int n,k;
  scanf("%d %d",&n,&k);
  printf("%lld",df(n,n,k));
  return 0;
}
