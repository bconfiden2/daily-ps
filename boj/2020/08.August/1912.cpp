#include <iostream>

using namespace std;

int n, answer = -1000, maxi;

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for(int i = 1, temp ; i <= n ; i++)
    {
        cin >> temp;
        if(maxi < 0) maxi = temp;           // 직전까지의 합이 0보다 작으면 최댓값 다시 누적
        else         maxi = maxi + temp;    // 그 외의 경우 최댓값에서 계속 더해나감
        if(maxi > answer) answer = maxi;    // 최댓값 갱신은 필요시에만
    }
    cout << answer << endl;
}