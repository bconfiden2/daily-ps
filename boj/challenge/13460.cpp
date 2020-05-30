#include <iostream>
#include <vector>
#define MINI(x,y) x < y ? x : y
using namespace std;

class Point
{
public:
  int x;
  int y;

  Point() { x=0; y = 0;}
  Point(int a, int b) : x(a), y(b) {}
  void Set(int a, int b) { x = a; y = b;}
};

Point Red, Blue, Hole;
int n, m, result;
char data;
vector<vector<char>> map;
int dirX[4] = {-1, 1, 0, 0};
int dirY[4] = {0, 0, 1, -1};

int move(int count, Point target, Point other, int dir)
{
  // 향할 곳이 벽이라면 바로 빠져나오기
  if(map[target.x + dirX[dir]][target.y + dirY[dir]] == '#') return 11; // 방향

  // 벽이 아닐 경우 해당 방향으로 뒤집어줌
  count++;
  Point R(target.x, target.y);
  Point B(other.x, other.y);

  bool fMove = true;
  bool sMove = true;
  while(!fMove && !sMove) // 방향
  {
    if(map[R.x + dirX[dir]][R.y + dirY[dir]] != '#')
    {
      R.x += dirX[dir];
      R.y += dirY[dir];
      fMove = true;
    }
    else fMove = false;
    if(map[B.x + dirX[dir]][B.y + dirY[dir]] != '#')
    {
      B.x += dirX[dir];
      B.y += dirY[dir];
      sMove = true;
    }
    else sMove = false;

    if(B.x == Hole.x && B.y == Hole.y) return 11;
    if(R.x == Hole.x && R.y == Hole.y) return count;
  }

  if(R.x == B.x && R.y == B.y)
  {
    switch (dir) {
      case 0:
        target.x < other.x ? B.x++ : R.x++;
        break;
      case 1:
        target.x > other.x ? B.x-- : R.x--;
        break;
      case 2:
        target.y > other.y ? B.y-- : R.y++;
        break;
      case 3:
        target.y < other.y ? B.y++ : R.y--;
        break;
    }
  }

  // 만약 카운트가 10이 넘어갈 경우 유효하지 않으니 빠져나옴
  if(count > 10) return 11;
  cout << R.x << " " << B.y << endl;
  // 모든 방향 다 호출
  return MINI(MINI(MINI(move(count + 1, R, B, 0), move(count + 1, R, B, 1)), move(count + 1, R, B, 2)), move(count + 1 , R, B, 3));
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
      if(data == 'R') Red.Set(i, j);
      else if(data == 'B') Blue.Set(i, j);
      else if(data == 'O') Hole.Set(i, j);
    }
    map.emplace_back(line);
  }
  cout << Red.x << " " << Red.y << endl;
  cout << Blue.x << " " << Blue.y << endl;
  cout << Hole.x << " " << Hole.y << endl;
  result = MINI(MINI(MINI(move(0, Red, Blue, 0), move(0, Red, Blue, 1)), move(0, Red, Blue, 2)), move(0, Red, Blue, 3));
  if(result == 11) result = -1;
  cout << result << '\n';
}
