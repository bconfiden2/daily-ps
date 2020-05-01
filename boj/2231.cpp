#include <iostream>
using namespace std;

int main(void)
{
  int n = 0;
  cin >> n;

  int temp = n;
  int digitOfN = 0;
  while(temp / 10 > 0)
  {
    digitOfN++;
    temp /= 10;
  }

  int i = 0;
  //int* digits = new int[digitOfN + 1];
  for(i = n - temp - 9 * digitOfN ; i < n - temp ; i++)
  {
    int sum = 0;
    for(int j = 0, naa = 1 ; j < digitOfN + 1 ; j++, naa *= 10)
    {
      sum += i / naa % 10;
    }
    if(sum + i == n)
    {
      cout << i << endl;
      break;
    }
  }
  if(i == n - temp)
  {
    cout << 0 << endl;
  }

  //delete digits;
  return 0;
}
