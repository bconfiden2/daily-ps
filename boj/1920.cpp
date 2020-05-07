#include <algorithm>
#include <cstdio>

using namespace std;

int main(void)
{
  int n = 0;
  scanf("%d", &n);

  int* nums = new int[n];
  for(int i = 0 ; i < n ; i++)
  {
    scanf("%d", nums+i);
  }

  int m = 0;
  scanf("%d", &m);
  sort(nums, nums+n);
  for(int i = 0 ; i < m ; i++)
  {
    int a = 0;
    scanf("%d", &a);
    printf("%d\n", binary_search(nums, nums+n, a));
  }
}
