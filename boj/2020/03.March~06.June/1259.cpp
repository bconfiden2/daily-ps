#include <iostream>
using namespace std;

int main(void)
{
  while(1)
  {
    int data = 0;
    cin >> data;
    if(!data) break;

    int digits[5] = {0};
    int digitNum = 0;
    while(data / 10 > 0)
    {
      digits[digitNum++] = data % 10;
      data /= 10;
    }
    digits[digitNum++] = data % 10;
    data /= 10;

    bool palin = true;
    for(int i = 0 ; i < digitNum / 2 ; i++)
    {
      if(digits[i] != digits[digitNum - i - 1])
      {
        palin = false;
      }
    }

    if(palin) cout << "yes";
    else cout << "no";
    cout << endl;
  }
}
