#include <cstdio>
#define N (210)
#define M (N*N)
int p[M+1][3],poi;
int s[N+1];
int q[N+1][3];
int que[N+1];
bool in[N+1];
int n,m;
int main()
{
  freopen("in","r",stdin);
  scanf("%d%d",&n,&m);
  poi=1;
  for(int i=0;i<m;++i)
    {
      int f,t,c;
      scanf("%d%d%d",&f,&t,&c);
      p[poi][0]=t,p[poi][1]=s[f],p[poi][2]=c-1,s[f]=poi++;
    }
  int f,l;
  f=0,l=1;
  que[f]=1;
  in[1]=1;
  q[1][0]=q[1][1]=q[1][2]=1;
  for(;f!=l;)
    {
      int tmp=que[f];
      in[tmp]=0;
      for(int i=s[tmp];i;i=p[i][1])
	{
	  int t=p[i][0];
	  int k=p[i][2];
	  for(int j=0;j<3;++j)
	    if(j!=k)
	      if(q[tmp][j] && (!q[t][k] || q[tmp][j]+1<q[t][k]))
		  {
		    q[t][k]=q[tmp][j]+1;
		    if(!in[t])
		      {
			in[que[l]=t]=1;
			if(++l>N)
			  l=0;
		      }
		  }
	}
      if(++f>N)
	f=0;
    }
  int ans=M+2;
  for(int i=0;i<3;++i)
    if(q[n][i] && q[n][i]<ans)
      ans=q[n][i];
  if(ans<M+2)
    printf("%d",ans-1);
  else printf("-1");
  return 0;
}
