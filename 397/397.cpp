#include <iostream>
#include <cstdio>
using namespace std;
int p[1000005][3];
int main()
{
  freopen("in.txt","r",stdin);
  int poi=0,all=0;
  for(;;)
    {
      char t;
      cin>>t;
      //cout<<'!'<<t<<endl;
      if(cin.eof())
	break;
      if(t<='z' && t>='a')
	{
	  ++all;
	  p[all][0]=(int)t;
	  p[all][1]=poi;
	  p[all][2]=p[poi][2];
	  if(p[poi][2])
	    p[p[poi][2]][1]=all;
	  p[poi][2]=all;
	  poi=all;
	}
      else if(t=='L')
	{
	  if(poi)
	    poi=p[poi][1];
	}
      else if(t=='R')
	{
	  if(p[poi][2])
	    poi=p[poi][2];
	}
      //else break;
    }
  for(int i=p[0][2];i;i=p[i][2])
    printf("%c",p[i][0]);
  return 0;
}
      
