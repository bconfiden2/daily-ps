#include <iostream>

using namespace std;

int rooms[100] = {0};
int roomCounter = 0;

void filling(int row, int col, char** map)
{
  map[row][col] = '-';
  rooms[roomCounter]++;

  if(map[row - 1][col] == '.') // 위쪽
  {
    filling(row - 1, col, map);
  }
  if(map[row][col - 1] == '.') // 왼쪽
  {
    filling(row, col - 1, map);
  }
  if(map[row][col + 1] == '.') // 오른쪽
  {
    filling(row, col + 1, map);
  }
  if(map[row + 1][col] == '.') // 아래쪽
  {
    filling(row + 1, col, map);
  }
}

int main(void)
{
  int testCases = 0;
  cin >> testCases;
  for(int tc = 0 ; tc < testCases ; tc++)
  {
    int row, col;
    cin >> col >> row;

    // 방 정보 입력
    char** map = new char*[row];
    for(int i = 0 ; i < row ; i++)
    {
      map[i] = new char[col];
      for(int j = 0 ; j < col ; j++)
      {
        cin >> map[i][j];
      }
    }

    // 방 세기
    for(int i = 1 ; i < row - 1 ; i++)
    {
      for(int j = 1 ; j < col - 1 ; j++)
      {
        if(map[i][j] == '.')
        {
          filling(i, j, map);
          roomCounter++;
        }
      }
    }

    // 정렬
    for(int i = 0 ; i < roomCounter ; i++)
    {
      for(int j = i + 1 ; j < roomCounter ; j++)
      {
        if(rooms[j] > rooms[i])
        {
          int temp = rooms[j];
          rooms[j] = rooms[i];
          rooms[i] = temp;
        }
      }
    }

    // 출력
    cout << roomCounter << endl;
    for(int i = 0 ; i < roomCounter ; i++)
    {
      cout << rooms[i] << " ";
    }
    cout << endl;

    // 방 지우고 초기화
    for(int i = 0 ; i < row ; i++)
    {
      delete[] map[i];
    }
    delete[] map;

    for(int i = 0 ; i < roomCounter ; i++)
    {
      rooms[i] = 0;
    }
    roomCounter = 0;
  }
}
