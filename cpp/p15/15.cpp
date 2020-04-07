/*************************************************************
*                                                            *
*  Problem : 삼각형의 종류
*                                                            *
**************************************************************
*                                                            *
*                     20152635 경영학부 빅데이터경영통계전공 김상홍  *
*                                                            *
*************************************************************/
#include <iostream>
#include <cmath>
using namespace std;

int CalculateLength(int, int, int, int);
int power(int, int);

int main(void)
{
  int testCases = 0;
  cin >> testCases;

  for(int i = 0 ; i < testCases ; i++)
  {
    int ax, ay, bx, by, cx, cy;
    cin >> ax >> ay >> bx >> by >> cx >> cy;

    //세 변의 길이를 잰다 (제곱)
    int a = CalculateLength(ax, ay, bx, by);
    int b = CalculateLength(bx, by, cx, cy);
    int c = CalculateLength(ax, ay, cx, cy);
    int temp = 0;

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
    if(sqrt(a) + sqrt(b) <= sqrt(c))
    {
      cout << 0 << endl;
    }
    //예각, 둔각, 직각 인지 판별
    else if(a + b == c)
    {
      cout << 1 << endl;
    }
    else if(a + b < c)
    {
      cout << 2 << endl;
    }
    else if(a + b > c)
    {
      cout << 3 << endl;
    }
  }

  return 0;
}

int CalculateLength(int x1, int y1, int x2, int y2)
{
  int length = 0;
  length = power(x2 - x1, 2) + power(y2 - y1, 2);
  return length;
}

int power(int a, int b)
{
  int result = 1;
  for(int i = 0 ; i < b ; i++)
  {
    result *= a;
  }
  return result;
}
