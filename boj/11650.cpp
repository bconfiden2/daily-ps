#include <cstdio>
#include <utility>
#include <algorithm>
using namespace std;

pair<int,int> pairs[100000];

int main(void)
{
  int n = 0;
  scanf("%d", &n);
  for(int i = 0 ; i < n ; i++)
  {
    int a, b;
    scanf("%d %d", &a, &b);
    pairs[i] = make_pair(a,b);
  }
  sort(pairs, pairs+n);
  for(int i = 0 ; i < n ; i++)
  {
    printf("%d %d\n", pairs[i].first, pairs[i].second);
  }
}
