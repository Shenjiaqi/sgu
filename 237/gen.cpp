#include <cstdio>
#include <cstdlib>
#include <ctime>

int main()
{
  for (int i(0); i < 255; ++i)
    {
      printf("!");
    }
  return 0;
  
  int n = 30;
  srand(time(NULL));
  
  for (int i(0); i < n; ++i)
    {
      int r(rand() % n);
      if (r < 10)
	{
	  printf("*");
	}
      else if (r < 15)
	{
	  printf("?");
	}
      else if (r < 20)
	{
	  printf("!");
	}
      else
	{
	  printf("%c", (rand() % 26) + 'a');
	}
    }
  return 0;
}
