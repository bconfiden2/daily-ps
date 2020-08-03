#include <iostream>
#include <algorithm>

using namespace std;

int n, temp, _max;
int data[500][500];                     // 맨 왼쪽과 맨 오른쪽 역시 부모 값을 0 으로 줌

int main(void)
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    cin >> n;

    for(int idx = 1 ; idx <= n ; idx++)
    {
        for(int i = 1 ; i <= idx ; i++)
        {
            cin >> temp;
            data[idx][i] = max(data[idx-1][i-1], data[idx-1][i]) + temp;    // 자기 위의 두 값들 중 최댓값을 골라서 더해줌
            if(data[idx][i] > _max) _max = data[idx][i];                    // 최댓값 갱신
        }
    }
    cout << _max << endl;
}