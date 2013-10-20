#include <iostream>
#include <vector>
#include <functional>
#include <cstdio>
using namespace std;
int main()
{
  freopen("in.txt","r",stdin);
  int n,x;
  cin>>n>>x;
  vector<vector<int> > p;
  p.resize(n+1);
  for(int i=1;i<=n;++i)
    {
      int d;
      cin>>d;
      for(int j=0;j<d;++j)
	{
	  int f;
	  cin>>f;
	  p[i].push_back(f);
	}
    }
  vector<bool> isf,isff;
  isf.resize(n+1);
  isff.resize(n+1);
  fill(isf.begin(),isf.end(),false);
  fill(isff.begin(),isff.end(),false);
  for(int i=0;i<p[x].size();++i)
    {
      isf[p[x][i]]=1;
      for(int j=0;j<p[p[x][i]].size();++j)
	isff[p[p[x][i]][j]]=1;
    }
  int num(0);
  for(int i=1;i<=n;++i)
    if(i!=x && !isf[i] && isff[i])
      ++num;
  cout<<num;
  for(int i=1;i<=n;++i)
    if(i!=x && !isf[i] && isff[i])
      cout<<endl<<i;
  return 0;
}
