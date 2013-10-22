#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <queue>
#include <algorithm>
using namespace std;
#define N 100
#define M 1000
int p[M*2+1][4],poi;
int s[N+1];
int d[N+1];
int fa[N+1];
int seq[N+1];
int nnum[N+1];
queue<int> que;
void add(int f,int t)
{
  ++poi,p[poi][0]=t,p[poi][1]=s[f],p[s[f]][2]=poi,s[f]=poi,p[poi][2]=0,
    p[poi][3]=f;
  ++d[f];
  ++poi,p[poi][0]=f,p[poi][1]=s[t],p[s[t]][2]=poi,s[t]=poi,p[poi][2]=0,
    p[poi][3]=t;
  ++d[t];
}
void del(int i)
{
  --d[p[i][3]];
  if(p[i][2]==0)
    s[p[i][3]]=p[i][1],p[p[i][1]][2]=0;
  else
    p[p[i][1]][2]=p[i][2],p[p[i][2]][1]=p[i][1];
}
int query(int a)
{
  return fa[a]==a?a:fa[a]=query(fa[a]);
}
void joi(int a,int b)
{
  a=query(a),b=query(b);
  if(a!=b)
    fa[a]=b;
}
int main()
{
  freopen("in.txt","r",stdin);
  int tst;
  scanf("%d",&tst);
  for(;tst--;)
    {
      int n,m;
      scanf("%d%d",&n,&m);
      memset(s,0,sizeof(s));
      memset(d,0,sizeof(d));
      poi=0;
      for(int j=0,f,t;j<m;++j)
	{
	  scanf("%d%d",&f,&t);
	  add(f,t);
	}
      for(int i=1;i<=n;++i)
	{
	  if(d[i]==1)
	    que.push(i);
	  fa[i]=i;
	}
      for(;;)
	{
	  if(!que.empty())
	    {
	      int v=0;
	      for(;!que.empty();)
		{
		  int tmp=que.front();
		  que.pop();
		  if(d[tmp]==1)
		    {
		      v=tmp;
		      break;
		    }
		}
	      if(v)
		{
		  int k=p[s[v]][0];
		  joi(v,k);
		  int tmp=s[v];
		  del(tmp+((tmp&1)?1:-1));
		  del(tmp);
		  int num=2;
		  for(int i=s[k];i;i=p[i][1])
		    {
		      int t=p[i][0];
		      if(d[t]==1)
			{
			  joi(k,t);
			  del(i);
			  del(i+((i&1)?1:-1));
			  ++num;
			}
		    }
		  if((num&1)==0)
		    {
		      for(int i=s[k];i;i=p[i][1])
			{
			  int t=p[i][0];
			  del(i);
			  del(i+((i&1)?1:-1));
			  if(d[t]==1)
			    que.push(t);
			}
		    }
		  else if(d[k]==1)
		    que.push(k);
		}
	    }
	  else
	    {
	      int v=0;
	      /*for(int i=1;i<=n;++i)
		if(d[i]==1)
		return 1;*/
	      for(int i=1;i<=n;++i)
		if(d[i]>0)
		  {
		    v=i;
		    break;
		  }
	      if(v)
		{
		  //if(s[v]==0)
		  //return 1;
		  int k=p[s[v]][0];
		  if(k==v)
		    for(;;)
		      ;
		  int cad1=k,cad2=v;
		  bool chg=false;
		  for(int i=p[s[v]][1];i;i=p[i][1])
		    {
		      int t=p[i][0];
		      if(d[t]==2)
			{
			  if(s[t]==0 || p[s[t]][1]==0)
			    return 1;
			  int a=p[s[t]][0];
			  int b=p[p[s[t]][1]][0];
			  if((a==v && b==k) || (a==k && b==v))
			    {
			      chg=true;
			      if(d[k]>2)
				cad1=t,cad2=v;
			      else if(d[t]>2)
				cad1=t,cad2=k;
			      else return 1;
			      break;
			    }
			}
		    }
		  joi(cad1,cad2);
		  int chk[N+1]={0};
		  int zz[N+1];
		  memcpy(zz,d,sizeof(zz));
		  for(int i=s[cad1];i;i=p[i][1])
		    {
		      int t=p[i][0];
		      del(i);
		      del(i+((i&1)?1:-1));
		      ++chk[t];
		      if(d[t]==1)
			que.push(t);
		      //else if(d[t]==0 && t!=cad2)
		      //return 1;
		    }
		  for(int i=s[cad2];i;i=p[i][1])
		    {
		      int t=p[i][0];
		      del(i);
		      del(i+((i&1)?1:-1));
		      if(d[t]==1)
			que.push(t);
		      else if(d[t]==0 && t!=cad1)
			{
			  if(chk[t]==1 && zz[t]==2 && chg)
			    {
			      //return 1;
			    }
			}
		    }
		}
	      else break;
	    }
	}
//       for(int i=1;i<=n;++i)
// 	if(d[i] || s[i])
// 	  return 1;
      memset(seq,0,sizeof(seq));
      memset(nnum,0,sizeof(nnum));
      for(int i=1,j=1;i<=n;++i)
	{
	  int t=query(i);
	  if(seq[t]==0)
	    seq[t]=j++;
	  printf("%d ",seq[t]);
	  ++nnum[seq[t]];
	}
//         for(int i=1;i<=n/2;++i)
// 	  if(nnum[i]==1)
// 	    return 1;
      printf("\n");
    }
  return 0;
}
