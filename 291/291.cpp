#include <cstdio>
#include <queue>
using namespace std;
#define N (22204)
#define Q (1000)
#define C (1000)
bool occupy[Q][C];
int num[N];
int q,c,n,t;
struct ele
{
  int x,y;
  int frm;
  ele(int a,int b,int c){x=a,y=b,frm=c;};
};
int main()
{
  freopen("in","r",stdin);
  scanf("%d%d%d%d",&q,&c,&n,&t);
  queue<ele>que;
  for(int i=0;i<n;++i)
    {
      int x,y;
      scanf("%d%d",&x,&y);
      --x,--y;
      ++num[i];
      que.push(ele(x,y,i));
      occupy[x][y]=1;
    }
  que.push(ele(-1,-1,-1));
  for(int i=0;que.size()>1 && i<t;)
    {
      int x,y,f;
      x=que.front().x;
      y=que.front().y;
      f=que.front().frm;
      que.pop();
      if(x<0)
	{
	  ++i;
	  que.push(ele(-1,-1,-1));
	  continue;
	}
      static const int dir[4][2]={{0,1},{0,-1},{-1,0},{1,0}};
      for(int j=0;j<4;++j)
	{
	  int xx=x+dir[j][0];
	  int yy=y+dir[j][1];
	  if(xx>=0 && (xx<q) && yy>=0 && yy<c && !occupy[xx][yy])
	     ++num[f],que.push(ele(xx,yy,f)),occupy[xx][yy]=1;
	}
    }
  for(int i=0;i<n;++i)
    printf("%d\n",num[i]);
  return 0;
}
