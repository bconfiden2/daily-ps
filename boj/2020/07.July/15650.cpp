#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, m;

int main(void)
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;

    vector<bool> pv(n, true);
    for(int i =  0 ; i < m ; i++)           // 8개 중 m 개의 조합을 계산
    {
        pv[i] = false;
    }
    do
    {
        for(int i = 0 ; i < pv.size() ; i++)
        {
            if(pv[i] == 0) cout << i + 1 << " ";    // 해당 조합 출력
        }
        cout << '\n';
    } while(next_permutation(pv.begin(), pv.end()));
}