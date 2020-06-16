#include <iostream>
int main(void)
{
  int n, i = 0, res = 0;
  int bills[6] = {500, 100, 50, 10, 5, 1};
  std::cin >> n;
  n = 1000 - n;
  // 거스름돈이 0원이 될 때 까지
  while(n != 0)
  {
    // 만약 이번 단위로 빼는게 가능하다면
    if(n - bills[i] >= 0)
    {
      // 빼주고 카운트 해줌
      n -= bills[i];
      res++;
    }
    // 빼는게 불가능하다면 다음 작은 단위로
    else
    {
      i++;
    }
  }
  std::cout << res << '\n';
}
