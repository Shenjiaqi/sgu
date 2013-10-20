// unique algorithm example
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;

bool myfunction (int i, int j) {
  return (i==j);
}
typedef pair<double,double> pp;
bool equ(pp a,pp b)
{
    return a==b;
}
int main () {
  int myints[] = {10,20,20,20,30,30,20,20,10};    // 10 20 20 20 30 30 20 20 10
  vector<int> myvector (myints,myints+9);
  vector<int>::iterator it;

  // using default comparison:
  it = unique (myvector.begin(), myvector.end()); // 10 20 30 20 10 ?  ?  ?  ?
                                                  //                ^

  myvector.resize( it - myvector.begin() );       // 10 20 30 20 10

  // using predicate comparison:
  vector<pp>ll;
  unique (ll.begin(), ll.end(),equ);   // (no changes)

  // print out content:
  cout << "myvector contains:";
  for (it=myvector.begin(); it!=myvector.end(); ++it)
    cout << " " << *it;

  cout << endl;

  return 0;
}
