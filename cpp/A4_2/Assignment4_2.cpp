/*************************************************************
*                                                            *
*  Problem : 두 정수 사이 모든 정수의 합 구하기                    *
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
    int m = 0, n = 0;
    cin >> m;
    cin >> n;

    if(m == n)
    {
      cout << m << endl;
    }
    else
    {
      cout << (m + n) * (n - m + 1) / 2 << endl;
    }
  }

  return 0;
}
