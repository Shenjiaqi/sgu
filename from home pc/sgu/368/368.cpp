#include <cstdio>
#define N 100
#define M 100
int p[M];
int q[M];
int main()
{
  int n,m;
  scanf("%d%d",&n,&m);
  for(int i=0;i<m;++i)
    scanf("%d",p+i);
  int cnt(0);
  char buf[107],bufi;
  for(int i=0;i<n;++i)
    {
      getchar();
      for(bufi=0;'\n'!=(buf[bufi]=getchar());++bufi)
	;
      buf[bufi]='\0';
      int score(0),k;
      scanf("%d",&k);
      for(int j=0;j<k;++j)
	scanf("%d",q+j);
      for(int j=0;j<k;++j)
	{
	  int x,y,z;
	  scanf("%d%d%d",&x,&y,&z);
	  int t=p[q[j]-1];
	  if(t<x)
	    score+=2;
	  else if(t<y)
	    score+=3;
	  else if(t<z)
	    score+=4;
	  else score+=5;
	}
      int s;
      scanf("%d",&s);
      char buuf[107],buufi;
      for(int j=0;j<s;++j)
	{
	  getchar();
	  for(buufi=0;'\n'!=(buuf[buufi]=getchar());++buufi)
	    ;
	  buuf[buufi]='\0';
	  int c;
	  scanf("%d",&c);
	  if(score>=c)
	    {
	      printf("%s %s\n",buf,buuf);
	      ++cnt;
	    }
	}
    }
  if(0==cnt)
    printf("Army");
  return 0;
}
