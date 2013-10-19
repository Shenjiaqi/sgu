#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <string.h>
using namespace std;
int main()
{
  freopen("in","r",stdin);
  int n;
  cin>>n;
  char buf[107];
  char res[777];
  for(int i=0;i<n;++i)
    {
      char tmp;
      for(;;)
	{
	  scanf("%c",&tmp);
	  if(tmp=='"')
	    break;
	}
      int l=0;
      for(;;)
	{
	  scanf("%c",&tmp);
	  if(tmp=='"')
	    break;
	  buf[l++]=tmp;
	}
      int rei=0;
      int state=0;
      res[0]=0;
      for(int j=0;j<l;++j)
	{
	  switch (state)
	    {
	    case 0:
	      if(buf[j]==' ')
		;
	      else if(buf[j]=='-')
		state=2;
	      else
		{
		  res[rei++]=buf[j];
		  state=1;
		}
	      break;
	    case 1:
	      if(buf[j]==' ')
		state=6;
	      else if(buf[j]=='-')
		state=2;
	      else res[rei++]=buf[j];
	      break;
	    case 2:
	      if(buf[j]==' ')
		;
	      else if(buf[j]=='-')
		state=3;
	      else
		{
		  res[rei++]='-';
		  res[rei++]=buf[j];
		  state=1;
		}
	      break;
	    case 3:
	      if(buf[j]==' ')
		;
	      else if(buf[j]=='-')
		state=4;
	      else
		{
		  res[rei++]=' ';
		  res[rei++]='-';
		  res[rei++]='-';
		  res[rei++]=' ';
		  res[rei++]=buf[j];
		  state=1;
		}
	      break;
	    case 4:
	      if(buf[j]==' ')
		{
		  ;
		}
	      else if(buf[j]=='-')
		{
		  for(++j;j<l;++j)
		    if(buf[j]=='-')
		      ++state;
		    else if(buf[j]==' ')
		      ;
		    else break;
		  if(state&1)
		    {
		      res[rei++]=' ';
		      res[rei++]='-';
		      res[rei++]='-';
		      res[rei++]='-';
		      state-=3;
		    }
		  for(int k=0;k<state;k+=2)
		    {
		      res[rei++]=' ';
		      res[rei++]='-';
		      res[rei++]='-';
		    }
		  res[rei++]=' ';
		  if(j<l)
		    res[rei++]=buf[j];
		  state=1;
		}
	      else
		{
		  res[rei++]=' ';
		  res[rei++]='-';
		  res[rei++]='-';
		  res[rei++]='-';
		  res[rei++]=' ';
		  res[rei++]=buf[j];
		  state=1;
		}
	      break;
	    case 6:
	      if(buf[j]=='-')
		{
		  state=2;
		}
	      else if(buf[j]==' ')
		;
	      else
		{
		  res[rei++]=' ';
		  res[rei++]=buf[j];
		  state=1;
		}
	      break;
	    default:
	      break;
	    }
	}
      if(res[0]!='-' && (state==1 || state==0 || state==6 || state==3 || state==4) )
	{
	  if(state==3 || state==4)
	    {
	      res[rei++]=' ';
	      res[rei++]='-';
	      res[rei++]='-';
	      if(state==4)
		res[rei++]='-';
	      res[rei++]=' ';
	    }
	  cout<<'"';
	  for(int j=0;j<rei;++j)
	    cout<<res[j];
	  cout<<'"'<<endl;
	}
      else cout<<"error"<<endl;
    }
  return 0;
}
