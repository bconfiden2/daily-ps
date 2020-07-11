#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(void)
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for(int i = 0 ; i < n ; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    int ans = 0, temp = 0;
    for(int i = 0 ; i < n ; i++)
    {
        // 해당 순서의 사람이 걸리는 시간
        temp += v[i];
        // 그 사람이 걸린 시간을 전체합에 더해줌
        ans += temp;
    }
    cout << ans;
}