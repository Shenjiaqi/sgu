#ifndef __STRSTACK_H__
#define __STRSTACK_H__
#include <string>
#include <vector>
using namespace std;
class strstack
{
private:
	vector<string> sta;
	int n;
public:
	void clear();
	strstack();
	int newstr(string s);
	string getstr(int k);
	int getsize();
};
#endif
