#ifndef __OPN_TABLE__
#define __OPN_TABLE__
#include <vector>
using namespace std;
class opn_tab_entry
{
private:
	int para;
	int syn;
	int img;
public:
	opn_tab_entry(int p,int s,int i){para=p,syn=s,img=i;};
	int getpara(){return para;};
	int getsyn(){return syn;};
	int getimg(){return img;};
};
class opn_table
{
private:
	vector<opn_tab_entry> list;
public:
	opn_table(){list.push_back(opn_tab_entry(0,0,0));};
	int add(int p,int s,int i);
	void output_h(FILE *file,int l,bool h);
	int getsize();
	int getpara(int i);
	int getsyn(int i);
	int getimg(int i);
};
#endif
