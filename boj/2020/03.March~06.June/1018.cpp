#include <iostream>
using namespace std;

char answer[8][8] =
{
  {'B','W','B','W','B','W','B','W'},
  {'W','B','W','B','W','B','W','B'},
  {'B','W','B','W','B','W','B','W'},
  {'W','B','W','B','W','B','W','B'},
  {'B','W','B','W','B','W','B','W'},
  {'W','B','W','B','W','B','W','B'},
  {'B','W','B','W','B','W','B','W'},
  {'W','B','W','B','W','B','W','B'}
};

int checkColor(int row, int col, char** board)
{
  int sum1 = 0;
  int sum2 = 0;
    for(int i = 0 ; i < 8 ; i++)
    {
      for(int j = 0 ; j < 8 ; j++)
      {
        if(board[row + i][col + j] != answer[i][j]) sum1++;
        else sum2++;
      }
    }
/*
  char first = board[row][col];
  for(int i = 0 ; i < 8 ; i++)
  {
    char lineFirst;
    if(i % 2 == 0)
    {
      lineFirst = first;
    }
    else
    {
      if(first == 'W')
      {
        lineFirst = 'B';
      }
      else
      {
        lineFirst = 'W';
      }
    }

    for(int j = 0 ; j < 8 ; j++)
    {
      if(j % 2 == 0)
      {
        if(board[row + i][col + j] != lineFirst)
        {
          sum++;
        }
      }
      else
      {
        if(board[row + i][col + j] == lineFirst)
        {
          sum++;
        }
      }
    }
  }
*/
  return sum1 > sum2 ? sum2 : sum1;
}

int main(void)
{
  int n, m;
  cin >> n >> m;

  char** board = new char*[n];
  for(int i = 0 ; i < n ; i++)
  {
    board[i] = new char[m];
    for(int j = 0 ; j < m ; j++)
    {
      cin >> board[i][j];
    }
  }



  int min = 64;

  for(int i = 0 ; i <= n - 8 ; i++)
  {
    for(int j = 0 ; j <= m - 8 ; j++)
    {
      int m = checkColor(i, j, board);
      if(m < min)
      {
        min = m;
      }
    }
  }

  for(int i = 0 ; i < n ; i++)
  {
    delete[] board[i];
  }
  delete[] board;

  cout << min << endl;
}
