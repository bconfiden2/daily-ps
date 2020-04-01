/*************************************************************
*                                                            *
*  Problem : 숫자로 삼각형 출력하기                               *
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
    int triSize = 0;
    cin >> triSize;

    for(int j = 1 ; j <= triSize ; j++)
    {
      int printValue = j;
      cout << printValue << " ";
      for(int k = 1 ; k < j ; k++)
      {
        printValue += triSize - k;
        cout << printValue;
        if(k != j-1) cout << " ";
      }
      cout << endl;
    }
  }
}
