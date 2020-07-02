#include <iostream>

using namespace std;

// DP 배열
long long P[101] = {0, 1, 1, 1, 2, 2, 3, 4, 5, 7, 9};

int main(void)
{
    int t;
    cin >> t;
    // 그림에서 보이는 것 처럼 직전꺼랑 5번째전 수 더해주면 된다.
    for(int i = 11 ; i <= 100 ; i++)
    {
        P[i] = P[i - 1] + P[i - 5];
    }
    for(int tc = 0 ; tc < t ; tc++)
    {
        int n;
        cin >> n;
        cout << P[n] << '\n';
    }
}