#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define N (200)
#define K (200)
int p[(N*K+2+N+K)*2+1][3],poi;
int s[1+N+K+2];
int c[1+N+K+2];
int d[1+N+K+2];
int n,k;
int S,T;
void add(int f,int t,int v)
{
  p[poi][0]=t,p[poi][1]=s[f],p[poi][2]=v,s[f]=poi++;
  p[poi][0]=f,p[poi][1]=s[t],p[poi][2]=0,s[t]=poi++;
}
bool bfs()
{
  static int que[N+K+2+1];
  memset(d,0,sizeof(d));
  memcpy(c,s,sizeof(c));
  d[S]=1;
  int f,l;
  f=0,l=1;
  que[f]=S;
  for(;f<l;++f)
    {
      int tmp=que[f];
      for(int i=c[tmp];i;i=p[i][1])
	if(!d[p[i][0]] && p[i][2]>0)
	   que[l++]=p[i][0],d[p[i][0]]=1+d[tmp];
    }
  return d[T];
}
int dfs(int v,int val)
{
  if(v==T)
    return val;
  int r=val;
  int i=c[v];
  for(;i;i=p[i][1])
    if(d[p[i][0]]==1+d[v] && p[i][2]>0)
      {
	int tmp=dfs(p[i][0],min(p[i][2],val));
	val-=tmp;
	p[i][2]-=tmp;
	p[(i&1)?(i+1):(i-1)][2]+=tmp;
	if(!val)
	  break;
      }
  c[v]=i;
  return (r-val);
}
int mf()
{
  int r(0);
  for(;bfs();)
    for(int tmp;tmp=dfs(S,K*2);)
      {
	r+=tmp;
      }
  return r;
}
void pr()
{
  for(int i=1;i<=k;++i)
    {
      printf("2 ");
      int tmp=0;
      for(int j=s[n+i];tmp<2 && j;j=p[j][1])
	if(p[j][2])
	  {
	    ++tmp;
	    printf("%d ",p[j][0]);
	  }
      printf("\n");
    }
}
int main()
{
  freopen("in.txt","r",stdin);
  scanf("%d%d",&n,&k);
  S=n+k+1;
  T=1+S;
  poi=1;
  for(int i=1;i<=n;++i)
    {
      add(S,i,1);
      int j;
      scanf("%d",&j);
      for(;j;--j)
	{
	  int tmp;
	  scanf("%d",&tmp);
	  add(i,n+tmp,1);
	}
    }
  for(int i=1;i<=k;++i)
    add(i+n,T,2);
  if(mf()<2*k)
    printf("NO");
  else
    {
      printf("YES\n");
      pr();
    }
  return 0;
}
