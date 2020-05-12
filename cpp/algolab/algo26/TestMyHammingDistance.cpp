#include <iostream>
#include <fstream>
#include <cstdlib>
#include "MyHammingDistance.h"

using namespace std;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int numTestCases;
  cin >> numTestCases;

  for(int i = 0 ; i < numTestCases ; i++)
  {
    unsigned int num1, num2;
    cin >> num1 >> num2;

    MyBinaryNumber bn1(num1), bn2(num2);

    cout << bn1.getHammingWeight(bn1.getValue()) << " ";
    cout << bn2.getHammingWeight(bn2.getValue()) << " ";
    cout << bn1.getHammingDistance(bn2) << '\n';
  }

  return 0;
}
