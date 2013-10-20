#include <cstdio>
#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int main()
{
  freopen("in.txt","r",stdin);
  int c[10];
  int up,down,__;
  cin>>c[1]>>c[2]>>c[3]>>up;
  cin>>c[4]>>c[5]>>c[6]>>down;
  cin>>c[7]>>c[8]>>c[9];
  cin>>__>>c[0];
  int step[100];
  for(int i=0;i<100;++i)
    step[i]=-1;
  int x,y;
  cin>>x>>y;
  step[x]=0;
  queue<int> que;
  int in[100]={0};
  que.push(x);
  in[x]=1;
  for(int i=0;i<10;++i)
    if(c[i] && step[i]<0)
    {
      step[i]=1;
      in[i]=1;
      que.push(i);
    }
  if(__)
    for(int i=1;i<10;++i)
      if(c[i])
        for(int j=0;j<10;++j)
          if(c[j])
            if(step[i*10+j]<0)
              {
                step[i*10+j]=3;
                que.push(10*i+j);
                in[10*i+j]=1;
              }
  for(;!que.empty();)
    {
      int v=que.front();
      if(up)
	{
	  int tmp=(v+1)%100;
	  if(step[tmp]<0 || step[tmp]>step[v]+1)
	    {
	      step[tmp]=step[v]+1;
	      if(!in[tmp])
		{
		  que.push(tmp);
		  in[tmp]=1;
		}
	    }
	}
      if(down)
	{
	  int tmp=(v+99)%100;
	  if(step[tmp]<0 || step[tmp]>step[v]+1)
	    {
	      step[tmp]=step[v]+1;
	      if(!in[tmp])
		{
		  in[tmp]=1;
		  que.push(tmp);
		}
	    }
	}
      que.pop();
      in[v]=0;
    }
  cout<<step[y];
  return 0;
}
