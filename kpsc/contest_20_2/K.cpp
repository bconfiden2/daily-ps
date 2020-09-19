#include <iostream>

using namespace std;

int n, a, b;
int dpa[201] = {0, 1, 2};

int main(void)
{
    cin >> n >> a >> b;
    a /= 2;
    for(int i = 3 ; i <= n ; i++)
    {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << 2 << '\n';
}