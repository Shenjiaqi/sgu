#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <functional>
using namespace std;
typedef long long ll;
typedef pair<int,int> pp;
#define N 100007
vector<pp> p;
int n;
map<int,int> mapp;
map<int,int>::iterator ite,ii;

int main()
{
  freopen("in","r",stdin);
  scanf("%d",&n);
  for(int i=0;i<n;++i)
    {
      int x,y;
      scanf("%d%d",&x,&y);
      p.push_back(pp(x,y));
      mapp[y]=0;
    }
  int num(0);
  for(ite=mapp.begin();ite!=mapp.end();++ite)
    ite->second=num++;
  for(int i=0;i<n;++i)
    p[i].second=mapp[p[i].second];
  sort(p.begin(),p.end());
  return 0;
}
