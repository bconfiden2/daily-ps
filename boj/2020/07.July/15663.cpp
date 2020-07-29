#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
vector<int> arr(8, 10001);
vector<int> ans(8, 0);
vector<bool> visited(8, false);
vector<vector<int>> bef;

bool exist()                                        // 기존에 뽑았던 수열들 중에 현재 수열이 있는지 확인하는 함수
{
    for(int idx = 0 ; idx < bef.size() ; idx++)     // 기존 수열들 완전탐색
    {
        bool same = true;
        for(int i = 0 ; i < m ; i++)
        {
            if(bef[idx][i] != ans[i])               // 만약 다른게 한개라도 있으면 same 은 false
            {
                same = false;
                break;
            }
        }
        if(same) return true;                       // 수열의 모든 원소가 같다면 true 를 반환
    }
    return false;
}

void check(int cur, int size)
{
    if(size == m)
    {
        if(exist()) return;                         // 만약 기존 수열에 이미 존재한다면 그냥 종료
        for(int i = 0 ; i < m ; i++)                // 그 외에는
        {
            cout << ans[i] << " ";                  // 출력해주고
        }
        cout << '\n';
        bef.push_back(ans);                         // 뽑은 수열 목록에 현재 수열도 추가
        return;
    }
    for(int i = 0 ; i < n ; i++)
    {
        if(visited[i] == false)
        {
            visited[i] = true;
            ans[size] = arr[i];                     // 현재 자릿수를 넣어주고
            check(i, size + 1);                     // 다음 자릿수 재귀호출
            visited[i] = false;
        }
    }
}

int main(void)
{
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    check(-1, 0);
}