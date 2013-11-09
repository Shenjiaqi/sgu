#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <utility>
using namespace std;
const int n=1e5+7;
typedef pair<string,int> sp;
char s[n];
int dp[n*64+1];
bool cmp2(const sp&a,const sp&b)
{
  string c=a.first+b.first;
  string d=b.first+a.first;
  return c<d;
}
const string tmp[]={"R1","R2","R4","R8",
		    "R16","R32","R64"};
int main()
{
  //freopen("in","r",stdin);
  scanf("%s",s);
  int l=strlen(s);
  int num(0);
  for(int i=0,j=0;i<l;)
    {
      if(s[i]=='R')
	{
	  ++i;
	  if(s[i]=='1')
	    {
	      ++i;
	      if(s[i]=='6')
		num+=(j=4),++i;
	      else
		num+=(j=64);
	    }
	  else if(s[i]=='3')
	    num+=(j=2),i+=2;
	  else if(s[i]=='6')
	    num+=(j=1),i+=2;
	  else if(s[i]=='2')
	    num+=(j=32),++i;
	  else if(s[i]=='4')
	    num+=(j=16),++i;
	  else num+=(j=8),++i;
	}
      else j>>=1,num+=j,++i;
    }
  vector<sp> b;
  for(int i=0;i<7;++i)
    {
      string t=tmp[i];
      int cc=1<<(6-i);
      int c=1<<(6-i);
      for(int j=0;j<7-i;++j)
	b.push_back(sp(t,c)),t+=".",cc>>=1,c+=cc;
    }
  memset(dp,1<<6,sizeof(dp));
  int inf=dp[0];
  dp[num]=0;
  for(int i=num;i>=0;--i)
    for(int j=0;j<b.size();++j)
      {
	int t=i-b[j].second;
	if(t>=0)
	  {
	    int cst=dp[i]+b[j].first.length();
	    if(cst<dp[t])
	      dp[t]=cst;
	  }
      }
  sort(b.begin(),b.end(),cmp2);
  for(int c=0,i=0;c<num;++i)
    {
      int l=b[i].first.length();
      int sub=b[i].second;
      int cn=(num-c)/sub;
      for(;cn>0 && (dp[c+sub*cn]>dp[c]-cn*l);--cn)
	;
      if(cn>0)
	{
	  c+=cn*sub;
	  for(int k=0;k<cn;++k)
	    printf("%s",b[i].first.c_str());
	}
    }
  return 0;
}
