#include <iostream>

using namespace std;

int n, k;
int w, v;
int dp[2][100001];
int answer;

int main(void)
{
    cin >> n >> k;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> w >> v;

        for(int j = 1 ; j <= k ; j++)
        {
            if(j < w) dp[i%2][j] = dp[(i+1)%2][j];                              // 배낭에 들어갈 수 없으면 이전 물건 값 그대로
            else dp[i%2][j] = max(dp[(i+1)%2][j], dp[(i+1)%2][j - w] + v);      // 이전 물건 값과 새롭게 추가한 물건값을 비교해서 더 큰 쪽을 저장
            if(dp[i%2][j] > answer) answer = dp[i%2][j];                        // 최댓값 갱신
        }
    }

    cout << answer << endl;
}