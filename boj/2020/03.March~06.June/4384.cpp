#include <iostream>
#include <algorithm>
using namespace std;

// 인원수별로 가능한 몸무게의 합들
// 각 팀의 최대 인원은 50, 최대 몸무게는 22500 이다
bool dp[50 + 1][22500 + 1];
// 참여인원 각각의 몸무게
int all[100];

int main(void)
{
  int n;
  cin >> n;
  int sum = 0;
  for(int i = 0 ; i < n ; i++)
  {
    cin >> all[i];
    sum += all[i];
  }
  // 가능한 몸무게의 합들을 구하는 과정
  dp[0][0] = true;
  for(int i = 0 ; i < n ; i++) // 한 명 추가될때마다
  {
    for(int j = n/2 ; j > 0 ; j--) // 모든 인원수별로
    {
      for(int k = 22500 ; k >= all[i] ; k--) // 가능한 몸무게들 전부 갱신
      {
        // 만약 직전 인원수 중 이번 몸무게를 뺀 몸무게가 가능했다면, 이번 인원수에서 가능함.
        dp[j][k] |= dp[j - 1][k - all[i]];
      }
    }
  }
  // 두 팀 차이 최솟값 찾는 과정
  int t1, t2, diff = 45000;
  for(int i = 0 ; i < 22500 ; i++)
  {
    // n 명일때 가능한 몸무게의 조합들 중
    if(dp[n/2][i])
    {
      // 상대 팀과의 차이가 적은 몸무게로 업데이트
      int temp = abs(sum - 2 * i);
      if(diff > temp)
      {
        diff = temp;
        t1 = i;
      }
    }
  }
  // 작은 몸무게 순으로 출력
  t2 = sum - t1;
  if(t1 > t2) cout << t2 << " " << t1 << '\n';
  else cout << t1 << " " << t2 << '\n';
}
