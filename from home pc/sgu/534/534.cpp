#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define N 100007
int s[N];
int p[N*2+1][4],poi;
int q[N+1][2];
int w[N+1][4],wi;
int out[N+1],oi;
int mm[N+1][3];
void add(int f,int t,int v)
{
  ++poi,p[poi][0]=t,p[poi][1]=v,p[poi][2]=s[f],p[poi][3]=-1,s[f]=poi;
}
int dfs1(int v,int f)
{
  for(int i=s[v];i;i=p[i][2])
    if(f!=p[i][0])
      {
        p[i][3]=q[p[i][1]][0]+dfs1(p[i][0],v);
        if(mm[v][0]<p[i][3])
          mm[v][1]=mm[v][0],mm[v][0]=p[i][3],mm[v][2]=p[i][0];
        else if(mm[v][1]<p[i][3])
          mm[v][1]=p[i][3];
      }
  return mm[v][0];
}
void ad(int &a,int b,int c)
{
  if(c==0)
    {
        int tmp=wi++;
        w[tmp][0]=w[tmp][1]=w[tmp][3]=tmp;
        w[tmp][2]=b;
        if(a>=0)
        {
            w[w[a][1]][3]=tmp;
            w[a][1]=tmp;
        }
        else a=tmp;
    }
  else
    {
      if(a<0)
	a=b;
      else if(b>=0)
	{
	  w[w[a][1]][3]=b;
	  w[a][1]=w[b][1];
	}
    }
}
void dfs2(int v,int f,int l)
{
    if(l>mm[v][0])
        mm[v][1]=mm[v][0],mm[v][0]=l,mm[v][2]=f;
    else if(mm[v][1]<l)
        mm[v][1]=l;
  for(int i=s[v];i;i=p[i][2])
    if(p[i][0]!=f)
      dfs2(p[i][0],v,q[p[i][1]][0]+(mm[v][2]==p[i][0]?mm[v][1]:mm[v][0]));
    else
    {
        p[i][3]=l;
    }
}
int ddfs(int v,int f,int &u)
{
  int mi=0;
  for(int i=s[v];i;i=p[i][2])
    if(p[i][0]!=f)
      mi=max(p[i][3],mi);
  int k(0);
  u=-1;
  for(int i=s[v];i;i=p[i][2])
    if(p[i][0]!=f && p[i][3]==mi)
      {
	int t;
	int tmp=ddfs(p[i][0],v,t);
	if(q[p[i][1]][1]<tmp)
	  {
	    k+=q[p[i][1]][1];
	    ad(u,p[i][1],0);
	  }
	else
	  {
	    k+=tmp;
	    ad(u,t,1);
	  }
      }
    if(k==0)
        return 2000000000;
  return k;
}
void pt(int c)
{
  for(int i=w[c][0],j=w[c][1];;i=w[i][3])
    {
      out[oi++]=w[i][2];
      if(i==j)
        break;
    }
}
void output()
{
   printf("\n%d\n",oi);
   for(int i=0;i<oi;++i)
     printf("%d ",out[i]);
}
int main()
{
  freopen("in.txt","r",stdin);
  int n;
  scanf("%d",&n);
  for(int i=1;i<n;++i)
    {
      int f,t,l,c;
      scanf("%d%d%d%d",&f,&t,&l,&c);
      --t,--f;
      add(f,t,i);
      add(t,f,i);
      q[i][0]=l,q[i][1]=c;
    }
  dfs1(0,-1);
  int mpv,mp;
  mpv=-1;
  dfs2(0,-1,0);
  //for(int i=s[0];i;i=p[i][2])
    //dfs2(p[i][0],0,q[p[i][1]][0]+(p[i][0]==mm[0][2]?mm[0][1]:mm[0][0]));
  for(int i=0,diff=1e9+1;i<n;++i)
    {
      int m1=mm[i][0],m2=mm[i][1];
      if(m1+m2>mpv || (m1+m2==mpv && abs(m1-m2)<diff))
        mpv=m1+m2,mp=i,diff=abs(m1-m2);
    }
  int mk1=mm[mp][0],mk2=mm[mp][1];
      if(mk1==mk2)
	{
	  typedef pair<int,int> pp;
	  vector<pp> b;
	  int bbi=-1;
	  for(int i=s[mp];i;i=p[i][2])
	    if(p[i][3]==mk1)
	      {
            int t;
            int tmp=ddfs(p[i][0],mp,t);
            if(tmp>q[p[i][1]][1])
            {
                tmp=q[p[i][1]][1];
                t=-1;
                ad(t,p[i][1],0);
            }
            b.push_back(pp(tmp,t));
            if(bbi<0 || b[bbi].first<tmp)
              bbi=b.size()-1;
	      }
	  int ans(0);
	  for(int i=0;i<b.size();++i)
	    if(i!=bbi)
	      {
		ans+=b[i].first;
		pt(b[i].second);
	      }
	  printf("%d",ans);
	}
      else
	{
	  int aa,taa=-1;
	  int bb,tbb=-1;
	  bb=0;
	  for(int i=s[mp];i;i=p[i][2])
	    {
	      if(p[i][3]==mk1)
	      {
                aa=ddfs(p[i][0],mp,taa);
                if(aa>q[p[i][1]][1])
                {
                    aa=q[p[i][1]][1];
                    taa=-1;
                    ad(taa,p[i][1],0);
                }
	      }
	      else if(p[i][3]==mk2)
		{
		  int tmp;
		  int cc=ddfs(p[i][0],mp,tmp);
		  if(cc>q[p[i][1]][1])
		  {
            cc=q[p[i][1]][1];
            tmp=-1;
            ad(tmp,p[i][1],0);
            }
            bb+=cc;
		  if(tbb<0)
		    tbb=tmp;
		  else ad(tbb,tmp,1);
		}
	    }
	  if(aa<bb || bb<=0)
	    {
	      printf("%d",aa);
	      pt(taa);
	    }
	  else
	    {
	      printf("%d",bb);
	      pt(tbb);
	    }
	}
  output();
  return 0;
}
