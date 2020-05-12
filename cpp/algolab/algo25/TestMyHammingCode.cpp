#include <iostream>
#include <fstream>
#include <cstdlib>
#include "MyHammingCode.h"
using namespace std;

int main()
{
  int numTestCases;
  cin >> numTestCases;

  for(int i = 0; i < numTestCases; i++)
  {
    int type;
    unsigned int num;
    cin >> type >> num;

    MyHammingCode hamCode(num);

    if (type == 0)
    {
      cout << hamCode.getEncodedValue() << endl;
    }
    else
    {
      cout << hamCode.getDecodedValue() << endl;
    }
  }

  return 0;
}
