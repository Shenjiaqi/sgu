#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;
#define P (1000)
typedef long long ll;
ll arrive[2][P+1][P+1]={0};
int main()
{
  //freopen("in","r",stdin);
  bool prime[P]={0};
  for(int i=2;i*i<P;++i)
    if(!prime[i])
      for(int j=i*i;j<P;j+=i)
	prime[j]=1;
  int ans[P+1]={0};
  FILE * fd=fopen("out","w");
  for(int i=3;i<P;++i)
    if(!prime[i])
      {
	printf("!%d\n",i);
	memset(arrive,0,sizeof(arrive));
	for(int j=0;j<2*i;++j)
	  {
	    int f,t;
	    f=j&1,t=1-f;
	    memcpy(arrive[t],arrive[f],sizeof(arrive[0]));
	    arrive[t][j%i][1]+=(ll)1;
	    for(int k=0;k<i;++k)
	      for(int l=1;l<i/*min(i,j+1)*/;++l)
		if(arrive[f][k][l])
		  arrive[t][(k+j)%i][l+1]+=arrive[f][k][l];
	  }
	fprintf(fd,"\"%lld\", ",arrive[((2*i)&1)][0][i]);
      }
  return 0;
}
