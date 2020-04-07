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

    int count = 0;
    int sum = 0;

    for(int j = 1 ; j < n ; j++)
    {
      if(n % j == 0)
      {
        count++;
        sum += j;
      }
    }

    cout << count << " " << sum << endl;
  }

  return 0;
}
