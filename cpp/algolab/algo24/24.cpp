#include <iostream>

using namespace std;

//int rooms[100];

void filling(int row, int col, char** map, char data)
{
  map[row][col] = data;

  if(map[row - 1][col] == '.') // 위쪽
  {
    filling(row - 1, col, map, data);
  }
  if(map[row][col - 1] == '.') // 왼쪽
  {
    filling(row, col - 1, map, data);
  }
  if(map[row][col + 1] == '.') // 오른쪽
  {
    filling(row, col + 1, map, data);
  }
  if(map[row + 1][col] == '.') // 아래쪽
  {
    filling(row + 1, col, map, data);
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

    int p = 96; // 아스키코드 디버깅용
    // 방을 번호로 채우기
    int roomCounter = p;

    for(int i = 1 ; i < row - 1 ; i++)
    {
      for(int j = 1 ; j < col - 1 ; j++)
      {
        if(map[i][j] == '.')
        {
          filling(i, j, map, char(++roomCounter));
        }
      }
    }

    // 방 칸수 세기
    int* roomNumbers = new int[roomCounter + 1 - p];
    for(int i = 0 ; i < roomCounter + 1 - p ; i++)
    {
      roomNumbers[i] = 0;
    }
    for(int i = 1 ; i < row - 1 ; i++)
    {
      for(int j = 1 ; j < col - 1 ; j++)
      {
        if(map[i][j] != '+')
        {
          roomNumbers[int(map[i][j]) - p]++;
        }
      }
    }

    // 정렬
    for(int i = 1 ; i < roomCounter + 1 - p ; i++)
    {
      for(int j = i + 1 ; j < roomCounter + 1 - p ; j++)
      {
        if(roomNumbers[j] > roomNumbers[i])
        {
          int temp = roomNumbers[j];
          roomNumbers[j] = roomNumbers[i];
          roomNumbers[i] = temp;
        }
      }
    }


    // 출력
    cout << roomCounter - p << endl;
    for(int i = 1 ; i < roomCounter + 1 - p ; i++)
    {
      cout << roomNumbers[i] << " ";
    }
    cout << endl;


    // 맵 출력 (디버깅용)
    for(int i = 0 ; i < row ; i++)
    {
      for(int j = 0 ; j < col ; j++)
      {
        cout << map[i][j];
      }
      cout << endl;
    }

    // 방 지우기
    for(int i = 0 ; i < row ; i++)
    {
      delete[] map[i];
    }
    delete[] map;
  }
}
