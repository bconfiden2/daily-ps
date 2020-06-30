#include <iostream>
#include <vector>
#define pow2(n) ((n)*(n))
using namespace std;

// 각 진영을 하나의 객체로 취급
struct Point
{
  int x;
  int y;
  int r;
  // 서로 연결되어 있는 노드 정보들
  vector<Point*> nodes;
  // dfs 탐색 시 체크 여부
  bool checked = false;

  // dfs 탐색 시 호출되는 함수
  void changeState()
  {
    // 이미 체크되었던 진영이면 그냥 끝
    if(checked) return;
    checked = true;
    // 나에게 연결되어 있는 진영들을 다 체크해준다
    for(int i = 0 ; i < nodes.size() ; i++)
    {
      nodes[i]->changeState();
    }
  }
};


int main(void)
{
  cin.tie(0);
  cout.tie(0);
  ios_base::sync_with_stdio(0);

  int t;
  cin >> t;
  for(int tc = 0 ; tc < t ; tc++)
  {
    int n;
    int number = 0;
    cin >> n;

    // 각 진영들에 대한 정보
    vector<Point> v;
    v.reserve(n); // n개
    int x, y, r;
    // 진영 정보 넣어주고
    for(int i = 0 ; i < n ; i++)
    {
      cin >> x >> y >> r;
      v.emplace_back(Point{x, y, r});
    }
    // 각 진영들을 서로 연결해준다
    for(int i = 0 ; i < v.size() ; i++)
    {
      for(int j = i + 1 ; j < v.size() ; j++)
      {
        if(pow2(v[i].x - v[j].x) + pow2(v[i].y - v[j].y) <= pow2(v[i].r + v[j].r))
        {
          v[i].nodes.push_back(&v[j]);
          v[j].nodes.push_back(&v[i]);
        }
      }
    }
    // dfs 탐색 시작, 연결되어있는 진영별로 하나씩 카운트
    for(int i = 0 ; i < v.size() ; i++)
    {
      if(v[i].checked == false)
      {
        v[i].changeState();
        number++;
      }
    }

    cout << number << '\n';
  }
}