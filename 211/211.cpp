#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
using namespace std;
int calcarry(int k)
{//0 1 2 1 2 1 2
 //0 0 0 1 1 2 2
  if(k==0)
    return 0;
  return (k-1)/2;
}
map<int,int> mapp[3];
vector<int> pos;
vector<int> carry;
vector<int> val;
int chg(int pos,int *out)
{
  out[0]=pos;
  mapp[val[pos]].erase(pos);
  ++val[pos];
  int r=0;
  if(val[pos]==3)
    {
      val[pos]=1,--carry[pos];
      r=1;
    }
  mapp[val[pos]][pos]=1;
  out[1]=val[pos];
  return r;
}
int main()
{
  freopen("in","r",stdin);
  int n,m;
  cin>>n>>m;
  pos.resize(n);
  for(int i=0;i<m;++i)
    cin>>pos[i];
  carry.resize(n);
  fill(carry.begin(),carry.end(),0);
  for(int i=0;i<n;++i)
    ++carry[pos[i]];
  for(int i=0;i<n;++i)
    if(i)
      carry[i]=calcarry(carry[i]+carry[0]);
    else carry[0]=calcarry(carry[0]);
  int out[4][2];
  val.resize(n);
  fill(val.begin(),val.end(),0);
  for(int i=0,j;i<m;++i)
    {
      int po=pos[i];
      j=0;
      for(;chg(po,out[j++]);)
	++po;
      for(;j+1<4;++j)
	{
	  for(po=-1;!mapp[2].empty();po=-1)
	    {
	      po=(mapp[2].begin())->first;
	      if(carry[po]<=0)
		mapp[2].erase(po);
	      else break;
	    }
	  if(po<0)
	    break;
	  for(;val[po+1]==2;++po)
	    ;
	  if(po==pos[i])
	    --j;
	  chg(po,out[j++]);
	  chg(po+1,out[j++]);
	}
      cout<<j;
      for(int c=0;c<j;++c)
	cout<<' '<<out[c][0]<<' '<<out[c][1];
      cout<<endl;
    }
  return 0;
}
