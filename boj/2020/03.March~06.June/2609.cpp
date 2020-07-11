#include <iostream>
using namespace std;

#define max(a,b) a>b?a:b

int main(void)
{
  int a, b;
  cin >> a >> b;

  int at = a, bt = b;

  int gcd = 0;
  int lcm = 0;

  while(b)
  {
    int r = a%b;
    a = b;
    b = r;
  }
  gcd = a;
  lcm = at * bt / gcd;

  cout << gcd << endl << lcm << endl;
}
