#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[8];
bool visited[8];
int ans[8];

void check(int cur, int size)
{
    if(size == m)
    {
        for(int i = 0 ; i < m ; i++)
        {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
    for(int i = 0 ; i < n ; i++)        // 수열에서 중복값만 없으면 되기 때문에 모든 값들 탐색
    {
        if(visited[i] == false)         // 앞에서 뽑은 값이 아닐 경우에
        {
            visited[i] = true;
            ans[size] = arr[i];         // 답에 넣어주고
            check(i, size + 1);         // 다음 자릿수 확인
            visited[i] = false;
        }
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
    sort(arr, arr+n);                   // 입력된 수열 정렬
    
    check(-1, 0);                       // 시작을 -1 로 해야 0번 인덱스부터 훑을 수 있음
}