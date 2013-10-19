#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
#define MAXT (1000)
#define MAXL (1000)
#define N (100)
int main()
{
  freopen("in","r",stdin);
  int n;
  scanf("%d",&n);
  vector<int> tl;
  for(int i=0,t;i<n;++i)
    {
      scanf("%d",&t);
      tl.push_back(t);
    }
  for(int i=0,l;i<n;++i)
    {
      scanf("%d",&l);
      tl[i]+=l*(MAXT+1);
    }
  sort(tl.begin(),tl.end());
  int ans=0;
  for(int i=n-1,accu=0;i>=0;--i)
    {
      int T,L;
      L=tl[i]/(MAXT+1);
      T=tl[i]%(MAXT+1);
      accu+=T;
      ans=max(ans,accu+L);
    }
  printf("%d",ans);
  return 0;
}
