#include <iostream>
using namespace std;

int main(void)
{
  unsigned int a = 648;
  unsigned int b = 1 << 3;
  unsigned int c = a & b;
  if(a & b != 0)
  {
    cout << "!!!!" << endl;
  }
  if(1)
  {
    cout << "??" << endl;
  }
  cout << ((a & b) != 0) << endl;
}
