#include <algorithm>
#include <vector>
#include <cstdio>
using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(false);
  int n = 0;
  scanf("%d", &n);

  int* num = new int[n];

  for(int i = 0 ; i < n ; i++)
  {
    scanf("%d", &num[i]);
  }
  sort(num, num + n);
  for(int i = 0 ; i < n ; i++)
  {
    printf("%d\n", num[i]);
  }

  delete num;
  return 0;
}
