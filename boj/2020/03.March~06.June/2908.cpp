#include <iostream>
using namespace std;

int main(void)
{
  int A, B;
  cin >> A >> B;

  int answer = 0;

  if(A % 10 > B % 10)
  {
      answer = 100 * (A % 10) + 10 * (A / 10 % 10) + A / 100;
  }
  else if( A % 10 < B % 10)
  {
      answer = 100 * (B % 10) + 10 * (B / 10 % 10) + B / 100;
  }
  else
  {
    if(A / 10 % 10 > B / 10 % 10)
    {
      answer = 100 * (A % 10) + 10 * (A / 10 % 10) + A / 100;
    }
    else if(A / 10 % 10 < B / 10 % 10)
    {
      answer = 100 * (B % 10) + 10 * (B / 10 % 10) + B / 100;
    }
    else
    {
      if(A / 10 > B / 10)
      {
        answer = 100 * (A % 10) + 10 * (A / 10 % 10) + A / 100;
      }
      else
      {
        answer = 100 * (B % 10) + 10 * (B / 10 % 10) + B / 100;
      }
    }
  }

  cout << answer << endl;
}
