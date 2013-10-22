#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <utility>
#include <string.h>
using namespace std;
#define N 200007
typedef long long ll;
ll p[N];
int tmp[N];
int tmp2[N];
ll u[3][N*2][2];
int nnn[3]={0};
typedef pair<ll,ll> pp;
void pt(int c)
{
  cout<<'!'<<c<<' '<<nnn[c]<<endl;
  for(int i=0;i<nnn[c];++i)
    cout<<u[c][i][0]<<' '<<u[c][i][1]<<endl;
  cout<<endl;
}
void cm(int v)
{
  if(nnn[v]<2)
    return ;
  int nn=0;
  for(int j=1;j<nnn[v];++j)
    if(u[v][nn][1]+1==u[v][j][0])
      u[v][nn][1]=u[v][j][1];
    else
      {
	++nn;
	if(nn<j)
	  u[v][nn][0]=u[v][j][0],
	    u[v][nn][1]=u[v][j][1];
      }
  nnn[v]=nn+1;
  //cout<<nn<<endl;
}
int main()
{
  freopen("in.txt","r",stdin);
  int n;
  scanf("%d",&n);
  ll m=1;
  m<<=60;
  for(int i=0;i<n;++i)
    {
      cin>>p[i];
      m=min(m,p[i]);
    }
  if(n&1)
    {
      ll sub(0);
      for(ll i=1;i<((ll)1<<60) && sub<m;i<<=1)
	{
	  ll x(0);
	  for(int j=0;j<n;++j)
	    x^=p[j];
	  if(x&i)
	    {
	      sub|=i;
	      for(int j=0;j<n;++j)
		  p[j]-=i;
	    }
	}
      if(sub>=m)
	printf("0");
      else printf("1");
    }
  else
    {
      ll x(0);
      for(int i=0;i<n;++i)
	x^=p[i];
      if(x&1)
	printf("0");
      else
	{
	  int *seq,*seq_;
	  seq=tmp;
	  seq_=tmp2;
	  for(int i=0;i<n;++i)
	    seq[i]=i;
	  for(int i=1;i<61;++i)
	    {
	      int num0(0);
	      ll l=1;
	      l<<=(i-1);
	      for(int j=0;j<n;++j)
		if(0==(p[j]&l))
		  ++num0;
	      int num1=n;
	      for(int j=n-1;j>=0;--j)
		{
		  int v=seq[j];
		  if(p[v]&l)
		    seq_[--num1]=v;
		  else seq_[--num0]=v;
		}
	      int *tmp=seq;
	      seq=seq_;
	      seq_=tmp;
	      int a=i%3;
	      int b=(i+1)%3;
	      int c=(i+2)%3;
	      nnn[c]=nnn[b]=0;
	      ll z=(x>>i)&(ll)1;
	      l<<=1;
	      ll mask=l-(ll)1;
	      int jj=0;
	      if(0==(mask&(p[seq[0]])))
		for(;jj<n && (mask&p[seq[jj]])==0;++jj)
		  ;
	      if(z==0)
		{
		  int tmp=nnn[c]++;
		  u[c][tmp][0]=0;
		  u[c][tmp][1]=0;
		}
	      for(ll s=1;s<=m;)
		{
		  if(0==(z^(jj&1)))
		    {
		      int tmp=nnn[c]++;
		      u[c][tmp][0]=s,
			u[c][tmp][1]=jj<n?(p[seq[jj]]&mask):mask;
		    }
		  if(jj>=n)
		    break;
		  s=(p[seq[jj]]&mask);
		  for(;jj<n && (p[seq[jj]]&mask)==s;++jj)
		    ;
		  ++s;
		}
	      cm(c);
	      if(i>1)
		{
		  for(int j=0,k=0;j<nnn[a] && k<nnn[c];)
		    {
		      if(u[a][j][1]<u[c][k][0])
			++j;
		      else if(u[a][j][0]>u[c][k][1])
			++k;
		      else
			{
			  int tmp=nnn[b]++;
			  u[b][tmp][0]=max(u[a][j][0],u[c][k][0]);
			  u[b][tmp][1]=min(u[a][j][1],u[c][k][1]);
			  if(u[a][j][1]==u[c][k][1])
			    ++j,++k;
			  else if(u[a][j][1]<u[c][k][1])
			    ++j;
			  else ++k;
			}
		    }
		}
	      else
		{
		  memcpy(u[b],u[c],sizeof(u[0][0])*nnn[c]);
		  nnn[b]=nnn[c];
		}
	      for(int j=0,k=nnn[b];j<k && (l|u[b][j][0])<m;++j)
		{
		  u[b][k+j][0]=l|u[b][j][0];
		  u[b][k+j][1]=l|u[b][j][1];
		  ++nnn[b];
		}
	      cm(b);
	    }
	  ll ans(0);
	  int z=61%3;
	  for(int i=0;i<nnn[z] && u[z][i][0]<m;++i)
	    ans+=(min(m-1,u[z][i][1])-u[z][i][0]+1);
	  //pt(a);
	  cout<<ans;
	}
    }
  return 0;
}
