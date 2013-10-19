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
int dp[101*101*100][2];
int ant(int v)
{
  int r(0);
  for(int i=1;i<v;i*=3)
    ++r;
  return r;
}
int dfs(int p,int n,int e,int all,int at,int usd)
{
  if(e>=all-1)
    return (usd<=at?1:0);
  int a,u=all-p-n-e;
  int enc=101*(101*p+n)+e;
  if(dp[enc][0]==0)
    {
      dp[enc][0]=ant(u+p+n);
      if(dp[enc][0]+usd>at)
	{
	  dp[enc][0]=0;
	  return 0;
	}
      int half=all>>1;
      for(int p1=min(half,p);p1>=0;--p1)
	for(int n1=min(half-p1,n);n1>=0;--n1)
	  for(int u1=min(half-p1-n1,u);u1>=0;--u1)
	    {
	      int h=p1+n1+u1;
	      if(h)
		for(int p2=min(h,p-p1);p2>=0;--p2)
		  for(int n2=min(h-p2,n-n1);n2>=0;--n2)
		    for(int u2=min(h-p2-n2,u-u1);u2>=0;--u2)
		      {
			int e2=h-p2-n2-u2;
			if(e2<=e)
			  {
			    int p_=p2+u2,n_=n1+u1,e_=e+p-p2+n-n1+u-u1-u2;
			    if((p_==p && n_==n && e_==e) || !dfs(p_,n_,e_,all,at,usd+1))
			      continue;
			    p_=p1+u1,n_=n2+u2,e_=e+n-n2+p-p1+u-u1-u2;
			    if((p_==p && n_==n && e_==e) || !dfs(p_,n_,e_,all,at,usd+1))
			      continue;
			    p_=p-p1-p2,n_=n-n1-n2,e_=e+p1+n1+p2+n2+u1+u2;
			    if((p_==p && n_==n && e_==e) || !dfs(p_,n_,e_,all,at,usd+1))
			      continue;
			    if(dp[enc][0]<at-usd)
			      dp[enc][0]=0;
			    dp[enc][1]=(p1*101+n1)*101+u1;
			    dp[enc][2]=(p2*101+n2)*101+u2;
			    return 1;
			  }
		      }
	    }
    }
  else if(dp[enc][0]+usd<=at)
    return 1;
  else return 0;
  dp[enc][0]=0;//  cout<<p<<' '<<n<<' '<<e<<' '<<all<<' '<<usd<<' '<<dp[enc]<<endl;
  return 0;
}
void pt(const int p[4],int lev,const int sta[100],int c)
{
  /*cout<<"lev "<<lev<<" p[2] "<<p[2]<<" p[3] "<<p[3]<<endl;
    for(int i=0;i<p[3];++i)
    cout<<sta[i]<<' ';cout<<endl;*/
  if(p[2]==p[3])
    return ;
  for(int i=2;i<(lev<<1);++i)
    printf(" ");
  if(c)
    printf("case %c:\n",(c==1?'<':(c==2?'=':'>')));
  if(p[2]==p[3]-1)
    {
      for(int i=0;i<(lev<<1);++i)
	printf(" ");
      printf("fake ");
      for(int i=0;i<p[3];++i)
	if(sta[i]!=2)
	  {
	    printf("%d",(i+1));
	    break;
	  }
      printf("\n");
      return ;
    }
  int q[2][4];
  int enc=101*(101*p[0]+p[1])+p[2];
  q[0][3]=dp[enc][1]%101,q[1][3]=dp[enc][2]%101;
  q[0][1]=(dp[enc][1]/101)%101,q[1][1]=(dp[enc][2]/101)%101;
  q[0][0]=dp[enc][1]/101/101,q[1][0]=dp[enc][2]/101/101;
  q[0][2]=0,q[1][2]=q[0][0]+q[0][1]+q[0][3]-q[1][0]-q[1][1]-q[1][3];
  /*cout<<lev<<endl;
    for(int i=0;i<2;++i)
    {
    for(int j=0;j<4;++j)
    cout<<q[i][j]<<' ';
    cout<<endl;
    }*/

  for(int i=0;i<(lev<<1);++i)
    printf(" ");
  printf("weigh ");
  int ssta[100];
  int f=0,l=100;
  int kk[2][4];
  memset(kk,0,sizeof(kk));
  for(int i=0;i<p[3];++i)
    {
      //cout<<kk[0][sta[i]]<<' '<<q[0][sta[i]]<<' '<<sta[i]<<endl;
      if(kk[0][sta[i]]<q[0][sta[i]])
	{
	  //cout<<"!!"<<(i+1)<<endl;
	  ++kk[0][sta[i]];
	  ssta[f++]=i+1;
	}
      else if(kk[1][sta[i]]<q[1][sta[i]])
	{
	  ++kk[1][sta[i]];
	  ssta[--l]=i+1;
	}
    }
  for(int i=0;i<f;++i)
    {
      if(i)
	printf("+");
      printf("%d",ssta[i]);
    }
  printf(" vs ");
  for(int i=99;i>=l;--i)
    {
      if(i!=99)
	printf("+");
      printf("%d",ssta[i]);
    }
  printf("\n");
  memset(kk,0,sizeof(kk));
  for(int i=0;i<p[3];++i)
    {
      ssta[i]=sta[i];
      if(sta[i]==0)
	{
	  if(kk[0][0]<q[0][0])
	    {
	      ++kk[0][0];
	      ssta[i]=2;
	    }
	  else if(kk[1][0]<q[1][0])
	    ++kk[1][0],ssta[i]=0;
	  else ssta[i]=2;
	}
      else if(sta[i]==1)
	{
	  if(kk[0][1]<q[0][1])
	    ++kk[0][1],ssta[i]=1;
	  else if(kk[1][1]<q[1][1])
	    {
	      ++kk[1][1];
	      ssta[i]=2;
	    }
	  else ssta[i]=2;
	}
      else if(sta[i]==3)
	{
	  if(kk[0][3]<q[0][3])
	    {
	      ++kk[0][3];
	      ssta[i]=1;
	    }
	  else if(kk[1][3]<q[1][3])
	    {
	      ++kk[1][3];
	      ssta[i]=0;
	    }
	  else ssta[i]=2;
	}
    }
  int pp[4];
  pp[3]=p[3];
  pp[0]=q[1][0]+q[1][3];
  pp[1]=q[0][1]+q[0][3];
  pp[2]=p[2]+p[0]-q[1][0]+p[1]-q[0][1]+p[3]-p[0]-p[1]-p[2]-q[0][3]-q[1][3];
  pt(pp,lev+1,ssta,1);


  memset(kk,0,sizeof(kk));
  for(int i=0;i<p[3];++i)
    {
      ssta[i]=sta[i];
      if(sta[i]==0)
	{
	  if(kk[0][0]<q[0][0])
	    {
	      ++kk[0][0];
	      ssta[i]=2;
	    }
	  else if(kk[1][0]<q[1][0])
	    {
	      ++kk[1][0];
	      ssta[i]=2;
	    }
	  else ssta[i]=0;
	}
      else if(sta[i]==1)
	{
	  if(kk[0][1]<q[0][1])
	    {
	      ++kk[0][1];
	      ssta[i]=2;
	    }
	  else if(kk[1][1]<q[1][1])
	    {
	      ++kk[1][1];
	      ssta[i]=2;
	    }
	  else ssta[i]=1;
	}
      else if(sta[i]==3)
	{
	  if(kk[0][3]<q[0][3])
	    {
	      ++kk[0][3];
	      ssta[i]=2;
	    }
	  else if(kk[1][3]<q[1][3])
	    {
	      ++kk[1][3];
	      ssta[i]=2;
	    }
	  else ssta[i]=3;
	}
    }
  pp[0]=p[0]-q[0][0]-q[1][0];
  pp[1]=p[1]-q[0][1]-q[1][1];
  pp[2]=p[2]+q[0][0]+q[0][1]+q[1][0]+q[1][1]+q[0][3]+q[1][3];
  pt(pp,lev+1,ssta,2);

  memset(kk,0,sizeof(kk));
  for(int i=0;i<p[3];++i)
    {
      ssta[i]=sta[i];
      if(sta[i]==0)
	{
	  if(kk[0][0]<q[0][0])
	    ++kk[0][0],ssta[i]=0;
	  else if(kk[1][0]<q[1][0])
	    {
	      ++kk[1][0];
	      ssta[i]=2;
	    }
	  else ssta[i]=2;
	}
      else if(sta[i]==1)
	{
	  if(kk[0][1]<q[0][1])
	    {
	      ++kk[0][1];
	      ssta[i]=2;
	    }
	  else if(kk[1][1]<q[1][1])
	    ++kk[1][1],ssta[i]=1;
	  else ssta[i]=2;
	}
      else if(sta[i]==3)
	{
	  if(kk[0][3]<q[0][3])
	    {
	      ++kk[0][3];
	      ssta[i]=0;
	    }
	  else if(kk[1][3]<q[1][3])
	    {
	      ++kk[1][3];
	      ssta[i]=1;
	    }
	  else ssta[i]=2;
	}
    }
  pp[0]=q[0][0]+q[0][3];
  pp[1]=q[1][1]+q[1][3];
  pp[2]=p[2]+p[0]-q[0][0]+p[1]-q[1][1]+p[3]-p[0]-p[1]-p[2]-q[0][3]-q[1][3];
  pt(pp,lev+1,ssta,3);
  for(int i=0;i<(lev<<1);++i)
    printf(" ");
  printf("end\n");
}
int main()
{
  freopen("in","r",stdin);
  //freopen("out","w",stdout);
  int n;
  cin>>n;
  int antc=ant(n);
  for(;!dfs(0,0,0,n,antc,0);++antc)
    memset(dp,0,sizeof(dp));
  printf("need %d weighings\n",antc);
  int sta[100];
  for(int i=0;i<n;++i)
    sta[i]=3;
  int p[4]={0};
  p[3]=n;
  pt(p,0,sta,0);
  return 0;
}
