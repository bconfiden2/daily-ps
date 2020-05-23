#include <iostream>
#include <vector>
using namespace std;

class Point
{
public :
  int row;
  int col;
  void SetPoint(int x, int y) { row = x, col = y; };
  bool Equal() { return };
private :
};

Point Red;
Point Blue;
Point Hole;
int n, m, result;
char data;
vector<vector<char>> map;

int solve()
{
  int res = 0;

  return res;
}

int main(void)
{
  cin >> n >> m;
  for(int i = 0 ; i < n ; i++)
  {
    vector<char> line;
    for(int j = 0 ; j < m ; j++)
    {
      cin >> data;
      line.emplace_back(data);
      if(data == 'R') Red.SetPoint(n, m);
      else if(data == 'B') Blue.SetPoint(n, m);
      else if(data == 'O') Hole.SetPoint(n, m);
    }
    map.emplace_back(line);
  }
  result = solve();
  cout << result << '\n';
}
