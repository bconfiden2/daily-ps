#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

// 정렬 기준
bool yFirst(pair<int,int> x, pair<int,int> y)
{
  // y값이 같을 경우에는 x값 오름차순
  if(x.second == y.second)
  {
    return x.first < y.first;
  }
  // y값 오름차순
  else
  {
    return x.second < y.second;
  }
}

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int n = 0;
  cin >> n;

  vector<pair<int,int>> v;

  for(int i = 0 ; i < n ; i++)
  {
    int x, y;
    cin >> x >> y;
    v.emplace_back(pair<int,int>(x,y));
  }

  sort(v.begin(), v.end(), yFirst);

  for(int i = 0 ; i < n ; i++)
  {
    cout << v[i].first << " " << v[i].second << '\n';
  }
}
