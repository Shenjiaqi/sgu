#include <cstdio>
#include <iostream>
#include <map>
#include <utility>
using namespace std;
#define N 100007
typedef long long ll;
typedef pair<int,int> pp;
#define BETWEEN(a,b,c) ( ((a)<=(b)&&(a)>=(c)) || ((a)>=(b)&&(a)<=(c)) )
int p[N];
map<pp,int> mapp;
bool dfs(int a,int b)//,bool dir)
{
  //cout<<a<<' '<<b<<endl;
  if(a==b)
    return true;
  if(mapp.find(pp(a,b))!=mapp.end())
    return false;
  //  for(;a+2<b;)
    /*if(p[a+1]==p[b-1])
      return dfs(a+1,b,true)||dfs(a+1,b,false)||dfs(a,b-1,true)||dfs(a,b-1,false);
      else*/
      {
	//bool t1=BETWEEN(p[a+1],p[b],p[b-1]);
	//bool t2=BETWEEN(p[b-1],p[a],p[a+1]);
	//if(!t1 && !t2)
	//break;
	if(BETWEEN(p[a+1],p[b],p[b-1])
	   && dfs(a+1,b))
	  return true;
	/*if(dir)
	  {
	    if(t1)
	      ++a;
	    else
	      --b,dir=false;
	  }
	else if(t2)
	  --b;
	else
	++a,dir=true;*/
	if(BETWEEN(p[b-1],p[a],p[a+1]) && dfs(a,b-1))
	  return true;
      }
  mapp[pp(a,b)]=1;
      //if(a+2==b)
      //return true;
  return false;
}
int main()
{
  freopen("in.txt","r",stdin);
  int n;
  scanf("%d",&n);
  if(n>100000)
    return 1;
  for(int i=0;i<n;++i)
    scanf("%d",p+i);
  //  int m=0;
  /*for(int i=0,j=1;j<n;m=++i,++j)
    {
      if(p[i]<=p[j])
	for(;n>j+1 && p[j+1]>=p[j];++j)
	  ;
      else
	for(;n>j+1 && p[j+1]<=p[j];++j)
	  ;
      p[i+1]=p[j];
      }*/
  if( dfs(0,n-1))//dfs(0,m,true)||dfs(0,m,false))
    cout<<"YES";
  else cout<<"NO";
  return 0;
}

