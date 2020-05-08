#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
  int k = 0;
  vector<int> v;

  int n = 0;
  scanf("%d",&n);
  while(n--)
  {
    scanf("%d", &k);
    v.push_back(k);
  }

  sort(v.begin(), v.end());

  int m = 0;
  scanf("%d", &m);
  while(m--)
  {
    scanf("%d", &k);
    printf("%ld ", upper_bound(v.begin(), v.end(), k) - lower_bound(v.begin(), v.end(), k));
  }
}
