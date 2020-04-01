#include <iostream>

using namespace std;

int main(void)
{
  int n = 0;
  cin >> n;

  for(int i = 0 ; i < n ; i++)
  {
    int numData, data;
    int last1Digit = 1;

    cin >> numData;

    for(int j = 0 ; j < numData ; j++)
    {
      cin >> data;
      last1Digit *= data;
      last1Digit %= 10;
    }
    cout << last1Digit << endl;
  }
}
