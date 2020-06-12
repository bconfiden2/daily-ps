#include <iostream>
int n;
unsigned long long fib[91] = {0, 1};
int main(void)
{
  std::cin >> n;
  // 굳이 90까지 돌 필요 없이 n 번까지만 구해준다
  for(int i = 2 ; i <= n ; i++)
  {
    fib[i] = fib[i-1] + fib[i-2];
  }
  std::cout << fib[n] << '\n';
}
