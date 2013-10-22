#ifndef __OUTPUTF__
#define __OUTPUTF__
#include <cstdio>
#include <vector>
#include <cstdarg>
using namespace std;
void addx(int x);
void delx(int x);
void addid();
void delid();
void mprint(int pos,bool h,FILE *file ,const char * fmt, ...);
#endif
