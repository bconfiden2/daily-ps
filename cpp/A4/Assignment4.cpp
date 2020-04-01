/*************************************************************
*                                                            *
*  Problem : 주어진 정수의 최대/최소 구하기                        *
*                                                            *
**************************************************************
*                                                            *
*                     20152635 경영학부 빅데이터경영통계전공 김상홍  *
*                                                            *
*************************************************************/

#include <iostream>
#include <limits.h>

using namespace std;

int main(void)
{
  int testCases = 0;
  cin >> testCases;

  for(int i = 0 ; i < testCases ; i++)
  {
    int cases = 0, num = 0;
    int max = 0, min = 0;
    cin >> cases;

    cin >> num;

    max = min = num;

    for(int j = 1 ; j < cases ; j++)
    {
      cin >> num;
      if(num > max)
      {
        max = num;
      }
      if(num < min)
      {
        min = num;
      }
    }

    cout << max << " " << min << endl;
  }

  return 0;
}
