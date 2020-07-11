#include <iostream>
using namespace std;

int main(void)
{
  int n;
  cin >> n;
  int num2 = 0, num5 = 0;
  int tar;
  // 1 ~ n 까지 인수분해하여 2의 갯수와 5의 갯수 세어줌
  for(int i = 1 ; i <= n ; i++)
  {
    tar = i;
    // 2의 갯수
    while(tar % 2 == 0)
    {
      num2++;
      tar /= 2;
    }
    // 5의 갯수
    while(tar % 5 == 0)
    {
      num5++;
      tar /= 5;
    }
  }
  // 더 작은 값 출력
  num2 >= num5 ? cout << num5 << '\n' : cout << num2 << '\n';
}
