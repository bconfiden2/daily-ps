#include <iostream>
using namespace std;

unsigned int power(int a, int n)
{
  unsigned int result = 1;

  for(int i = 0 ; i < n ; i++)
  {
    result *= a;
    result %= 1000000000;
  }

  cout << result << endl;
  return result;
}

int main(void)
{
  int L = 0;
  cin >> L;

  char* str = new char[L];
  cin >> str;

  long long sum = 0;
  long long r = 1;
  for(int i = 0 ; i < L ; i++)
  {
    sum += (long long)(int(str[i]) - 96) * r;
    sum %= 1234567891;
    r = (r * 31) % 1234567891;
  }

  cout << sum << endl;


  delete str;
}
