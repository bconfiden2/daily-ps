#include <iostream>
using namespace std;

int n;
int map[129][129];
int blue;
int white;

// size = 해당 호출에서 변의 길이, row 는 맵의 y좌표, col 은 맵의 x좌표
void cut(int size, int row, int col)
{
  // 만약 사이즈가 1이라 더 잘라낼게 없을 경우
  if(size == 1)
  {
    // 해당 위치의 값을 보고 파란색 하얀색 갯수 추가해줌
    if(map[row][col]) blue++;
    else white++;
    return;
  }

  // 사이즈가 1이 아니고 그 이상일 경우
  // 나의 사이즈*사이즈 만큼의 정사각형이 모두 같은 값을 가져야 해당 색깔로 추가할 수 있음
  bool avail = true;
  int first = map[row][col]; // 첫 시작 값
  for(int i = row ; i < row + size ; i++)
  {
    for(int j = col ; j < col + size ; j++)
    {
      // 내 정사각형이 모두 첫 시작값과 같아야만 자를수있음
      if(map[i][j] != first)
      {
        avail = false;
        break;
      }
    }
    if(!avail) break;
  }

  // 만약 내 정사각형이 하나의 색종이로 잘리면
  if(avail)
  {
    // 해당 색깔 추가
    if(first) blue++;
    else white++;
    return;
  }
  else // 안 잘리면 재귀호출로 4개를 다시 잘라준다
  {
    cut(size / 2, row, col);
    cut(size / 2, row + size / 2, col);
    cut(size / 2, row, col + size / 2);
    cut(size / 2, row + size / 2, col + size / 2);
  }
}

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  // 입력 받아서 맵에 넣어주고 ( 인덱스는 1부터 n 까지로 보기 편하게 해놨음 )
  for(int i = 1 ; i <= n ; i++)
  {
    for(int j = 1 ; j <= n ; j++)
    {
      cin >> map[i][j];
    }
  }
  // 첫 재귀를 전체 맵을 보는 걸로 시작
  cut(n, 1, 1);

  cout << white << '\n';
  cout << blue << '\n';
}
