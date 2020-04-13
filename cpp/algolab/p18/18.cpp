/*************************************************************
*                                                            *
*  Problem : 삼각형의 면적                                                
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
    int triangleSize = 0;
    int pointsDir = 0;

    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    int signSize = 0;
    signSize = (bx-ax) * (cy-ay) - (cx-ax) * (by-ay);

    if(signSize > 0)
    {
      pointsDir = 1;
    }
    else if(signSize < 0)
    {
      pointsDir = -1;
    }
    else
    {
      pointsDir = 0;
    }

    triangleSize = pointsDir * signSize;

    cout << triangleSize << " " << pointsDir << endl;
  }
}
