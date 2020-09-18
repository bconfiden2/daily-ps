#include <iostream>

using namespace std;

int n;
unsigned long long k, answer;
int data[100001];
unsigned long long dp[100001];

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n >> k;

    for(int i = 1, temp ; i <= n ; i++)
    {
        cin >> temp;
        data[i] = data[i-1] + temp;
        int idx = 0;
        for(idx = 0 ; idx < i ; idx++)
        {

        }
        dp[i] = dp[i-1] + idx;
        answer += dp[i];
    }

    cout << answer << '\n';
}