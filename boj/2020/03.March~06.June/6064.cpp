#include <iostream>
using namespace std;

int t;
int M, N, x, y;

// 최대 공약수, 유클리드 호제법
int gcd(int a, int b)
{
  return b == 0 ? a : gcd(b, a % b);
}

int main(void)
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);

  cin >> t;

  for(int i = 0 ; i < t ; i++)
  {
    cin >> M >> N >> x >> y;

    int ans = x;    // X축 고정시켜놓고 그 X축에 있는 Y값들을 비교
    int target = 0; // 해당 X축에 대한 해당 반복 때 비교할 Y값 임시 저장

    // 가능한 최대값은 가로 세로의 최소공배수
    int max = M * N / gcd(M, N);
    // 나머지 연산자를 사용할 경우 0~N-1 까지 나오기 때문에 N은 0으로 바꿔준다
    if(y == N) y = 0;

    for(int j = 0 ; j < N  ; j++)
    {
      // Y값은 N 으로 나눈 나머지
      target = ans % N;
      // 이번에 돌아올 Y 값이 내가 구하려는 y값과 같다면 반복 끝!
      if(target == y) break;
      // 다음턴에 돌아올 y 값을 판별하기 위해 M 만큼 증가
      ans += M;
      // 만약 가능한 최대값이 넘어갔을 경우 불가능한 경우라 판단
      if(ans > max)
      {
        ans = -1;
        break;
      }
    }
    cout << ans << '\n';
  }
}
