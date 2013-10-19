#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;
#define M (10000)
#define N (100)
typedef long long ll;
void add(int (*p)[5],int * s,int &poi,int from,int to,int t,int r,int pp)
{
  ++poi,p[poi][0]=to,p[poi][1]=t,p[poi][2]=r,p[poi][3]=pp,p[poi][4]=s[from],s[from]=poi;
  ++poi,p[poi][0]=from,p[poi][1]=t,p[poi][2]=r,p[poi][3]=pp,p[poi][4]=s[to],s[to]=poi;
}
void df(int (*p)[5],int * ss,int * pre,bool * vis,ll limit,int s)
{
  static int que[N+2];
  static int time[N+1];
  static bool in[N+1];
  memset(time,0,sizeof(time));
  memset(in,0,sizeof(in));
  int f,l;
  f=0,l=1;
  que[f]=s;
  for(;f!=l;)
    {
      int v=que[f];
      vis[v]=1;
      int now=time[v];
      for(int i=ss[v];i;i=p[i][4])
	{
	  int k=p[i][0];
	  if(k==s)
	    continue;
	  int time2=now+p[i][1];
	  if((ll)time2*(ll)p[i][3]+(ll)p[i][2]>limit)
	    continue;
	  if(time[k]==0 || time[k]>time2)
	    {
	      pre[k]=v;
	      time[k]=time2;
	      if(!in[k])
		in[k]=1,que[l]=k,l=(l+1)%(N+2);
	    }
	}
      f=(f+1)%(N+2);
      in[v]=0;
    }
}
void pt(int * pre,int v,int s,int l)
{
  if(v==s)
    {
      printf("%d %d",l,v);
      return;
    }
  pt(pre,pre[v],s,l+1);
  printf(" %d",v);
}
int main()
{
  freopen("in","r",stdin);
  int n,m,h,s,e;
  scanf("%d%d%d%d%d",&n,&m,&h,&s,&e);
  int corr[M*2+1][5],coi=0;
  int ss[N+1]={0};
  for(int i=0,a,b,t,r,p;i<m;++i)
    {
      scanf("%d%d%d%d%d",&a,&b,&t,&r,&p);
      add(corr,ss,coi,a,b,t,r,p);
    }
  int acc[N];
  for(int i=0;i<e;++i)
    scanf("%d",acc+i);
  int pre[N+1];
  int ans=h+1;
  bool vis[N+1];
  for(int m,f=0,l=h;f<=l;)
    {
      m=(f+l)/2;
      memset(pre,0,sizeof(pre));
      memset(vis,0,sizeof(vis));
      df(corr,ss,pre,vis,m,s);
      bool chk=0;
      for(int i=0;!chk && i<e;++i)
	if(vis[acc[i]])
	  chk=1;
      if(chk)
	ans=m,l=m-1;
      else f=m+1;
    }
  if(ans<=h)
    {
      printf("YES\n%d\n",ans);
      memset(pre,0,sizeof(pre));
      memset(vis,0,sizeof(vis));
      df(corr,ss,pre,vis,ans,s);
      for(int i=0;;++i)
	if(vis[acc[i]])
	  {
	    pt(pre,acc[i],s,1);
	    break;
	  }
    }
  else printf("NO");
  return 0;
}
