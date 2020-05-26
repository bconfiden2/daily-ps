#include <iostream>
#include <array>

using namespace std;

int n;
array<int, 1000> arr = {0,};

/*
int solve(int num, int idx)
{
  int res = 0;
  // 재귀로 푼 코드
  if(num == 0) return 1;
  // 현재 1x2 상자의 위치에서 가능한 다른 박스들을 탐색
  for(int i = idx ; i < n - 2* (num-1) - 1 ; i++)
  {
    res += solve(num - 1, i + 2);
  }

  return res;
}
*/

int main(void)
{
  cin >> n;
  int temp = n;
  int res = 0;

  arr[0] = 1;
  arr[1] = 2;
  for(int i = 2 ; i < n ; i++)
  {
    arr[i] = arr[i-1] + arr[i-2];
    arr[i] %= 10007;
  }
/*
  // 재귀 코드 호출부
  while(temp >= 0)
  {
    int t = solve((n -temp) / 2, 0);
    res += t;
    temp -= 2;
  }
*/
  cout << arr[n - 1] << '\n';
}
