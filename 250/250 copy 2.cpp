#include <cstdio>
#include <algorithm>
using namespace std;
#define N (190)
int p[N][N];
//int q[N][N];
//int d[N];
int ma[N][N];
int n1[N][N];
int n2[N][N];
bool z[N][N];
//int wid[N][N];
int main()
{
  freopen("in","r",stdin);
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)
      scanf("%d",*(p+i)+j);
  int ans(0),ansv0,ansv,ansv1,ansv2,ans0,ans1,ansh1,ansh2;
  for(int j=m;j>0;--j)
    {
      /*
      for(int i=1;i<=n;++i)
	d[i]=(p[i][j]?0:d[i]+1);
      */
      for(int i=1;i<=n;++i)
	{
	  /*
	  ma[i][i]=d[i];
	  for(int k=i+1;k<=n;++k)
	    ma[i][k]=min(d[k],ma[i][k-1]);
	  */
	  int k=i;
	  for(;k<=n && !p[k][j];++k)
	    ++ma[i][k];
	  for(;k<=n;++k)
	    ma[i][k]=0;
	}
      for(int i=1;i<=n;++i)
	{
	  n1[i][i]=i;
	  for(int k=i+1;k<=n;++k)
	    if(ma[i][n1[i][k-1]]*(n1[i][k-1]-i+1)<ma[i][k]*(k-i+1))
	      n1[i][k]=k;
	    else n1[i][k]=n1[i][k-1];
	}
      for(int k=n;k>0;--k)
	{
	  n2[k][k]=k;
	  for(int i=k-1;i>0;--i)
	    if(ma[n2[i+1][k]][k]*(k-n2[i+1][k]+1)<ma[i][k]*(k-i+1))
	      n2[i][k]=i;
	    else n2[i][k]=n2[i+1][k];
	}
      for(int i=1;i<=n;++i)
	if(ma[i][i])
	  for(int k=i+2;k<=n && ma[k][k];++k)
	    {
	      int all;
	      int a;
	      int b=ma[i+1][k-1];
	      int c;
	      if(b<=0)
		break;
	      b=min(b,min(ma[i][i],ma[k][k]));
	      for(int f=1,l=i;f<=l;)
		{
		  int mid=(f+l)>>1;
		  if(ma[n2[mid][i]][i]>=b)
		    l=mid-1,a=mid;
		  else f=mid+1;
		}
	      if(ma[n2[a][i]][i]<b)
		continue;
	      for(int f=k,l=n;f<=l;)
		{
		  int mid=(f+l)>>1;
		  if(ma[k][n1[k][mid]]>=b)
		    f=mid+1,c=mid;
		  else l=mid-1;
		}
	      if(ma[k][n1[k][c]]<b)
		continue;
	      int ra=n2[a][i],rc=n1[k][c];
	      a=ma[ra][i],c=ma[k][rc];
	      all=a*(i-ra+1)+b*(k-i-1)+c*(rc-k+1);
	      if(b==a || b==c)
		{
		  if(b<=1)
		    continue;
		  all-=1;
		  if(all>ans)
		    {
		      ans=all;
		      ansv0=j,ansv=j+b-2,ans0=ra,ans1=rc,ansv1=j+a-1,ansv2=j+c-1;
		      if(b==a)
			ansh1=k-2,ansh2=k;
		      else ansh1=i,ansh2=i+2;
		    }
		}
	      else
		{
		  if(all>ans)
		    {
		      //if(all==13)
		      //printf("%d %d\n",i,k);
		      ans=all;
		      ansv0=j,ansv=j+b-1,ans0=ra,ans1=rc,ansv1=j+a-1,ansv2=j+c-1;
		      ansh1=i,ansh2=k;
		    }
		}
	    }
    }
  if(ans<5)
    printf("-1");
  else
    {
      for(int i=ans0;i<=ansh1;++i)
	for(int j=ansv0;j<=ansv1;++j)
	  z[i][j]=1;
      for(int i=ansh1+1;i<ansh2;++i)
	for(int j=ansv0;j<=ansv;++j)
	  z[i][j]=1;
      for(int i=ansh2;i<=ans1;++i)
	for(int j=ansv0;j<=ansv2;++j)
	  z[i][j]=1;
      printf("%d\n",ans);
      //printf("%d %d %d %d %d %d %d %d\n",ansv0,ansv,ansv1,ansv2,ans0,ans1,ansh1,ansh2);
      for(int i=1;i<=n;++i)
	{
	  for(int j=1;j<=m;++j)
	    printf("%c ",(p[i][j]?'1':(z[i][j]?'8':'0')));
	  printf("\n");
	}
    }
  return 0;
}
