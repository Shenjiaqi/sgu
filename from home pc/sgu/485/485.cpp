#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
using namespace std;
#define N 27
typedef long long ll;
int p[N*3],vis[N*3];
int a[N],b[N],c[N];
int n,ans;
//int ca,cb,cc;
void dfs(int lev,/*ll mk,*/int l,int r,int num)
{
  if(lev<0)
    {
      //++cc;
      ans=max(num,ans);
      //return 0;
    }
  else
    {
      //      ++cb;
      /*ite=mapp.find(mk);
	if(ite!=mapp.end())
	{
	ans=max(ans,num+ite->second);
	return ite->second;
	}
	else */
      {
	for(;vis[l];--l)
	  ;
	r=min(r,l-1);
	if(num+(p[l]-b[lev])*p[l-1]*(lev+1)>ans)
	  {
	    //++ca;
	    vis[l]=true;
	    int lb=-1,ub=1001;
	    for(int i=lev+1;i<n;++i)
	      if(c[i]<p[l])
		lb=a[i];
	      else if(c[i]>p[l])
		{
		  ub=a[i];
		  break;
		}
	    int rt=0;
	    a[lev]=p[l]-b[lev];
	    for(int pre=-1;r>=lev && p[r]>=lb;--r)
	      if(p[r]<=ub && pre!=p[r])
		{
		  vis[r]=true;
		  pre=c[lev]=p[r];
		  //rt=max(a[lev]*c[lev]+dfs(lev-1,mk|(1LL<<l)|(1LL<<r),l-1,r-1,num+a[lev]*c[lev]),rt);
		  dfs(lev-1/*,mk|(1LL<<l)|(1LL<<r)*/,l-1,r-1,num+a[lev]*c[lev]);
		  vis[r]=false;
		}
	    vis[l]=false;
	    //mapp[mk]=rt;
	    //return rt;
	  }
      }
    }
  //return 0;
}
int main()
{
  int t;
  freopen("in.txt","r",stdin);
  scanf("%d%d",&t,&n);
  for(;t--;)
    {
      for(int i=0;i<3*n;++i)
	scanf("%d",p+i);
      sort(p,p+3*n);
      
      for(int i=0;i<n;++i)
	b[i]=p[n-1-i];
      for(int i=0;i<2*n;++i)
	p[i]=p[i+n];
      ans=0;
      //mapp.clear();
      dfs(n-1,/*0,*/2*n-1,2*n-1,0);
      printf("%d\n",ans);
      //cout<<endl<<ca<<' '<<cb<<' '<<cc<<' '<<endl;
    }
  return 0;
}
