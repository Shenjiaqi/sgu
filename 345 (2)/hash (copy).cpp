
#include <cstdio>
class a
{
public:
	~a(){printf("~a\n");};
};
class b
{
public:
	~b(){printf("~b\n");};
	class a t;
};
int main()
{
	class b tmp;
	return 0;
}
