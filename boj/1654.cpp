#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  vector<unsigned int> v;
  v.reserve(10000);

  int n, k;
  cin >> k >> n;
  unsigned int val, max = 0;
  // 최댓값은 구해놓는게 편하다
  for(int i = 0 ; i < k; i++)
  {
    cin >> val;
    if(val > max)
    {
      max = val;
    }
    v.emplace_back(val);
  }

  unsigned int sum = 0;

  unsigned int low = 1;
  unsigned int high = max;
  unsigned int mid = 0;
  // 이분탐색으로 최대 랜선 길이 값에 수렴
  while(low <= high)
  {
    // 중간값을 기준으로 검사한다.
    mid = (low + high) / 2;

    for(int i = 0 ; i < k ; i++)
    {
      sum += v[i] / mid;
    }
    // 만약 현재 값이 가능한 숫자라면, 그 위에도 가능한 값이 있을 수 있기 때문에 다시 탐색
    // 최솟값을 현재 값으로 설정
    if(sum >= n)
    {
      low = mid + 1;
    }
    // 아니라면 최댓값을 현재 값으로 설정
    else
    {
      high = mid - 1;
    }
    sum = 0;
  }

  cout << high << '\n';
}
