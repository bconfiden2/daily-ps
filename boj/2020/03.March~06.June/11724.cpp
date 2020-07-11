#include <iostream>
#include <vector>
#include <array>
using namespace std;

int n, m, cnt = 0;
// 방문 여부에 대한 배열
array<bool, 1001> arr;
// 노드들 간의 연결 상태를 보여주는 2차원 벡터
vector<vector<int>> v(1001);

// 노드 방문 시
void check(int i)
{
  // 이미 방문했던 노드면 바로 종료
  if(arr[i]) return;

  // 방문했다고 표시해주고
  arr[i] = true;
  // 자기에게 연결되어있는 노드들을 전부 방문
  for(int j = 0 ; j < v[i].size() ; j++)
  {
    check(v[i][j]);
  }
}

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  int l,r;
  // 입력받은 데이터를 가지고 노드들을 서로 연결
  for(int i = 0 ; i < m ; i++)
  {
    cin >> l >> r;
    v[l].emplace_back(r);
    v[r].emplace_back(l);
  }

  // 노드들을 전부 방문
  for(int i = 1 ; i <= n ; i++)
  {
    // 이미 방문했던 노드라면 다른 곳에 연결되어있다는 뜻
    if(arr[i])
    {
      continue;
    }
    // 방문하지 않은 노드 - 새로운 연결 요소 라는 뜻
    check(i);
    cnt++;
  }

  cout << cnt << '\n';
}
