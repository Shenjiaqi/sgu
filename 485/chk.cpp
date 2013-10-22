#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define N 25
int p[N*3];
int n,t;
int cal(int v)
{
  vector<int> a,c;
  for(int i=1,j=3*n-1;j>=n;i<<=1,--j)
    if(i&v)
      a.push_back(p[j]);
    else c.push_back(p[j]);
  int r(0);
  for(int i=0;i<n;++i)
    r+=(a[i]-p[i])*c[i];
  return r;
}
int main()
{
  freopen("in.txt","r",stdin);
  scanf("%d%d",&t,&n);
  for(;t--;)
    {
      for(int i=0;i<n*3;++i)
	scanf("%d",p+i);
      sort(p,p+n*3);
      for(int i=0;i<3*n;++i)
	cout<<p[i]<<' ';
      cout<<endl;
      int ans=0;
      int kk=0;
      for(int i=(1<<n)-1;i<(1<<(2*n));)
	{
	  int tmp=__builtin_popcount(i);
	  if(tmp==n)
	    {
	      int tt=cal(i);
	      if(ans<tt)
		ans=tt,kk=i;
	      ++i;
	    }
	  else if(tmp>n)
	    i+=(i&(-i));
	  else ++i;
	}
      vector<int> a,c;
      for(int i=1,j=3*n-1;j>=n;--j,i<<=1)
	if(i&kk)
	  a.push_back(p[j]);
	else c.push_back(p[j]);
      for(int i=0;i<n;++i)
	cout<<a[i]<<' '<<c[i]<<endl;
      printf("%d\n",ans);
    }
  return 0;
}
