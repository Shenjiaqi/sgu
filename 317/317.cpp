#include <iostream>
#include <cstdio>
#include <map>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
  freopen("in.txt","r",stdin);
  int b,n;
  cin>>b>>n;
  vector< pair<int,int> > p;
  vector< vector<pair<int,int> > > q;
  p.resize(n),q.resize(n);
  for(int i=0,m;i<n;++i)
  {
      cin>>p[i].first>>m;
      p[i].second=i;
      q[i].resize(m);
      for(int j=0;j<m;++j)
        cin>>q[i][j].first>>q[i][j].second;
      sort(q[i].begin(),q[i].end(),greater<pair<int,int> >());
  }
  p.push_back(make_pair(b,-1));
  sort(p.begin(),p.end());
  vector<double> ans;
  ans.resize(n+1);
  fill(ans.begin(),ans.end(),(double)-1.0);
  if(p[0].first==0)
  {
      ans[0]=0.0;
      for(int i=0;i<n;++i)
      {
          if(ans[i]<0 || p[i].second==-1)
            break;
          int id=p[i].second;
          for(int j=0,k=i+1,l=-1;k<=n && j<q[id].size();++j)
            if(p[k].first-p[i].first<=q[id][j].second)
            {
                double tmp=ans[i]+(double)(p[k].first-p[i].first)/(double)q[id][j].first;
                if(ans[k]<0 || ans[k]>tmp)
                    ans[k]=tmp;
                if(p[k].second==-1)
                    break;
                ++k;
                --j;
            }
      }
  }
  int k=0;
  for(;p[k].second!=-1;++k)
    ;
  if(ans[k]<0)
    cout<<-1;
  else
    printf("%.7lf",ans[k]);
  return 0;
}
