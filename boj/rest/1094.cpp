#include <iostream>

int n, a;

int main(void)
{
  std::cin >> n;
  // 최대값 64니까 2의 6승까지만 비트마스킹
  for(int i = 0 ; i < 7 ; i++)
  {
    // 해당 자릿수에 비트가 있으면 증가
    if(n & (1 << i))  a++;
  }
  std::cout << a << '\n';
}
