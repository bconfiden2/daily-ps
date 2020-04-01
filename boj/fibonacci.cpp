#include <iostream>
using namespace std;

int fibonacci(int);

int main(void)
{
  int idx = 0;
  cin >> idx;

/*
  int a1 = 0;
  int a2 = 1;
  int answer = 0;
  if(case == 0) answer = a1;
  else if(case == 1) answer = a2;
  else answer = fibonacci(idx);
*/

  cout << fibonacci(idx);
  return 0;
}

int fibonacci(int n)
{
  if(n==1) return 1;
  if(n==0) return 0;
  return fibonacci(n-1) + fibonacci(n-2);
}
