#include <iostream>
#include <vector>
//#define MINI(x,y) x < y ? x : y
using namespace std;

int MINI(int x, int y)
{
  return x < y ? x : y;
}

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
int dirX[4] = {-1, 1, 0, 0}; // 방향에 대한 (x,y)
int dirY[4] = {0, 0, 1, -1};

int move(int count, Point target, Point other, int dir)
{
  // 두 공이 향할 곳이 모두 벽이라면 바로 빠져나오기
  if(map[target.x + dirX[dir]][target.y + dirY[dir]] == '#' && map[other.x + dirX[dir]][other.y + dirY[dir]] == '#') { return 11;}

  // 만약 현재까지 10번을 굴렸으면 실패했다는 뜻
  if(count == 10) { return 11;}

  // 다음 방향이 둘 다 벽이 아닐 경우 일단 해당 방향으로 옮겨줄 것임
  // 한번 굴렸음을 표시
  count++;
  // 이번 함수 내에서 사용할 위치 두개 복사해서 생성
  Point R(target.x, target.y);
  Point B(other.x, other.y);

  bool fMove = true; // 빨간공 움직이는지 상태값
  bool sMove = true; // 파란공 움직이는지 상태값
  bool redIn = false; // 빨간공 빠졌는지 상태값
  bool blueIn = false; // 파란공 빠졌는지 상태값

  // 하나라도 움직이는 중이라면 계속 움직여줘야함 (벽에 닿을 때 까지)
  while(fMove || sMove)
  {
    // 빨간공 다음위치가 벽이 아니라면 옮겨준다
    if(map[R.x + dirX[dir]][R.y + dirY[dir]] != '#')
    {
      R.x += dirX[dir];
      R.y += dirY[dir];
      fMove = true;
    }
    else fMove = false;

    // 파란공 다음위치가 벽이 아니라면 옮겨준다
    if(map[B.x + dirX[dir]][B.y + dirY[dir]] != '#')
    {
      B.x += dirX[dir];
      B.y += dirY[dir];
      sMove = true;
    }
    else sMove = false;
    // 움직이다가 도중에 구멍을 만나게 되면 처리해준다
    if(B.x == Hole.x && B.y == Hole.y) blueIn = true;
    if(R.x == Hole.x && R.y == Hole.y) redIn = true;
  }
  // 만약 다 움직였는데 중간에 파란공이 빠졌다고 처리된 경우 실패
  if(blueIn) return 11;
  // 파란공이 안빠지고 빨간공만 빠졌을 경우에 성공처리해주고 count 반환
  if(redIn) return count;

  // 두 공이 겹쳤을 경우 하나 옮겨줘야 함
  if(R.x == B.x && R.y == B.y)
  {
    // 방향에 따라서 공 하나 해당방향으로 옮겨준다
    switch (dir) {
      case 0:
        target.x < other.x ? B.x++ : R.x++;
        break;
      case 1:
        target.x > other.x ? B.x-- : R.x--;
        break;
      case 2:
        target.y > other.y ? B.y-- : R.y--;
        break;
      case 3:
        target.y < other.y ? B.y++ : R.y++;
        break;
    }
  }

  // 이번에 옮겨준 방향에 따라서 다음번 재귀호출을 통제 (이번 방향과 반대방향으로 옮겨주는것은 의미가 없기 떄문에)
  // 이번에 옮겨준 위치를 기준으로 해당 방향들을 전부 탐색
  // 재귀호출
  switch (dir) {
    case 0:
      return MINI(MINI(move(count, R, B, 0), move(count, R, B, 3)), move(count, R, B, 2));
      break;
    case 1:
      return MINI(MINI(move(count, R, B, 3), move(count, R, B, 1)), move(count, R, B, 2));
      break;
    case 2:
      return MINI(MINI(move(count, R, B, 0), move(count, R, B, 1)), move(count, R, B, 2));
      break;
    case 3:
      return MINI(MINI(move(count, R, B, 0), move(count, R, B, 1)), move(count, R, B, 3));
      break;
  }
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
  // 첫 시작점에서 상하좌우를 다 탐색하고, 그 중 최솟값을 결과로 받음
  result = MINI(MINI(MINI(move(0, Red, Blue, 0), move(0, Red, Blue, 1)), move(0, Red, Blue, 2)), move(0, Red, Blue, 3));
  // 만약 모든 방향에 있어서 불가능하다고 나오면 -1
  if(result == 11) result = -1;
  cout << result << '\n';
}
