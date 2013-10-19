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
#define N 1000000
int p[N+1];
int q[N],qoi;
ll ans;
int ccc;
void df(int l,int num,int nn,int mm)
{
  ++ccc;
  if(l>=qoi || q[l]>nn || q[l]>mm)
    return ;
  df(l+1,num,nn,mm);
  nn/=q[l],mm/=q[l];
  ++num;
  if(num&1)
    ans-=((ll)mm*(ll)nn);
  else ans+=((ll)mm*(ll)nn);
  df(l+1,num,nn,mm);
}
int main()
{
  freopen("in","r",stdin);
  int n,m;
  cin>>n>>m;
  if(n==1 || m==1)
    {
      if(n==1 && m==1)
	cout<<0;
      else
	cout<<1;
      return 0;
    }
  for(int i=2;i<=N;++i)
    if(p[i]==0)
      {
	for(ll j=(ll)i*(ll)i;j<=N;j+=(ll)i)
	  p[j]=1;
	q[qoi++]=i;
      }
  --m,--n;
  ans=(ll)m*(ll)n+2;
  df(0,0,n,m);
  cout<<ans;
  return 0;
}
