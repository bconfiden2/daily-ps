#include <iostream>

using namespace std;

int t, n;
// 각각 0의 횟수와 1의 횟수들을 담아놓을 배열
int zero[41] = {1, 0, };
int one[41] = {0, 1, };

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  // 피보나치 함수 호출에서 0번과 1번 호출은 결국 똑같은 로직
  for(int i = 2 ; i < 41 ; i++)
  {
    zero[i] = zero[i-1] + zero[i-2];
    one[i] = one[i-1] + one[i-2];
  }

  cin >> t;
  for(int i = 0 ; i < t ; i++)
  {
    cin >> n;
    cout << zero[n] << " " << one[n] << '\n';
  }
}
