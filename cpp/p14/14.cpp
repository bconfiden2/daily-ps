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

void CheckTriangle(int, int, int);

int main(void)
{
  int testCases = 0;
  cin >> testCases;

  for(int i = 0 ; i < testCases ; i++)
  {
    int a = 0, b = 0, c = 0;
    cin >> a >> b >> c;

    CheckTriangle(a, b, c);
  }

  return 0;
}

void CheckTriangle(int a, int b, int c)
{
  if(a + b <= c)
  {
    cout << 0 << endl;
  }
  else if(a*a + b*b == c*c)
  {
    cout << 2 << endl;
  }
  else if(a == b)
  {
    if(b == c)
    {
      cout << 1 << endl;
    }
    else
    {
      cout << 3 << endl;
    }
  }
  else
  {
    cout << 4 << endl;
  }
}
