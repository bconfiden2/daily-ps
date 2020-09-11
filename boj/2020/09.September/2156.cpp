#include <iostream>

using namespace std;

int n;
int drink[10001];

int nex[10001];

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;

    for(int i = 1 ; i <= n ; i++) cin >> drink[i];      // 포도주 입력

    nex[1] = drink[1];                                  // 1,2 번째는 직접 입력
    nex[2] = drink[1] + drink[2];

    for(int i = 3 ; i <= n ; i++)                       // 3 - N 까지
    {                                                   // i-2 번째 최댓값 + 이번에 마심                (X Y 0 1)
                                                        // i-3 번째 최댓값 + 직전에 마시고 이번에도 마심 (X 0 1 1)
                                                        // i-1 번째 최댓값                             (X Y Z 0)
        nex[i] = max(max(nex[i-2] + drink[i] , nex[i-3] + drink[i-1] + drink[i]), nex[i-1]);
    }

    cout << nex[n] << endl;
}

/************************************************************
#include <cstdio>
#include <algorithm>
using namespace std;

int dp[3], tmp;

int maxi()
{
    return max(dp[0], max(dp[1], dp[2]));
}

int main()
{
    int n, x;
    scanf("%d", &n);
    while(n--)
    {
        scanf("%d", &x);
        tmp = maxi();
        if(dp[1]) dp[2] = dp[1] + x;
        dp[1] = dp[0] + x;
        dp[0] = tmp;

        printf("%d %d %d\n", dp[0], dp[1], dp[2]);
    }
    printf("%d\n", maxi());
}
***************************************************************/