/*************************************************************
*                                                            *
*  Problem : 세 정수의 정렬                                     *
*                                                            *
**************************************************************
*                                                            *
*                     20152635 경영학부 빅데이터경영통계전공 김상홍  *
*                                                            *
*************************************************************/

#include <iostream>
using namespace std;

void Sort3Integers(int, int, int);

int main(void)
{
  int numTestCases;

  cin >> numTestCases;

  for(int i  = 0 ; i < numTestCases ; i++)
  {
    int a, b, c;

    cin >> a >> b >> c;
    Sort3Integers(a,b,c);
  }

  return 0;
}

void Sort3Integers(int a, int b, int c)
{
  if(a <= b)
  {
    if(b <= c)
    {
      cout << a << " " << b << " " << c << endl;
    }
    else
    {
      if(a <= c)
      {
        cout << a << " " << c << " " << b << endl;
      }
      else
      {
        cout << c << " " << a << " " << b << endl;
      }
    }
  }
  else
  {
    if(c <= b)
    {
      cout << c << " " << b << " " << a << endl;
    }
    else
    {
      if(c <= a)
      {
        cout << b << " " << c << " " << a << endl;
      }
      else
      {
        cout << b << " " << a << " " << c << endl;
      }
    }
  }
}
