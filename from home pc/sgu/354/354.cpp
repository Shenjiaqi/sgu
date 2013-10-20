#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
#define N 600
int p[2][N][N];
int ref[N*N];
int seq[N][N];
int num[N+1];
int main()
{
  freopen("in.txt","r",stdin);
  int n;
  cin>>n;
  for(int i=0;i<2;++i)
    for(int j=0;j<n;++j)
      for(int k=0;k<n;++k)
	scanf("%d",&p[i][i?j:k][i?k:j]);
  vector<pair<int,int> > qq;
  vector<vector<int> > pri;
  pri.resize(n*n);
  qq.resize(n);
  int ppp[N+1][2];
  for(int c=0;c<2;++c)
    for(int i=0;i<n;++i)
      {
          ppp[0][0]=0;
          ppp[0][1]=0;
          for(int j=0;j<n;++j)
          {
              if(p[c][i][j]<0 || p[c][i][j]>j)
              {
                  cout<<'0';
                  return 0;
              }
              int poi=0;
              for(int k=0;k<p[c][i][j];++k)
                poi=ppp[poi][0];
              ++ppp[0][1];
              ppp[ppp[0][1]][0]=ppp[poi][0];
              ppp[ppp[0][1]][1]=j;
              ppp[poi][0]=ppp[0][1];
          }
          for(int j=ppp[0][0];;)
          {
              int k=ppp[j][0];
              if(k==0)
                break;
              int t=ppp[j][1],f=ppp[k][1];
              if(c)
                f+=(i*n),t+=(i*n);
              else
                f=f*n+i,t=t*n+i;
            //cout<<t<<' '<<f<<endl;
            pri[t].push_back(f);
            ++ref[f];
            j=k;
          }
      }
  queue<int> que;
  for(int i=n*n-1;i>=0;--i)
    if(0==ref[i])
      que.push(i);
  int ss=n*n;
  for(;!que.empty();)
    {
      int e=que.front();
      for(int i=0;i<pri[e].size();++i)
	if(0==--ref[pri[e][i]])
	  que.push(pri[e][i]);
      seq[e/n][e%n]=ss--;
      que.pop();
    }
  if(ss>0)
    cout<<0;
  else
  {/*
      for(int i=0;i<n;++i)
        for(int j=0;j<n;++j)
        {
            int a=0;
            for(int k=0;k<j;++k)
                if(seq[i][j]<seq[i][k])
                    ++a;
            if(a!=p[1][i][j])
            {
                cout<<0;
                return 0;
            }
            a=0;
            for(int k=0;k<i;++k)
                if(seq[i][j]<seq[k][j])
                    ++a;
            if(a!=p[0][j][i])
            {
                cout<<0;
                return 0;
            }
        }*/
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
            printf("%d ",seq[i][j]);
        printf("\n");
    }
  }
  return 0;
}
