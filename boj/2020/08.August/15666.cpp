#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int data[8];
int ans[8];

void check(int cur, int size)
{
    if(size == m)
    {
        for(int i = 0 ; i < m ; i++)        // m 개를 다 뽑았을 시 뽑은 값들 출력 후 종료
        {
            cout << ans[i] << " ";
        }
        cout << '\n';
        return;
    }
    
    int bef = 0;                            // 같은 자릿수의 값들 중에서는 같은 값이 나오지 않게
    for(int i = cur ; i < n ; i++)          // 중복이 허용되므로 시작은 현재 값부터
    {
        if(data[i] != bef)                  // 값들이 정렬되어있으므로, 직전에 뽑았던 값이 아닐 경우에만 실행
        {
            bef = data[i];
            ans[size] = data[i];            // 이번 자릿수 결정해주고
            check(i, size + 1);             // 다음 자릿수 뽑음
        }
    }
}

int main(void)
{
    cin >> n >> m;
    for(int i = 0 ; i < n ; i++)
    {
        cin >> data[i];
    }
    sort(data, data+n);

    check(0, 0);                            // 0 부터 시작
}