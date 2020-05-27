#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<pair<int, int>> v; // 자료형 주의!!

// 입력한 회의 시간들을 정렬해주는 기준함수
bool desc(pair<int, int> p, pair<int, int> p2)
{
  // 종료 시간이 같을 경우 시작시간 빠른 순
  if(p.second == p2.second)
  {
    return p1.first < p2.first;
  }
  // 종료 시간이 빠른 순
  return p.second < p2.second;
}

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  v.reserve(n);
  unsigned int l,r;
  for(int i = 0 ; i < n ; i++)
  {
    cin >> l >> r;
    v.emplace_back(pair<int, int>(l, r));
  }
  sort(v.begin(), v.end(), desc);

  int cnt = 1;
  int idx = 0; // 이전에 시작한 회의
  // 쭉 한번 돌면서 이전의 회의가 종료 되었으면 가장 앞에 있는 회의를 실행
  for(int i = 1 ; i < n ; i++)
  {
    if(v[i].first >= v[idx].second)
    {
      idx = i;
      cnt++;
    }
  }
  cout << cnt << '\n';
}
