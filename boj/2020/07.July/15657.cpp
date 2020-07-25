#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[9];
int ans[9];

void check(int cur, int size)
{
    if(size == m)
    {
        for(int i = 0 ; i < m ; i++)
        {
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }
    for(int i = cur ; i < n ; i++)          // 비내림차순이고 같은 수를 여러번 골라도 되므로, 현재 인덱스부터 탐색
    {
        ans[size] = arr[i];
        check(i, size + 1);                 // 다음 자리 탐색
    }
}

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    
    check(0, 0);                            // 첫 인덱스를 0 으로 시작해야함
}