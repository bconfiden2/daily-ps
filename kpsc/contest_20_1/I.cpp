#include <iostream>

#define MOD 1000000007

using namespace std;

int n, m;
int steps[100001] = {1, 1, 2};

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for(int i = 0, temp ; i < m ; i++)
    {
        cin >> temp;
        steps[temp] = -1;
    }

    for(int i = 2 ; i <= n ; i++)
    { 
        if(steps[i] == -1) continue;
        steps[i] = (max(steps[i-1], 0) + max(steps[i-2], 0)) % MOD;
    }
    cout << steps[n] << '\n';
}