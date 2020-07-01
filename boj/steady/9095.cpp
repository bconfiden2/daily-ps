#include <iostream>
using namespace std;

int main(void)
{
  // 1, 2, 3 일때 각각의 갯수 담아놓음
  int answer[11] = {0, 1, 2, 4};
  // 4 이상인 i 부터는 [(i-3) 에 3을 더하는 방법]. [(i-2) 에 2를 더하는 방법], [(i-1) 에 1을 더하는 방법] 의 합으로 구할 수 있다.
  for(int i = 4 ; i < 11 ; i++)
  {
    answer[i] = answer[i - 1] + answer[i - 2] + answer[i - 3];
  }
  int t;
  cin >> t;
  for(int tc = 0 ; tc < t ; tc++)
  {
    int n;
    cin >> n;
    cout << answer[n] << '\n';
  }
}
