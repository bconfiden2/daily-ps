#include <iostream>
#include <string>

using namespace std;

string a, b;
int answer;
int dp[1001][1001];

int main(void)
{
    cin >> a >> b;
    a = '0' + a;        // 문자열 인덱스를 배열과 똑같이 맞추기 위해서 앞에 쓰레기문자 붙임
    b = '0' + b;
    
    for(int r = 1 ; r < b.size() ; r++)     // 인덱스는 1부터 시작
    {
        for(int c = 1 ; c < a.size() ; c++)
        {
            if(a[c] == b[r]) dp[r][c] = dp[r-1][c-1] + 1;   // 같은 문자가 나오면 직전 LCS 값 + 1
            else dp[r][c] = dp[r][c-1] > dp[r-1][c] ? dp[r][c-1] : dp[r-1][c];  // 아닐 경우 왼쪽 / 위쪽 값 중 큰 값 선택

            if(dp[r][c] > answer) answer = dp[r][c];        // 최대 길이 갱신
        }
    }
    cout << answer << endl;
}