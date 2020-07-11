#include <iostream>

int stair[301];

int big(int a, int b)
{ return (a >= b ? a : b); }

int main(void)
{
  int n;
  std::cin >> n;
  int data;
  for(int i = 1 ; i <= n ; i++)
  {
    std::cin >> data;
    stair[i] = data;
  }
  // 한 칸 올라왔을 떄의 점수에 대한 배열
  int up1[301] = {0, stair[1], stair[1] + stair[2]};
  // 두 칸 올라왔을 때의 최댓값 점수에 대한 배열
  int up2[301] = {0, 0, stair[2]};

  for(int i = 3 ; i <= n ; i++)
  {
    // 한 칸 올라왔을 때는 전에 한 칸 올라왔을 수 없기 때문에, 두 칸 올라온 최고점에서 현재 점수를 더함
    up1[i] = stair[i] + up2[i - 1];
    // 두 칸 올라왔을 경우엔 전에 몇 칸 올라왔는지 상관 없기 때문에, 둘 중 최고점에서 현재 점수를 더함
    up2[i] = stair[i] + big(up1[i - 2], up2[i - 2]);
  }
  // 마지막 칸 올라왔을 때의 최고점
  std::cout << big(up1[n], up2[n]) << '\n';
}
