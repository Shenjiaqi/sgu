#include <cstdio>
#include <vector>
#include <utility>
using namespace std;
#define N (1000000)
int main()
{
  //freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  vector<bool> primes(N+1,true);
  vector<int> primenum;
  primes[0]=primes[1]=false;
  for(int i=2;i*i<=n;++i)
    if(primes[i])
      for(int j=i*i;j<=n;j+=i)
	primes[j]=false;
  vector<int>pripair;
  for(int i=5;i<=n;++i)
    if(primes[i-2] && primes[i])
      pripair.push_back(i-2);
  printf("%d\n",(int)pripair.size());
  for(int i=0;i<pripair.size();++i)
    printf("2 %d\n",pripair[i]);
  return 0;
}
