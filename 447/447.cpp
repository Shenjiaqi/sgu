#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define L 100007
const int Z=((1<<6)+1);
char s[L],si;
int p[L];
vector<string> ans;
int num[7];
const string tmp[]={"R1","R2","R4","R8",
		    "R16","R32","R64"};
int pos[1<<7+1];
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
      else
	{
	  ++si;
	  return lst<<1;
	}
    }
  return 0;
}
bool cmp(const string  a,const string b)
{
  string c=a+b;
  string d=b+a;
  return c<d;
}
int main()
{
  freopen("in","r",stdin);
  scanf("%s",s);
  int l=0;
  for(;p[l]=gnxt(l?p[l-1]:0);++l)
    ;
  for(int i=0;i<7;++i)
    pos[1<<i]=i;
  for(int i=0;i<l;++i)
    ++num[pos[p[i]]];
  for(int i=6;i>0;--i)
    num[i-1]+=(num[i]>>1),
      num[i]&=1;
  for(int i=6;i>0;--i)
    if(num[i]>0)
      {
	int j=i;
	for(;i>=0 && num[i];--i)
	  --num[i];
	string z=tmp[i+1];
	for(--j;j>i;--j)
	  z+=".";
	ans.push_back(z);
      }
  if(num[0])
    ans.push_back(tmp[0]);
  sort(ans.begin(),ans.end(),cmp);
  for(int i=0;i<ans.size();++i)
    {
      if(ans[i]==tmp[0])
	for(int j=0;j<num[0];++j)
	  printf("R1");
      else
	printf("%s",ans[i].c_str());
    }
  return 0;
}
