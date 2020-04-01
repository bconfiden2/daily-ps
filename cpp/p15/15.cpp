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
#include <cmath>
using namespace std;

double CalculateLength(int, int, int, int);

int main(void)
{
  int testCases = 0;
  cin >> testCases;

  for(int i = 0 ; i < testCases ; i++)
  {
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    //세 변의 길이를 잰다
    double a = CalculateLength(ax, ay, bx, by);
    double b = CalculateLength(bx, by, cx, cy);
    double c = CalculateLength(ax, ay, cx, cy);
    double temp = 0.0;

    //가장 긴 변을 c에다가 넣어준다
    if(a >= b)
    {
      if(a >= c)
      {
        temp = c;
        c = a;
        a = temp;
      }
    }
    else
    {
      if(b >= c)
      {
        temp = c;
        c = b;
        b = temp;
      }
    }

    //삼각형 기본 조건
    if(a + b <= c)
    {
      cout << 0 << endl;
    }
    //예각, 둔각, 직각 인지 판별
    else if(pow(a, 2) + pow(b, 2) == pow(c, 2))
    {
      cout << 1 << endl;
    }
    else if(pow(a, 2) + pow(b, 2) < pow(c,2))
    {
      cout << 2 << endl;
    }
    else
    {
      cout << 3 << endl;
    }
  }

  return 0;
}

double CalculateLength(int x1, int y1, int x2, int y2)
{
  double length = 0;
  length = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
  return length;
}
