/*************************************************************
*                                                            *
*  Problem : 직선그래프출력하기                                  *
*                                                            *
**************************************************************
*                                                            *
*                     20152635 경영학부 빅데이터경영통계전공 김상홍  *
*                                                            *
*************************************************************/
#include <iostream>

using namespace std;

void PrintLine(char, char, int, int);

int main(void)
{
  int testCases = 0;
  cin >> testCases;

  for(int i = 0 ; i < testCases ; i++)
  {
    int size = 0;
    int mid = 0;
    cin >> size;

    for(int j = size ; j >= 1 ; j--)
    {
      if(j == size/2 + 1)
      {
        PrintLine('+', 'O', j, size);
      }
      else
      {
        PrintLine('.', '*', j, size);
      }
    }
  }

  return 0;
}

void PrintLine(char empty, char point, int idx, int num)
{
  for(int i = 1 ; i <= num ; i++)
  {
    if(i == idx)
    {
      cout << point;
    }
    else if(i == num/2 + 1)
    {
      cout << 'I';
    }
    else
    {
      cout << empty;
    }
  }

  cout << endl;
}
