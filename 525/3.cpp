#include <cstdio>
#include <algorithm>
using namespace std;
#define N 1001
#define M 20001
void add(int f,int t,int pp[],int &ppoi,int ss[])
{
  ++ppoi,pp[ppoi][0]=t,pp[poi][1]=ss[f],ss[f]=ppoi;
}

int p[N][3],poi,s[N];
#define B 5
#define MSK ((1<<B)-1)
#define AA(x) ((x)>>B)
#define BB(x) (1<<((x)&MSK))
int gnd[N],idx,in[(N+MSK)>>B],sta[N],sti,low[N],bel[N],grp;
int du1[N],du2[N],q1[
void dfs(int v)
{
  in[AA(v)]|=BB(v);
  sta[sti++]=v;
  gnd[v]=low[v]=++idx;
  for(int i=s[v];i;i=p[i][1])
    {
      int t=p[i][0];
      if(gnd[t]==0)
	{
	  dfs(t);
	  low[v]=min(low[v],low[t]);
	}
      else if(in[t])
	low[v]=min(low[v],gnd[t]);
    }
  if(gnd[v]==low[v])
    {
      for(;;)
	{
	  int t=sta[--sti];
	  in[AA(t)]^=BB(t);
	  bel[t]=grp;
	  if(v==t)
	    break;
	}
      ++grp;
    }
}
int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=0;i<m;++i)
    {
      int f,t;
      scanf("%d%d",&f,&t);
      add(f,t,p,poi,s);
      p[poi][2]=i+1;
    }
  for(int i=0;i<n;++i)
    if(gnf[i]==0)
      dfs(i);
  for(int i=0;i<n;++i)
    {
      int f=bel[i];
      for(int j=s[i];j;j=p[j][1])
	{
	  int t=bel[p[j][0]];
	  if(0==(con[f][AA(t)]&(BB(t))))
	    {
	      con[f][AA(t)]|=BB(t);
	      
	    }
      
}
