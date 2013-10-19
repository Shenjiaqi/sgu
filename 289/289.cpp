#include <cstdio>
#include <algorithm>
using namespace std;
const char * RES[]={"Illegal position.",
		    "X wins.",
		    "Game is a draw.",
		    "0 wins."};
int status[(1<<19)+1];//3^9
int check(int conf)
{
  static int pla[3][3];
  int who(0);
  for(int i=0;i<3;++i)
    for(int j=0;j<3;++j)
      pla[i][j]=(3&conf),conf>>=2;
  for(int i=0;i<3 && !who;++i)
    if(pla[i][0] && pla[i][0]==pla[i][1] && pla[i][2]==pla[i][1])
      who=pla[i][0];
    else if(pla[0][i] && pla[0][i]==pla[1][i] && pla[1][i]==pla[2][i])
      who=pla[0][i];
  if(!who && pla[0][0] && pla[0][0]==pla[1][1] && pla[1][1]==pla[2][2])
    who=pla[0][0];
  if(!who && pla[0][2] && pla[0][2]==pla[1][1] && pla[1][1]==pla[2][0])
    who=pla[0][2];
  return who;
}
void cal(int conf,int who)
{
  if(status[conf])
    return;
  int res=check(conf);
  if(!res)
    {
      int whon=who,msk=3;
      for(int i=0;i<9;++i,msk<<=2,whon<<=2)
	if((msk&conf)==0)
	  {
	    cal(conf|whon,who==1?2:1);
	    int tmp=status[conf|whon];
	    if(res==0)
	      res=4-tmp;
	    else if(tmp==1)
	      ;
	    else if(tmp==2)
	      res=min(res,2);
	    else if(tmp==3)
	      res=1;
	  }
      if(res==0)
	res=2;
    }
  else res=3;
  status[conf]=res;
}
int main()
{
  freopen("in","r",stdin);
  cal(0,1);
  for(;;)
    {
      int conf(0);
      char t;
      int nx(0),no(0);
      for(int i=0;i<3;++i)
	{
	  for(int j=0;j<3;++j)
	    {
	      scanf("%c",&t);
	      if(t=='Q')
		return 0;
	      conf<<=2;
	      if(t=='X')
		conf|=1,++nx;
	      else if(t=='0')
		conf|=2,++no;
	    }
	  scanf("%c",&t);
	}
      scanf("%c",&t);
      int res=status[conf];
      if(res /*&& nx>=no && nx<=no+1*/)
	{
	  if(nx>no)
	    res=4-res;
	}
      printf("%s\n",RES[res]);
    }
  return 0;
}
