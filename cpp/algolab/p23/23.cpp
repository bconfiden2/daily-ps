/*************************************************************
*                                                            *
*  Problem : 패리티 비트                                                *
*                                                            *
**************************************************************
*                                                            *
*                     20152635 경영학부 빅데이터경영통계전공 김상홍  *
*                                                            *
*************************************************************/
#include <iostream>
using namespace std;

int pow(int, int);

int main(void)
{
  int testCases = 0;
  cin >> testCases;

  for(int i = 0 ; i < testCases ; i++)
  {
    unsigned int caseN = 0; // 마지막에 출력할 때 다시 사용해야 하기 때문에
    int tempN = 0; // 처리 시 사용할 입력값을 만들어서 사용
    int result = 0;
    cin >> caseN;
    tempN = caseN;

    int numOf1 = 0;

    for(int j = 30 ; j >= 0 ; j--)
    {
      int curDigit = pow(2, j);
      if(tempN / curDigit == 1)
      {
        numOf1++;
        tempN %= curDigit;
      }
    }

    if(numOf1 % 2 == 1)
    {
      caseN += pow(2, 31);
    }

    cout << caseN << endl;
  }
}

int pow(int a, int x)
{
  int value = 1;

  for(int i = 0 ; i < x ; i++)
  {
    value *= a;
  }

  return value;
}
