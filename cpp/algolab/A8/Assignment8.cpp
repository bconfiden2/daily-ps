/*************************************************************
*                                                            *
*  Problem : 모래시계 출력하기                                   *
*                                                            *
**************************************************************
*                                                            *
*                     20152635 경영학부 빅데이터경영통계전공 김상홍  *
*                                                            *
*************************************************************/
#include <iostream>
using namespace std;
void DrawLine(int, int);
int main(void)
{
  int testCases = 0;
  cin >> testCases;

  for(int i = 0 ; i < testCases ; i++)
  {
    int size = 0, midIdx = 0;
    cin >> size;

    midIdx = size / 2;

    for(int idx = 0 ; idx < size ; idx++)
    {
      if(idx <= midIdx)
      {
        DrawLine(idx, size);
      }
      else
      {
        DrawLine(2 * midIdx - idx, size);
      }
    }
  }
}

void DrawLine(int idx, int size)
{
  int i;

  for(i = 0 ; i < idx ; i++)
  {
    cout << '-';
  }

  for(i = 0 ; i < size - 2*idx ; i++)
  {
    if(i % 2 == 0)
    {
      cout << '*';
    }
    else
    {
      cout << '+';
    }
  }

  for(i = 0 ; i < idx ; i++)
  {
    cout << '-';
  }

  cout << endl;
}
