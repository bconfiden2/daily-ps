/*************************************************************
*                                                            *
*  Problem :                                                 *
*                                                            *
**************************************************************
*                                                            *
*                     20152635 경영학부 빅데이터경영통계전공 김상홍  *
*                                                            *
*************************************************************/
#include <iostream>
using namespace std;

int pow(int);
void PrintAnswer(int, int, int, int);

int main(void)
{
  int testCases = 0;
  cin >> testCases;

  for(int i = 0 ; i < testCases ; i++)
  {
    int x1, y1, x2, y2;
    int ax, ay;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> ax >> ay;

    //면을 9개로 나눈다!
    /*   1 | 2 | 3
        -----------
         4 | 5 | 6
        -----------
         7 | 8 | 9
    */ //5번 면적이 주어진 사각형 부분

    if(ax < x1) // 1,4,7
    {
      if(ay < y1) // 7
      {
        PrintAnswer(ax, ay, x1, y1);
      }
      else if(ay > y2) // 1
      {
        PrintAnswer(ax, ay, x1, y2);
      }
      else // 4
      {
        PrintAnswer(ax, ay, x1, ay);
      }
    }
    else if(ax > x2) // 3,6,9
    {
      if(ay < y1) // 9
      {
        PrintAnswer(ax, ay, x2, y1);
      }
      else if(ay > y2) // 3
      {
        PrintAnswer(ax, ay, x2, y2);
      }
      else // 6
      {
        PrintAnswer(ax, ay, x2, ay);
      }
    }
    else // 2,5,8
    {
      if(ay < y1) // 8
      {
        PrintAnswer(ax, ay, ax, y1);
      }
      else if(ay > y2) // 2
      {
        PrintAnswer(ax, ay, ax, y2);
      }
      else // 5
      {
        cout << 0 << " " << 0;
      }
    }

    cout << endl;
  }

  return 0;
}

int pow(int a)
{
  return a * a;
}

int abs(int a)
{
  if(a >= 0)
  {
    return a;
  }
  else
  {
    return -1 * a;
  }
}

void PrintAnswer(int px, int py, int bx, int by)
{
  cout << pow(px - bx) + pow(py - by) << " " << abs(px - bx) + abs(py - by);
}
