#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
bool cmp(const string &a,const string &b)
{
  if(a.length()==b.length())
    return a<b;
  return a.length()<b.length();
}
int main()
{
  freopen("in","r",stdin);
  int n;
  cin>>n;
  vector<string> str;
  for(int i=0;i<n;++i)
    {
      string tmp;
      cin>>tmp;
      str.push_back(tmp);
    }
  sort(str.begin(),str.end(),cmp);
  int ans=-1;
  for(int i=0;i<n-2;++i)
    {
      string num;
      int carry=0;
      int a=str[i].length()-1,b=str[i+1].length()-1;
      for(;a>=0 && b>=0;--a,--b)
	{
	  carry+=str[i][a]-'0'+str[i+1][b]-'0';
	  num=string("0")+num;
	  num[0]+=carry%10;
	  carry/=10;
	}
      if(a>=0)
	for(;a>=0;--a)
	  {
	    carry+=str[i][a]-'0';
	    num=(string)"0"+num;
	    num[0]+=carry%10;
	    carry/=10;
	  }
      else if(b>=0)
	for(;b>=0;--b)
	  {
	    carry+=str[i+1][b]-'0';
	    num=(string)"0"+num;
	    num[0]+=carry%10;
	    carry/=10;
	  }
      if(carry)
	{
	  num=(string)"0"+num;
	  num[0]+=carry;
	}
      if(cmp(str[i+2],num))
	{
	  ans=i;
	  break;
	}
    }
  if(ans>=0)
    for(int i=0;i<3;++i)
      cout<<str[i+ans]<<' ';
  else cout<<"0 0 0";
  return 0;
}
