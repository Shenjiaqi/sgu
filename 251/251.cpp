#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  int n;
  scanf("%d", &n);

  vector<int> r;
  r.resize(n);
  for (int i(0); i < n; ++i)
    {
      scanf("%d", &r[i]);
    }

  bool Ok(false);
  
  float pos[4][2] = {0};
  pos[1][1] = (r[0] + r[1] + r[2]) * 2.0;
  pos[2][0] = 1.0;

  if (n == 3)
    {
      Ok = true;
    }
  else if (n == 4)
    {
      if (r[0] == r[1])
	{
	  Ok = true;
	  pos[3][0] = 1.0;
	  pos[3][1] = 2.0 * (r[0] + r[2] + r[3]);
	}
      else if (r[0] + r[1] == r[3] + r[3])
	{
	  Ok = true;
	  pos[3][0] = -1.0;
	  pos[3][1] = 2.0 * (r[0] + r[2] + r[3]);
	}
    }

  if (Ok)
    {
      printf("YES\n");
      for (int i(0); i < n; ++i)
	{
	  printf("%.4f %.4f\n", pos[i][0], pos[i][1]);
	}
    }
  else
    {
      printf("NO");
    }

  return 0;
}
