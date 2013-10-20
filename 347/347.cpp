#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
bool cmp( string a, string b)
{
  string ab=a+b;
  string ba=b+a;
  return ab<ba;
}
int main()
{
  freopen("in.txt","r",stdin);
  int n;
  cin>>n;
  vector<string> p;
  p.resize(n);
  for(int i=0;i<n;++i)
    cin>>p[i];
  sort(p.begin(),p.end(),cmp);
  for(int i=0;i<n;++i)
    cout<<p[i];
  return 0;
}
