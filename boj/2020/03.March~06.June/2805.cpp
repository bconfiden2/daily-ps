#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<long long int> v;

// 나무들을 다 잘랐을 때 가능한 합이 m 을 넘는지, 못 넘는지
bool check(const long long int& mid)
{
  long long int sum = 0;

  for(int i = 0 ; i < n ; i++)
  {
    // 자른 길이가 0보다 클때만 더해줌
    if(v[i] - mid > 0)
    {
      sum += v[i] - mid;
      // 정렬되어있는 상태이기 때문에, 그냥 앞에서부터 쭉 더했을때 m 보다 크면 가능하다고 판단
      if(sum >= m)
      {
        return true;
      }
    }
  }

  return false;
}

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long int data;
  cin >> n >> m;

  v.reserve(1000000);
  for(int i = 0 ; i < n ; i++)
  {
    cin >> data;
    v.emplace_back(data);
  }
  // 나무들을 정렬해줘서 완전탐색 할 필요 없게
  sort(v.begin(), v.end());

  long long int low = 0;
  long long int high = *(v.end() - 1);
  long long int mid = 0;
  long long int ans = 0;

  // 이분 탐색 시작
  while(low <= high)
  {
    mid = (low + high) / 2;

    // 잘랐을 때 m 이 넘으면
    if(check(mid))
    {
      // 값을 넣어주고 위쪽을 탐색
      if(ans < mid) ans = mid;
      low = mid + 1;
    }
    else // 못 넘으면
    {
      // 아랫쪽을 탐색
      high = mid - 1;
    }
  }
  cout << ans << endl;
}
