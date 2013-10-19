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
#include <stdlib.h>
#include <functional>
using namespace std;
typedef long long ll;
int p[16*(1<<15)+(1<<15)];
int black[16][3],nb=0,x,y;
int qq[1<<15][15];
int zz[1<<15][15];
int n,m;
int main()
{
  freopen("in","r",stdin);
  cin>>n>>m;
  for(int i=0;i<n;++i)
    for(int j=0;j<m;++j)
      {
	char t;
	cin>>t;
	if(t=='*')
	  x=i,y=j;
	else if(t!='.')
	  black[nb][0]=i,black[nb][1]=j,black[nb][2]=t,++nb;
      }
  for(int i=0;i<(1<<nb);++i)
    {
      for(int j=0;j<nb;++j)
	if(i&(1<<j))
	  zz[i][black[j][0]]|=(1<<black[j][1]);
      for(int j=0;j<nb;++j)
	if(i&(1<<j))
	  {
	    if(black[j][2]=='K')
	      {
		for(int k=-2;k<=2;++k)
		  for(int l=-2;l<=2;++l)
		    if( l && k && (abs(l)!=abs(k)))
		      {
			int t1=black[j][0]+k,t2=black[j][1]+l;
			if(t1>=0 && t2>=0 && t1<n && t2<m)
			  qq[i][t1]|=(1<<t2);
		      }
	      }
	    else if(black[j][2]=='B')
	      {
		for(int k=1+black[j][0],l=1+black[j][1];k<n && l<m;++k,++l)
		  {
		    qq[i][k]|=(1<<l);
		    if(zz[i][k]&(1<<l)) break;
		  }
		for(int k=black[j][0]-1,l=black[j][1]-1;k>=0 && l>=0;--k,--l)
		  {
		    qq[i][k]|=(1<<l);
		    if(zz[i][k]&(1<<l)) break;
		  }
		for(int k=1+black[j][0],l=black[j][1]-1;k<n && l>=0;++k,--l)
		  {
		    qq[i][k]|=(1<<l);
		    if(zz[i][k]&(1<<l)) break;
		  }
		for(int k=black[j][0]-1,l=1+black[j][1];k>=0 && l<m;--k,++l)
		  {
		    qq[i][k]|=(1<<l);
		    if(zz[i][k]&(1<<l)) break;
		  }
	      }
	    else
	      {
		for(int k=black[j][0],l=black[j][1]+1;l<m;++l)
		  {
		    qq[i][k]|=(1<<l);
		    if(zz[i][k]&(1<<l)) break;
		  }
		for(int k=black[j][0],l=black[j][1]-1;l>=0;--l)
		  {
		    qq[i][k]|=(1<<l);
		    if(zz[i][k]&(1<<l)) break;
		  }
		for(int k=black[j][0]+1,l=black[j][1];k<n;++k)
		  {
		    qq[i][k]|=(1<<l);
		    if(zz[i][k]&(1<<l)) break;
		  }
		for(int k=black[j][0]-1,l=black[j][1];k>=0;--k)
		  {
		    qq[i][k]|=(1<<l);
		    if(zz[i][k]&(1<<l)) break;
		  }
	      }
	  }
    }
      /*for(int i=0;i<(1<<nb);++i)
    {
      cout<<i<<endl;
      for(int u=0;u<n;++u){
	for(int uu=0;uu<m;++uu)
	  cout<<(qq[i][u]&(1<<uu)?'.':' ');cout<<endl;}}
      */
  black[nb][0]=x,black[nb][1]=y;
  queue< int > que;
  que.push(((1<<nb)-1)|((nb)<<15));
  que.push(-1);
  memset(p,1<<7,sizeof(p));
  p[((1<<nb)-1)|((nb)<<15)]=0;
  /*for(int i=0;i<nb;++i){
    for(int j=0;j<n;++j){
    for(int k=0;k<m;++k)
    cout<<(qq[i][j]&(1<<k)?'.':' ');cout<<endl;}cout<<endl;}*/
  for(int i=0;i<nb;++i)
    {
      //cout<<i<<' '<<que.size()<<endl;
      for(;;)
	{
	  int v=que.front();
	  que.pop();
	  if(v<0)
	    {
	      que.push(-1);
	      break;
	    }
	  x=black[v>>15][0],y=black[v>>15][1];
	  int pp[15][15];
	  memset(pp,1<<7,sizeof(pp));
	  queue< int > qque;
	  qque.push((x<<15) | y );
	  qque.push(-1);
	  pp[x][y]=0;
	  /*for(int j=0;j<n;++j){
	    for(int k=0;k<m;++k)
	    cout<<(qq[v&((1<<15)-1)][j]&(1<<k)?'.':' ');cout<<endl;}*/
	  for(int c=1;qque.size()>1;)
	    {
	      int vv=qque.front();
	      qque.pop();
	      if(vv<0)
		{
		  ++c;
		  qque.push(-1);
		  continue;
		}
	      int xx=vv>>15,yy=vv&((1<<15)-1);
	      //cout<<'!'<<xx<<' '<<yy<<endl;
	      for(int k=-1;k<=1;++k)
		for(int l=-1;l<=1;++l)
		  if(k!=0 || l!=0)
		    {
		      int xxx=xx+k,yyy=yy+l;//cout<<xxx<<' '<<yyy<<endl;
		      if( (xxx>=0) && (n>xxx) && (yyy >= 0) && (yyy < m) &&
			  ((qq[v&((1<<15)-1)][xxx]&(1<<yyy))==0) && pp[xxx][yyy]<0)
			{
			  pp[xxx][yyy]=c;
			  if((zz[v&((1<<15)-1)][xxx]&(1<<yyy))==0)
			    qque.push((xxx<<15)|yyy);
			}
		    }
	    }
	  /*cout<<endl;
	  for(int u=0;u<n;++u){
	    for(int uu=0;uu<m;++uu)
	    cout<<(pp[u][uu]>=0 ? pp[u][uu]: 0)<<' ';cout<<endl;}cout<<endl;*/
	  for(int j=0,k=v&((1<<15)-1);j<nb;++j)
	    if(((1<<j)&k) && (pp[black[j][0]][black[j][1]]>0))
	      {
		int tmp=p[v]+pp[black[j][0]][black[j][1]];

		//cout<<'!'<<i<<' '<<p[v]<<' '<<pp[black[j][0]][black[j][1]]<<endl;
		int tmp2=(k^(1<<j))|(j<<15);
		if(p[tmp2]<0)
		  {
		    //cout<<i<<' '<<j<<endl;
		    que.push(tmp2);
		    p[tmp2]=tmp;
		  }
		else if(p[tmp2]>tmp)
		  p[tmp2]=tmp;
	      }
	}
    }
  int ans=-1;
  for(;;)
    {
      int v=que.front();
      que.pop();
      if(v<0)
	break;
      if(ans<0 || ans>p[v])
	ans=p[v];
    }
  cout<<ans;
  return 0;
}
