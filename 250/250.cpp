#include <cstdio>
#include <cstring>
#define N (190)
int p[N][N];
int d[N][N];
int q[N][N][N];
int ni[N],nii;
int main()
{
  freopen("in","r",stdin);
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=1;i<=n;++i)
    for(int j=1;j<=m;++j)
      scanf("%d",*(p+i)+j);
  for(int i=2;i<=m;++i)
    for(int j=1;j<=n;++j)
      {
	int k=j;
	for(;k<=n && !p[k][i-1];++k)
	  q[i][j][k]=q[i-1][j][k]+1;
	for(;k<=n;++k)
	  q[i][j][k]=0;
      }
  int ans(0),ansh1,ansh2,ans0,ans1,ansv1,ansv2,ansv,ansv0;
  for(int j=m;j>0;--j)
    {
      for(int i=1;i<=n;++i)
	{
	  int k=i;
	  for(;k<=n && !p[k][j];++k)
	      ++d[i][k];
	  for(;k<=n;++k)
	    d[i][k]=0;
	}
      nii=0;
      for(int i=1;i<=n;++i)
	if(d[i][i]==1)
	  ni[nii++]=i;
      for(int i=1,n1=0;i<=n;++i)
	{
	  for(;ni[n1]<i;++n1)
	    ;
	  for(int k=i+2,n2=0;k<=n;++k)
	    if(d[i][k]==1)
	      {
		int r,s;
		r=ni[n1];
		for(;n2+1<nii && ni[n2+1]<=k;++n2)
		  ;
		s=ni[n2];
		/*
		for(r=i;d[r][r]!=1;++r)
		  ;
		for(s=k;d[s][s]!=1;--s)
		  ;
		*/
		//if(r!=n1[i] || s!=n2[k])
		//fprintf(stderr,"! ");
		//r=n1[i];
		// s=n2[k];
		int ma=(r-i)*d[i][r-1]+(k-s)*d[s+1][k]+s-r+1+(k-i+1)*q[j][i][k];
		if(d[i][i]==1 && d[k][k]==1)
		  {
		    if(q[j][i][k] && ma-1>ans)
			ans=ma-1,ans0=i,ans1=k,ansv0=j-q[j][i][k],ansv=j-1,ansh1=i,ansh2=i+2,ansv1=j,ansv2=j;
		  }
		else if(d[i][i]==1)
		  {
		    int tmp=ma;
		    if(!q[j][i][k])
		      tmp=0;
		    else
		      {
			if(s==i)
			  tmp-=d[s+1][k];
			else
			  --tmp;
		      }
		    if(tmp>ans)
		      ans=tmp,ans0=i,ans1=k,ansv0=j-q[j][i][k],ansv=j-1,ansh1=(s==i?s:s-1),ansh2=(s==i?s-2:s-1),ansv1=j,ansv2=d[s+1][k]+j-1;
		  }
		else if(d[k][k]==1)
		  {
		    int tmp=ma;
		    if(!q[j][i][k])
		      tmp=0;
		    else
		      {
			if(r==k)
			  tmp-=d[i][r-1];
			else --tmp;
		      }
		    if(tmp>ans)
		      ans=tmp,ans0=i,ans1=k,ansv0=j-q[j][i][k],ansv=j-1,ansh1=(r==k?r-2:r-1),ansh2=(r==k?k:r+1),ansv1=d[i][r-1]+j-1,ansv2=j;
		  }
		else
		  {
		    if(ma>ans)
		      ans=ma,ans0=i,ans1=k,ansv0=j-q[j][i][k],ansv=j,ansh1=r-1,ansh2=s+1,ansv1=d[i][r-1]+j-1,ansv2=d[s+1][k]+j-1;
		  }
	      }
	}
    }
  if(ans<5)
    printf("-1");
  else
    {
      //printf("%d %d %d %d %d %d %d %d %d\n",ans,ansh1,ansh2,ans0,ans1,ansv1,ansv2,ansv,ansv0);
      printf("%d\n",ans);
      bool u[N][N]={0};
      for(int i=ans0;i<=ansh1;++i)
	for(int j=ansv0;j<=ansv1;++j)
	  u[i][j]=1;
      for(int i=ansh1+1;i<ansh2;++i)
	for(int j=ansv0;j<=ansv;++j)
	  u[i][j]=1;
      for(int i=ansh2;i<=ans1;++i)
	for(int j=ansv0;j<=ansv2;++j)
	  u[i][j]=1;
      for(int i=1;i<=n;++i)
	{
	  for(int j=1;j<=m;++j)
	    printf("%c ",(p[i][j]?'1':(u[i][j]?'8':'0')));
	  printf("\n");
	}
    }
  return 0;
}
