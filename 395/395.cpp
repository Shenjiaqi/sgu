#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
#include <map>
#include <fstream>
#include <cassert>
#include <set>
#include <queue>
#include <iostream>
#include <utility>
#include <stack>
#include <complex>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <list>
#include <functional>
#include <cctype>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<int,int> ppi;
typedef pair<ll,ll> ppl;
typedef pair<double,double> ppd;
#define PB push_back
#define MP make_pair
#define FIR first
#define SEC second
#define FOR(a,b,c) for(int a=(b);a<(c);++a)
#define FR(a,b) for(typeof(b.begin()) a=b.begin();a!=b.end();++a)
const int N = 207;
int p[N];
vector<string> name;
vector< pair<int, string> > ans;
int main()
{
  int n;
  cin >> n;
  map<string,int> nameList;
  name.resize(n);
  for( int i = 0 ; i < n ; ++i )
    {
      char type;
      cin >> type;
      if( type == '+' )
	{
	  p[i] = -1;
	  cin >> name[i];
	}
      else if( type == '-' )
	{
	  p[i] = -2;
	  cin >> name[i];
	}
      else
	cin >> p[i];
    }
  for( int i = 0 ; i < n ; ++i )
    if( p[i] < 0 )
      nameList[ name[i] ] = i;
  queue<pair<int, int> > log[N];
  for( int i = 0 ; i < n ; ++i )
    if( p[i] < 0 )
      {
	int pos = nameList[ name[i] ];
	log[pos].push( make_pair( i, p[i] ) );
      }
  set<pair<int,string> > logs[3][2];
  for( int i = 0 ; i < 107 ; ++i )
    {
      for( ; ; )
	{
	  string newName = "sjq";
	  for( int j = 0 ; j < 13 ; ++j )
	    {
	      newName += (char) ( ( rand() % ( 'z' - 'a' ) ) + 'a' );
	      if( nameList.find( newName ) == nameList.end() &&
		  logs[1][0].find( make_pair( 0, newName ) ) == 
		  logs[1][0].end() )
		break;
	    }
	  if( nameList.find( newName ) == nameList.end() &&
	      logs[1][0].find( make_pair( 0, newName ) ) == logs[1][0].end() )
	    {
	      logs[1][0].insert( make_pair( 0, newName ) );
	      break;
	    }
	}
    }
  for( typeof( nameList.begin() ) i = nameList.begin() ; i != nameList.end();
       ++i )
    {
      int pos = i->second;
      int nxt = log[pos].front().second == -1 ? 2 : 0;
      logs[nxt][0].insert( make_pair( log[pos].front().first,
				      i->first ) );
    }
  for( int i = 0 ; i < n ; ++i )
    if( p[i] < 0 )
      {
	int pos = nameList[ name[i] ];
	log[pos].pop();
	// if( p[i] == -1 )
	//   {
	  int a = p[i] == -1 ? 2 : 0;
	  int b = p[i] == -1 ? 0 : 1;
	    typeof( logs[a][b].begin() ) ite = 
	      logs[a][b].find( make_pair( i, name[i] ) );
	    if( ite == logs[a][b].end() )
	      {
		assert( logs[a][ 1 - b ].find( make_pair( i, name[i] ) )
			!= logs[a][ 1 - b ].end() );
		logs[a][ 1 - b ].erase( make_pair( i, name[i] ) );
		ans.push_back( make_pair( b, name[i] ) );
	      }
	    else
	      {
		// ans.push_back( make_pair( i, name[i] ) ) ;
		logs[a][b].erase(ite);
	      }
	    int nxtSeq = log[pos].empty() ? 0 : log[pos].front().first;
	    int nA = log[pos].empty() ? 1 : 
	      ( log[pos].front().second == -1 ? 2 : 0 );
	    logs[nA][ 1 - b ].insert( make_pair( nxtSeq, name[i]) );
	    ans.push_back( make_pair( 1 - b, name[i] ) );
	  // }
      }
    else
      {
	int sum(0);
	for( int j = 0; j < 3; ++j )
	  sum += logs[j][1].size();
	if( sum > p[i] )
	  {
	    typeof( logs[2][1].begin() ) ite;
	    for( int j = 2; j > 0 ; --j )
	      {
		ite = logs[j][1].begin();
		for( ; sum > p[i] && !logs[j][1].empty(); --sum )
		  {
		    logs[j][0].insert( *ite );
		    ans.push_back( make_pair( 0, ite->second ) );
		    typeof( ite ) ii = ite++;
		    logs[j][1].erase(ii);
		  }
	      }
	    if( sum > p[i] )
	      {
		ite = logs[0][1].end();
		for( --ite; !logs[0][1].empty() && sum > p[i]; --sum )
		  {
		    logs[0][0].insert( *ite );
		    ans.push_back( make_pair( 0, ite->second ) );
		    typeof(ite) ii = ite--;
		    logs[0][1].erase(ii);
		  }
	      }
	  }
	else if( sum < p[i] )
	  {
	    for( int j = 0; j < 2 && sum < p[i] ; ++j )
	      {
		typeof( logs[j][0].begin() ) ite = logs[j][0].begin();
		for( ; sum < p[i] && ite != logs[j][0].end(); ++sum )
		  {
		    logs[j][1].insert( *ite );
		    ans.push_back( make_pair( 1, ite->second ) );
		    typeof(ite) ii = ite++;
		    logs[j][0].erase(ii);
		  }
	      }
	  }
	string number;
	if( p[i] > 0 )
	  for( int j = p[i] ; j ; j /= 10 )
	    number = (char)( '0' + ( j % 10 ) ) + number;
	else number = '0';
	ans.push_back( make_pair( 3,  number) );
      }
  printf("%d\n", (int) ans.size() );
  for( int i = 0 ; i < ans.size() ; ++i )
    if( ans[i].first != 3 )
      printf("%c %s\n", ans[i].first == 1 ? '+' : '-', ans[i].second.c_str() );
    else
      printf("= %s\n", ans[i].second.c_str() );
  return 0;
}
