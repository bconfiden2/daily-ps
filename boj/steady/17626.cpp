#include <iostream>
using namespace std;

// 입력 받은 자연수까지의 모든 최솟값들을 구해놓을 배열
int ans[50001] = {0, 1, 2, 3, 1, 2};
// 제곱근들에 대한 배열
int sqr[225] = {0};

// i 번쨰에 대한 최솟값을 구하는 함수
int cntMin(int idx)
{
  int min = 4;
  for(int i = 1 ; i * i <= idx ; i++)
  {
    // 각 제곱값들 별로 완전 탐색, 제곱값을 뺀 값에 대한 최솟값은 이미 dp 배열에 존재
    int n = ans[idx - sqr[i]];
    if(n < min) min = n;
  }
  // 최솟값(min) + 특정 제곱값(1)
  return min + 1;
}

int main(void)
{
  int n;
  cin >> n;

  // 각 제곱값들은 갯수를 1로 초기화시켜줌
  for(int i = 1 ; i < 225 ; i++)
  {
    sqr[i] = i * i;
    ans[i * i] = 1;
  }
  // 1~n 까지 최솟값들을 배열에 저장
  for(int i = 6 ; i <= n ; i++)
  {
    // 제곱값들은 하지 않음
    if(ans[i] == 0)
    {
      ans[i] = cntMin(i);
    }
  }

  cout << ans[n] << '\n';
}
