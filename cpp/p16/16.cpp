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

      }
      else if(ay > y2) // 1
      {

      }
      else // 4
      {
        cout << (x1-ax) * (x1-ax) << " " << x1 - ax;
      }
    }
    else if(ax > x2) // 3,6,9
    {
      if(ay < y1) // 9
      {

      }
      else if(ay > y2) // 3
      {

      }
      else // 6
      {
        cout << (ax-x2) * (ax-x2) << " " << ax - x2;
      }
    }
    else // 2,5,8
    {
      if(ay < y1) // 8
      {
        cout << (y1-ay) * (y1-ay) << " " << y1 - ay;
      }
      else if(ay > y2) // 2
      {
        cout << (ay-y2) * (ay-y2) << " " << ay - y2;
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
