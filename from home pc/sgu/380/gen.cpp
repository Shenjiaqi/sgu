#include <cstdio>
#include <iostream>
#include <map>
#include <utility>
#include <cstdlib>
using namespace std;
#define N 100000
typedef long long ll;
typedef pair<ll,ll> pp;
#define BETWEEN(a,b,c) (((a)<=(b)&&(a)>=(c))||((a)>=(b)&&(a)<=(c)))
int p[N];
map<ll,int> mapp;
int main()
{
  freopen("in.txt","w",stdout);
  int n=20;
  printf("%d\n0",n);
  srand(7);
  for(int i=2;i<n;++i)
    printf(" %d",(rand()%5?1:-1)*(rand()%3));
  printf(" 0");
  return 0;
}

