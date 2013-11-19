#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
#define N 21
int s[N],d[N];
int cnt[N][N];
int n;
bool dfs(int lim,int lev)
{
  int c1,c2;
  c1=0,c2=N-1;
  for(int i=0;i<n;++i)
    if(s[i]>d[i])
      cnt[lev][c1++]=i;
    else if(s[i]<d[i])
      cnt[lev][c2--]=i;
  if(max(c1,N-c2-1)>lim)
    return false;
  if(c1==0)
    return true;
  if(lim<=0)
    return false;
  for(int i=0;i<c1;++i)
    {
      int p1=cnt[lev][i];
      int det=s[p1]-d[p1];
      s[p1]=d[p1];
      for(int j=N-1;j>c2;--j)
	{
	  int p2=cnt[lev][j];
	  s[p2]+=det;
	  if(dfs(lim-1,lev+1))
	    {
	      s[p2]-=det;
	      s[p1]+=det;
	      return true;
	    }
	  s[p2]-=det;
	}
      s[p1]+=det;
    }
  return false;
}
int main()
{
  scanf("%d",&n);
  int s1(0),s2(0);
  for(int i=0;i<n;++i)
    {
      scanf("%d",s+i);
      s1+=s[i];
    }
  for(int i=0;i<n;++i)
    {
      scanf("%d",d+i);
      s2+=d[i];
    }
  if(s1!=s2)
    {
      printf("-1");
      return 0;
    }
  int v1(0),v2(0);
  for(int i=0;i<n;++i)
    if(s[i]>d[i])
      ++v1;
    else if(s[i]<d[i])
      ++v2;
  int ans(0);
  for(int f=max(v1,v2),t=n;f<=t;)
    {
      int m=(f+t)>>1;
      if(dfs(m,0))
	ans=m,t=m-1;
      else f=m+1;
      cout<<f<<' '<<t<<' '<<ans<<endl;
    }
  printf("%d",ans);
  return 0;
}
