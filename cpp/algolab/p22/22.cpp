#include <iostream>
using namespace std;

int main(void)
{
  int testCases = 0;
  cin >> testCases;

  for(int i = 0 ; i < testCases ; i++)
  {
    int inputNum = 0;
    cin >> inputNum;

    int result = 1;
    int lastNum = 0;
    int zeroNum = 0;

    int numOf2 = 0;
    int numOf5 = 0;

    for(int j = 0 ; j < inputNum ; j++)
    {
      int num = 0;
      cin >> num;

      while(num % 2 == 0)
      {
        numOf2++;
        num /= 2;
      }
      while(num % 5 == 0)
      {
        numOf5++;
        num /= 5;
      }

      result *= num % 10;
      result %= 10;
    }

    if(numOf2 >= numOf5)
    {
      zeroNum = numOf5;
      numOf2 = numOf2 - numOf5;
      while(numOf2)
      {
        result *= 2;
        result %= 10;
        numOf2--;
      }
    }
    else
    {
      zeroNum = numOf2;
      numOf5 = numOf5 - numOf2;
      while(numOf5)
      {
        result *= 5;
        result %= 10;
        numOf5--;
      }
    }
    lastNum = result % 10;

    cout << lastNum % 10 << " " << zeroNum << endl;
  }
}
