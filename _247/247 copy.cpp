#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define P (1000)
typedef long long ll;
char (*str)[]={};
int main()
{
  //freopen("in","r",stdin);
  bool prime[P]={0};
  for(int i=2;i*i<P;++i)
    if(!prime[i])
      for(int j=i*i;j<P;j+=i)
	prime[j]=1;
  char * ans[P]={NULL};
  for(int i=3,j=0;i<P;++i)
    if(!prime[i])
      ans[i]=j++;
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;++i)
    printf("%s",str+ans[i]);
  return 0;
}
