#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, k;

int binfind(const vector<int>& v, int key)          // 해당 값을 이진탐색
{
    int start = 0;
    int end = v.size() - 1;
    int mid = 0;

    while(start <= end)
    {
        mid = (start + end) / 2;

        if(v[mid] == key)     return mid;           // 만약 존재한다면 해당 인덱스를 반환하고
        else if(v[mid] > key) end = mid - 1;
        else                  start = mid + 1;
    }

    return mid - 1;                                 // 존재하지 않는다면 해당 인덱스 직전 값을 반환한다
}

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> k;

    vector<int> v(m);                           // 가지고 있는 카드들
    vector<bool> v2(m, false);                  // 해당 카드를 냈었는지 안 냈었는지 확인용
    for(int i = 0 ; i < m ; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    vector<int> out(k);
    for(int i = 0 ; i < k ; i++)                // 철수가 낼 카드 순서
    {
        cin >> out[i];
    }
    for(int i = 0 ; i < k ; i++)
    {
        for(int idx = binfind(v, out[i]) + 1 ; idx < v.size() ; idx++)  // 철수가 내는 값을 찾아보고, 해당 값의 다음 카드부터 탐색
        {
            if(v2[idx] == false)                // 내가 내지 않았던 카드들 중에 가장 작은 카드
            {
                v2[idx] = true;                 // 냈다고 표시
                cout << v[idx] << '\n';
                break;
            }
        }
    }
}