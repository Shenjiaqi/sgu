#include <cstdio>
#define N (10)
#define M (10)
#define K (6)
int p[N][M];
bool mask[N][M];
int n,m,k;
void df(int x,int y,int set)
{
  if(__builtin_popcount(set)<=1)
    return;
  for(int i=x;i<n;++i)
    {
      for(int j=((x==i)?y:0);j<m;++j)
	{
	  int tmp=set&p[i][j];
	  if((tmp!=set)&&tmp)
	    {
	      mask[i][j]=1;
	      df(x+(y==m-1),(y==m-1)?0:(y+1),tmp);
	      df(x+(y==m-1),(y==m-1)?0:(y+1),set^tmp);
	      return ;
	    }
	}
    }
}
int use[K+1][2],uoi;
int chk[1<<K],ni;
bool check()
{
  ++ni;
  if(!ni)
    ni=1;
  for(int i=0;i<k;++i)
    {
      int tmp=0;
      for(int j=0;j<uoi;++j)
	tmp=((tmp<<1)|(bool)(p[use[j][0]][use[j][1]]&(1<<i)));
      if(chk[tmp]==ni)
	return 0;
      chk[tmp]=ni;
    }
  return 1;
}
bool used[1<<K];
int dfs(int x,int y,int num)
{
  if(num==0)
      return check();
  else
    for(int i=x;i<n;++i)
      for(int j=(x==i)?y:0;j<m;++j)
	{
	  if(used[p[i][j]])
	    continue;
	  used[p[i][j]]=1;
	  //	  printf("!%d %d %d\n",num,i,j);
	  use[uoi][0]=i,use[uoi][1]=j;
	  
	  ++uoi;
	  if(dfs(x+(y==m-1),y==m-1?0:(y+1),num-1))
	    return 1;
	  --uoi;
	  used[p[i][j]]=0;
	}
  return 0;
}
const int lim[7]={0,0,1,2,2,3,3};
int main()
{
  freopen("in","r",stdin);
  scanf("%d%d%d",&n,&m,&k);
  for(int i=0;i<k;++i)
    {
      scanf("\n");
      for(int j=0;j<n;++j)
	{
	  for(int l=0;l<m;++l)
	    {
	      char tmp;
	      scanf("%c",&tmp);
	      if(tmp=='1')
		p[j][l]|=1<<i;
	    }
	  scanf("\n");
      }
    }
  int ans;
  for(ans=lim[k];ans<k-1;++ans)
    if(dfs(0,0,ans))
      break;
  if(ans<k-1)
      for(int i=0;i<uoi;++i)
	mask[use[i][0]][use[i][1]]=1;
  else
    {
      ans=k-1;
      df(0,0,(1<<k)-1);
    }
  printf("%d\n",ans);
  for(int i=0;i<n;++i)
    {
      for(int j=0;j<m;++j)
	printf("%d",((int)mask[i][j]));
      printf("\n");
    }
  return 0;

}
