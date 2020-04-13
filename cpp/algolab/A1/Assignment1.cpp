/*************************************************************
*                                                            *
*  Problem : 주어진 정수의 합 구하기                              *
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
    int dataNum = 0, sum = 0, data = 0;
    cin >> dataNum;

    for(int j = 0 ; j < dataNum ; j++)
    {
      cin >> data;

      sum += data;
    }

    cout << sum << endl;
  }

  return 0;
}
