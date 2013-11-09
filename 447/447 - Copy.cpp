#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define L 100007
const int Z=((1<<6)+1);
char s[L],si;
int p[L];
int dp[L][7][7];
int mi[L][3];
int up[Z],down[Z],pos[Z];
int frm[L][7][7];
void bt(int len,int j,int k)
{
  if(len>0)
    {
      bt(frm[len][j][k],k?mi[len][1]:j-1,k?mi[len][2]:k-1);
      if(k)
	for(int i=0;i<k;++i)
	  printf(".");
      else
	printf("R%d",(1<<j));
    }
}
int gnxt(int lst)
{
  if(s[si])
    {
      if(s[si]=='R')
	{
	  ++si;
	  if(s[si]=='1')
	    {
	      ++si;
	      if(s[si]=='6')
		{
		  ++si;
		  return 16;
		}
	      return 1;
	    }
	  else if(s[si]=='3')
	    {
	      si+=2;
	      return 32;
	    }
	  else if(s[si]=='6')
	    {
	      si+=2;
	      return 64;
	    }
	  else
	    {
	      ++si;
	      return (int)(s[si-1]-'0');
	    }
	}
      else return lst<<1;
    }
  return 0;
}
int gl(int i)
{
  return i>9?3:2;
}
int main()
{
  scanf("%s",s);
  int l=1;
  for(;p[l]=gnxt(l?p[l-1]:0);++l)
    ;
  for(int i=0;i<7;++i)
    up[1<<(6-i)]=1<<i,down[1<<i]=1<<(6-i),pos[1<<i]=i;
  memset(dp,1<<6,sizeof(dp));
  int inf=dp[0][0][0];
  dp[0][0][6]=0;
  mi[0][0]=0,mi[0][1]=0,mi[0][2]=6;
  for(int i=1;i<=l;++i)
    {
      for(int j=i,sum=0;j>0;--j)
	{
	  sum+=down[p[j]];
	  if(sum>64)
	    break;
	  if(sum==(sum&(-sum)))
	    {
	      int t=pos[up[sum]];
	      int l=gl(up[sum]);
	      if(dp[i][t][0]>mi[j-1][0]+l)
		dp[i][t][0]=mi[j-1][0]+l,
		  frm[i][t][0]=j-1;
	      if(t)
		for(int k=1;k<7;++k)
		  if(dp[j-1][t-1][k-1]+1<dp[i][t][k])
		    dp[i][t][k]=dp[j-1][t-1][k-1]+1,
		      frm[i][t][k]=j-1;
	    }
	}
      mi[i][0]=inf;
      for(int j=0;j<6;++j)
	for(int k=0;k<6;++k)
	  if(mi[i][0]>dp[i][j][k])
	    mi[i][0]=dp[i][j][k],
	      mi[i][1]=j,mi[i][2]=k;
    }
  int ii=0,jj=0;
  for(int i=0;i<7;++i)
    for(int j=0;j<7;++j)
      if(dp[l][ii][jj]>dp[l][i][j])
	ii=i,jj=j;
  bt(l,ii,jj);
  return 0;
}
