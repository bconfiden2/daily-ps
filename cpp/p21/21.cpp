#include <iostream>
using namespace std;

int main(void)
{
  int testCases = 0;
  cin >> testCases;

  for(int i = 0 ; i < testCases ; i++)
  {
    int n = 0;
    cin >> n;
    bool sosu = true;

    for(int j = 2 ; j * j <= n ; j++)
    {
      if(n % j == 0)
      {
        sosu = false;
        break;
      }
    }

    if(sosu)
    {
      cout << 1 << endl;
    }
    else
    {
      cout << 0 << endl;
    }
  }
}
