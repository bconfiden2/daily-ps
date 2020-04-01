/*************************************************************
*                                                            *
*  Problem : 끝자리 숫자 계산하기                                *
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
    int dataNum = 0;
    int answer = 1;

    cin >> dataNum;

    for(int j = 0 ; j < dataNum ; j++)
    {
      int data;
      cin >> data;
      answer *= data % 10;
      answer %= 10;
    }
    cout << answer << endl;
  }
}
