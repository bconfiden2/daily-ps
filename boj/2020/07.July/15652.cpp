#include <iostream>

using namespace std;

int n, m;

int ans[8];

void check(int cur, int size)
{
    if(size == m)                       // 길이가 M 에 도달하면 값들 출력 후 종료
    {
        for(int i = 0 ; i < m ; i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
        return;
    }
    for(int i = cur ; i < n ; i++)      // 중복 가능하기 때문에 cur 부터 끝까지 반복
    {
        ans[size] = i + 1;              // 현재 자리에 값을 넣어주고
        check(i, size + 1);             // 다음 값 결정하기 위한 재귀
    }
}

int main(void)
{
    cin >> n >> m;
    check(0, 0);
}