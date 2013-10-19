#include <cstdio>
#include <cstring>
#define N (190)
int p[N][N];
int d[N][N];
int q[N][N][N];
int mk1[N][N],mk2[N][N];
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
  for(int i=1;i<=n;++i)
    for(int k=i;k<=n;++k)
      mk1[i][k]=k,mk2[i][k]=i;
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
		for(;n2+1<nii && ni[n2+1]<=k;++n2)
		  ;
		r=mk1[i][ni[n1]-1>=i?ni[n1]-1:i];
		s=mk2[ni[n2]+1>k?k:ni[n2]+1][k];
		/*
		for(r=i;d[r][r]!=1;++r)
		  ;
		for(s=k;d[s][s]!=1;--s)
		  ;
		*/
		int ma=d[i][r]*(r-i+1) + d[s][k]*(k-s+1) + (k-i+1)*(q[j][i][k])+s-r-1;
		if(j==3 && i==2 && k==7)
		  printf("%d %d %d %d %d %d\n",ma,i,ni[n1],s,k,mk2[s][k]);
		  //int ma=(r-i)*d[i][r-1]+(k-s)*d[s+1][k]+s-r+1+(k-i+1)*q[j][i][k];
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
			if(s==i+1)
			  tmp-=d[s][k];
			else
			  --tmp;
		      }
		    if(tmp>ans)
		      ans=tmp,ans0=i,ans1=k,ansv0=j-q[j][i][k],ansv=j-1,ansh1=(s==i+1?s-1:s-2),ansh2=(s==i+1?s+1:s),ansv1=j,ansv2=d[s][k]+j-1;
		  }
		else if(d[k][k]==1)
		  {
		    int tmp=ma;
		    if(!q[j][i][k])
		      tmp=0;
		    else
		      {
			if(r+1==k)
			  tmp-=d[i][r];
			else --tmp;
		      }
		    if(tmp>ans)
		      ans=tmp,ans0=i,ans1=k,ansv0=j-q[j][i][k],ansv=j-1,ansh1=(r+1==k?r-1:r),ansh2=(r+1==k?r+1:r+2),ansv1=d[i][r]+j-1,ansv2=j;
		  }
		else
		  {
		    if(ma>ans)
		      ans=ma,ans0=i,ans1=k,ansv0=j-q[j][i][k],ansv=j,ansh1=r,ansh2=s,ansv1=d[i][r]+j-1,ansv2=d[s][k]+j-1;
		  }
	      }
	}
      for(int i=1;i<=n;++i)
	{
	  mk1[i][i]=i;
	  for(int k=i+1;k<=n;++k)
	    {
	      if(d[i][k]*(k-i+1)>=(mk1[i][k-1]-i+1)*d[i][mk1[i][k-1]])
		mk1[i][k]=k;
	      else mk1[i][k]=mk1[i][k-1];
	    }
	}
      for(int k=n;k>0;--k)
	{
	  mk2[k][k]=k;
	  for(int i=k-1;i>0;--i)
	    {
	      if(d[i][k]*(k-i+1)>=(k-mk2[i+1][k]+1)*d[mk2[i+1][k]][k])
		mk2[i][k]=i;
	      else mk2[i][k]=mk2[i+1][k];
	    }
	}
      if(j==4)
	printf("!%d\n",mk2[6][7]);
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
